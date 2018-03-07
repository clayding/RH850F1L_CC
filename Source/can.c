#include "can.h"


//#define RULE_PAGE_SET_TEST

typedef struct{
    uint8_t error_index;
    void (*CanErrorHandler)(void);
}CAN_ERROR_TypeDef;


static void Can_ErrorHandling(void);
static void CanBusOff(void);
static void CanBusOffRecover(void);

CAN_ERROR_TypeDef can_error[] = {
    { RSCAN_BUS_ERROR,Can_ErrorHandling},
    { RSCAN_ERROR_WARNING,Can_ErrorHandling},
    { RSCAN_ERROR_PASSIVE,Can_ErrorHandling},
    { RSCAN_BUS_OFF_ENTRY,CanBusOff},
    { RSCAN_BUS_OFF_RECOVERY,CanBusOffRecover},
    { RSCAN_OVERLOAD_ERROR,Can_ErrorHandling},
    { RSCAN_BUS_DOMINANT_LOCK,Can_ErrorHandling},
    { RSCAN_ARBITRATION_LOST,Can_ErrorHandling},
    { RSCAN_STUFF_ERROR,Can_ErrorHandling},
    { RSCAN_FORM_ERROR,Can_ErrorHandling},
    { RSCAN_ACK_ERROR,Can_ErrorHandling},
    { RSCAN_CRC_ERROR,Can_ErrorHandling},
    { RSCAN_R_BIT_ERROR,Can_ErrorHandling},
    { RSCAN_D_BIT_ERROR,Can_ErrorHandling},
    { RSCAN_ACK_DELIMITER_ERROR,Can_ErrorHandling},
    { RSCAN_DLC_ERROR,Can_ErrorHandling},
};
/* @brief - Initialization of RsCAN module.
 * @param none
 * @reval none
 */
void CanInit(void)
{
    RSCAN_InitTypeDef rscan3;
    RSCAN_RECV_RULE_TypeDef rule[3];
    RSCAN_TRFIFO_CFG_TypeDef tf_cfg_param[3];
    RSCAN_RXFIFO_CFG_TypeDef rf_cfg_param[8];

    memset(rule,0,ARRAY_SIZE(rule) * sizeof(RSCAN_RECV_RULE_TypeDef));
    memset(tf_cfg_param,0,ARRAY_SIZE(tf_cfg_param) * sizeof(RSCAN_TRFIFO_CFG_TypeDef));
    memset(rf_cfg_param,0,ARRAY_SIZE(rf_cfg_param) * sizeof(RSCAN_RXFIFO_CFG_TypeDef));

    rscan3.channel = 4;
    rscan3.sp.fcan_src = 1;
    rscan3.sp.bit_time = CANbaudrateSet(CAN_BAUDRATE_250K);

    {//for example
        rule[0].r_pointer.dlc_t = RSCAN_DLC_CHECK_DISABLED;
        rule[0].r_pointer.label_t = 0x891;
        rule[0].r_pointer.recv_buf = RSCAN_RX_BUF;
        rule[0].r_pointer.recv_buf_index = 9;
        rule[0].r_pointer.k_index = 0;
        rule[0].r_pointer.x_index = 0;
        rule[0].r_id_info.ide = RSCAN_RECV_IDE_STD;
        rule[0].r_id_info.rtr = RSCAN_RECV_DATA_FRM;
        rule[0].r_id_info.target_msg = RSCAN_RECV_FROM_OTHER;
        rule[0].r_id_info.id = 0x123;
        rule[0].r_id_info.mask = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK |CAN_GAFLIDM_MASK;


        rule[1].r_pointer.dlc_t = RSCAN_DLC_CHECK_DISABLED;
        rule[1].r_pointer.label_t = 0x745;
        rule[1].r_pointer.recv_buf = RSCAN_RX_FIFO;
        rule[1].r_pointer.recv_buf_index = 0;
        rule[1].r_pointer.k_index = 0;
        rule[1].r_pointer.x_index = 1;
        rule[1].r_id_info.ide = RSCAN_RECV_IDE_STD;
        rule[1].r_id_info.rtr = RSCAN_RECV_DATA_FRM;
        rule[1].r_id_info.target_msg = RSCAN_RECV_FROM_OTHER;
        rule[1].r_id_info.id = 0x456;
        rule[1].r_id_info.mask = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK |CAN_GAFLIDM_MASK;

        rule[2].r_pointer.dlc_t = RSCAN_DLC_CHECK_DISABLED;
        rule[2].r_pointer.label_t = 0x745;
        rule[2].r_pointer.recv_buf = RSCAN_TRFIFO;
        rule[2].r_pointer.recv_buf_index = 0;
        rule[2].r_pointer.k_index = 3*rscan3.channel;
        rule[2].r_pointer.x_index = 0;
        rule[2].r_id_info.ide = RSCAN_RECV_IDE_STD;
        rule[2].r_id_info.rtr = RSCAN_RECV_DATA_FRM;
        rule[2].r_id_info.target_msg = RSCAN_RECV_FROM_OTHER;
        rule[2].r_id_info.id = 0x789;
        rule[2].r_id_info.mask = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK |CAN_GAFLIDM_MASK;
    }

    {
        uint8_t k = 0,x = 0;
        for(k = 0;k < 3; k++){
            tf_cfg_param[k].k_index = 3*rscan3.channel + k;
            if(k%3){
                tf_cfg_param[k].param_un.param_bits.txbuf_num_linked= k;//transmit buffer 9 linked to fifo
                tf_cfg_param[k].param_un.param_bits.mode= RSCAN_TRFIFO_TRANSMIT_MODE;//transmit mode
            }else{
                tf_cfg_param[k].param_un.param_bits.mode= RSCAN_TRFIFO_RECV_MODE;//transmit mode
            }
            tf_cfg_param[k].param_un.param_bits.int_req_tm = 0x01;
            tf_cfg_param[k].param_un.param_bits.int_src_sel = 1;
            tf_cfg_param[k].param_un.param_bits.buf_depth = 0x01;
        }

        for(x = 0;x < 8;x++){
            rf_cfg_param[x].x_index = x;
            rf_cfg_param[x].param_un.param_bits.int_req_tm = 0x01;
            rf_cfg_param[x].param_un.param_bits.int_src_sel = 1;
            rf_cfg_param[x].param_un.param_bits.buf_depth = 0x01;
        }
    }
    rscan3.rule_num = ARRAY_SIZE(rule);
    rscan3.rule_p = rule;

    rscan3.fifo_cfg.trfifo_cfg_num = ARRAY_SIZE(tf_cfg_param);
    rscan3.fifo_cfg.trfifo_cfg_p = tf_cfg_param;

    rscan3.fifo_cfg.rxfifo_cfg_num = ARRAY_SIZE(rf_cfg_param);
    rscan3.fifo_cfg.rxfifo_cfg_p = rf_cfg_param;

    rscan3.txbuf_mask_st.txbuf_mask = RSCAN_TRANSMIT_BUF_0 | RSCAN_TRANSMIT_BUF_1 |
        RSCAN_TRANSMIT_BUF_9| RSCAN_TRANSMIT_BUF_15;

    RSCAN_Init(&rscan3);
}

/* @brief - Reset RsCAN module,as same as the initialization.
 * @param none
 * @reval none
 */
void CanReset(void)
{
    CanInit();
}

void CanStart(void)
{
    CanInit();
}

void CanStop(void)
{
    uint8_t i = 0;

    CAN_CLEAR_ALL();//clear all regiters
    //Transition to global reset mode
    RSCAN_Global_Mode_Ctl(RSCAN_RESET_MODE,1);
    //guarantee not in global stop mode
    while(__RSCAN_GET_GLOBAL_STAT(CAN_GSLPSTS_MASK));

    for(i = 0;i < MAX_CHANNEL_NUM;i++){
        //transition to channel reset mode
        RSCAN_Channel_Mode_Ctl(i,RSCAN_RESET_MODE,1);
        //guarantee not in channel stop mode
        while(__RSCAN_GET_CHANNEL_STAT(i,CAN_CSLPSTS_MASK));
    }

    for(i = 0; i < 8;i++)
        __RSCAN_SET_RECV_FIFO_STAT(i,CAN_RFEMP_MASK,0x01);
    for(i = 0; i < 18;i++)
        __RSCAN_SET_TRFIFO_STAT(i,CAN_CFEMP_MASK,0x01);
    for(i = 0; i < MAX_CHANNEL_NUM;i++)
        __RSCAN_SET_TRANSMIT_QUEUE_STAT(i,CAN_TXQEMP_MASK,0x01);
}

/* @brief - Select the communication speed .
 * @param baudrate - the baudrate selected to set the speed
 * @reval bit_time - return the RSCAN_BIT_TIMING_TypeDef
 */
RSCAN_BIT_TIMING_TypeDef CANbaudrateSet(CAN_BAUDRATE_Type baudrate)
{
    RSCAN_BIT_TIMING_TypeDef bit_time;
    bit_time.sjw = 0x0;// 1Tq
    bit_time.tseg2 = 0x3;// 4Tq
    bit_time.tseg1 = 0x0a;// 11Tq
    switch(baudrate){
        case CAN_BAUDRATE_100K:
            bit_time.brp = 10-1;
            break;
        case CAN_BAUDRATE_125K:
            bit_time.brp = 8-1;
            break;
        case CAN_BAUDRATE_250K:
            bit_time.brp = 4-1;
            break;
        case CAN_BAUDRATE_500K:
            bit_time.brp = 2-1;
            break;
        default:  // default 250K
            bit_time.brp = 4-1;
            break;
    }

    return bit_time;
}

/* @brief - Transmit data using the transmit buffer with the specified buffer id .
 * @param TxbufferId - the transmit buffer id used to send the data
 * @reval none
 */
void CanTransmitBuffer(uint8_t TxbufferId)
{
    uint8_t data[8] = {0x45,0x56,0x78,0x89,0x90};
    uint8_t date_len = 8;

    CanTransmit(TxbufferId,0x123,date_len,data);
}

/* @brief - Transmit data using the transmit buffer with the specified buffer id ,
            ID, the length of data and the pointer to data array
 * @param TxbufferId - the transmit buffer id used to send the data
 * @param ID -  the ID of the message to be transmitted from the transmit buffer
 * @param Length - the length of the message
 * @param data_p - the pointer to data array contains the message
 * @reval -1 - send failed, positive number - the size of data transmited successfully
 */
int8_t CanTransmit(uint8_t TxbufferId,uint32_t ID,uint8_t Length,uint8_t *data_p)
{
    uint8_t sent_size;
    RSCAN_TXID_INFO_TypeDef id_info;

    id_info.index = TxbufferId;
    id_info.ide = 0;
    id_info.rtr = 0;
    id_info.id = ID;

    if(__RSCAN_GET_TRANSMIT_STAT(id_info.index,CAN_TMTRM_MASK))
        return -1;

    sent_size = RSCAN_TxBuffer_Write(id_info,Length,data_p);

    return sent_size;
}

/* @brief - Get the state of the data transmission
 * @param TxbufferId - the transmit buffer id used to send the data
 * @reval TRUE - transmit successfully ,otherwise failed.
 */
bool Can_TxConfirmation(uint8_t TxbufferId)
{
    while(TxbufferId != RSCAN_Transmit_Confirm(RSCAN_TX_BUF,TxbufferId));

    return TRUE;
}

/* @brief - read the message received stored in receive buffer
 * @param RxbufferId - the receive buffer id used to store the message
 * @param p_can_id -  the ID of the message read from receive buffer
 * @param p_dlc - the length of the message received by buffer
 * @param msg_p - the pointer to used to stored the message
 * @reval none
 */
void CanMsgReceived(uint8_t RxbufferId,uint32_t *p_can_id, uint8_t *p_dlc, uint8_t *msg_p)
{
    int8_t ret = -1;
    RSCAN_RXID_INFO_TypeDef id_info;

    id_info.index = RxbufferId;
    while(ret == -1){
        ret  = RSCAN_RxBuffer_Read(&id_info,msg_p);
    }

    *p_can_id = id_info.id;
    *p_dlc = ret;
}

/* @brief -  the error-handling functions according to different types of errors.
 * @param global_err - 1: the gobal error , 0 : CAN m error
 * @param channel - the specified channel on which the error occured.
 * @reval none
 */
void Can_ErrorStatus(bool global_err,uint8_t channel)
{
    uint32_t err_ret = 0;
    uint8_t err_index = 0,max_err_index = 0,err_index_offset = 0;

    if(!global_err){
        err_ret = RSCAN_Channel_Error(channel);
        max_err_index = RSCAN_ACK_DELIMITER_ERROR + 1;
    }else{
        err_ret = RSCAN_Global_Error();
        err_index_offset = RSCAN_ACK_DELIMITER_ERROR + 1;
        max_err_index = ARRAY_SIZE(can_error);
    }
    for(err_index = err_index_offset;err_index < max_err_index &&
        (err_ret >> (err_index - err_index_offset));err_index++){
        if(err_index == can_error[err_index].error_index){
            can_error[err_index].CanErrorHandler();
            break;
        }
    }
}

void Can_ErrorHandling(void)
{
    //do nothing,just for test
}

/* @brief - Config the CAN mode, global mode or channel mode
 * @param channel - the specified channel to set the mode
 * @param mode - the specified mode indicated by CAN_MODE_Type
 * @reval none
 */
void CanModeConfig(uint8_t channel,CAN_MODE_Type mode)
{
    if(mode > CAN_CHANNEL_STOP_MODE) return;//mode not supported

    if(mode >= CAN_COMMUNICATION_MODE && mode <= CAN_CHANNEL_STOP_MODE){
        mode -= CAN_COMMUNICATION_MODE;

        RSCAN_Channel_Mode_Ctl(channel,(RSCAN_CHANNEL_MODE_Type)mode,1);
    }else{
        RSCAN_Global_Mode_Ctl((RSCAN_GLOBAL_MODE_Type)mode,1);
    }
}

void CanBusOff(void)
{

}

void CanBusOffRecover(void)
{

}

/* @brief - Check that the channel m whether in bus-off or not.
 * @param channel - the channel number selected to check
 * @reval TRUE - in bus-off state, FALSE - not in bus-off state
 */
bool CanBusOffState(uint8_t channel)
{
    if(__RSCAN_GET_CHANNEL_STAT(channel,CAN_BOSTS_MASK))
        return TRUE; //in bus-off state
    return FALSE;//not in bus-off state
}
/* @brief - Select bus-off recovery mode.
 * @param channel - the channel number selected to set
 * @param mode - 4 modes could be selected,0-3
 * @reval none
 */
void CanBusOffRecoverModeSelect(uint8_t channel,uint8_t mode)
{
/*      b22 b21
        0 0: ISO11898-1 compliant
        0 1: Entry to channel halt mode automatically at bus-off entry
        1 0: Entry to channel halt mode automatically at bus-off end
        1 1: Entry to channel halt mode (in bus-off state) by program request*/
    __RSCAN_SET_CHANNEL_CTL(channel,CAN_BOM_MASK,mode << CAN_BOM_OFFSET);
}

/* @brief : Perform the RAM test.
 * @param test_page : select a page to test (0-56)
 * @param test_data : some data used to test
 * @param size : the length of test_data
 * @reval none
 */
int8_t CAN_RAM_Test(uint8_t test_page,uint32_t *test_data,uint8_t size)
{
    return  RSCAN_RAM_Test_Perform(test_page,test_data,size);
}


/***************************TEST CODE******************************************/

//Using tx buffer to perform the transmission of message
void R_CAN_Send_TxBuf(uint8_t channel)
{
    __IO uint8_t data[8] = {0x10,0x56,0x78,0x89,0x90};
    __IO uint8_t p = 0;
    RSCAN_TXID_INFO_TypeDef id_info;
    RSCAN_BUF_AVAIL_TypeDef buf;

    RSCAN_All_Buf_Avail(&buf);
    for(p = 0;p < 16 && (buf.p_masked >> p);p++){
        if(((buf.p_masked >> p) & 0x01) == 0) continue;

        id_info.index = channel * 16 + p;

        id_info.ide = 0;
        id_info.rtr = 0;
        id_info.id = p;

        if(__RSCAN_GET_TRANSMIT_STAT(id_info.index,CAN_TMTRM_MASK)){
            //A transmit request is present.
            continue;
        }

        RSCAN_TxBuffer_Write(id_info,5,data);

        while(p != RSCAN_Transmit_Confirm(RSCAN_TX_BUF,id_info.index));
    }
}

void R_CAN_Send_TrFIFO(void)
{
    uint8_t data[] = {
        0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,
    };
    uint8_t k = 0;
    uint32_t tx_k_mask = 0;

    RSCAN_TXID_INFO_TypeDef id_info;
    RSCAN_BUF_AVAIL_TypeDef buf;

    RSCAN_All_Buf_Avail(&buf);
    tx_k_mask = buf.k_masked & buf.k_state;

    for(k = 0;k < 18 && (tx_k_mask >> k);k++){
        if(((tx_k_mask >> k) & 0x01) == 0) continue;

        id_info.index = k;
        id_info.ide = 0;
        id_info.rtr = 0;
        id_info.id = k;

        if(__RSCAN_GET_TRFIFO_STAT(k,CAN_CFTXIF_MASK))
	    continue;

        RSCAN_TRFIFO_Write(id_info,ARRAY_SIZE(data),data);
    }
}

void R_CAN_RxBuf(uint32_t *p_can_id, uint8_t *p_dlc, uint8_t msg[8])
{
    __IO int8_t arr_index = 0,ret = -1;
    __IO uint32_t q_mask = 0,q = 0;
    RSCAN_RXID_INFO_TypeDef id_info;
    RSCAN_BUF_AVAIL_TypeDef buf;

    RSCAN_All_Buf_Avail(&buf);
    while(ret == -1){
        for(arr_index = 0;arr_index < (TOTAL_RECV_BUF_NUM/32 + 1);arr_index++){
            q_mask = buf.q_masked[arr_index];

            for(q = 0;q < TOTAL_RECV_BUF_NUM && (q_mask >> q);q++){
                if(((q_mask >> q) & 0x01) == 0) continue;

                id_info.index = q;
                ret  = RSCAN_RxBuffer_Read(&id_info,msg);
                *p_can_id = id_info.id;
	    }
        }
    }
    *p_dlc  = ret;
}
