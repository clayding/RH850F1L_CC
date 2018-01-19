/**
  ******************************************************************************
  * @file    rh850f1l_rtc.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   19-January-2018
  * @brief   Real-Time Clock module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of Real-Time Clock peripheral:
  *           + Initialization and de-initialization functions
  *           + Real-Time Clock functions
  ******************************************************************************
  */

#include "rh850f1l_rtc.h"



void RTCA_Init(void)
{

}



uint8_t RTCA_Subcounter_Config(bool enable)
{
    uint8_t sub_cnt_stat = 0;

    if(enable){
        __RTCA_ENABLE_SUB_COUNTER();
    }else{
        __RTCA_DISABLE_SUB_COUNTER();
    }

    sub_cnt_stat  = __RTCA_GET_SUB_COUNTER_STAT();

    return sub_cnt_stat; //return the state of sub-counter
}

int8_t RTCA_Set_Operate_Mode(uint8_t opt_mode)
{
    uint8_t sub_cnt_stat = 0;
    sub_cnt_stat = __RTCA_GET_SUB_COUNTER_STAT();

    //The operation mode must not be changed while
    //sub-counter operation is enabled (RTCAnCTL0.RTCAnCEST = 1).
    if(sub_cnt_stat)
        return -1;

    __RTCA_SET_OPERATE_MODE(opt_mode);
}
