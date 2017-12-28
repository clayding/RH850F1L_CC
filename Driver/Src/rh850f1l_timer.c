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
#include "rh850f1l.h"
#include "rh850f1l_timer.h"
#include "rh850f1l_clk.h"
/*************************************OS Timer declaration Start***************/
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

/*************************************OS Timer declaration End*****************/

static __IO uint8_t taub_channel = 0;
static ErrorStatus TAUB_Set_Channel_Mode(TAUB_ChMode_TypeDef *mode );

/*************************************OS Timer defination start****************/
static void OSTM_Start_Ctl_Set(void* unit,OSTM_OPERATE_MODE_Type opt_mode,
    OSTM_START_INT_STAT_Type int_stat);

uint8_t OSTM_Count_State_Get(void* unit);

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
  __IO uint32_t tick_start = 0,current_tick = 0;
  tick_start = OSTM_GetTick();
  while(((current_tick = OSTM_GetTick()) - tick_start) < delay_us);
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

/**************************OS Timer defination end*****************************/

void TAUB_Independent_Init(TAUB_ChMode_TypeDef *mode)
{
    __IO uint8_t i = 0;
    uint16_t channel_mask = 0x00;

    if(mode->ch_no / 16) return; //guarantee that taub_channel is [0,15]
    taub_channel = mode->ch_no;

    //Set the TAUBnTPS register to specify the clock frequency of CK0 to CK3.
    for(;i <= (uint8_t)TAUB_CK3;i++)
        __SET_TAUB_PRESCALER(TAUB_PRSn_OFFSET(i),10);// 2^10 = 1024 ==> PLCLK/1024 = 40M/1024


    if(TAUB_Set_Channel_Mode(mode) == ERROR){
        while(1){};
    }

    __SET_TAUB_CDR(taub_channel,0x9896); //0x9896 ==> 39062==> 40M/39062 = 1024 = 2^10

    channel_mask |= 0x01 << taub_channel;
    __START_COUNTER(channel_mask);
}

void TAUB_Synchronous_Init(TAUB_ChMode_TypeDef mode_arr[],uint8_t size)
{
    uint8_t i = 0;
    uint16_t channel_mask = 0x00;

    for(;i <= (uint8_t)TAUB_CK3;i++)
        __SET_TAUB_PRESCALER(TAUB_PRSn_OFFSET(i),10);// 2^10 = 1024 ==> PLCLK/1024 = 40M/1024

    for(i = 0;i< size;i++){
        if(mode_arr[i]->ch_no / 16) continue;

        if(TAUB_Set_Channel_Mode(&mode[i]) == ERROR){
            while(1){};
        }
        __SET_TAUB_CDR(taub_channel,0x9896); //0x9896 ==> 39062==> 40M/39062 = 1024 = 2^10

        if(mode_arr[i].enable_sim_cfg){
            TAUB_Simultaneous_Rewrite_Init(taub_channel,mode_arr[i].sim_cfg);
        }

        chanel_mask |= (0x01 << taub_channel);
    }

    __START_COUNTER(chanel_mask);

}

ErrorStatus TAUB_Simultaneous_Rewrite_Init(uint8_t channel_num,TAUB_SIMULREWR_CFG_TypeDef sim_cfg)
{
    uint16_t ret = 0;

    __ENABLE_RELOAD_DATA(channel_num,TRUE,ret);
    if(ret) return ERROR;

    __SET_RELOAD_DATA_CTL_CH(channel_num,sim_cfg.ch_ctl,ret);
    if(ret) return ERROR;

    __SET_RELAOD_DATA_MODE(channel_num,sim_cfg.sig_gen,ret);
    if(ret) return ERROR;

    __SET_RELAOD_DATA_CTL(channel_num,sim_cfg.is_trig_ch,ret);
    if(ret) return ERROR;

    __ENABLE_RELOAD_DATA_TRIGGER(channel_num);

}


ErrorStatus TAUB_Set_Channel_Mode(TAUB_ChMode_TypeDef *mode )
{
    __IO uint16_t ret_mode = 0;

    __SET_TAUB_CMOR_CKS(taub_channel,mode->clk_sel);
    __SET_TAUB_CMOR_CCS0(taub_channel,mode->cnt_clk4cnt_counter);

    __SET_TAUB_CMOR_MAS(taub_channel,mode->mas);

    if(mode->sts != TAUB_STS_PROHIBITED)
        __SET_TAUB_CMOR_STS(taub_channel,mode->sts);

    __SET_TAUB_CMOR_COS(taub_channel,mode->cos);

    if(mode->md_un.md_bits.high7bit == TAUB_MD_PROHIBITED1 ||
         mode->md_un.md_bits.high7bit == TAUB_MD_PROHIBITED2 )
         return ERROR;
    __SET_TAUB_CMOR_MD(taub_channel,mode->md_un.md);

    __GET_TAUB_CMOR(ret_mode,taub_channel);// for test

    return SUCCESS;
}
