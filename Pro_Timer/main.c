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
#include "delay.h"

typedef struct
{
    char *led_name;
    Port_Group_Index_Type led_pgrp;
    uint16_t led_pin;
} LED_CTL_Struct;

static void LED_Struct_Init(LED_CTL_Struct *lcs_t, uint8_t arr_size);
static void LED_Blink(LED_CTL_Struct *lcs_t, uint8_t arr_size);
static void led_blink(void);

LED_CTL_Struct lcs[3];

extern void (*Eiit_Handler_Ptr)(void);

void main(void)
{

    LED_Struct_Init(lcs, ARRAY_SIZE(lcs));
    Board_MCU_Init();

    while (1)
    {
        led_blink();
        mdelay(1000);

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

    //Eiit_Handler_Ptr = led_blink;
}

void LED_Blink(LED_CTL_Struct lcs_t[], uint8_t arr_size)
{
    static volatile uint8_t j = 0;
    __IO int count = 1;
    while (count)
    {
        /*Method 1  use Pn reg*/
        Port_Write_OutputData_Bit(lcs_t[0].led_pgrp,lcs_t[0].led_pin,(BitAction)j);
        Port_Write_OutputData_Bit(lcs_t[1].led_pgrp,lcs_t[1].led_pin,(BitAction)j);
        j = !j;
        count--;
    }
}

void led_blink(void)
{
    LED_Blink(lcs, ARRAY_SIZE(lcs));
}

void assert_failed(uint8_t *file, uint32_t line)
{
    while (1)
    {
    }
}
