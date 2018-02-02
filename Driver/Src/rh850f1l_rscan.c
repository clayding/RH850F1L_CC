/**
  ******************************************************************************
  * @file    rh850f1l_rscan.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   1-February-2018
  * @brief   Rs-CAN module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of Rs-CAN peripheral:
  *           + Initialization and de-initialization functions
  *           + Rs-CAN functions
  ******************************************************************************
  */
#include "rh850f1l_rscan.h"

#define RSCAN_MAX_CHANNEL_NUM   3  // 0-2 channel

static uint32_t  RSCAN_Global_Mode_Ctl(RSCAN_GLOBAL_MODE_Type mode, uint8_t ctl, uint8_t val);

void RSCAN_Init(void)
{
    uint8_t channel = 0;
    RSCAN_Set_Communication_Speed com_sp;
    //rscan clock domain Setting

    /*the GRAMINIT flag in the RSCAN0GSTS register is cleared to 0 when CAN RAM
    initialization is completed*/
    while(__RSCAN_GET_GLOBAL_STAT(CAN_GRAMINIT_MASK));

    //Transition from global stop mode to global reset mode
    RSCAN_Global_Mode_Ctl(RSCAN_STOP_MODE,1,0);

    //guarantee not in global stop mode
    while(__RSCAN_GET_GLOBAL_STAT(CAN_GSLPSTS_MASK));

    //transition from channel stop mode to channel reset mode
    RSCAN_Channel_Mode_Ctl(channel,RSCAN_STOP_MODE,1,0);

    //guarantee not in channel stop mode
    while(__RSCAN_GET_CHANNEL_STAT(channel,CAN_CSLPSTS_MASK));

    //Config the clock, bit_timing and communication speed
    RSCAN_Communication_Speed_Set(com_sp);





}
/*
    @param ctl 0-- read   1-- wirte*/
uint32_t  RSCAN_Global_Mode_Ctl(RSCAN_GLOBAL_MODE_Type mode, uint8_t ctl, uint8_t val)
{
    __IO uint32_t mask = 0, ret = 0;
    __IO uint8_t offset = 0;

    mask = (mode == RSCAN_STOP_MODE)?CAN_GSLPR_MASK:CAN_GMDC_MASK;
    offset = (mode == RSCAN_STOP_MODE)?CAN_GSLPR_OFFSET:CAN_GMDC_OFFSET;

    if(ctl){ //write into
        __RSCAN_SET_GLOBAL_CTL(mask,val << offset);
    }
    ret = __RSCAN_GET_GLOBAL_CTL(mask);

    return ret;
}

/*
    @param ctl 0-- read   1-- wirte*/
int32_t  RSCAN_Channel_Mode_Ctl(uint8_t channel,RSCAN_CHANNEL_MODE_Type mode,uint8_t ctl, uint8_t val)
{
    __IO uint32_t mask = 0,ret = 0;
    __IO uint8_t offset = 0;

    if(channel > RSCAN_MAX_CHANNEL_NUM - 1) return -1;//channel not supported

    mask = (mode == RSCAN_STOP_MODE)?CAN_CSLPR_MASK:CAN_CHMDC_MASK;
    offset = (mode == RSCAN_STOP_MODE)?CAN_CSLPR_OFFSET:CAN_CHMDC_OFFSET;

    if(ctl){ //write into
        __RSCAN_SET_CHANNEL_CTL(channel,mask,val << offset);
    }

    ret = __RSCAN_GET_CHANNEL_CTL(channel,mask);

    return ret;
}

void RSCAN_Communication_Speed_Set(uint8_t channel, RSCAN_COM_SPEED_PARAM_TypeDef speed_param )
{
    __IO uint32_t ch_cfg = 0;
    __IO uint8_t sjw = 0,tseg2 = 2,tseg1 = 4,brp = 0;

    sjw   = speed_param.bit_time.sjw;
    tseg2 = speed_param.bit_time.tseg2;
    tseg1 = speed_param.bit_time.tseg1;
    brp   = speed_param.bit_time.brp;

    if(speed_param.fcan_src == RSCAN_CLKC) //select the clkc as the clock source
        __RSCAN_SET_GLOBAL_CFG(CAN_DCS_MASK,0,CAN_DCS_OFFSET);
    else //select the clk_xincan as the clock source
        __RSCAN_SET_GLOBAL_CFG(CAN_DCS_MASK,1,CAN_DCS_OFFSET);

    if(channel > RSCAN_MAX_CHANNEL_NUM - 1) return;//channel not supported

    ch_cfg = __RSCAN_GET_CHANNEL_CFG(channel);//Get the old value in register

    if(sjw <= 4 && sjw <= tseg2){ //sjw should not greater than 4Tq
        ch_cfg &= ~CAN_SJW_MASK;// clear the bits
        ch_cfg |= (sjw << CAN_SJW_OFFSET) & CAN_SJW_MASK;
    }

    //Set TSEG2 to a range of 2Tq(0b00) to 8 Tq,not greater than 8Tq
    if(tseg2 != 0 && tseg2 <= 8 && tseg2 < tseg1){
        ch_cfg &= ~CAN_TSEG2_MASK;// clear the bits
        ch_cfg |= (tseg2 << CAN_TSEG2_OFFSET) & CAN_TSEG2_MASK;
    }

    //Set TSEG1 to a range of 4Tq(0b11) to 16Tq(0b1111),not greater than 8Tq
    if(tseg1 >= 4 &&  tseg1 <= 16){
        ch_cfg &= ~CAN_TSEG1_MASK;// clear the bits
        ch_cfg |= (tseg1 << CAN_TSEG1_OFFSET) & CAN_TSEG1_MASK;
    }

    if(brp >> 10 == 0){//between 0 and 1023
        ch_cfg &= ~CAN_BRP_MASK;// clear the bits
        ch_cfg |= brp & CAN_BRP_MASK;
    }

    __RSCAN_SET_CHANNEL_CFG(channel,ch_cfg);
}

void RSCAN_Receive_Rule_Set(uint8_t channel)
{
    if(channel > RSCAN_MAX_CHANNEL_NUM) return;

    //Set the number of receive rules
    if(channel / 4)
        __RSCAN_SET_RULE_NUMBER_1(7-channel,0x80); //default 0x80,should be modified
    else /*channel < 4 */
        __RSCAN_SET_RULE_NUMBER_0(3-channel,0x80);

    /*Set the AFLDAE bit in the RSCAN0GAFLECTR register to 1 to enable writing
    data to the receive rule table*/
    __RSCAN_RECV_TABLE_WRITE_EN(1);

    //Select a page to be set by the AFLPN[4:0] bits in the RSCAN0GAFLECTR register
    __RSCAN_RECV_TABLE_PAGE_NO_CFG(1);

    //Set receive rules by the RSCAN0GAFLIDj, RSCAN0GAFLMj,RSCAN0GAFLP0j and RSCAN0GAFLP1j registers.



    /*Set the AFLDAE bit in the RSCAN0GAFLECTR register to 0 to disable writing
    data to the receive rule table.*/
    __RSCAN_RECV_TABLE_WRITE_EN(0);
}

void RSCAN_RuleID_Set(uint8_t j,uint32_t id,uint8_t tar_meg,uint8_t rtr,uint8_t ide)
{
    __IO uint32_t val = id;

    /*Set the ID of the receive rule.For the standard ID, set the ID in bits
    b10 to b0 and set bits b28 to b11 to 0.*/
    val &= (ide == 0)?(CAN_GAFLID_MASK >> 18) : CAN_GAFLID_MASK;

    //Receive Rule Target Message Select
    val |= (tar_meg << CAN_GAFLLB_OFFSET) & CAN_GAFLLB_MASK;
    //RTR Select 0: Data frame 1: Remote frame
    val |= (rtr << CAN_GAFLRTR_OFFSET) & CAN_GAFLLB_MASK;
    //IDE Select 0: Standard ID 1: Extended ID
    val |= (ide << CAN_GAFLIDE_OFFSET) & CAN_GAFLLB_MASK;


    __RSCAN_SET_RULE_ID(j,val);

    /*//The IDE bit is compared and the RTR bit is compared*/
    val = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK;
    __RSCAN_SET_RULE_MASK(j,CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK,val);
}

void RSCAN_Rule_Pointer_Set(RSCAN_RECV_RULE_POINTER_TypeDef rule_p)
{
    uint32_t val = 0;
    RSCAN_DLC_CHECK_Type dlc_t; //Receive Rule DLC disable or 1-8 data bytes
    uint16_t label_t;           //the 12-bit label information.
    bool recv_buf_used;         //TRUE or FLASE
    uint8_t buf_num;            //the receive buffer number to store received message
    uint8_t tr_sel;             //transmit/receive FIFO buffer number k 0-17
    uint8_t r_sel;              //receive FIFO buffer number x 0-7

    val = ((rule_p.dlc_t << CAN_GAFLDLC_OFFSET) & CAN_GAFLDLC_MASK) |
        ((rule_p.label_t << CAN_GAFLPTR_OFFSET) & CAN_GAFLPTR_OFFSET);

    if(rule_p.recv_buf_used){
        val |= ((rule_p.recv_buf_used << CAN_GAFLRMV_OFFSET) & CAN_GAFLRMV_MASK) |
            ((rule_p.buf_num << CAN_GAFLRMDP_OFFSET) & CAN_GAFLRMDP_MASK);
    }



}
