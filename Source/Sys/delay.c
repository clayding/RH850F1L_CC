/**
  ******************************************************************************
  * @file    delay.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   15-December-2017
  * @brief  Implementation of all the functions in delay.h.
  *          This file provides firmware functions implementation to manage the following
  *          functionalities of the specific board.
  ******************************************************************************
  */
#include "delay.h"

void udelay( __IO usecond_t delay_us)
{
     OSTM_Delay(delay_us);
}

void mdelay(__IO msecond_t delay_ms)
{
    udelay(delay_ms*1000);
}
