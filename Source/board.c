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
#include "rh850f1l_clk.h"
#include "rh850f1l_port.h"

/*!
 * Flag to indicate if the MCU is Initialized
 */
static bool mcu_initialized = false;

static void Board_Port_Config(void);

void Board_MCU_Init(void)
{
    if(mcu_initialized == false){
        System_Clock_Config();
    }
    mcu_initialized = true;

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
    port.bmc_t = BIDIRECTION_MODE_ENABLED;
    Port_Init(PortGroupNum10,&port);

    port.pin_mask = PORT_PIN_5;
    port.opt_mode = PORT_MODE;
    port.io_mode = PORT_OUTPUT_MODE;
    port.bmc_t = BIDIRECTION_MODE_ENABLED;
    Port_Init(PortGroupNum8,&port);

    port.pin_mask = PORT_PIN_6;
    port.opt_mode = PORT_MODE;
    port.io_mode = PORT_INPUT_MODE;
    port.bmc_t = BIDIRECTION_MODE_ENABLED;
    Port_Init(PortGroupNum8,&port);

}
