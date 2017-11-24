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

/*!
 * Flag to indicate if the MCU is Initialized
 */
static bool mcu_initialized = false;

void Board_MCU_Init(void)
{
    if(mcu_initialized == false){
        System_Clock_Config();
    }
    mcu_initialized = true;

}

void System_Clock_Config(void)
{

    while(Clock_ROSC_Get_Status() == OSC_INACTIVE)
    {

    }
}
