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

#define MAX_CHANNEL_NUM         3  // 0-2 channel
#define TOTAL_RECV_BUF_NUM      1  // Receive Buffer Number Configuration - set to 1, max 96

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
    RSCAN_Global_Mode_Ctl(RSCAN_RESET_MODE,1);

    //guarantee not in global stop mode
    while(__RSCAN_GET_GLOBAL_STAT(CAN_GSLPSTS_MASK));

    //transition from channel stop mode to channel reset mode
    RSCAN_Channel_Mode_Ctl(channel,RSCAN_RESET_MODE,1);

    //guarantee not in channel stop mode
    while(__RSCAN_GET_CHANNEL_STAT(channel,CAN_CSLPSTS_MASK));

    //Config the clock, bit_timing and communication speed
    RSCAN_Communication_Speed_Set(com_sp);

    RSCAN_Receive_Rule_Set(0);

    RSCAN_Buffer_Set();

    RSCAN_Global_Mode_Ctl(RSCAN_RESET_MODE,1);
    RSCAN_Channel_Mode_Ctl(0,RSCAN_RESET_MODE,1);

    //Interrupt control register of interrupt controller
    RSCAN_Eiint_Init();

    //Transition to global operating mode (Set GMDC[1:0] in the RSCAN0GCTR register to 00B)
    RSCAN_Global_Mode_Ctl(RSCAN_OPERATE_MODE,1);
    while((__RSCAN_GET_GLOBAL_STAT(CAN_GRSTSTS_MASK));

    //Transition to channel communication mode (Set CHMDC[1:0] in the RSCAN0CmCTR register to 00B)
    RSCAN_Channel_Mode_Ctl(0,RSCAN_COMMUNICATION_MODE,1);
    __RSCAN_GET_CHANNEL_STAT(channel,CAN_CRSTSTS_MASK);
}
/*
    @param ctl 0-- read   1-- wirte*/
uint32_t  RSCAN_Global_Mode_Ctl(RSCAN_GLOBAL_MODE_Type mode, uint8_t ctl)
{
    __IO uint32_t mask = 0, ret = 0;

    /* mode                     RSCAN0GCTR[2] RSCAN0GCTR[1]  RSCAN0GCTR[0]
    RSCAN_OPERATE_MODE,             0               0               0
    RSCAN_COMMUNICATION_MODE        0               0               0
    RSCAN_RESET_MODE                0               0               1
    RSCAN_TEST_MODE                 0               1               0
    RSCAN_STOP_MODE                 1               x               x*/

    mask = CAN_GSLPR_MASK | CAN_GMDC_MASK;

    if(ctl){ //write into
        __RSCAN_SET_GLOBAL_CTL(mask,(uint32_t)mode);
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

    if(channel > MAX_CHANNEL_NUM - 1) return -1;//channel not supported

    /* mode                     RSCAN0GCTR[2] RSCAN0GCTR[1]  RSCAN0GCTR[0]
    RSCAN_OPERATE_MODE,             0               0               0
    RSCAN_COMMUNICATION_MODE        0               0               0
    RSCAN_RESET_MODE                0               0               1
    RSCAN_TEST_MODE                 0               1               0
    RSCAN_STOP_MODE                 1               x               x*/

    mask = CAN_GSLPR_MASK | CAN_GMDC_MASK;

    if(ctl){ //write into
        __RSCAN_SET_CHANNEL_CTL(channel,mask,(uint32_t)mode);
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

    if(channel > MAX_CHANNEL_NUM - 1) return;//channel not supported

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
    uint8_t j = 0;
    if(channel > MAX_CHANNEL_NUM) return;

    //Set the number of receive rules
    if(channel / 4)
        __RSCAN_SET_RULE_NUMBER_1(7-channel,0); //default 0x80,should be modified
    else /*channel < 4 */
        __RSCAN_SET_RULE_NUMBER_0(3-channel,1);

    /*Set the AFLDAE bit in the RSCAN0GAFLECTR register to 1 to enable writing
    data to the receive rule table*/
    __RSCAN_ENABLE_RECV_TABLE_WRITE(1);

    //Select a page to be set by the AFLPN[4:0] bits in the RSCAN0GAFLECTR register
    __RSCAN_RECV_TABLE_PAGE_NUM_CFG(1);

    //Set receive rules by the RSCAN0GAFLIDj, RSCAN0GAFLMj,RSCAN0GAFLP0j and RSCAN0GAFLP1j registers.

    for(;j < 1; j++){
        RSCAN_RuleID_Set(j,0,0,0,0);
        RSCAN_Rule_Pointer_Set();
    }


    /*Set the AFLDAE bit in the RSCAN0GAFLECTR register to 0 to disable writing
    data to the receive rule table.*/
    __RSCAN_ENABLE_RECV_TABLE_WRITE(0);
}
/*ide IDE Select 0: Standard ID 1: Extended ID
  rtr RTR Select 0: Data frame 1: Remote frame
  tar_meg Receive Rule Target Message Select
    0: When a message transmitted from another CAN node is received
    1: When the own transmitted message is received
  id Set the ID of the receive rule.For the standard ID, set the ID in bits b10
    to b0 and set bits b28 to b11 to 0.*/
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

void RSCAN_Rule_Pointer_Set(uint8_t j,RSCAN_RECV_RULE_POINTER_TypeDef rule_p)
{
    uint32_t val = 0;

    val = (uint32_t)(((rule_p.dlc_t << CAN_GAFLDLC_OFFSET) & CAN_GAFLDLC_MASK) |
        ((rule_p.label_t << CAN_GAFLPTR_OFFSET) & CAN_GAFLPTR_MASK));

    if(rule_p.recv_buf_used){
        val |= ((rule_p.recv_buf_used << CAN_GAFLRMV_OFFSET) & CAN_GAFLRMV_MASK) |
            ((rule_p.buf_num << CAN_GAFLRMDP_OFFSET) & CAN_GAFLRMDP_MASK);
    }

    __RSCAN_SET_RULE_POINTER0(j,val);

    //TODO . Up to eight FIFO buffers are selectable. However, when the GAFLRMV bit in the
    //RSCAN0GAFLP0j register is set to 1 (a message is stored in the receive buffer), up to seven FIFO
    //buffers can be selected
    //TODO Only receive FIFO buffers and the transmit/receive FIFO buffer for which the
    //CFM[1:0] bits in the RSCAN0CFCCk register are set to 00B (receive mode) or 10B (gateway mode)
    //are selectable.
    val = 0x01 << (tr_sel + 8);
    val |= 0x01 << r_sel;
    __RSCAN_SET_RULE_POINTER1(j,val);
}



void RSCAN_Buffer_Set(uint8_t x,uint8_t k,uint8_t m)
{
    uint32_t val = 0,mask = 0;
    uint8_t trans_buf_index = 0;

    //Set receive buffer (the RSCAN0RMNB register)
    //TOTAL_RECV_BUF_NUM must be lower than 96
    __RSCAN_SET_TOTAL_RECV_BUF_NUM(TOTAL_RECV_BUF_NUM);

    //Set receive FIFO buffer (the RSCAN0RFCCx register)
    // Select receive interrupt request timing by the RFIGCV[2:0] bits
    // Select an interrupt source by the RFIM bit
    // Set the number of FIFO buffer stages by the RFDC [2:0] bits
    val = (uint32_t)(((0x01 << CAN_RFIGCV_OFFSET) & CAN_RFIGCV_MASK) |
        ((0x01 << CAN_RFIM_OFFSET) & CAN_RFIM_MASK) |
        ((0x01 << CAN_RFDC_OFFSET) & CAN_RFDC_OFFSET));

    mask = CAN_RFIGCV_MASK | CAN_RFIM_MASK | CAN_RFDC_OFFSET;
    __RSCAN_SET_RECV_FIFO_BUF(x,mask,val);

    //Set transmit/receive FIFO buffer (the RSCAN0CFCCk register)
    // Set the number of transmit buffer to be linked by the CFTML[3:0] bits.
    // Select an interval timer count source by the CFITR and CFITSS bits.
    // Select a mode by the CFM[1:0] bits.
    // Select receive interrupt request timing by the CFIGCV[2:0] bits.
    // Select an interrupt source by the CFIM bit.
    // Set the number of FIFO buffer stages by the CFDC[2:0] bits.
    val = (uint32_t)(((0x01 << CAN_CFTML_OFFSET) & CAN_CFTML_MASK) |
        ((0x00 << CAN_CFITR_OFFSET)  & CAN_CFITR_MASK)  |
        ((0x00 << CAN_CFITSS_OFFSET) & CAN_CFITSS_MASK) |
        ((0x00 << CAN_CFM_OFFSET)    & CAN_CFM_MASK)    |
        ((0x01 << CAN_CFIGCV_OFFSET) & CAN_CFIGCV_MASK) |
        ((0x00 << CAN_CFIM_OFFSET)   & CAN_CFIM_MASK)   |
        ((0x01 << CAN_CFDC_OFFSET)   & CAN_CFDC_MASK));
    mask = CAN_CFTML_MASK | CAN_CFITR_MASK | CAN_CFITSS_MASK | CAN_CFM_MASK |
        CAN_CFDC_MASK;
    __RSCAN_SET_TrRe_FIFO_BUF(k,mask,val);

    //Set transmit queue (the RSCAN0TXQCCm register)
    //Select an interrupt source by the TXQIM bit.
    //Set the number of transmit queue stages by the TXQDC[3:0] bits

    val = (uint32_t)(((0x01 << CAN_TXQIM_OFFSET) & CAN_TXQIM_MASK) |
        ((0x02 << CAN_TXQDC_OFFSET) & CAN_TXQDC_MASK));
    mask = CAN_TXQIM_MASK | CAN_TXQDC_MASK;

    __RSCAN_SET_TRANSMIT_QUEUE(m,mask,val);

    //TODO Set transmit history buffer (the RSCAN0THLCCm register)

    //Enable interrupt of buffer to be used
    // Enable receive FIFO interrupts by the RFIE bit in the RSCAN0RFCCx register.
    __RSCAN_SET_RECV_FIFO_BUF(x,CAN_RFIE_MASK,1);
    // Enable transmit/receive FIFO transmit interrupts by the CFTXIE bit in the RSCAN0CFCCk register.
    __RSCAN_SET_TrRe_FIFO_BUF(k,CAN_CFTXIE_MASK,1);
    // Enable transmit/receive FIFO receive interrupts by the CFRXIE bit in the RSCAN0CFCCk register.
    __RSCAN_SET_TrRe_FIFO_BUF(k,CAN_CFRXIE_MASK,1);
    // Enable transmit abort interrupts by the TAIE bit in the RSCAN0CmCTR register.
    __RSCAN_SET_CHANNEL_CTL(m,CAN_TAIE_MASK,1);
    // Enable transmit complete interrupts by the TMIE bit in the RSCAN0TMIECy register.
    val = (uint32_t)(0x01 << (trans_buf_index % 32));
    mask = val;
    __RSCAN_ENABLE_TRANSMIT_BUF_INT(trans_buf_index/32,mask,val); //TODO...
    // Enable transmit queue interrupts by the TXQIE bit in the RSCAN0TXQCCm register.
    __RSCAN_SET_TRANSMIT_QUEUE(m,CAN_TXQIE_MASK,1);
    // Enable transmit history interrupts by the THLIE bit in the RSCAN0THLCCm register
    //TODO...
}

void RSCAN_Eiint_Init(void)
{
    Eiint_InitTypeDef eiint;

    if(channel > MAX_CHANNEL_NUM) return; //channel not supoort

    /*  channel NO.     error       transmit/receive FIFO       transmit    receive FIFO
                        interrupt   receive complete interrupt  interrupt   interrupt
         5              279                 280                     281         X
         4              264                 265                     266         X
         3              212                 213                     214         X
         2              209                 210                     211         X
         1              105                 106                     107         X
         0              16                  17                      18          X
         Global         14                  X                       X           15    */

    eiint.eiint_ch = 14;          //CAN Global error interrupt
    eiint.eiint_ext_int = 0;
    eiint.eiint_process = INT_PROCESS_ENABLE;
    eiint.eiint_refer_method = TABLE_REFER_METHOD;
    eiint.eiint_priority = INT_PRIORITY_7;
    eiint.eiint_detect = EDGE_DETECTION | FALL_EDGE_ENABLE | RISE_EDGE_DISABLE;
    Eiit_Init(&eiint);

    eiint.eiint_ch = 16; //CAN0 error interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 18;//CAN0 transmit interrupt
    Eiit_Init(&eiint);
}
