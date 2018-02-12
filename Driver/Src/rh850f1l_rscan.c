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
#include "rh850f1l_ext.h"

#define MAX_CHANNEL_NUM         4  // 0-3 channel
#define TOTAL_RECV_BUF_NUM      10  // Receive Buffer Number Configuration - set to 1, max 96
#define MAX_RULE_NUM_PER_PAGE   16

static uint32_t  RSCAN_Global_Mode_Ctl(RSCAN_GLOBAL_MODE_Type mode, uint8_t ctl);
static int32_t  RSCAN_Channel_Mode_Ctl(uint8_t channel,RSCAN_CHANNEL_MODE_Type mode,uint8_t ctl);
static void RSCAN_Communication_Speed_Set(uint8_t channel, RSCAN_COM_SPEED_PARAM_TypeDef *speed_param );
void RSCAN_Receive_Rule_Set(uint8_t channel,RSCAN_RECV_RULE_TypeDef *rule_p,uint8_t rule_num);
static void RSCAN_RuleID_Set(uint8_t j,RSCAN_RECV_RULE_ID_INFO_TypeDef *id_info_p);
static void RSCAN_Rule_Pointer_Set(uint8_t j,RSCAN_RECV_RULE_POINTER_TypeDef *rule_p);
static void RSCAN_Buffer_Set(uint8_t m,int8_t x,int8_t k);
void RSCAN_Eiint_Init(void);

void RSCAN_Init(RSCAN_InitTypeDef *Rscan_InitStruct)
{
    uint8_t channel = 0;
    RSCAN_COM_SPEED_PARAM_TypeDef com_sp;
    RSCAN_RECV_RULE_TypeDef rule[2];
    {//for example
        rule[0].r_pointer.dlc_t = RSCAN_DLC_CHECK_DISABLED;
        rule[0].r_pointer.label_t = 0x891;
        rule[0].r_pointer.recv_buf_used = 1;
        rule[0].r_pointer.recv_buf_index = 0;
        rule[0].r_pointer.k_index = -1;
        rule[0].r_pointer.x_index = -1;

        rule[0].r_id_info.ide = RSCAN_RECV_IDE_STD;
        rule[0].r_id_info.rtr = RSCAN_RECV_DATA_FRM;
        rule[0].r_id_info.target_msg = RSCAN_RECV_FROM_OTHER;
        rule[0].r_id_info.id = 0x123;
        rule[0].r_id_info.mask = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK |CAN_GAFLIDM_MASK;


        rule[1].r_pointer.dlc_t = RSCAN_DLC_CHECK_DISABLED;
        rule[1].r_pointer.label_t = 0x745;
        rule[1].r_pointer.recv_buf_used = 1;
        rule[1].r_pointer.recv_buf_index = 1;
        rule[1].r_pointer.k_index = -1;
        rule[1].r_pointer.x_index = -1;
	    rule[1].r_id_info.ide = RSCAN_RECV_IDE_STD;
        rule[1].r_id_info.rtr = RSCAN_RECV_DATA_FRM;
        rule[1].r_id_info.target_msg = RSCAN_RECV_FROM_OTHER;
        rule[1].r_id_info.id = 0x456;
	    rule[1].r_id_info.mask = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK |CAN_GAFLIDM_MASK;

    }

    channel = Rscan_InitStruct->channel; //channel 3
    com_sp = Rscan_InitStruct->sp;

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
    RSCAN_Communication_Speed_Set(channel,&com_sp);

    RSCAN_Receive_Rule_Set(channel,rule,ARRAY_SIZE(rule));

    RSCAN_Buffer_Set(channel,rule[0].r_pointer.x_index,rule[0].r_pointer.k_index);

    RSCAN_Global_Mode_Ctl(RSCAN_RESET_MODE,1);
    RSCAN_Channel_Mode_Ctl(channel,RSCAN_RESET_MODE,1);

    //Interrupt control register of interrupt controller
    RSCAN_Eiint_Init();

    //Transition to global operating mode (Set GMDC[1:0] in the RSCAN0GCTR register to 00B)
    RSCAN_Global_Mode_Ctl(RSCAN_OPERATE_MODE,1);
    while(__RSCAN_GET_GLOBAL_STAT(CAN_GRSTSTS_MASK));

    //Transition to channel communication mode (Set CHMDC[1:0] in the RSCAN0CmCTR register to 00B)
    RSCAN_Channel_Mode_Ctl(channel,RSCAN_COMMUNICATION_MODE,1);
    while(__RSCAN_GET_CHANNEL_STAT(channel,CAN_CRSTSTS_MASK));
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
int32_t  RSCAN_Channel_Mode_Ctl(uint8_t channel,RSCAN_CHANNEL_MODE_Type mode,uint8_t ctl)
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

    mask = CAN_CSLPR_MASK | CAN_CHMDC_MASK;
    if(ctl){ //write into
        __RSCAN_SET_CHANNEL_CTL(channel,mask,(uint32_t)mode);
    }

    ret = __RSCAN_GET_CHANNEL_CTL(channel,mask);

    return ret;
}

void RSCAN_Communication_Speed_Set(uint8_t channel, RSCAN_COM_SPEED_PARAM_TypeDef *speed_param )
{
    __IO uint32_t ch_cfg = 0;
    __IO uint8_t sjw = 0,tseg2 = 2,tseg1 = 4,brp = 0;

    sjw   = speed_param->bit_time.sjw;
    tseg2 = speed_param->bit_time.tseg2;
    tseg1 = speed_param->bit_time.tseg1;
    brp   = speed_param->bit_time.brp;

    if(speed_param->fcan_src == RSCAN_CLKC) //select the clkc as the clock source
        __RSCAN_SET_GLOBAL_CFG(CAN_DCS_MASK,0);
    else //select the clk_xincan as the clock source
        __RSCAN_SET_GLOBAL_CFG(CAN_DCS_MASK,0x01 << CAN_DCS_OFFSET);

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
/*page_index :select the index of page to register the receive rule 0-23
  num_per_page: up to 16 receive rules can be registered per page */
void RSCAN_Receive_Rule_Set(uint8_t channel,RSCAN_RECV_RULE_TypeDef *rule_p,
    uint8_t rule_num)
{
    uint8_t j = 0, i = 0,rule_n = 0,rule_num_per_page = MAX_RULE_NUM_PER_PAGE;
    uint8_t page_index_useful = 0,current_rule_num = 0,pages = 0;
    if(channel > MAX_CHANNEL_NUM - 1) return;

    // Get the page index available,all the page registered sequentially
    for(i = 0; i < MAX_CHANNEL_NUM;i++){
        if(i /4)
            rule_n += __RSCAN_GET_RULE_NUMBER_1(7-i);
        else
            rule_n += __RSCAN_GET_RULE_NUMBER_0(3-i);
        if(i == (MAX_CHANNEL_NUM - 1)){
            page_index_useful = rule_n / MAX_RULE_NUM_PER_PAGE;
        }
    }

    //Set the number of receive rules for channel x
    if(channel / 4){
        current_rule_num = __RSCAN_GET_RULE_NUMBER_1(7-channel);
        if(rule_num != current_rule_num){
            __RSCAN_SET_RULE_NUMBER_1(7-channel,rule_num); //default 0x80,should be modified
            current_rule_num = rule_num;
        }
    }else{ /*channel < 4 */
        current_rule_num = __RSCAN_GET_RULE_NUMBER_0(3-channel);
        if(rule_num != current_rule_num){
            __RSCAN_SET_RULE_NUMBER_0(3-channel,rule_num);
            current_rule_num = rule_num;
        }
    }

    /*Set the AFLDAE bit [8] in the RSCAN0GAFLECTR register to 1 to enable writing
    data to the receive rule table*/
    __RSCAN_ENABLE_RECV_TABLE_WRITE(1);

    pages  = (current_rule_num / MAX_RULE_NUM_PER_PAGE);
    if(current_rule_num % MAX_RULE_NUM_PER_PAGE) pages++;

    for(i = page_index_useful;i < page_index_useful + pages;i++){
        uint8_t start_rule_num_index = 0;
        //Select a page to be set by the AFLPN[4:0] bits in the RSCAN0GAFLECTR register
        __RSCAN_RECV_TABLE_PAGE_NUM_CFG(i);
        if( i == (page_index_useful + pages - 1)){
            rule_num_per_page = current_rule_num % MAX_RULE_NUM_PER_PAGE;
        }
        start_rule_num_index = (i == page_index_useful) ? (rule_n % MAX_RULE_NUM_PER_PAGE):0;
        //Set receive rules by the RSCAN0GAFLIDj, RSCAN0GAFLMj,RSCAN0GAFLP0j and RSCAN0GAFLP1j registers.
        for( j = start_rule_num_index ;j < rule_num_per_page; j++){
            uint8_t arr_index = j - start_rule_num_index;
            RSCAN_RuleID_Set(j,&rule_p[arr_index].r_id_info);//id = 0,When the own transmitted message is received,data frame,standard ID
            RSCAN_Rule_Pointer_Set(j,&rule_p[arr_index].r_pointer);
        }
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
void RSCAN_RuleID_Set(uint8_t j,RSCAN_RECV_RULE_ID_INFO_TypeDef *id_info_p)
{
    __IO uint32_t val = id_info_p->id;

    /*Set the ID of the receive rule.For the standard ID, set the ID in bits
    b10 to b0 and set bits b28 to b11 to 0.*/
    val &= (id_info_p->ide == 0)?(CAN_GAFLID_MASK >> 18) : CAN_GAFLID_MASK;

    //Receive Rule Target Message Select
    val |= (id_info_p->target_msg << CAN_GAFLLB_OFFSET) & CAN_GAFLLB_MASK;
    //RTR Select 0: Data frame 1: Remote frame
    val |= (id_info_p->rtr << CAN_GAFLRTR_OFFSET) & CAN_GAFLRTR_MASK;
    //IDE Select 0: Standard ID 1: Extended ID
    val |= (id_info_p->ide << CAN_GAFLIDE_OFFSET) & CAN_GAFLIDE_MASK;


    __RSCAN_SET_RULE_ID(j,val);
    /*//The IDE bit is compared and the RTR bit is compared*/
    val = id_info_p->mask;
    __RSCAN_SET_RULE_MASK(j, id_info_p->mask,val);
}

void RSCAN_Rule_Pointer_Set(uint8_t j,RSCAN_RECV_RULE_POINTER_TypeDef *pointer_p)
{
    uint32_t val = 0;

    val = (uint32_t)(((pointer_p->dlc_t << CAN_GAFLDLC_OFFSET) & CAN_GAFLDLC_MASK) |
        ((pointer_p->label_t << CAN_GAFLPTR_OFFSET) & CAN_GAFLPTR_MASK));

    if(pointer_p->recv_buf_used){
        val |= ((pointer_p->recv_buf_used << CAN_GAFLRMV_OFFSET) & CAN_GAFLRMV_MASK) |
            ((pointer_p->recv_buf_index << CAN_GAFLRMDP_OFFSET) & CAN_GAFLRMDP_MASK);
    }

    __RSCAN_SET_RULE_POINTER0(j,val);

    //TODO . Up to eight FIFO buffers are selectable. However, when the GAFLRMV bit in the
    //RSCAN0GAFLP0j register is set to 1 (a message is stored in the receive buffer), up to seven FIFO
    //buffers can be selected
    //TODO Only receive FIFO buffers and the transmit/receive FIFO buffer for which the
    //CFM[1:0] bits in the RSCAN0CFCCk register are set to 00B (receive mode) or 10B (gateway mode)
    //are selectable.
    val  = 0;
    if(pointer_p->k_index >=0 && pointer_p->k_index <= 17)
        val = 0x01 << (pointer_p->k_index + 8);
    if(pointer_p->x_index >= 0 && pointer_p->x_index <= 7)
        val |= 0x01 << pointer_p->x_index;

    __RSCAN_SET_RULE_POINTER1(j,val);
}

void RSCAN_Buffer_Set(uint8_t m,int8_t x,int8_t k)
{
    uint32_t val = 0,mask = 0;
    uint8_t trans_buf_index = 48;

    //Set receive buffer (the RSCAN0RMNB register)
    //TOTAL_RECV_BUF_NUM must be lower than 96
    __RSCAN_SET_TOTAL_RECV_BUF_NUM(TOTAL_RECV_BUF_NUM);

    if(x != -1 ){
        //Set receive FIFO buffer (the RSCAN0RFCCx register)
        // Select receive interrupt request timing by the RFIGCV[2:0] bits
        // Select an interrupt source by the RFIM bit
        // Set the number of FIFO buffer stages by the RFDC [2:0] bits
        val = (uint32_t)(((0x01 << CAN_RFIGCV_OFFSET) & CAN_RFIGCV_MASK) |
            ((0x01 << CAN_RFIM_OFFSET) & CAN_RFIM_MASK) |
            ((0x01 << CAN_RFDC_OFFSET) & CAN_RFDC_OFFSET));

        mask = CAN_RFIGCV_MASK | CAN_RFIM_MASK | CAN_RFDC_OFFSET;
        __RSCAN_SET_RECV_FIFO_BUF(x,mask,val);
    }

    if(k != -1){
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
    }
#if 0
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
#endif
    // Enable transmit abort interrupts by the TAIE bit in the RSCAN0CmCTR register.
    __RSCAN_SET_CHANNEL_CTL(m,CAN_TAIE_MASK,1 << CAN_TAIE_OFFSET);

    // Enable transmit complete interrupts by the TMIE bit in the RSCAN0TMIECy register.
    val = (uint32_t)(0x01 << (trans_buf_index % 32));
    mask = val;
    __RSCAN_ENABLE_TRANSMIT_BUF_INT((trans_buf_index/32),mask,val); //TODO...
#if 0
    // Enable transmit queue interrupts by the TXQIE bit in the RSCAN0TXQCCm register.
    __RSCAN_SET_TRANSMIT_QUEUE(m,CAN_TXQIE_MASK,1);
    // Enable transmit history interrupts by the THLIE bit in the RSCAN0THLCCm register
    //TODO...
#endif
}

void RSCAN_Eiint_Init(void)
{
    Eiint_InitTypeDef eiint;
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
    eiint.eiint_detect = LEVEL_DETECTION |LOW_LEVEL_DETECT;
    Eiit_Init(&eiint);

    eiint.eiint_ch = 16; //CAN0 error interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 18;//CAN0 transmit interrupt
    Eiit_Init(&eiint);
}

int8_t RSCAN_Transmit_Buffer_Write(RSCAN_TRANSMIT_ID_INFO_TypeDef id_info, uint8_t data_len,
        uint8_t* data_p)
{
    uint8_t p = 0, size = 0;
    uint8_t len = 0,data[8] = {0};
    uint32_t val = 0;


    if(id_info.index > 95) return -1;// max 95
    p = id_info.index;

    val = (uint32_t)(((id_info.ide << CAN_TMIDE_OFFSET) & CAN_TMIDE_MASK) |
        ((id_info.rtr << CAN_TMRTR_OFFSET) & CAN_TMRTR_MASK) |
        ((id_info.his_en << CAN_THLEN_OFFSET) & CAN_THLEN_MASK));

    /*Set the ID of the receive rule.For the standard ID, set the ID in bits
    b10 to b0 and set bits b28 to b11 to 0.*/
    if(id_info.ide == 0)
        val |= id_info.id & (CAN_TMID_MASK >> 18);
    else
        val |= id_info.id & CAN_TMID_MASK;

    __RSCAN_SET_TRANSMIT_BUF_ID(p,val);

    val = (uint32_t)(((data_len << CAN_TMDLC_OFFSET) & CAN_TMDLC_MASK) |
        ((id_info.label_t << CAN_TMPTR_OFFSET) & CAN_TMPTR_MASK));

    __RSCAN_SET_TRANSMIT_BUF_POINTER(p,val);

    len = (data_len > 8) ? 8: data_len;//data length not greater than 8

    for(size = 0; len && size < len; size++){
        data[size] = data_p[size];
    }

    __RSCAN_WRITE_TRANSMIT_BUF_DATA_L(p,&data[0]);
    __RSCAN_WRITE_TRANSMIT_BUF_DATA_H(p,&data[4]);

    //Set the TMTR bit in the corresponding RSCAN0TMCp register to 1 (requesting transmission)
    //__RSCAN_SET_TRANSMIT_BUF_CTL(p,CAN_TMOM_MASK,1 << CAN_TMOM_OFFSET);
    __RSCAN_SET_TRANSMIT_BUF_CTL(p,CAN_TMTR_MASK,1);

    return size;//return the actual data size to be transmited
}

int8_t RSCAN_Transmit_Recv_FIFO_Write(RSCAN_TRANSMIT_ID_INFO_TypeDef id_info, uint8_t data_len,
        uint8_t* data_p)
{
    uint8_t k = 0, size = 0;
    uint8_t len = 0, data[8] = {0};
    uint32_t val = 0;

    if(id_info.index > 17) return -1;// max 17
    k = id_info.index;

    // Is transmit/receive FIFO buffer full?
    // (Is CFFLL flag in the RSCAN0CFSTSk register 1?)
    if(__RSCAN_GET_TrRe_FIFO_STAT(k,CAN_CFFLL_MASK))
        return -1;//if full, return

    val = (uint32_t)(((id_info.ide << CAN_CFIDE_OFFSET) & CAN_CFIDE_MASK) |
        ((id_info.rtr << CAN_CFRTR_OFFSET) & CAN_CFRTR_MASK) |
        ((id_info.his_en << CAN_THLEN_OFFSET) & CAN_THLEN_MASK));

    /*Set the ID of the receive rule.For the standard ID, set the ID in bits
    b10 to b0 and set bits b28 to b11 to 0.*/
    if(id_info.ide == 0)
        val |= id_info.id & (CAN_CFID_MASK >> 18);
    else
        val |= id_info.id & CAN_CFID_MASK;

    __RSCAN_SET_TrRe_FIFO_ID(k,val);

    val = (uint32_t)(((data_len << CAN_CFDLC_OFFSET) & CAN_TMDLC_MASK) |
        ((id_info.label_t << CAN_CFPTR_OFFSET) & CAN_CFPTR_MASK));

    __RSCAN_SET_TrRe_FIFO_POINTER(k,val);

    len = (data_len > 8) ? 8: data_len;

    for(size = 0; len && size < len; size++){
        data[size] = data_p[size];
    }

    __RSCAN_WRITE_TrRe_FIFO_DATA_H(k,&data[0]);
    __RSCAN_WRITE_TrRe_FIFO_DATA_L(k,&data_p[4]);

    //Set the RSCAN0CFPCTRk register to 0xFF
    _RSCAN_SET_TrRe_FIFO_POINTER(k);

    return size;
}

int8_t RSCAN_Transmit_Queue_Write(RSCAN_TRANSMIT_ID_INFO_TypeDef id_info, uint8_t data_len,
        uint8_t* data_p)
{
    uint8_t p = 0, m = 0, size = 0;
    uint8_t len = 0, data[8] = {0};
    uint32_t val = 0;


    if(id_info.index > 5) return -1;// max 5
    m = id_info.index;
    p = m * 16 + 15; //p = m × 16 + 15, m = 0 to 5

    //Is transmit queue full?(Is TXQFLL flag in the RSCAN0TXQSTSm register 1?)
    if(__RSCAN_GET_TRANSMIT_QUEUE_STAT(m,CAN_TXQFLL_MASK))
        return -1;//if full, return


    val = (uint32_t)(((id_info.ide << CAN_TMIDE_OFFSET) & CAN_TMIDE_MASK) |
        ((id_info.rtr << CAN_TMRTR_OFFSET) & CAN_TMRTR_MASK) |
        ((id_info.his_en << CAN_THLEN_OFFSET) & CAN_THLEN_MASK));

    /*Set the ID of the receive rule.For the standard ID, set the ID in bits
    b10 to b0 and set bits b28 to b11 to 0.*/
    if(id_info.ide == 0)
        val |= id_info.id & (CAN_TMID_MASK >> 18);
    else
        val |= id_info.id & CAN_TMID_MASK;

    __RSCAN_SET_TRANSMIT_BUF_ID(p,val);

    val = (uint32_t)(((data_len << CAN_TMDLC_OFFSET) & CAN_TMDLC_MASK) |
        ((id_info.label_t << CAN_TMPTR_OFFSET) & CAN_TMPTR_MASK));

    __RSCAN_SET_TRANSMIT_BUF_POINTER(p,val);

    len = (data_len > 8) ? 8: data_len;

    for(size = 0; len && size < len; size++){
        data[size] = data_p[size];
    }

    //__RSCAN_WRITE_TRANSMIT_BUF_DATA_H(p,&data[0]);
    __RSCAN_WRITE_TRANSMIT_BUF_DATA_L(p,&data[4]);

    //Set the RSCAN0TXQPCTRm register to 0xFF
    __RSCAN_SET_TRANSMIT_QUEUE_POINTER(m);

    return size;
}


int8_t RSCAN_Receive_Buffer_Read(RSCAN_RECV_ID_INFO_TypeDef *id_info_p,uint8_t* data_p)
{
    __IO uint8_t q = 0,y = 0,bit_pos = 0,i = 0;
    __IO uint8_t recv_size = 0,*p = NULL;
    __IO uint32_t val = 0;

    if(id_info_p->index > 95) return -1;// max 95
    q = id_info_p->index;

    bit_pos = q % 32;
    y = q /32;

    //Has a new message been received? (Is the RMNSq flag in the RSCAN0RMNDy register 1?)
    if(__RSCAN_CHECK_RECV_NEW_MSG(y,0x01 << bit_pos) == 0){
        return -1; //no new message in receive buffer q
    }

    //Set the RMNSq flag in the RSCAN0RMNDy register to 0
    __RSCAN_CLEAR_NEW_MSG_FLAG(y,0x01 << bit_pos);

    val =  __RSCAN_GET_RECV_BUF_ID(q);
    id_info_p->ide = (val & CAN_RMIDE_MASK) >> CAN_RMIDE_OFFSET;
    id_info_p->rtr = (val & CAN_RMRTR_MASK) >> CAN_RMRTR_OFFSET;
    id_info_p->id  = (val & CAN_RMID_MASK);

    val = __RSCAN_GET_RECV_BUF_POINTER(q);
    id_info_p->label_t = (val & CAN_RMPTR_MASK)  >> CAN_RMPTR_OFFSET;
    recv_size = (val & CAN_RMDLC_MASK)  >> CAN_RMDLC_OFFSET;
    id_info_p->time_stamp = (val & CAN_RMTS_MASK);

    p =(uint8_t*)__RSCAN_READ_RECV_BUF_DATA_L(q);

    for( i = 0; recv_size && i <recv_size;i++){
        data_p[i] = p[i];
    }

    //TODO Are all RMNSq flags in the RSCAN0RMNDy register 0?????????
    return recv_size;
}

int8_t RSCAN_Transmit_Recv_FIFO_Read(RSCAN_RECV_ID_INFO_TypeDef *id_info_p,uint8_t* data_p)
{
    uint8_t k = 0, i = 0;
    uint8_t recv_size = 0,*p = NULL;
    uint32_t val = 0;

    if(id_info_p->index > 17) return -1;// max 17
    k = id_info_p->index;

    if(__RSCAN_GET_TrRe_FIFO_STAT(k,CAN_CFEMP_MASK))
        return -1;//if empty, return

    val = __RSCAN_GET_TrRe_FIFO_ID(k);

    id_info_p->ide = (val & CAN_CFIDE_MASK) >> CAN_CFIDE_OFFSET;
    id_info_p->rtr = (val & CAN_CFRTR_MASK) >> CAN_CFRTR_OFFSET;
    id_info_p->id  = (val & CAN_CFID_MASK);

    val = __RSCAN_GET_TrRe_FIFO_POINTER(k);

    id_info_p->label_t = (val & CAN_CFPTR_MASK)  >> CAN_CFPTR_OFFSET;
    recv_size = (val & CAN_CFDLC_MASK)  >> CAN_CFDLC_OFFSET;
    id_info_p->time_stamp = (val & CAN_CFTS_MASK);

    p =(uint8_t*)__RSCAN_READ_RECV_BUF_DATA_L(k);

    for( i = 0; recv_size && i <recv_size;i++){
        data_p[i] = p[i];
    }
    //Set the RSCAN0CFPCTRk register to 0xFF
    _RSCAN_SET_TrRe_FIFO_POINTER(k);

    return recv_size;
}

int8_t RSCAN_Receive_FIFO_Read(RSCAN_RECV_ID_INFO_TypeDef *id_info_p,uint8_t* data_p)
{
    uint8_t x = 0, i = 0;
    uint8_t recv_size = 0,*p = NULL;
    uint32_t val = 0;

    if(id_info_p->index > 7) return -1;// max 7
    x = id_info_p->index;

    if(__RSCAN_GET_RECV_FIFO_STAT(x,CAN_RFEMP_MASK))
        return -1;//if empty, return

    val = __RSCAN_GET_RECV_FIFO_ID(x);

    id_info_p->ide = (val & CAN_RFIDE_MASK) >> CAN_RFIDE_OFFSET;
    id_info_p->rtr = (val & CAN_RFRTR_MASK) >> CAN_RFRTR_OFFSET;
    id_info_p->id  = (val & CAN_RFID_MASK);

    val = __RSCAN_GET_RECV_FIFO_POINTER(x);

    id_info_p->label_t = (val & CAN_RFPTR_MASK)  >> CAN_RFPTR_OFFSET;
    recv_size = (val & CAN_RFDLC_MASK)  >> CAN_RFDLC_OFFSET;
    id_info_p->time_stamp = (val & CAN_RFTS_MASK);

    p =(uint8_t*)__RSCAN_READ_RECV_BUF_DATA_L(x);

    for( i = 0; recv_size && i <recv_size;i++){
        data_p[i] = p[i];
    }

    //Set the RSCAN0RFPCTRx register to 0xFF
    _RSCAN_SET_RECV_FIFO_POINTER(x);

    return recv_size;
}

bool R_CAN_Send_TxBuf0(uint8_t channel)
{
    uint8_t data[8] = {0x45,0x56,0x78,0x89,0x90};
    uint8_t p = 0,sent_size = 0;
    RSCAN_TRANSMIT_ID_INFO_TypeDef id_info;
    {
        id_info.index = channel * 16 + 0;
        id_info.ide = 0;
        id_info.rtr = 0;
        id_info.id = 0x21;
    }

    p = id_info.index;


    if(__RSCAN_GET_TRANSMIT_STAT(p,CAN_TMTRM_MASK))
        return FALSE;

    sent_size = RSCAN_Transmit_Buffer_Write(id_info,5,data);

    return TRUE;
}


bool R_CAN_Receive_RxBuf0(uint32_t *p_can_id, uint8_t * p_dlc, uint8_t msg[8])
{
    int8_t ret = -1;
    RSCAN_RECV_ID_INFO_TypeDef id_info;

    id_info.index = 1;
    while(ret == -1){
        ret  = RSCAN_Receive_Buffer_Read(&id_info,msg);
    }

    *p_can_id = id_info.id;
    *p_dlc = ret;

    return TRUE;
}
