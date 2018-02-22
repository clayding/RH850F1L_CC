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

typedef struct
{
    char *led_name;
    Port_Group_Index_Type led_pgrp;
    uint16_t led_pin;
    uint8_t reverse_bit;
} LED_CTL_Struct;

static void LED_Struct_Init(LED_CTL_Struct *lcs_t, uint8_t arr_size);
static void LED_Blink(LED_CTL_Struct *lcs_t, uint8_t arr_size);
static void led_blink1(void);
static void led_blink2(void);

LED_CTL_Struct lcs[3];

extern void (*Eiit_Handler_Ptr)(void);
extern void (*Eiit_Handler_Ptr_2)(void);

void main(void)
{
    uint32_t can_id;
    uint8_t  dlc;
    uint8_t  msg[8];

    LED_Struct_Init(lcs, ARRAY_SIZE(lcs));
    Board_MCU_Init();

    while (1)
    {
       R_CAN_Receive_RxBuf0(&can_id,&dlc,msg);
       //R_CAN_Send_TxBuf0(3);
       //CanMsgReceived(95,&can_id,&dlc,msg);
       //CanTransmitBuffer(48);
       CanTransmit(48,can_id,dlc,msg);
       while(Can_TxConfirmation(48) == FALSE);

       //transmit successfully
       __RSCAN_SET_TRANSMIT_STAT(48,CAN_TMTRF_MASK,0);


    }
}

void LED_Struct_Init(LED_CTL_Struct *lcs_t, uint8_t arr_size)
{

    lcs_t->led_name = "LED1";
    lcs_t->led_pgrp = PortGroupNum10;
    lcs_t->led_pin = PORT_PIN_3;

    lcs_t++;
    lcs_t->led_name = "LED2";
    lcs_t->led_pgrp = PortGroupNum8;
    lcs_t->led_pin = PORT_PIN_5;

    lcs_t++;
    lcs_t->led_name = "P8_6";
    lcs_t->led_pgrp = PortGroupNum8;
    lcs_t->led_pin = PORT_PIN_6;

    Eiit_Handler_Ptr = led_blink2;
    Eiit_Handler_Ptr_2 = led_blink1;
}

void LED_Blink(LED_CTL_Struct lcs_t[], uint8_t arr_size,uint8_t ledn)
{
    static volatile uint8_t j = 0;
    __IO int count = 1;
    while (count)
    {
        /*Method 1  use Pn reg*/
        Port_Write_OutputData_Bit(lcs_t[ledn].led_pgrp,lcs_t[ledn].led_pin,(BitAction)lcs_t[ledn].reverse_bit);
        lcs_t[ledn].reverse_bit = !lcs_t[ledn].reverse_bit;
        //j = !j;

        count--;
    }
}

void led_blink1(void)
{
    LED_Blink(lcs, ARRAY_SIZE(lcs),0);
}

void led_blink2(void)
{
    LED_Blink(lcs, ARRAY_SIZE(lcs),1);
}
void assert_failed(uint8_t *file, uint32_t line)
{
    while (1)
    {
    }
}
