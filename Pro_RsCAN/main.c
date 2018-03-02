/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :Mon, Oct 24, 2016                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
#include "rh850f1l.h"
#include "rh850f1l_port.h"
#include "rh850f1l_ext.h"
#include "rh850f1l_timer.h"
#include "rh850f1l_rscan.h"
#include "delay.h"


extern void (*Eiit_Handler_Ptr)(void);
extern void (*Eiit_Handler_Ptr_2)(void);

void main(void)
{
    uint32_t can_id;
    uint8_t  dlc;
    uint8_t  msg[8];

    Board_MCU_Init();

    while (1)
    {
        /*uint8_t i = 1;
        uint32_t test_data[64] = {0};
        for(;i < 65;i++){
            test_data[i-1] = i;
        }
        CAN_RAM_Test_Perform(1,test_data,64);*/

       //R_CAN_Receive_RxBuf0(&can_id,&dlc,msg);
       //R_CAN_Send_TxBuf0(3);
       CanMsgReceived(0,&can_id,&dlc,msg);
       //CanTransmitBuffer(48);
       //CanTransmit(64,can_id,dlc,msg);
       R_CAN_Send_TrFIFO(3);
       while(Can_TxConfirmation(64) == FALSE);

       //transmit successfully
       __RSCAN_SET_TRANSMIT_STAT(64,CAN_TMTRF_MASK,0);

    }
}
