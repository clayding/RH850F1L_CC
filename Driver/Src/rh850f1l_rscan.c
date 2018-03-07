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

static RSCAN_BUF_MASKED_TypeDef buf_masked;//all the receive buf,transmit buf,transmit/receive fifo available

static void RSCAN_Com_Speed_Set(uint8_t channel, RSCAN_COM_SPEED_PARAM_TypeDef *speed_param );
void RSCAN_Receive_Rule_Set(uint8_t channel,RSCAN_RECV_RULE_TypeDef *rule_p,uint8_t rule_num);
static void RSCAN_RuleID_Set(uint8_t j,RSCAN_RECV_RULE_ID_INFO_TypeDef *id_info_p);
static void RSCAN_Rule_Pointer_Set(uint8_t j,RSCAN_RECV_RULE_POINTER_TypeDef *rule_p);
static void RSCAN_Buffer_Set(uint8_t m,RSCAN_TXBUF_MASK_TypeDef *txbuf_st_p,
    RSCAN_FIFO_CFG_TypeDef *cfg_param_p);

static uint8_t RSCAN_Parse_RXFIFO_Param(uint8_t m,RSCAN_RXFIFO_CFG_TypeDef *cfg_param_p,
    uint8_t cfg_param_size);
static void RSCAN_Enable_RecvFIFO(uint8_t x_mask);
static RSCAN_TXBUF_MASK_TypeDef RSCAN_Parse_TRFIFO_Param(uint8_t m,RSCAN_TRFIFO_CFG_TypeDef *cfg_param_p,
    uint8_t cfg_param_size);
static void RSCAN_Enable_TRFIFO(uint8_t m,uint32_t k_mask);

static void RSCAN_Enable_Buf_Int(uint8_t m,uint8_t x_mask,RSCAN_TXBUF_MASK_TypeDef *txbuf_st_p);
void RSCAN_Eiint_Init(void);

/**
  * @brief  Initializes the RSCAN peripheral according to the specified
  *   parameters in the Rscan_InitStruct.
  * @param  Rscan_InitStruct: pointer to a CAN_InitTypeDef structure that
  *   contains the configuration information for the RSCAN peripheral.
  * @retval none
  */
void RSCAN_Init(RSCAN_InitTypeDef *Rscan_InitStruct)
{
    uint8_t channel = 0,rule_num = 0;
    RSCAN_COM_SPEED_PARAM_TypeDef com_sp;

    RSCAN_RECV_RULE_TypeDef *rule_p = Rscan_InitStruct->rule_p;
    rule_num = Rscan_InitStruct->rule_num;

    channel = Rscan_InitStruct->channel; //channel m
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
    RSCAN_Com_Speed_Set(channel,&com_sp);

    //RSCAN_Receive_Rule_Set(channel,rule,ARRAY_SIZE(rule));
    RSCAN_Receive_Rule_Set(channel,rule_p,rule_num);

    RSCAN_Buffer_Set(channel,&Rscan_InitStruct->txbuf_mask_st,
        &Rscan_InitStruct->fifo_cfg);

    RSCAN_Global_Mode_Ctl(RSCAN_RESET_MODE,1);
    RSCAN_Channel_Mode_Ctl(channel,RSCAN_RESET_MODE,1);

    //Interrupt control register of interrupt controller
    RSCAN_Eiint_Init();

    //Transition to global operating mode (Set GMDC[1:0] in the RSCAN0GCTR register to 00B)
    RSCAN_Global_Mode_Ctl(RSCAN_OPERATE_MODE,1);
    while(__RSCAN_GET_GLOBAL_STAT(CAN_GRSTSTS_MASK));

    RSCAN_Enable_RecvFIFO(buf_masked.x_masked);

    //Transition to channel communication mode (Set CHMDC[1:0] in the RSCAN0CmCTR register to 00B)
    RSCAN_Channel_Mode_Ctl(channel,RSCAN_COMMUNICATION_MODE,1);
    while(__RSCAN_GET_CHANNEL_STAT(channel,CAN_CRSTSTS_MASK));

    RSCAN_Enable_TRFIFO(channel,buf_masked.k_masked);
}
/**
  * @brief  Used to set the mode of entire RS-CAN module according to the specified mode
  * @param  mode: global operating mode, global reset mode, or global test mode
  * @param ctl 0: read, 1: write
  * @retval return the configured value in register RSCAN0GCTR — Global Control Register
  */
uint32_t  RSCAN_Global_Mode_Ctl(RSCAN_GLOBAL_MODE_Type mode, uint8_t ctl)
{
    __IO uint32_t mask = 0,ret = 0;

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

/**
  * @brief  Used to set a channel mode according to the specified mode
  * @param  mode: channel communication mode, channel reset mode, or channel halt mode
  * @param ctl 0: read, 1: write
  * @retval return the configured value in register RSCAN0CmCTR — Channel Control Register
  * if channel is within 0 to MAX_CHANNEL_NUM - 1,otherwise return -1
  */
int32_t  RSCAN_Channel_Mode_Ctl(uint8_t channel,RSCAN_CHANNEL_MODE_Type mode,uint8_t ctl)
{
    __IO uint32_t mask = 0,ret = 0;

    if(channel > MAX_CHANNEL_NUM - 1) return -1;//channel not supported

    /* mode                     RSCAN0CmCTR[2] RSCAN0CmCTR[1]  RSCAN0CmCTR[0]
    RSCAN_OPERATE_MODE,             0               0               0
    RSCAN_COMMUNICATION_MODE        0               0               0
    RSCAN_RESET_MODE                0               0               1
    RSCAN_HALT_MODE                 0               1               0
    RSCAN_STOP_MODE                 1               x               x*/

    mask = CAN_CSLPR_MASK | CAN_CHMDC_MASK;
    if(ctl){ //write into
        __RSCAN_SET_CHANNEL_CTL(channel,mask,(uint32_t)mode);
    }

    ret = __RSCAN_GET_CHANNEL_CTL(channel,mask);

    return ret;
}
/**
  * @brief Set the CAN communication speed for each channel according to the specified
  *   parameters in the speed_param.
  * @param  speed_param: pointer to a RSCAN_COM_SPEED_PARAM_TypeDef structure that
  *   contains the configuration information for the communication speed.
  * @retval none
  */
void RSCAN_Com_Speed_Set(uint8_t channel, RSCAN_COM_SPEED_PARAM_TypeDef *speed_param )
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
/**
  * @brief Select the index of page to register the receive rule according to the specified
  *   parameters in the rule_p and the rule_num.
  * @param  rule_p: pointer to a RSCAN_RECV_RULE_TypeDef structure that
  *   contains the configuration information for the receive rules.
  * @param rule_num: the number of receive rule need to be set,up to 16 receive rules
  *   can be registered per page
  * @retval none
  */
void RSCAN_Receive_Rule_Set(uint8_t channel,RSCAN_RECV_RULE_TypeDef *rule_p,
    uint8_t rule_num)
{
    __IO uint8_t j = 0, i = 0,rule_n = 0,rule_num_per_page = MAX_RULE_NUM_PER_PAGE;
    __IO uint8_t page_index_usable = 0,current_rule_num = 0,pages = 0, arr_index = 0;;

    if(channel > (MAX_CHANNEL_NUM - 1) || rule_num == 0) return;

    // Get the page index available,all the page registered sequentially
    for(i = 0; i < MAX_CHANNEL_NUM;i++){
        if(i /4)
            rule_n += __RSCAN_GET_RULE_NUMBER_1(7-i);
        else
            rule_n += __RSCAN_GET_RULE_NUMBER_0(3-i);
        if(i == (MAX_CHANNEL_NUM - 1)){
            page_index_usable = rule_n / MAX_RULE_NUM_PER_PAGE;
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

    current_rule_num += rule_n % MAX_RULE_NUM_PER_PAGE;

    //the number of page need to be used
    pages  = (current_rule_num / MAX_RULE_NUM_PER_PAGE);
    // if not reach a complete page, regard as a complete page calculated
    if(current_rule_num % MAX_RULE_NUM_PER_PAGE) pages++;

    for(i = page_index_usable;i < page_index_usable + pages;i++){
        __IO uint8_t start_rule_num_index = 0;
        //Select a page to be set by the AFLPN[4:0] bits in the RSCAN0GAFLECTR register
        __RSCAN_RECV_TABLE_PAGE_NUM_CFG(i);
        if( i == (page_index_usable + pages - 1)){
            rule_num_per_page = current_rule_num % MAX_RULE_NUM_PER_PAGE;
        }
        start_rule_num_index = (i == page_index_usable) ? (rule_n % MAX_RULE_NUM_PER_PAGE):0;

	//when start_rule_num_index + rule_num_per_page < MAX_RULE_NUM_PER_PAGE
	if(page_index_usable == (page_index_usable + pages - 1)){
	    rule_num_per_page += start_rule_num_index;
	}

        //Set receive rules by the RSCAN0GAFLIDj, RSCAN0GAFLMj,RSCAN0GAFLP0j and RSCAN0GAFLP1j registers.
        for( j = start_rule_num_index ;j < rule_num_per_page; j++){
            RSCAN_RuleID_Set(j,&rule_p[arr_index].r_id_info);//id = 0,When the own transmitted message is received,data frame,standard ID
            RSCAN_Rule_Pointer_Set(j,&rule_p[arr_index].r_pointer);
            arr_index++;
        }
    }

    /*Set the AFLDAE bit in the RSCAN0GAFLECTR register to 0 to disable writing
    data to the receive rule table.*/
    __RSCAN_ENABLE_RECV_TABLE_WRITE(0);
}
/**
  * @brief To config the receive rule ID according to the specified
  *   parameters in id_info_p.
  * @param j: the index of receive rule need to be registered per page.(0-15)
  * @param id_info_p: pointer to a RSCAN_RECV_RULE_ID_INFO_TypeDef structure that
  *   contains the configuration information for the receive rules ID.
  * @retval none
  */
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
/**
  * @brief To config the RSCAN0GAFLP0j and RSCAN0GAFLP0j according to the specified
  *   parameters in pointer_p.
  * @param j: the index of receive rule need to be registered per page.(0-15)
  * @param pointer_p: pointer to a RSCAN_RECV_RULE_POINTER_TypeDef structure that
  *   contains the configuration information for the receive rule pointer.
  * @retval none
  */
void RSCAN_Rule_Pointer_Set(uint8_t j,RSCAN_RECV_RULE_POINTER_TypeDef *pointer_p)
{
    uint32_t val = 0;

    val = (uint32_t)(((pointer_p->dlc_t << CAN_GAFLDLC_OFFSET) & CAN_GAFLDLC_MASK) |
        ((pointer_p->label_t << CAN_GAFLPTR_OFFSET) & CAN_GAFLPTR_MASK));

    if(pointer_p->recv_buf == RSCAN_RX_BUF){
        if(pointer_p->recv_buf_index > TOTAL_RECV_BUF_NUM - 1){
            ERROR("the receive buffer index exceed the max receive number");
        }else{
            val |= ((0x01 << CAN_GAFLRMV_OFFSET) & CAN_GAFLRMV_MASK) |
                ((pointer_p->recv_buf_index << CAN_GAFLRMDP_OFFSET) & CAN_GAFLRMDP_MASK);

            buf_masked.q_masked[pointer_p->recv_buf_index/32] |= 0x01 << pointer_p->recv_buf_index % 32;
        }
    }

    __RSCAN_SET_RULE_POINTER0(j,val);

    //TODO . Up to eight FIFO buffers are selectable. However, when the GAFLRMV bit in the
    //RSCAN0GAFLP0j register is set to 1 (a message is stored in the receive buffer), up to seven FIFO
    //buffers can be selected
    //TODO Only receive FIFO buffers and the transmit/receive FIFO buffer for which the
    //CFM[1:0] bits in the RSCAN0CFCCk register are set to 00B (receive mode) or 10B (gateway mode)
    //are selectable.
    val  = 0;
    if(pointer_p->recv_buf == RSCAN_TRFIFO && pointer_p->k_index <= 17)
        val = 0x01 << (pointer_p->k_index + 8);
    if(pointer_p->recv_buf == RSCAN_RX_FIFO && pointer_p->x_index <= 7){
        val |= 0x01 << pointer_p->x_index;
        buf_masked.x_masked |= 0x01 << pointer_p->x_index;
    }

    __RSCAN_SET_RULE_POINTER1(j,val);
}
/**
  * @brief Set the receive buffer,receive fifo and trasmit/receive fifo,transmit buffer
  *   according to the specified parameters in txbuf_st_p related to tx buffer and cfg_param_p
  *   which related to receive FIFO and trasmit/receive fifo.
  * @param m: the index of channel(0-MAX_CHANNEL_NUM-1)
  * @param txbuf_st_p: pointer to a RSCAN_TXBUF_MASK_TypeDef structure that
  *   contains the configuration information for the transmit buffer.
  * @param cfg_param_p: pointer to a RSCAN_FIFO_CFG_TypeDef structure that
  *   contains the configuration information for the receive FIFO and trasmit/receive fifo.
  * @retval none
  */
void RSCAN_Buffer_Set(uint8_t m,RSCAN_TXBUF_MASK_TypeDef *txbuf_st_p,
    RSCAN_FIFO_CFG_TypeDef *cfg_param_p)
{
    __IO uint8_t bit_pos = 0,x_mask = 0;
    RSCAN_TXBUF_MASK_TypeDef txbuf_st_parsed;

    memset(&txbuf_st_parsed,0,sizeof(txbuf_st_parsed));

    //Set receive buffer (the RSCAN0RMNB register)
    //TOTAL_RECV_BUF_NUM must be lower than 96
    __RSCAN_SET_TOTAL_RECV_BUF_NUM(TOTAL_RECV_BUF_NUM);

    x_mask = RSCAN_Parse_RXFIFO_Param(m,cfg_param_p->rxfifo_cfg_p,cfg_param_p->trfifo_cfg_num);
    txbuf_st_parsed = RSCAN_Parse_TRFIFO_Param(m,cfg_param_p->trfifo_cfg_p,cfg_param_p->trfifo_cfg_num);

    txbuf_st_p->tf_mask = txbuf_st_parsed.tf_mask;
    txbuf_st_p->txbuf_mask &= ~txbuf_st_parsed.txbuf_mask;


    buf_masked.x_masked &= x_mask;
    buf_masked.k_masked |= txbuf_st_p->tf_mask.k_mask;
    buf_masked.k_state  |= txbuf_st_parsed.tf_mask.k_stat;
    buf_masked.p_masked = txbuf_st_p->txbuf_mask;

#if 0
    //Set transmit queue (the RSCAN0TXQCCm register)
    //Select an interrupt source by the TXQIM bit.
    //Set the number of transmit queue stages by the TXQDC[3:0] bits
    val = (uint32_t)(((0x01 << CAN_TXQIM_OFFSET) & CAN_TXQIM_MASK) |
        ((0x02 << CAN_TXQDC_OFFSET) & CAN_TXQDC_MASK));
    mask = CAN_TXQIM_MASK | CAN_TXQDC_MASK;

    __RSCAN_SET_TRANSMIT_QUEUE(m,mask,val);

    //TODO Set transmit history buffer (the RSCAN0THLCCm register)
#endif

    RSCAN_Enable_Buf_Int(m,x_mask,txbuf_st_p);
}
/**
  * @brief Make the receive buffers indicated by x_mask available
  * @param x_mask:bit position in x_mask indicate the receive index
  * @retval none
  */
void RSCAN_Enable_RecvFIFO(uint8_t x_mask)
{
    __IO uint8_t bit_pos = 0;
    RSCAN_MODE_Type mode;

    mode =(RSCAN_GLOBAL_MODE_Type)RSCAN_Global_Mode_Ctl((RSCAN_GLOBAL_MODE_Type)0,0); // the 2nd paramter 0 means read out the mode

    if((mode == RSCAN_OPERATE_MODE) || (mode == RSCAN_TEST_MODE)){
        //Setting the RFE bit to 1 makes receive FIFO buffers available
        //Modify this bit in global operating mode or global test mode
        for(bit_pos = 0; bit_pos < 8 && (x_mask >> bit_pos);bit_pos++){
            if((x_mask & (0x01 << bit_pos)) == 0) continue;
            __RSCAN_SET_RECV_FIFO_BUF(bit_pos,CAN_RFE_MASK,1);
        }
    }

}
/**
  * @brief Parse the parameters in cfg_param_p.
  * @param cfg_param_p: pointer to a RSCAN_RXFIFO_CFG_TypeDef structure that
  *   contains the configuration information for the receive fifo.
  * @param cfg_param_size:the numer of parameters pointer to RSCAN_RXFIFO_CFG_TypeDef
  * @retval x_mask:bit position in x_mask indicate the receive index
  */
uint8_t RSCAN_Parse_RXFIFO_Param(uint8_t m,RSCAN_RXFIFO_CFG_TypeDef *cfg_param_p,
    uint8_t cfg_param_size)
{
    __IO uint8_t x_mask = 0,i = 0;
    __IO uint32_t val = 0,mask = 0;

    for(;i < cfg_param_size;i++){
        if(cfg_param_p[i].x_index < 8){

            x_mask |=(uint8_t)(0x01 << cfg_param_p[i].x_index);
            //Set receive FIFO buffer (the RSCAN0RFCCx register)  x >= 0 && x <= 7
            // Select receive interrupt request timing by the RFIGCV[2:0] bits
            // Select an interrupt source by the RFIM bit
            // Set the number of FIFO buffer stages by the RFDC [2:0] bits
            val = (uint32_t)(((cfg_param_p[i].param_un.reg_bits.RFIGCV << CAN_RFIGCV_OFFSET) & CAN_RFIGCV_MASK) |
                ((cfg_param_p[i].param_un.reg_bits.RFIM << CAN_RFIM_OFFSET) & CAN_RFIM_MASK) |
                ((cfg_param_p[i].param_un.reg_bits.RFDC << CAN_RFDC_OFFSET) & CAN_RFDC_MASK));

            mask = CAN_RFIGCV_MASK | CAN_RFIM_MASK | CAN_RFDC_MASK;
            __RSCAN_SET_RECV_FIFO_BUF(cfg_param_p[i].x_index,mask,val);
        }
    }
    return x_mask;
}
/**
  * @brief Parse the parameters in cfg_param_p.
  * @param m: the index of channel(0-MAX_CHANNEL_NUM-1)
  * @param cfg_param_p: pointer to a RSCAN_TRFIFO_CFG_TypeDef structure that
  *   contains the configuration information for the receive fifo.
  * @param cfg_param_size:the numer of parameters pointer to RSCAN_TRFIFO_CFG_TypeDef
  * @retval txbuf_struct:
  */
RSCAN_TXBUF_MASK_TypeDef RSCAN_Parse_TRFIFO_Param(uint8_t m,RSCAN_TRFIFO_CFG_TypeDef *cfg_param_p,
    uint8_t cfg_param_size)
{
    __IO uint8_t i = 0;
    RSCAN_TXBUF_MASK_TypeDef txbuf_struct;

    memset(&txbuf_struct,0,sizeof(txbuf_struct));

    for(;i < cfg_param_size;i++){
        if(m != (cfg_param_p[i].k_index / 3))
            continue;
        if(cfg_param_p[i].param_un.param_bits.mode == RSCAN_TRFIFO_RECV_MODE){
            txbuf_struct.tf_mask.k_mask |= ((0x01 << cfg_param_p[i].k_index) & 0x3FFFF);
        }

        if(cfg_param_p[i].param_un.param_bits.mode == RSCAN_TRFIFO_TRANSMIT_MODE){
            txbuf_struct.tf_mask.k_mask |= ((0x01 << cfg_param_p[i].k_index) & 0x3FFFF);
            txbuf_struct.tf_mask.k_stat |= ((0x01 << cfg_param_p[i].k_index) & 0x3FFFF);
            txbuf_struct.txbuf_mask |= (0x01 << cfg_param_p[i].param_un.param_bits.txbuf_num_linked);
        }
        //Set transmit/receive FIFO buffer (the RSCAN0CFCCk register)
        // Set the number of transmit buffer to be linked by the CFTML[3:0] bits.
        // Select an interval timer count source by the CFITR and CFITSS bits.
        // Select a mode by the CFM[1:0] bits.
        // Select receive interrupt request timing by the CFIGCV[2:0] bits.
        // Select an interrupt source by the CFIM bit.
        // Set the number of FIFO buffer stages by the CFDC[2:0] bits.
        __RSCAN_SET_TRFIFO_BUF( cfg_param_p[i].k_index,CAN_CFTML_MASK | CAN_CFITR_MASK | CAN_CFITSS_MASK
            | CAN_CFIGCV_MASK |CAN_CFIM_MASK | CAN_CFDC_MASK,cfg_param_p[i].param_un.cfg_param);
    }

    return txbuf_struct;
}

/**
  * @brief Make the transmit/receive fifo buffer indicated by k_mask available
  * @param m: the index of channel(0-MAX_CHANNEL_NUM-1)
  * @param k_mask:bit position in k_mask indicate the transmit/receive fifo buffer index
  * @retval none
  */
void RSCAN_Enable_TRFIFO(uint8_t m,uint32_t k_mask)
{
    __IO uint8_t bit_pos = 0;

    for(bit_pos = 0; bit_pos < 18 && (k_mask >> bit_pos);bit_pos++){
        if((k_mask & (0x01 << bit_pos)) == 0) continue;
            __RSCAN_SET_TRFIFO_BUF(bit_pos,CAN_CFE_MASK,1);
    }
}
/**
  * @brief Enable received interrupt and the transmit abort or complete interrupt
  * @param m: the index of channel(0-MAX_CHANNEL_NUM-1)
  * @param x_mask:bit position in x_mask indicate the receive index
  * @param txbuf_st_p:pointer to a RSCAN_TXBUF_MASK_TypeDef structure that
  *   contains the configuration information for transmit buffer,fifo and queue.
  * @retval none
  */
void RSCAN_Enable_Buf_Int(uint8_t m,uint8_t x_mask,RSCAN_TXBUF_MASK_TypeDef *txbuf_st_p)
{
    __IO uint8_t bit_pos = 0,txbuf_index = 0;
    __IO uint32_t val = 0,mask = 0,k_mask = 0,k_stat = 0;

    /********************Enable interrupt of buffer to be used*****************/
    for(bit_pos = 0;bit_pos < 8 && (x_mask >> bit_pos);bit_pos++){
        if((x_mask & (0x01 << bit_pos)) == 0) continue;
        // Enable receive FIFO interrupts by the RFIE bit in the RSCAN0RFCCx register.
        __RSCAN_SET_RECV_FIFO_BUF(bit_pos,CAN_RFIE_MASK,0x01 << CAN_RFIE_OFFSET);
    }

    k_mask = txbuf_st_p->tf_mask.k_mask >> (3*m);
    k_stat = txbuf_st_p->tf_mask.k_stat >> (3*m);

    /*********Transmit/Receive FIFO Receive Interrupt Enable********/
    for(bit_pos = 0;bit_pos < 3;bit_pos++){
        if(0x01 & ((k_mask ^ k_stat) >> bit_pos)){
            // Enable transmit/receive FIFO receive interrupts by the CFRXIE bit in the RSCAN0CFCCk register.
            __RSCAN_SET_TRFIFO_BUF((3*m + bit_pos),CAN_CFRXIE_MASK,0x01 << CAN_CFRXIE_OFFSET);
        }
    }
    /*********Transmit/Receive FIFO transmit Interrupt Enable********/
    for(bit_pos = 0;bit_pos < 3;bit_pos++){
        if(0x01 & ((k_mask & k_stat) >> bit_pos)){
            // Enable transmit/receive FIFO transmit interrupts by the CFTXIE bit in the RSCAN0CFCCk register.
            __RSCAN_SET_TRFIFO_BUF((3*m + bit_pos),CAN_CFTXIE_MASK,0x01 << CAN_CFTXIE_OFFSET);
        }
    }
    // Enable transmit abort interrupts by the TAIE bit in the RSCAN0CmCTR register.
    __RSCAN_SET_CHANNEL_CTL(bit_pos,CAN_TAIE_MASK,0x01 << CAN_TAIE_OFFSET);

    // Enable transmit complete interrupts by the TMIE bit in the RSCAN0TMIECy register.
    for(bit_pos = 0;bit_pos < 16 && (txbuf_st_p->txbuf_mask >> bit_pos);bit_pos++){
        if((txbuf_st_p->txbuf_mask & (0x01 << bit_pos)) == 0) continue;
        txbuf_index  = m * 16 + bit_pos;
        val = (uint32_t)(0x01 << (txbuf_index % 32));
        mask = val;
        __RSCAN_ENABLE_TRANSMIT_BUF_INT((txbuf_index/32),mask,val);
    }


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

    eiint.eiint_ch = 15; //Global Receive FIFOinterrupts
    Eiit_Init(&eiint);

    eiint.eiint_ch = 16; //CAN0 error interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 18;//CAN0 transmit interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 212; //CAN3 error interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 213; //CAN3  transmit/receive FIFO receive complete interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 214;//CAN3 transmit interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 264; //CAN4 error interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 265; //CAN4  transmit/receive FIFO receive complete interrupt
    Eiit_Init(&eiint);

    eiint.eiint_ch = 266;//CAN4 transmit interrupt
    Eiit_Init(&eiint);

}
/**
  * @brief store the date transmit buffer and request transmission
  * @param data_len: the number of bytes.
  * @param data_p:contains the data need to be sent
  * @param id_info:pointer to a RSCAN_TXID_INFO_TypeDef structure that
  *   contains the ID information for transmission on this time.
  * @retval size:the length of message sent already.
  */
int8_t RSCAN_TxBuffer_Write(RSCAN_TXID_INFO_TypeDef id_info, uint8_t data_len,
        uint8_t* data_p)
{
    uint8_t p = 0, size = 0;
    uint8_t len = 0,data[8] = {0};
    uint32_t val = 0;


    if(id_info.index > 95) {
        ERROR("the buffer index exceed the max index:95");
        return -1;// max 95
    }
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
/**
  * @brief store the date transmit/receive fifo buffer which configured as transmit mode
  * @param data_len: the number of bytes.
  * @param data_p:contains the data need to be sent
  * @param id_info:pointer to a RSCAN_TXID_INFO_TypeDef structure that
  *   contains the ID information for transmission on this time.
  * @retval size:the length of message sent already.
  */
int8_t RSCAN_TRFIFO_Write(RSCAN_TXID_INFO_TypeDef id_info, uint8_t data_len,
        uint8_t* data_p)
{
    uint8_t k = 0,size = 0,sent_len = 0;
    uint32_t val = 0;

    if(id_info.index > 17){
        ERROR("the transmit/receive fifo buffer index exceed the max index:17");
        return -1;// max 17
    }
    k = id_info.index;

    val = (uint32_t)(((id_info.ide << CAN_CFIDE_OFFSET) & CAN_CFIDE_MASK) |
        ((id_info.rtr << CAN_CFRTR_OFFSET) & CAN_CFRTR_MASK) |
        ((id_info.his_en << CAN_THLEN_OFFSET) & CAN_THLEN_MASK));

    /*Set the ID of the receive rule.For the standard ID, set the ID in bits
    b10 to b0 and set bits b28 to b11 to 0.*/
    if(id_info.ide == 0)
        val |= id_info.id & (CAN_CFID_MASK >> 18);
    else
        val |= id_info.id & CAN_CFID_MASK;

    __RSCAN_SET_TRFIFO_ID(k,val);

    // Is transmit/receive FIFO buffer full?
    // (Is CFFLL flag in the RSCAN0CFSTSk register 1?)
    while(__RSCAN_GET_TRFIFO_STAT(k,CAN_CFFLL_MASK) == 0 && sent_len < data_len){//if not full
        uint8_t data[8] = {0};

        for(size = 0; size < (data_len - sent_len); size++){
	           if((size) == 8) break;
            data[size] = data_p[size + sent_len];

        }
        sent_len += size;

        val = (uint32_t)((( size << CAN_CFDLC_OFFSET) & CAN_TMDLC_MASK) |
            ((id_info.label_t << CAN_CFPTR_OFFSET) & CAN_CFPTR_MASK));

        __RSCAN_SET_TRFIFO_POINTER(k,val);

        __RSCAN_WRITE_TRFIFO_DATA_L(k,&data[0]);
        __RSCAN_WRITE_TRFIFO_DATA_H(k,&data[4]);

        //Set the RSCAN0CFPCTRk register to 0xFF
        _RSCAN_SET_TRFIFO_POINTER(k);
    }

    return sent_len;
}
/**
  * @brief store the date transmit queue and request transmission
  * @param data_len: the number of bytes.
  * @param data_p:contains the data need to be sent
  * @param id_info:pointer to a RSCAN_TXID_INFO_TypeDef structure that
  *   contains the ID information for transmission on this time.
  * @retval size:the length of message sent already.
  */
int8_t RSCAN_TxQueue_Write(RSCAN_TXID_INFO_TypeDef id_info, uint8_t data_len,
        uint8_t* data_p)
{
    //TODO
    return -1;
}

/**
  * @brief read the date from receive buffer
  * @param id_info_p:pointer to a RSCAN_RXID_INFO_TypeDef structure that
  *   store the ID information for receive on this time.
  * @param data_p:contains the data read out already
  * @retval recv_size:the length of message read already.
  */
int8_t RSCAN_RxBuffer_Read(RSCAN_RXID_INFO_TypeDef *id_info_p,uint8_t* data_p)
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

    p =(uint8_t*)__RSCAN_READ_RECV_BUF_ADDR(q);

    for( i = 0; recv_size && i <recv_size;i++){
        data_p[i] = p[i];
    }

    //TODO Are all RMNSq flags in the RSCAN0RMNDy register 0?????????
    return recv_size;
}
/**
  * @brief read the date from trasmit/receive fifo buffer which configured as receive mode
  * @param id_info_p:pointer to a RSCAN_RXID_INFO_TypeDef structure that
  *   store the ID information for receive on this time.
  * @param len_p:the length of the message read out already
  * @param data_p:contains the data read out already
  * @retval the result about this reading process.
  */
RSCAN_TRFIFO_RESULT_Type RSCAN_TRFIFO_Read(RSCAN_RXID_INFO_TypeDef *id_info_p,uint8_t *len_p,
    uint8_t* data_p)
{
    uint8_t k = 0, i = 0;
    uint8_t recv_size = 0,*p = NULL;
    uint32_t val = 0;

    if(id_info_p->index > 17)
        return RSCAN_RXFIFO_ERR;// max 17
    k = id_info_p->index;

    if(__RSCAN_GET_TRFIFO_STAT(k,CAN_CFEMP_MASK) == 0){

        val = __RSCAN_GET_TRFIFO_ID(k);

        id_info_p->ide = (val & CAN_CFIDE_MASK) >> CAN_CFIDE_OFFSET;
        id_info_p->rtr = (val & CAN_CFRTR_MASK) >> CAN_CFRTR_OFFSET;
        id_info_p->id  = (val & CAN_CFID_MASK);

        val = __RSCAN_GET_TRFIFO_POINTER(k);

        id_info_p->label_t = (val & CAN_CFPTR_MASK)  >> CAN_CFPTR_OFFSET;
        recv_size = (val & CAN_CFDLC_MASK)  >> CAN_CFDLC_OFFSET;
        id_info_p->time_stamp = (val & CAN_CFTS_MASK);

        p =(uint8_t*)__RSCAN_READ_TRFIFO_ADDR(k);

        for( i = 0; recv_size && i <recv_size;i++){
            data_p[i] = p[i];
        }
        *len_p = recv_size;
        //Set the RSCAN0CFPCTRk register to 0xFF
        _RSCAN_SET_TRFIFO_POINTER(k);

        if(__RSCAN_GET_TRFIFO_STAT(k,CAN_CFEMP_MASK) == 0)
            return  RSCAN_RXFIFO_NOT_EMPTY;
    }

    //clear transmit/receive FIFO receive interrupt request flag
    __RSCAN_SET_TRFIFO_STAT(k,CAN_CFRXIF_MASK,0);
    return RSCAN_RXFIFO_EMPTY;

}
/**
  * @brief read the date from receive fifo buffer.
  * @param id_info_p:pointer to a RSCAN_RXID_INFO_TypeDef structure that
  *   store the ID information for receive on this time.
  * @param len_p:the length of the message read out already
  * @param data_p:contains the data read out already
  * @retval the result about this reading process.
  */
RSCAN_RXFIFO_RESULT_Type RSCAN_RxFIFO_Read(RSCAN_RXID_INFO_TypeDef *id_info_p,uint8_t *len_p,
    uint8_t* data_p)
{
    __IO uint8_t x = 0, i = 0;
    __IO uint8_t recv_size = 0,*p = NULL;
    __IO uint32_t val = 0;

    if(id_info_p->index > 7)
        return RSCAN_RXFIFO_ERR;// max 7

    x = id_info_p->index;

    if(__RSCAN_GET_RECV_FIFO_STAT(x,CAN_RFEMP_MASK) == 0)
    {   //if message exists

        val = __RSCAN_GET_RECV_FIFO_ID(x);

        id_info_p->ide = (val & CAN_RFIDE_MASK) >> CAN_RFIDE_OFFSET;
        id_info_p->rtr = (val & CAN_RFRTR_MASK) >> CAN_RFRTR_OFFSET;
        id_info_p->id  = (val & CAN_RFID_MASK);

        val = __RSCAN_GET_RECV_FIFO_POINTER(x);

        id_info_p->label_t = (val & CAN_RFPTR_MASK)  >> CAN_RFPTR_OFFSET;
        recv_size = (val & CAN_RFDLC_MASK)  >> CAN_RFDLC_OFFSET;
        id_info_p->time_stamp = (val & CAN_RFTS_MASK);

        p =(uint8_t*)__RSCAN_READ_RECV_FIFO_ADDR(x);

        for( i = 0; recv_size && i <recv_size;i++){
            data_p[i] = p[i];
        }
	    *len_p = recv_size;
	 //Set the RSCAN0RFPCTRx register to 0xFF
         _RSCAN_SET_RECV_FIFO_POINTER(x);

        if(__RSCAN_GET_RECV_FIFO_STAT(x,CAN_RFEMP_MASK) == 0){
            return  RSCAN_RXFIFO_NOT_EMPTY;
        }
    }

    __RSCAN_SET_RECV_FIFO_STAT(x,CAN_RFIF_MASK,0);
    return RSCAN_RXFIFO_EMPTY;
}
/**
  * @brief Confirm that transmission is done,and the clear the bit flag
  * @param tx_type: transmission processed by using the tx buffer or tx/rx fifo,
  *    seletc the type to confirm the transmission
  * @param txbuf_id:the tx buffer id or tx/rx fifo buffer id according to the mode
  * @retval trasmit completely return the tx_buf_id ,failed return -1
  */
int8_t RSCAN_Transmit_Confirm(RSCAN_TX_BUF_Sel_Type tx_type,int8_t txbuf_id)
{
    __IO uint8_t ret = 0;

    if( tx_type == RSCAN_TX_BUF && txbuf_id >= 0 && txbuf_id < 96){
        ret = __RSCAN_GET_TRANSMIT_STAT(txbuf_id,CAN_TMTRF_MASK);

        if(ret == RSCAN_TRANSMIT_COMPLETED_WITHOUT_ABORT ||
            ret == RSCAN_TRANSMIT_COMPLETED_WITH_ABORT){
            __RSCAN_SET_TRANSMIT_STAT(txbuf_id,CAN_TMTRF_MASK,0);
            return txbuf_id;
        }
    }

    if(tx_type == RSCAN_TRFIFO && txbuf_id >= 0 && txbuf_id < 18){
        //check that transmit/receive FIFO transmit interrupt request is present, then clear.
        if(__RSCAN_GET_TRANSMIT_STAT(txbuf_id,CAN_CFTXIF_MASK) == CAN_CFTXIF_MASK){
            __RSCAN_SET_TRANSMIT_STAT(txbuf_id,CAN_CFTXIF_MASK,0x01 << CAN_CFTXIF_OFFSET);
            return txbuf_id;
        }
    }

    return -1;
}

uint32_t RSCAN_Channel_Error(uint8_t channel)
{
    return __RSCAN_GET_CHANNEL_Error(channel,0x7FFFF);
}

uint32_t RSCAN_Global_Error(void)
{
    return __RSCAN_GET_GLOBAL_Error(0x07);
}


int8_t RSCAN_RAM_Test_Perform(uint8_t test_page,uint32_t *test_data,uint8_t size)
{
    uint8_t i = 0;
    //Set a value within a range of page 0 (00H) to page 56 (38H).
    //Data in the set page can be read from and written to the RSCAN0RPGACCr register (r = 0 to 63)
    //so the max size of the test data is 64
    if(test_page > 0x38 || size > 64) return -1;
    //Set the GMDC[1:0] bits in the RSCAN0GCTR register to 10B.
    RSCAN_Global_Mode_Ctl(RSCAN_TEST_MODE,1);

    //guarantee in global test mode
    while(__RSCAN_GET_GLOBAL_STAT(CAN_GHLTSTS_MASK) == 0);

    //Write 7575H to the LOCK[15:0] bits in the RSCAN0GLOCKK register.
    //Write 8A8AH to the LOCK[15:0] bits in the RSCAN0GLOCKK register
    __RSCAN_SET_LOCK_KEY(0x7575);
    __RSCAN_SET_LOCK_KEY(0x8A8A);
    //Set the RTME bit in the RSCAN0GTSTCTR register to 1
    __RSCAN_SET_GLOBAL_TEST_CTL(CAN_RTME_MASK,0x01 << CAN_RTME_OFFSET);

    //Select the RAM test page by the RTMPS[6:0] bits in the RSCAN0GTSTCFG register.
    __RSCAN_SET_GLOBAL_TEST_CONFIG(CAN_RTMPS_MASK,test_page << CAN_RTMPS_OFFSET);

    //Verify RAM write/read using the RSCAN0RPGACCr register
    for(i = 0; i< size; i++){
        __IO uint32_t read_data = 0;
        __RSCAN_WRITE_RAM_TEST_PAGE(i,test_data[i]);
        read_data = __RSCAN_READ_RAM_TEST_PAGE(i);
        if(read_data != test_data[i])
            return -1;
        //Before closing the RAM test, write 0000 0000H to all pages of the CAN RAM
        __RSCAN_WRITE_RAM_TEST_PAGE(i,0);
    }
    //Set the RTME bit in the RSCAN0GTSTCTR register to 0, disable RAM test
    __RSCAN_SET_GLOBAL_TEST_CTL(CAN_RTME_MASK,0);
    return 0;
}

/**
  * @brief Get all the useable buffers useable
  * @param buf_used: pointer to RSCAN_BUF_AVAIL_TypeDef to get the useable buffer masks:
  * @retval None
  */

void RSCAN_All_Buf_Avail(RSCAN_BUF_AVAIL_TypeDef *buf_used)
{
    *buf_used = buf_masked;
}


void RSCAN_Ecc_Init(bool err_1bit_corr_en, bool err_2bit_detect_int)
{
    __IO uint16_t mask = 0,val = 0;

    if(err_1bit_corr_en){
        mask |= CAN_EC1ECP_MASK;
        val  &= ~CAN_EC1ECP_MASK; //to enable,clear this bit
    }

    if(err_2bit_detect_int){
        mask |= CAN_EC2EDIC_MASK;
        val  |= CAN_EC2EDIC_MASK; //to enable,set this bit
    }

    //(0, 1) must be written to (EMCA1, EMCA0) at the same time
    //before setting the ECTHM  to
    mask |= CAN_EMCA1_MASK | CAN_EMCA0_MASK;
    val |= 0x01 << CAN_EMCA0_OFFSET;

    //clear the ECEMF bit that error determination is enabled
    mask |= CAN_ECEMF_MASK;

    __RSCAN_SET_ECC_CTL_REG(mask,val);
}

bool RSCAN_Ecc_Err_Checked(void)
{
    if(__RSCAN_GET_ECC_CTL_REG(CAN_ECEMF_MASK)){
        return TRUE;
    }
    return FALSE;
}

/***************************Global interrupt handler***************************/
#pragma interrupt RSCAN0GlobalErrorIntHandler(channel = 14, enable = false, callt = false, fpu = false)
void RSCAN0GlobalErrorIntHandler(unsigned long eiic)
{

}

#pragma interrupt RSCAN0RecvFIFOIntHandler(channel = 15, enable = false, callt = false, fpu = false)
void RSCAN0RecvFIFOIntHandler(unsigned long eiic)
{
    uint8_t msg[8] = {0},len = 0,x = 0;
    RSCAN_RXID_INFO_TypeDef id_info;
    RSCAN_BUF_AVAIL_TypeDef buf;

    RSCAN_All_Buf_Avail(&buf);
    for(x = 0;x < 8 && (buf.x_masked >> x);x++){
        if((buf.x_masked >> x) & 0x01){
            id_info.index = x;
            while(RSCAN_RxFIFO_Read(&id_info,&len,msg) == RSCAN_RXFIFO_NOT_EMPTY);
        }
    }

}

/**********************RSCAN0 channel 1 interrupt handler**********************/
#pragma interrupt RSCAN0CH0ErrorIntHandler(channel = 16, enable = false, callt = false, fpu = false)
void RSCAN0CH0ErrorIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH0TrFIFORecvCompletionIntHandler(channel = 17, enable = false, callt = false, fpu = false)
void RSCAN0CH0TrFIFORecvCompletionIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH0SendCompleteIntHandler(channel = 18, enable = false, callt = false, fpu = false)
void RSCAN0CH0SendCompleteIntHandler(unsigned long eiic)
{
    while(1){};
}

/**********************RSCAN0 channel 1 interrupt handler**********************/
#pragma interrupt RSCAN0CH1ErrorIntHandler(channel = 105, enable = false, callt = false, fpu = false)
void RSCAN0CH1ErrorIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH1TrFIFORecvCompletionIntHandler(channel = 106, enable = false, callt = false, fpu = false)
void RSCAN0CH1TrFIFORecvCompletionIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH1SendCompleteIntHandler(channel = 107, enable = false, callt = false, fpu = false)
void RSCAN0CH1SendCompleteIntHandler(unsigned long eiic)
{
    while(1){};
}

/**********************RSCAN0 channel 2 interrupt handler**********************/
#pragma interrupt RSCAN0CH2ErrorIntHandler(channel = 209, enable = false, callt = false, fpu = false)
void RSCAN0CH2ErrorIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH2TrFIFORecvCompletionIntHandler(channel = 210, enable = false, callt = false, fpu = false)
void RSCAN0CH2TrFIFORecvCompletionIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH2SendCompleteIntHandler(channel = 211, enable = false, callt = false, fpu = false)
void RSCAN0CH2SendCompleteIntHandler(unsigned long eiic)
{
    while(1){};
}

/**********************RSCAN0 channel 3 interrupt handler**********************/
#pragma interrupt RSCAN0CH3ErrorIntHandler(channel = 212, enable = false, callt = false, fpu = false)
void RSCAN0CH3ErrorIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH3TrFIFORecvCompletionIntHandler(channel = 213, enable = false, callt = false, fpu = false)
void RSCAN0CH3TrFIFORecvCompletionIntHandler(unsigned long eiic)
{
    uint8_t msg[8] = {0},len = 0,k = 0;
    uint32_t k_mask = 0;
    RSCAN_RXID_INFO_TypeDef id_info;
    RSCAN_BUF_AVAIL_TypeDef buf;

    RSCAN_All_Buf_Avail(&buf);
    k_mask = buf.k_masked ^ buf.k_state;

    for(k = 0;k < 18 && (k_mask >> k);k++){
        if((0x01 & (k_mask >> k)) == 0) continue;
        id_info.index = k;
        while(RSCAN_TRFIFO_Read(&id_info,&len,msg) == RSCAN_RXFIFO_NOT_EMPTY);
    }
}

#pragma interrupt RSCAN0CH3SendCompleteIntHandler(channel = 214, enable = false, callt = false, fpu = false)
void RSCAN0CH3SendCompleteIntHandler(unsigned long eiic)
{
    uint8_t i = 0;
    for(i = 0;i < 96;i++){
        __RSCAN_ENABLE_TRANSMIT_BUF_INT((i/32),1 << (i%32),0);//clear the tx buffer int
    }
    for(i = 0;i< 18;i++){
    	if(__RSCAN_GET_TRFIFO_STAT(i,CAN_CFTXIF_MASK))
            __RSCAN_SET_TRFIFO_STAT(i,CAN_CFTXIF_MASK,0);
    }
}

/**********************RSCAN0 channel 4 interrupt handler**********************/
#pragma interrupt RSCAN0CH4ErrorIntHandler(channel = 264, enable = false, callt = false, fpu = false)
void RSCAN0CH4ErrorIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH4TrFIFORecvCompletionIntHandler(channel = 265, enable = false, callt = false, fpu = false)
void RSCAN0CH4TrFIFORecvCompletionIntHandler(unsigned long eiic)
{
    uint8_t msg[8] = {0},len = 0,k = 0;
    uint32_t k_mask = 0;
    RSCAN_RXID_INFO_TypeDef id_info;
    RSCAN_BUF_AVAIL_TypeDef buf;

    RSCAN_All_Buf_Avail(&buf);
    k_mask = buf.k_masked ^ buf.k_state;

    for(k = 0;k < 18 && (k_mask >> k);k++){
        if((0x01 & (k_mask >> k)) == 0) continue;
        id_info.index = k;
        while(RSCAN_TRFIFO_Read(&id_info,&len,msg) == RSCAN_RXFIFO_NOT_EMPTY);
    }
}

#pragma interrupt RSCAN0CH4SendCompleteIntHandler(channel = 266, enable = false, callt = false, fpu = false)
void RSCAN0CH4SendCompleteIntHandler(unsigned long eiic)
{
    uint8_t i = 0;
    for(i = 0;i < 96;i++){
        __RSCAN_ENABLE_TRANSMIT_BUF_INT((i/32),1 << (i%32),0);//clear the tx buffer int
    }
    for(i = 0;i< 18;i++){
    	if(__RSCAN_GET_TRFIFO_STAT(i,CAN_CFTXIF_MASK))
            __RSCAN_SET_TRFIFO_STAT(i,CAN_CFTXIF_MASK,0);
    }
}

/**********************RSCAN0 channel 5 interrupt handler**********************/
#pragma interrupt RSCAN0CH5ErrorIntHandler(channel = 279, enable = false, callt = false, fpu = false)
void RSCAN0CH5ErrorIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH5TrFIFORecvCompletionIntHandler(channel = 280, enable = false, callt = false, fpu = false)
void RSCAN0CH5TrFIFORecvCompletionIntHandler(unsigned long eiic)
{
    while(1){};
}

#pragma interrupt RSCAN0CH5SendCompleteIntHandler(channel = 281, enable = false, callt = false, fpu = false)
void RSCAN0CH5SendCompleteIntHandler(unsigned long eiic)
{
    while(1){};
}
