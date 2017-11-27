/**
  ******************************************************************************
  * @file    rh850f1l_clk.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of Clock Control module.
  ******************************************************************************
  */
#ifndef RH850F1L_CLK_H
#define RH850F1L_CLK_H

#include "rh850f1l.h"

 #define ROSCCLK_FREQUENCY   (8*1024*1024) //Hi IntOSC frequency8MHz

typedef enum {
    MOSC_DISABLE,
    MOSC_ENABLE = !MOSC_DISABLE,
}MOSC_OPT_Type;

typedef enum {
    OSC_INACTIVE,
    OSC_ACTIVED = !OSC_INACTIVE,
}MOSC_STATUS_Type,ROSCSTATUS_Type;

typedef enum {
    MOSC_AMP_HIGH,      //00b,20 MHz < fX ≤ 24 MHz
    MOSC_AMP_MID_HIGH,  //01b,16 MHz < fX ≤ 20 MHz
    MOSC_AMP_MID_LOW,   //10b,8 MHz < fX ≤ 16 MHz
    MOSC_AMP_LOW,       //11b,8 MHz
}MOSC_AMP_GAIN_Type;



void Clock_MOSC_Config(MOSC_OPT_Type opt);

#endif //RH850F1L_CLK_H
