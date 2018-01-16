/**
  ******************************************************************************
  * @file    rh850f1l_wdta.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   10-December-2017
  * @brief   Window Watchdog Timer module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and timer/counter peripheral:
  *           + Initialization and de-initialization functions
  *           + Window Watchdog Timer functions
  ******************************************************************************
  */
#include "rh850f1l_wdta.h"



static __IO uint8_t next_ref_value = 0xAC;

void WDTA_Start(WDTA_UNIT_Type unit, WDTA_MODE_TypeDef *mode)
{
    __IO uint8_t ref_val = 0;
    __IO uint8_t expect_tm = 0xAC;

    WDTA_Mode_Config(unit,mode);
#if 0
    __ENABLE_WDTA(_WDTA0);
#else
    ref_val = (unit == _WDTA0)?__GET_WDTA_REFER_VALUE(_WDTA0):__GET_WDTA_REFER_VALUE(_WDTA1);

    expect_tm -= ref_val;
    next_ref_value = ROTATE_LEFT(expect_tm,8,1);
    __ENABLE_WDTA_VAC(_WDTA0,expect_tm);
#endif
}


void WDTA_Mode_Config(WDTA_UNIT_Type unit, WDTA_MODE_TypeDef *mode)
{
    __IO uint8_t set_mode = 0;
    set_mode = (mode->inter_time << 4) | (mode->int_en << 3) | (mode->err_mode << 2) |(mode->ws);
    if(unit == _WDTA0)
    	__SET_WDTA_MODE(_WDTA0,set_mode);
    else
        __SET_WDTA_MODE(_WDTA1,set_mode);
}

void WDTA_Reload(WDTA_UNIT_Type unit)
{
    __IO uint8_t expect_tm = 0xAC;

    if(unit == _WDTA0){
#if 0
        __ENABLE_WDTA(_WDTA0);
#else
    expect_tm -= next_ref_value;
    next_ref_value = ROTATE_LEFT(expect_tm,8,1);
    __ENABLE_WDTA_VAC(_WDTA0,expect_tm);
#endif
    }else{
        
    }
}
