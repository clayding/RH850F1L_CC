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
#include "rh850f1l_port.h"
#include "rh850f1l_ext.h"
#include "rh850f1l_timer.h"
#include "rh850f1l_rscan.h"
#include "delay.h"


extern void (*Eiit_Handler_Ptr)(void);
extern void (*Eiit_Handler_Ptr_2)(void);

void main(void)
{
    __IO uint16_t msg;

    Board_MCU_Init();

    //R_CAN_RxBuf(&can_id,&dlc,msg);
    //R_CAN_Send_TxBuf(3);
    //R_CAN_Send_TrFIFO();
    //UART_Send(0,"123456789",9);
	//printf("Staring wait\n");
    UART_Send_Data_Buf(0,"012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789",120);
    while (1)
    {

    }

}
