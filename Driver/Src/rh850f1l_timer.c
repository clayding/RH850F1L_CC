/**
  ******************************************************************************
  * @file    rh850f1l_timer.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   10-December-2017
  * @brief   Timer/Counter module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and timer/counter peripheral:
  *           + Initialization and de-initialization functions
  *           + Timer and Counter functions
  * @note   Supply of the count clock my not continued when the debugger acquires
  *         control of the microcontroller (at breakpoints and so on) ,this
  *         determinated by the setting of OSTMnEMU
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rh850f1l_timer.h"
#include "rh850f1l_clk.h"
/*************************************OS Timer*********************************/
#define OSTM_CLK    CPUCLK2      //OSTM supply clock is CPUCLK2
#define US_DIV      1000000      //40MHz/1M = 40,then once the INT occured ,indicate 1 us elapsed
#define MS_DIV      (US_DIV/1000)//once the INT occured ,indicate 1 ms elapsed
#define S_DIV       (1)         //once the INT occured ,indicate 1s elapsed
#define OSTM_DIV    US_DIV
#define OSTM_OPERATE_MODE_MASK  ((uint8_t)0x01 << 1)
#define OSTM_START_INT_MASK     ((uint8_t)0x01)

/*Set the start value of the down-counter or the value with which the counter is
compared*/
#define __SET_OSTM_CMP_VAL(_UNIT_,_VALUE_)  do{ \
                                                OSTM0.CMP = _VALUE_ & 0xFFFFFFFF; \
                                            }while(0)
/*Get the start value of the down-counter or the value with which the counter is
compared*/
#define __GET_OSTM_CMP_VAL(_UNIT_,_RET_)    do{ \
                                                _RET_ = OSTM0.CMP; \
                                            }while(0)
/* Get the counter value of the timer*/
#define __GET_OSTM_CURRENT_COUNT(_UNIT_,_RET_)  do{ \
                                                    _RET_ = OSTM0.CNT; \
                                                }while(0)
/*Starts the counter*/
#define __ENABLE_OSTM_START_TRIG(_UNIT_)        do{ \
                                                    OSTM0.TS |= 0x01;\
                                                }while(0)
/*Stop the counter*/
#define __ENABLE_OSTM_STOP_TRIG(_UNIT_)         do{ \
                                                    OSTM0.TT |= 0x01 ;\
                                                }while(0)

#define __SET_OSTM_EMU_VAL(_UNIT_,_VAL_)        {/*TODO.............*/}

__IO uint32_t uw_tick;

static void OSTM_Start_Ctl_Set(void* unit,OSTM_OPERATE_MODE_Type opt_mode,
    OSTM_START_INT_STAT_Type int_stat);

static uint8_t OSTM_Count_State_Get(void* unit);

void OSTM_Init()
{
    __SET_OSTM_CMP_VAL(OSTM0,OSTM_CLK/OSTM_DIV - 1 );/*CPUCLK 40MHz ----> us*/
    OSTM_Start_Ctl_Set(&OSTM0,OSTM_COMPARE_MODE/*OSTM_INTERVAL_MODE*/,OSTM_START_INT_DISABLE);
    __ENABLE_OSTM_START_TRIG(OSTM0);
    while(OSTM_Count_State_Get(&OSTM0) == 0x00);
}

/**
  * @brief This function is called to increment  a global variable "uw_tick"
  *        used as application time base.
  * @note In the default implementation, this variable is incremented each 1us
  *       in Systick ISR.
  * @retval None
  */
void OSTM_IncTick(void)
{
    uw_tick++;
}

uint32_t OSTM_GetTick(void)
{
  return uw_tick;
}

void OSTM_Delay(__IO uint32_t delay_us)
{
  uint32_t tick_start = 0;
  tick_start = OSTM_GetTick();
  while((OSTM_GetTick() - tick_start) < delay_us);
}


/**
  * @brief This function specifies the operating mode for the counter
  *         and controls the generation of OSTMTINT interrupt requests
  *         when counting starts.
  * @param unit  the unit of OSTM,
  * @param opt_mode  operating mode OSTM_INTERVAL_MODE or OSTM_COMPARE_MODE,
  * @param int_stat  enable or disable the generation of OSTMTINT interrupt
  *         requests when counting starts
  */
void OSTM_Start_Ctl_Set(void* unit,OSTM_OPERATE_MODE_Type opt_mode,
    OSTM_START_INT_STAT_Type int_stat)
{
    __IO uint8_t *ctl_ptr = &(((__IO struct __tag47 *)unit)->CTL);

    if(opt_mode == OSTM_INTERVAL_MODE)
        CLEAR_BIT(ctl_ptr,OSTM_OPERATE_MODE_MASK);
    else //if(opt_mode == OSTM_COMPARE_MODE)
        SET_BIT(ctl_ptr,OSTM_OPERATE_MODE_MASK);

    if(int_stat == OSTM_START_INT_ENABLE)
        SET_BIT(ctl_ptr,OSTM_START_INT_MASK);
    else //if(int_stat == OSTM_START_INT_DISABLE)
        CLEAR_BIT(ctl_ptr,OSTM_START_INT_MASK);
}

/**
  * @brief This function's judge that whether the counter is enabled or disabled
  * @param unit  the unit of OSTM,
  * @retval 0 counter disabled,otherwise enabled
  */
uint8_t OSTM_Count_State_Get(void* unit)
{
    __IO uint8_t *te_ptr = &(((__IO struct __tag47 *)unit)->TE);

    return READ_BIT(te_ptr,0x01);
}

/**
  * @brief This function's destination is reload new value to OSTMnCMP in
  *         free_run compare mode,because the counter count up from 0x00000000
  *         to 0xFFFFFFFF,even an interrupt occured.
  * @param new_value the new value written to OSTMnCMP
  */
void OSTM_Cmp_Reload(const uint32_t new_value)
{
    __IO uint32_t current_count = 0;//Get the current count before writing new

    __GET_OSTM_CURRENT_COUNT(OSTM0,current_count);
    if(new_value)//if value is not 0,then write the new to OSTMnCMP
        __SET_OSTM_CMP_VAL(OSTM0,current_count + new_value/OSTM_DIV - 1 );
    else//if 0,write the default value to register
        __SET_OSTM_CMP_VAL(OSTM0,current_count + OSTM_CLK/OSTM_DIV - 1 );
}
