#ifndef CAN_H
#define CAN_H

#include "rh850f1l_rscan.h"

typedef enum{
    CAN_BAUDRATE_100K,
    CAN_BAUDRATE_125K,
    CAN_BAUDRATE_250K,
    CAN_BAUDRATE_500K,
}CAN_BAUDRATE_Type;


void CanInit(void);

void CanReset(void);

RSCAN_BIT_TIMING_TypeDef CANbaudrateSet(CAN_BAUDRATE_Type baudrate);

void CanTransmitBuffer(uint8_t TxbufferId);

uint8_t CanTransmit(uint8_t TxbufferId,uint32_t ID,uint8_t Length,uint8_t *data_p);

bool Can_TxConfirmation(uint8_t TxbufferId);
void CanMsgReceived(uint8_t RxbufferId,uint32_t *p_can_id, uint8_t *p_dlc, uint8_t msg[8]);


#endif //CAN_H
