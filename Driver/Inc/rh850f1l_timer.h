/**
  ******************************************************************************
  * @file    rh850f1l_timer.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of Timer Registers module.
  ******************************************************************************
  */

#ifndef RH850F1L_TIMER_H
#define RH850F1L_TIMER_H
#include "rh850f1l.h"

 typedef enum{
     OSTM_INTERVAL_MODE,//Interval timer mode
     OSTM_COMPARE_MODE, // Free-run compare mode
 }OSTM_OPERATE_MODE_Type;

 typedef enum{
     OSTM_START_INT_DISABLE,
     OSTM_START_INT_ENABLE = !OSTM_START_INT_DISABLE,
 }OSTM_START_INT_STAT_Type;

void OSTM_Init();
void OSTM_Delay(__IO uint32_t delay_us);
void OSTM_Cmp_Reload(const uint32_t new_value);


#endif//RH850F1L_TIMER_H
