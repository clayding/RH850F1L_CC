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


typedef enum {
    OSC_DISABLE,
    OSC_ENABLE = !OSC_DISABLE,
}OSC_OPT_Type;

typedef enum {
    OSC_INACTIVE,
    OSC_ACTIVED = !OSC_INACTIVE,
}OSC_STATUS_Type;

typedef enum {
    MOSC_AMP_HIGH,      //00b,20 MHz < fX ≤ 24 MHz
    MOSC_AMP_MID_HIGH,  //01b,16 MHz < fX ≤ 20 MHz
    MOSC_AMP_MID_LOW,   //10b,8 MHz < fX ≤ 16 MHz
    MOSC_AMP_LOW,       //11b,8 MHz
}MOSC_AMP_GAIN_Type;

typedef enum {
    M_OSC_TYPE,//Main OSC
    R_OSC_TYPE,//HI Int OSC
    PLL_TYPE,//PLL
}X_OSC_Type;

typedef enum { //Domain Clock
    AWDTA,ATAUJ,ARTCA,AADCA,AFOUT,//AWO_Domain
    CPUCLK,IPERI1,IPERI2,ILIN,IADCA,ICAN,ICANOSC,ICSI,//ISO Domain
    DOMAIN_CLK_TYPE_MAX,
}DOMAIN_CLK_Type;

typedef enum { //return after Setting CLock Domain 
    SET_SRC_CLK_FAIL,
    SET_CLK_DIVIDER_FAIL = SET_SRC_CLK_FAIL,
    SET_CLK_DOMAIN_SUCCESS,
    SET_OTHER_FAIL,
}SET_CLK_DOMAIN_RET_Type;

typedef struct {
    uint32_t src_clk_ctl_val;
    uint32_t clk_divider_val;
}SET_CLK_DOMAIN_Struct;

void Clock_MOSC_Config(OSC_OPT_Type opt);
OSC_STATUS_Type Clock_OSC_Get_Status(X_OSC_Type otp);
void Clock_PLL_Config(OSC_OPT_Type opt);

#endif //RH850F1L_CLK_H
