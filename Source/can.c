
#include "can.h"


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

void CanInit(void)
{
    RSCAN_InitTypeDef rscan3;
    rscan3.channel = 3;
    rscan3.sp.fcan_src = 1;
    rscan3.sp.bit_time = CANbaudrateSet(CAN_BAUDRATE_250K);

    rscan3.rule_num = 2;

    {//for example
        rscan3.rule[0].r_pointer.dlc_t = RSCAN_DLC_CHECK_DISABLED;
        rscan3.rule[0].r_pointer.label_t = 0x891;
        rscan3.rule[0].r_pointer.recv_buf = RSCAN_RECV_FIFO;
        rscan3.rule[0].r_pointer.recv_buf_index = 0;
        rscan3.rule[0].r_pointer.k_index = 0;
        rscan3.rule[0].r_pointer.x_index = 0;

        rscan3.rule[0].r_id_info.ide = RSCAN_RECV_IDE_STD;
        rscan3.rule[0].r_id_info.rtr = RSCAN_RECV_DATA_FRM;
        rscan3.rule[0].r_id_info.target_msg = RSCAN_RECV_FROM_OTHER;
        rscan3.rule[0].r_id_info.id = 0x123;
        rscan3.rule[0].r_id_info.mask = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK |CAN_GAFLIDM_MASK;


        rscan3.rule[1].r_pointer.dlc_t = RSCAN_DLC_CHECK_DISABLED;
        rscan3.rule[1].r_pointer.label_t = 0x745;
        rscan3.rule[1].r_pointer.recv_buf = RSCAN_RECV_FIFO;
        rscan3.rule[1].r_pointer.recv_buf_index = 1;
        rscan3.rule[1].r_pointer.k_index = 0;
        rscan3.rule[1].r_pointer.x_index = 1;
        rscan3.rule[1].r_id_info.ide = RSCAN_RECV_IDE_STD;
        rscan3.rule[1].r_id_info.rtr = RSCAN_RECV_DATA_FRM;
        rscan3.rule[1].r_id_info.target_msg = RSCAN_RECV_FROM_OTHER;
        rscan3.rule[1].r_id_info.id = 0x456;
        rscan3.rule[1].r_id_info.mask = CAN_GAFLIDEM_MASK|CAN_GAFLRTRM_MASK |CAN_GAFLIDM_MASK;

    }
    RSCAN_Init(&rscan3);
}

void CanReset(void)
{
    CanInit();
}

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

void CanTransmitBuffer(uint8_t TxbufferId)
{
    uint8_t data[8] = {0x45,0x56,0x78,0x89,0x90};
    uint8_t date_len = 8;

    CanTransmit(TxbufferId,0x123,date_len,data);
}

int8_t CanTransmit(uint8_t TxbufferId,uint32_t ID,uint8_t Length,uint8_t *data_p)
{
    uint8_t sent_size;
    RSCAN_TRANSMIT_ID_INFO_TypeDef id_info;

    id_info.index = TxbufferId;
    id_info.ide = 0;
    id_info.rtr = 0;
    id_info.id = ID;

    if(__RSCAN_GET_TRANSMIT_STAT(id_info.index,CAN_TMTRM_MASK))
        return -1;

    sent_size = RSCAN_Transmit_Buffer_Write(id_info,Length,data_p);

    return sent_size;
}

bool Can_TxConfirmation(uint8_t TxbufferId)
{
    __IO uint8_t ret = 0;

    ret = __RSCAN_GET_TRANSMIT_STAT(TxbufferId,CAN_TMTRF_MASK);

    if(ret == RSCAN_TRANSMIT_COMPLETED_WITHOUT_ABORT ||
        ret == RSCAN_TRANSMIT_COMPLETED_WITH_ABORT){
        ret = 0;
        return TRUE;
    }

    return FALSE;
}

void CanMsgReceived(uint8_t RxbufferId,uint32_t *p_can_id, uint8_t *p_dlc, uint8_t msg[8])
{
    int8_t ret = -1;
    RSCAN_RECV_ID_INFO_TypeDef id_info;

    id_info.index = RxbufferId;
    while(ret == -1){
        ret  = RSCAN_Receive_Buffer_Read(&id_info,msg);
    }

    *p_can_id = id_info.id;
    *p_dlc = ret;
}

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
