/**
  ******************************************************************************
  * @file    board.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   24-November-2017
  * @brief  Implementation of all the functions in board.h.
  *          This file provides firmware functions implementation to manage the following
  *          functionalities of the specific board.
  ******************************************************************************
  */

#include "board.h"

/*!
 * Flag to indicate if the MCU is Initialized
 */
static bool mcu_initialized = FALSE;

static void Board_Port_Config(void);

void Board_MCU_Init(void)
{
    if(mcu_initialized == FALSE){
        System_Clock_Config();
    }
    mcu_initialized = TRUE;

    Board_Port_Config();
}

void System_Clock_Config(void)
{

    while(Clock_OSC_Get_Status(R_OSC_TYPE) == OSC_INACTIVE); //HI IntOSC is not actived,just loop
    //while(Clock_ROSC_Get_Status() == OSC_ACTIVED);//Just for test,del later
    //HI Int OSc is actived
    Clock_MOSC_Config(OSC_ENABLE);//Config Main OSC
    Clock_PLL_Config(OSC_ENABLE); //Config PLL
    Clock_Domain_Set(CPUCLK);//set clock domain for cpuclk
    Clock_Domain_Set(IPERI1);//set clock domain for iperi1
    Clock_Domain_Set(IPERI2);//set clock domain for iperi2
    //Clock_Domain_Set(AFOUT);
    //Clock_Fout_Config();

}

void Board_Port_Config(void)
{
    Port_InitTypeDef port;

    port.pin_mask = PORT_PIN_3;
    port.opt_mode = PORT_MODE;
    port.io_mode = PORT_OUTPUT_MODE;
    port.echar_t = OUTPUT_PP | OUTPUT_LDS;
    port.bmc_t = BIDIRECTION_MODE_ENABLED;
    Port_Init(PortGroupNum10,&port);

    port.pin_mask = PORT_PIN_5;
    //port.opt_mode = PORT_MODE;
    //port.io_mode = PORT_OUTPUT_MODE;
    //port.bmc_t = BIDIRECTION_MODE_ENABLED;
    Port_Init(PortGroupNum8,&port);

    port.pin_mask = PORT_PIN_9;
    port.opt_mode = AF_MODE;
    port.io_mode = PORT_INPUT_MODE;
    port.echar_t = INPUT_PU|INPUT_PD|INPUT_SHMT1;
    port.alter_t = ALT_FUNC_1;
    Port_Init(PortGroupNum0,&port);

    {
        Eiint_InitTypeDef eiint;
        eiint.eiint_ch = P_12;
        eiint.eiint_ext_int = 1;
        eiint.eiint_process = INT_PROCESS_ENABLE;
        eiint.eiint_refer_method = TABLE_REFER_METHOD;
        eiint.eiint_priority = INT_PRIORITY_7;
        eiint.eiint_detect = EDGE_DETECTION | FALL_EDGE_ENABLE | RISE_EDGE_DISABLE;
        Eiit_Init(&eiint);

        eiint.eiint_ch = 76;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_5;
        Eiit_Init(&eiint);

        eiint.eiint_ch = 134;
        eiint.eiint_ext_int = 0;
        eiint.eiint_priority = INT_PRIORITY_6;
        Eiit_Init(&eiint);

        OSTM_Init();
        {
            TAUB_ChMode_TypeDef ch_mode;
            ch_mode.clk_sel = TAUB_CK0;
            ch_mode.cnt_clk4cnt_counter = 0;
            ch_mode.mas = 0;
            ch_mode.sts = 0;
            ch_mode.cos = 0;
            ch_mode.md_un.md_bits.high7bit = 0;
            ch_mode.md_un.md_bits.low1bit = 0;
            TAUB_Init(0,&ch_mode);
        }
    }

}
