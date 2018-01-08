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
static __IO uint8_t taud_channel = 0;
static ErrorStatus TAUB_Set_Channel_Mode(TAUB_ChMode_TypeDef *mode );
static void TAUB_Filter_Ctl_Operate(uint8_t channel_num);
static ErrorStatus TAUD_Set_Channel_Mode(TAUD_ChMode_TypeDef *mode );
static void TAUD_Filter_Ctl_Operate(uint8_t channel_num);

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

/*************************TAUB defination start********************************/
void TAUB_Independent_Init(TAUB_ChMode_TypeDef *mode)
{
    __IO uint8_t i = 0;
    uint16_t channel_mask = 0x00;

    if(mode->ch_no / 16) return; //guarantee that taub_channel is [0,15]
    taub_channel = mode->ch_no;

    //Set the TAUBnTPS register to specify the clock frequency of CK0 to CK3.
    for(;i <= (uint8_t)TAU_CK3;i++)
        __SET_TAU_PRESCALER(_TAUB0,_TAUB0_PRSn_OFFSET(i),mode->clk_div);


    if(TAUB_Set_Channel_Mode(mode) == ERROR){
        while(1){};
    }

    __SET_TAU_CDR(_TAUB0,taub_channel,mode->cdr);

    channel_mask |= 0x01 << taub_channel;
    __START_COUNTER(_TAUB0,channel_mask);
}

void TAUB_Batch_Init(TAUB_ChMode_TypeDef mode_arr[],uint8_t size)
{
    uint8_t i = 0;
    uint16_t channel_mask = 0x00;

    for(;i <= (uint8_t)TAU_CK3;i++)
        __SET_TAU_PRESCALER(_TAUB0,_TAUB0_PRSn_OFFSET(i),mode_arr[i].clk_div);// 40M/16 = 2500 --- 1ms

    for(i = 0;i< size;i++){
        if(mode_arr[i].ch_no / 16) continue;
        taub_channel = mode_arr[i].ch_no;

        if(TAUB_Set_Channel_Mode(&mode_arr[i]) == ERROR){
            while(1){};
        }
        __SET_TAU_CDR(_TAUB0,taub_channel,mode_arr[i].cdr);

        if(mode_arr[i].enable_sim_cfg){
            TAUB_Simultaneous_Rewrite_Init(taub_channel,mode_arr[i].sim_cfg);
        }

        if(mode_arr[i].mas != 1)
            TAUB_Set_Channel_Output_Mode(taub_channel,mode_arr[i].ch_output_mode.taub_mode);
        channel_mask |= (0x01 << taub_channel);
    }

    __START_COUNTER(_TAUB0,channel_mask);

}

ErrorStatus TAUB_Simultaneous_Rewrite_Init(uint8_t channel_num,TAUB_SIMULREWR_CFG_TypeDef sim_cfg)
{
    uint16_t ret = 0;

    __ENABLE_RELOAD_DATA(_TAUB0,channel_num,TRUE,ret);
    if(ret) return ERROR;

    __SET_RELOAD_DATA_CTL_CH(_TAUB0,channel_num,sim_cfg.ch_ctl,ret);
    if(ret) return ERROR;

    __SET_RELAOD_DATA_MODE(_TAUB0,channel_num,sim_cfg.sig_gen,ret);
    if(ret) return ERROR;

    __SET_RELAOD_DATA_CTL(_TAUB0,channel_num,sim_cfg.is_trig_ch,ret);
    if(ret) return ERROR;

    __ENABLE_RELOAD_DATA_TRIGGER(_TAUB0,channel_num);

}

/**
  * @brief Set the TAUBnCMORm, controls channel m operation.
  * @param  mode: pointer to the TAUB_ChMode_TypeDef .
  * @retval ERROR: error occured, otherwise successfully
  */
ErrorStatus TAUB_Set_Channel_Mode(TAUB_ChMode_TypeDef *mode )
{
    __IO uint16_t ret_mode = 0;

    __SET_TAU_CMOR_CKS(_TAUB0,taub_channel,mode->clk_sel);
    __SET_TAU_CMOR_CCS0(_TAUB0,taub_channel,mode->cnt_clk4cnt_counter);

    __SET_TAU_CMOR_MAS(_TAUB0,taub_channel,mode->mas);

    if(mode->sts != TAU_STS_PROHIBITED)
        __SET_TAU_CMOR_STS(_TAUB0,taub_channel,mode->sts);

    if(mode->sts == TAU_STS_EDGE_TIN_TRIG){
        TAUB_Filter_Ctl_Operate(taub_channel);
        __SET_TAU_CMUR(_TAUB0,taub_channel,mode->tin_detect);
    }

    __SET_TAU_CMOR_COS(_TAUB0,taub_channel,mode->cos);

    if(mode->md_un.md_bits.high7bit == TAUB_MD_PROHIBITED1 ||
         mode->md_un.md_bits.high7bit == TAUB_MD_PROHIBITED2 )
         return ERROR;
    __SET_TAU_CMOR_MD(_TAUB0,taub_channel,mode->md_un.md);

    __GET_TAU_CMOR(_TAUB0,ret_mode,taub_channel);// for test

    return SUCCESS;
}

/*  channel output mode     TOE     TOM     TOC     TDE
 *  software mode           0       x       x       x
 *
 *  independent 1           1       0       0       0
 *  independent 2           1       0       1       0
 *  synchronous 1           1       1       0       0
 *  synchronous 2           1       1       1       0
 *synchronous 2 with dead   1       1       1       1
 */

void TAUB_Set_Channel_Output_Mode(uint8_t channel_num,TAUB_CH_OUTPUT_MODE_Type out_mode)
{
    __IO uint16_t ret = 0;
    __IO uint8_t tom = 0,toc = 0;

    if(out_mode   == TAUB_BY_SOFTWARE_MODE){
        __ENABLE_INDEPENDENT_OUTPUT(_TAUB0,channel_num,FALSE);
    }else{
        __ENABLE_INDEPENDENT_OUTPUT(_TAUB0,channel_num,TRUE);
        if(out_mode ==  TAUB_INDEPENDENT_OUTPUT_MODE_1){
            toc = 0;
        }else if(out_mode ==  TAUB_INDEPENDENT_OUTPUT_MODE_2){
            toc = 1;
        }else{ // TAUB_SYNCHRONOUS_OUTPUT_MODE_1 or TAUB_SYNCHRONOUS_OUTPUT_MODE_2
            tom = 1;
        }

        if(out_mode ==  TAUB_SYNCHRONOUS_OUTPUT_MODE_1){
            toc = 0;
        }

        if(out_mode ==  TAUB_SYNCHRONOUS_OUTPUT_MODE_2){
            toc = 1;
        }

        __SET_OUTPUT_MODE(_TAUB0,channel_num,tom,ret);//TOM
        __SET_OUTPUT_CONFIG(_TAUB0,channel_num,toc,ret);//TOC
    }
    __SET_OUTPUT_LEVEL(_TAUB0,channel_num,0,ret);
}

/* @brief -Set(Write) or Get(Read) filter control register  DNFA TAUB0ICTL
 * @param channel_num - the channel num defined in Table 6.10 , .....
 */
void TAUB_Filter_Ctl_Operate(uint8_t channel_num)
{
    __ENBALE_DIGITAL_NOISE_ELIMI(_TAUB0,channel_num,1);
}

/*************************TAUB defination end********************************/

/*************************TAUD defination start********************************/
void TAUD_Independent_Init(TAUD_ChMode_TypeDef *mode)
{
    __IO uint8_t i = 0;
    uint16_t channel_mask = 0x00;

    if(mode->ch_no / 16) return; //guarantee that taud_channel is [0,15]
    taud_channel = mode->ch_no;

    //Set the TAUDnTPS register to specify the clock frequency of CK0 to CK3.
    for(;i <= (uint8_t)TAU_CK3;i++)
        __SET_TAU_PRESCALER(_TAUD0,_TAUD0_PRSn_OFFSET(i),mode->clk_div);


    if(TAUD_Set_Channel_Mode(mode) == ERROR){
        while(1){};
    }

    __SET_TAU_CDR(_TAUD0,taud_channel,mode->cdr);

    channel_mask |= 0x01 << taud_channel;
    __START_COUNTER(_TAUD0,channel_mask);
}

void TAUD_Batch_Init(TAUD_ChMode_TypeDef mode_arr[],uint8_t size)
{
    uint8_t i = 0;
    uint16_t channel_mask = 0x00;

    for(;i <= (uint8_t)TAU_CK3;i++)
        __SET_TAU_PRESCALER(_TAUD0,_TAUD0_PRSn_OFFSET(i),mode_arr[i].clk_div);// 40M/16 = 2500 --- 1ms

    for(i = 0;i< size;i++){
        if(mode_arr[i].ch_no / 16) continue;
        taud_channel = mode_arr[i].ch_no;

        if(TAUD_Set_Channel_Mode(&mode_arr[i]) == ERROR){
            while(1){};
        }
        __SET_TAU_CDR(_TAUD0,taud_channel,mode_arr[i].cdr);

        if(mode_arr[i].enable_sim_cfg){
            TAUD_Simultaneous_Rewrite_Init(taud_channel,mode_arr[i].sim_cfg);
        }

        if(mode_arr[i].mas != 1)
            TAUD_Set_Channel_Output_Mode(taud_channel,mode_arr[i].ch_output_mode.taud_mode);
            if(taud_channel == 1)
                __SET_TAUD_TRIGGER_CHANNEL(taud_channel,1);
            else
                __SET_TAUD_TRIGGER_CHANNEL(taud_channel,0);

        channel_mask |= (0x01 << taud_channel);
    }

    __START_COUNTER(_TAUD0,channel_mask);

}

ErrorStatus TAUD_Simultaneous_Rewrite_Init(uint8_t channel_num,TAUD_SIMULREWR_CFG_TypeDef sim_cfg)
{
    uint16_t ret = 0;

    __ENABLE_RELOAD_DATA(_TAUD0,channel_num,TRUE,ret);
    if(ret) return ERROR;

    __SET_RELOAD_DATA_CTL_CH(_TAUD0,channel_num,sim_cfg.ch_ctl,ret);
    if(ret) return ERROR;

    __SET_RELAOD_DATA_MODE(_TAUD0,channel_num,sim_cfg.sig_gen,ret);
    if(ret) return ERROR;

    __SET_RELAOD_DATA_CTL(_TAUD0,channel_num,sim_cfg.is_trig_ch,ret);
    if(ret) return ERROR;

    __ENABLE_RELOAD_DATA_TRIGGER(_TAUB0,channel_num);

}

/**
  * @brief Set the TAUDnCMORm, controls channel m operation.
  * @param  mode: pointer to the TAUD_ChMode_TypeDef .
  * @retval ERROR: error occured, otherwise successfully
  */
ErrorStatus TAUD_Set_Channel_Mode(TAUB_ChMode_TypeDef *mode )
{
    __IO uint16_t ret_mode = 0;

    __SET_TAU_CMOR_CKS(_TAUD0,taud_channel,mode->clk_sel);
    __SET_TAU_CMOR_CCS0(_TAUD0,taud_channel,mode->cnt_clk4cnt_counter);

    __SET_TAU_CMOR_MAS(_TAUD0,taud_channel,mode->mas);

    if(mode->sts != TAU_STS_PROHIBITED)
        __SET_TAU_CMOR_STS(_TAUD0,taud_channel,mode->sts);
    if(mode->sts == TAU_STS_EDGE_TIN_TRIG){
        TAUD_Filter_Ctl_Operate(taud_channel);
        __SET_TAU_CMUR(_TAUD0,taud_channel,mode->tin_detect);
    }

    __SET_TAU_CMOR_COS(_TAUD0,taud_channel,mode->cos);

    if(mode->md_un.md_bits.high7bit == TAUD_MD_PROHIBITED1 ||
         mode->md_un.md_bits.high7bit == TAUD_MD_PROHIBITED2 )
         return ERROR;
    __SET_TAU_CMOR_MD(_TAUD0,taud_channel,mode->md_un.md);

    __GET_TAU_CMOR(_TAUD0,ret_mode,taud_channel);// for test

    return SUCCESS;
}


void TAUD_Set_Channel_Output_Mode(uint8_t channel_num,TAUD_CH_OUTPUT_MODE_Type out_mode)
{
    __IO uint16_t ret = 0;
    __IO uint8_t tom = 0,toc = 0,tde = 0,tre = 0,tme = 0,tdm = 0;
    __IO bool toe = TRUE;//default true

    switch(out_mode)
    {
        case TAUD_BY_SOFTWARE_MODE:
            toe = FALSE;
            break;
        case TAUD_INDEPENDENT_OUTPUT_MODE_1:
            break;
        case TAUD_INDEPENDENT_OUTPUT_MODE_1_WITH_REAL_TIME:
            tre = 1;
            break;
        case TAUD_INDEPENDENT_OUTPUT_MODE_2:
            toc =1;
            break;
        case TAUD_SYNCHRONOUS_OUTPUT_MODE_1:
            tom =1;
            break;
        case TAUD_SYNCHRONOUS_OUTPUT_MODE_1_WITH_NON_COMP://with non-complementary modulation output
            tom = 1;
            tre = 1;
            break;
        case TAUD_SYNCHRONOUS_OUTPUT_MODE_2:
            tom =1;
            toc =1;
            break;
        case TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_ONE_PHASE://with one-phase PWM output
            tdm = 1;
        case TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_DEAD_TIME://with dead time output
            tom = 1;
            toc = 1;
            tde = 1;
            break;
        case TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_COMP://with complementary modulation output
            tde = 1;
        case TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_NON_COMP://with non-complementary modulation output
            tom = 1;
            toc = 1;
            tre = 1;
            tme = 1;
            break;
        default:
            break;
    }
    __ENABLE_INDEPENDENT_OUTPUT(_TAUD0,channel_num,toe);//TOE
    __SET_OUTPUT_MODE(_TAUD0,channel_num,tom,ret);//TOM
    __SET_OUTPUT_CONFIG(_TAUD0,channel_num,toc,ret);//TOC
    __ENABLE_DEAD_TIME(_TAUD0,channel_num,tde);//TDE
    __ENABLE_TAUD_REAL_TIME_OUTPUT(channel_num,tre);//TRE
    __ENABEL_TAUD_MODULATION_OUTPUT(channel_num,tme);//TME
    __SET_TAUD_TIME_ADD_DEAD_TIME(channel_num,tdm);//TDM
    __SET_TAUD_LEVEL_TO_TOUT(channel_num,0);//TRO
}


/* @brief -Set(Write) or Get(Read) filter control register  DNFA TAUD0ICTL
 * @param channel_num - the channel num defined in Table 6.10 , .....
 */
void TAUD_Filter_Ctl_Operate(uint8_t channel_num)
{
    __ENBALE_DIGITAL_NOISE_ELIMI(_TAUD0,channel_num,1);
}
/*************************TAUD defination end********************************/
