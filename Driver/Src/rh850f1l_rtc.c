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

#define __RTCA_RW_BUFFER_BEGIN()    do{ \
                                        /*Check that the previous write or read operation is complete*/ \
                                        while(__RTCA_GET_ALL_COUNTER_STAT());   \
                                                                                \
                                        __RTCA_STOP_ALL_COUNTER();/*Stop all clock counters */\
                                                                                \
                                        /*Wait until the corresponding status flag is set and all clock counters have stopped*/ \
                                        while(__RTCA_GET_ALL_COUNTER_STAT() == 0); \
                                    }while(0)

#define __RTCA_RW_BUFFER_END()      __RTCA_RESTART_ALL_COUNTER()/*Restart all clock counters*/



static int8_t RTCA_Set_Operate_Mode(uint8_t opt_mode);

static RTCA_TIME_CAL_TypeDef RTCA_Read_Count(void);

RTCA_TIME_CAL_TypeDef RTCA_Read_Count_Buffer(void);

int8_t RTCA_Write_Count_Buffer( RTCA_TIME_CAL_TypeDef *timew);

RTCA_TIME_TypeDef RTCA_Read_Time_Count(void);

RTCA_TIME_TypeDef RTCA_Read_Time_Count_Buffer(void);

int8_t RTCA_Write_Time_Count_Buffer(RTCA_TIME_TypeDef *timew);

RTCA_CALENDAR_TypeDef RTCA_Read_Calendar_Count(void);

RTCA_CALENDAR_TypeDef RTCA_Read_Calendar_Count_Buffer(void);

int8_t RTCA_Write_Calendar_Count_Buffer(RTCA_CALENDAR_TypeDef *calw);

int8_t RTCA_Get_Alarm_Time(RTCA_ALARM_TIME_Type alarm_time);

int8_t RTCA_Set_Alarm_Time(RTCA_ALARM_TIME_Type alarm_time,uint8_t val);

void RTCA_Set_Clock_Error_Correction(RTCA_CLK_ERR_CORRECTION_Union un, bool rewrite);

void RTCA_Set_SubCnt_Compare(uint32_t cmp_val, bool rewrite);

void RTCA_Update_Counter(RTCA_UPDATE_TypeDef Rtca_UpdateStruct);

void RTCA_Read_SubCnt_Buffer(void);



void RTCA_Init(RTCA_INIT_TypeDef Rtca_InitStruct)
{
    __RTCA_SET_HOUR_FORMAT(0);//12-hour format (1 to 12, am/pm)
    if(RTCA_Set_Operate_Mode(0)) return ;//0: 32.768 kHz mode

    if(__RTCA_GET_OPERATE_MODE() == 0)
        RTCA_Set_Clock_Error_Correction(Rtca_InitStruct.err_correct,0);//Set clock error-correction parameters
    else
        RTCA_Set_SubCnt_Compare(Rtca_InitStruct.cmp_val,0);//Set sub-counter overflow value (RTCATCKI - 1 in Hz)

    /*Write start values to the count buffer registers*/
    RTCA_Write_Count_Buffer(&Rtca_InitStruct.time_cal);
    __RTCA_ENABLE_1S_INT();
    __RTCA_ENABLE_SUBCOUNTER();
}


int8_t RTCA_Set_Operate_Mode(uint8_t opt_mode)
{
    uint8_t sub_cnt_stat = 0;
    sub_cnt_stat = __RTCA_GET_SUBCOUNTER_STAT();

    //The operation mode must not be changed while
    //sub-counter operation is enabled (RTCAnCTL0.RTCAnCEST = 1).
    if(sub_cnt_stat) return -1;

    __RTCA_SET_OPERATE_MODE(opt_mode);

    return 0;
}

/* @brief - Reading counter registers directly
 * @param - none
 * @retval timer - the struct hold the values read from the registers
 */
RTCA_TIME_CAL_TypeDef RTCA_Read_Count(void)
{
    int16_t  pre_count = 0, cur_count = 1;
    RTCA_TIME_CAL_TypeDef timer;

    /*Check that the previous write or read operation is complete.*/
    while(__RTCA_GET_ALL_COUNTER_STAT());

    while(pre_count != cur_count){
        pre_count = _RTCA0_BASE.SECC & 0x7F;//Read RTCAnSECC 1st time
        /*Read the clock counters*/
        timer.time.second = _RTCA0_BASE.SECC & 0x7F;
        timer.time.minute = _RTCA0_BASE.MINC & 0x7F;
        timer.time.hour = _RTCA0_BASE.HOURC & 0x3F;
        timer.calendar.weekday = _RTCA0_BASE.WEEKC & 0x03;
        timer.calendar.day = _RTCA0_BASE.DAYC & 0x3F;
        //timer.calendar.month _RTCA0_BASE.MONC & 0x1F;
        timer.calendar.year = _RTCA0_BASE.YEARC & 0xFF;
        /*Read RTCAnSECC 2nd time*/
        cur_count = _RTCA0_BASE.SECC & 0x7F;
    }

    return timer;
}

/* @brief - Reading count buffer registers following specified operations
 * @param - none
 * @retval timer - the struct hold the values read from the registers
 */
RTCA_TIME_CAL_TypeDef RTCA_Read_Count_Buffer(void)
{
    RTCA_TIME_CAL_TypeDef timer;

    __RTCA_RW_BUFFER_BEGIN();

    /*Read the clock counters*/
    timer.time.second = _RTCA0_BASE.SEC & 0x7F;
    timer.time.minute = _RTCA0_BASE.MIN & 0x7F;
    timer.time.hour = _RTCA0_BASE.HOUR & 0x3F;
    timer.calendar.weekday = _RTCA0_BASE.WEEK & 0x03;
    timer.calendar.day = _RTCA0_BASE.DAY & 0x3F;
    timer.calendar.month =  _RTCA0_BASE.MONTH & 0x1F;
    timer.calendar.year = _RTCA0_BASE.YEAR & 0xFF;

    __RTCA_RW_BUFFER_END();

    return timer;
}

int8_t RTCA_Write_Count_Buffer( RTCA_TIME_CAL_TypeDef *timew)
{
    if(timew->time.second > 59) return -1;
    _RTCA0_BASE.SEC = timew->time.second & 0x7F;

    if(timew->time.minute > 59) return -1;
    _RTCA0_BASE.MIN = timew->time.minute & 0x7F;

    IS_HOUR_VALUE(timew->time.hour);
    _RTCA0_BASE.HOUR = timew->time.hour & 0x3F;

    if(timew->calendar.weekday > 6) return -1;
    _RTCA0_BASE.WEEK = timew->calendar.weekday & 0x03;

    if(timew->calendar.day < 1 || timew->calendar.day > 31) return -1;
    _RTCA0_BASE.DAY = timew->calendar.day & 0x3F;

    if(timew->calendar.month < 1 || timew->calendar.month > 12) return -1;
    _RTCA0_BASE.MONTH = timew->calendar.month & 0x1F;

    if(timew->calendar.year > 99) return -1;
    _RTCA0_BASE.YEAR = timew->calendar.year & 0xFF;

    return 0;
}

RTCA_TIME_TypeDef RTCA_Read_Time_Count(void)
{
    int16_t  pre_count = 0, cur_count = 1;
    RTCA_TIME_TypeDef timer;

    while(pre_count != cur_count){
        pre_count = _RTCA0_BASE.SECC & 0x7F;//Read RTCAnSECC 1st time
        timer.second = _RTCA0_BASE.TIMEC & 0x7F;
        timer.minute = _RTCA0_BASE.TIMEC >> 8 & 0x7F;
        timer.hour = _RTCA0_BASE.TIMEC >> 16 & 0x3F;
        /*Read RTCAnSECC 2nd time*/
        cur_count = _RTCA0_BASE.SECC & 0x7F;
    }

    return timer;
}

RTCA_TIME_TypeDef RTCA_Read_Time_Count_Buffer(void)
{
    RTCA_TIME_TypeDef timer;

    __RTCA_RW_BUFFER_BEGIN();

    timer.second = _RTCA0_BASE.TIME & 0x7F;
    timer.minute = _RTCA0_BASE.TIME >> 8 & 0x7F;
    timer.hour = _RTCA0_BASE.TIME >> 16 & 0x3F;

    __RTCA_RW_BUFFER_END();

    return timer;
}

int8_t RTCA_Write_Time_Count_Buffer(RTCA_TIME_TypeDef *timew)
{
    if(timew->second > 59) return -1;
    MODIFY_REG(&(_RTCA0_BASE.TIME), 0x7F, timew->second & 0x7F);

    if(timew->minute > 59) return -1;
    MODIFY_REG(&(_RTCA0_BASE.TIME), 0x7F << 8, (timew->minute & 0x7F) << 8);

    IS_HOUR_VALUE(timew->hour);
    MODIFY_REG(&(_RTCA0_BASE.TIME), 0x7F << 16, (timew->hour & 0x7F) << 16);

    return 0;
}

RTCA_CALENDAR_TypeDef RTCA_Read_Calendar_Count(void)
{
    int16_t  pre_count = 0, cur_count = 1;
    RTCA_CALENDAR_TypeDef calr;

    while(pre_count !=cur_count){
        pre_count = _RTCA0_BASE.SECC & 0x7F;//Read RTCAnSECC 1st time
        calr.weekday = _RTCA0_BASE.CALC & 0x03;
        calr.day = (_RTCA0_BASE.CALC >> 8) & 0x3F;
        calr.month = (_RTCA0_BASE.CALC >> 16) & 0x1F;
        calr.year = (_RTCA0_BASE.CALC >> 24) & 0xFF;

	/*Read RTCAnSECC 2nd time*/
        cur_count = _RTCA0_BASE.SECC & 0x7F;
    }

    return calr;
}

RTCA_CALENDAR_TypeDef RTCA_Read_Calendar_Count_Buffer(void)
{
    RTCA_CALENDAR_TypeDef calr;

    __RTCA_RW_BUFFER_BEGIN();

    calr.weekday = _RTCA0_BASE.CAL & 0x03;
    calr.day = _RTCA0_BASE.CAL >> 8 & 0x3F;
    calr.month = _RTCA0_BASE.CAL >> 16 & 0x1F;
    calr.year = _RTCA0_BASE.CAL >> 24 & 0xFF;

    __RTCA_RW_BUFFER_END();

    return calr;
}

int8_t RTCA_Write_Calendar_Count_Buffer(RTCA_CALENDAR_TypeDef *calw)
{
    if(calw->weekday > 6) return -1;
    MODIFY_REG(&(_RTCA0_BASE.CAL), 0x03, calw->weekday & 0x03);

    if(calw->day < 1 || calw->day > 31) return -1;
    MODIFY_REG(&(_RTCA0_BASE.CAL), 0x3F << 8 , (calw->day & 0x3F) << 8);

    if(calw->month < 1 || calw->month > 12) return -1;
    MODIFY_REG(&(_RTCA0_BASE.CAL), 0x1F << 16, (calw->month & 0x1F) << 16);

    if(calw->year > 99) return -1;
    MODIFY_REG(&(_RTCA0_BASE.CAL), 0xFF << 24, (calw->year & 0xFF) >> 24);

    return 0;
}


int8_t RTCA_Get_Alarm_Time(RTCA_ALARM_TIME_Type alarm_time)
{
    int8_t count = -1;
    if(alarm_time == RTCA_MIN_ALARM_TIME){
        count = _RTCA0_BASE.ALM & 0x7F;
    }else if(alarm_time == RTCA_HOUR_ALARM_TIME){
        count = _RTCA0_BASE.ALH & 0x3F;
    }else if(alarm_time == RTCA_WEEK_ALARM_TIME){
        count = _RTCA0_BASE.ALW & 0x7F;
    }
    return count;
}

int8_t RTCA_Set_Alarm_Time(RTCA_ALARM_TIME_Type alarm_time,uint8_t val)
{
    if(alarm_time == RTCA_MIN_ALARM_TIME){
        if(val > 59) return -1;
        _RTCA0_BASE.ALM = val;
    }else if(alarm_time == RTCA_HOUR_ALARM_TIME){
        IS_HOUR_VALUE(val);
        _RTCA0_BASE.ALH = val;
    }else if(alarm_time == RTCA_WEEK_ALARM_TIME){
        if(val > 6) return -1;
        _RTCA0_BASE.ALW |= 0x01 << val;
    }

    return RTCA_Get_Alarm_Time(alarm_time);
}
/*Writing to RTCAnSUBU*/
void RTCA_Set_Clock_Error_Correction(RTCA_CLK_ERR_CORRECTION_Union un, bool rewrite)
{
    /*Check that sub-counter is operating*/
    while(rewrite &&__RTCA_GET_SUBCOUNTER_STAT() == 0);
    /*and Wait until the previous write to RTCAnSUBU has been completed*/
    while(__RTCA_Get_SUBU_WRITE_STAT() == 1);

    _RTCA0_BASE.SUBU = un.err_correct;//Rewrite RTCAnSUBU
}

/*Writing to RTCAnSCMP*/
void RTCA_Set_SubCnt_Compare(uint32_t cmp_val, bool rewrite)
{
    /*Check that sub-counter is operating */
    while(rewrite && __RTCA_GET_SUBCOUNTER_STAT() == 0);

    /*Wait until the previous write to RTCAnSCMP has been completed*/
    while(__RTCA_Get_SCMP_WRITE_STAT() == 1);

    __RTCA_SET_SUBCOUNTER_CMP(cmp_val);//Rewrite RTCAnSCMP
}

void RTCA_Update_Counter(RTCA_UPDATE_TypeDef Rtca_UpdateStruct)
{
    __RTCA_RW_BUFFER_BEGIN();

    __RTCA_SET_HOUR_FORMAT(0);//Select 12-hour or 24-hour format

    /*Write start values to the count buffer registers*/
    RTCA_Write_Count_Buffer(&Rtca_UpdateStruct.time_cal);

    __RTCA_RW_BUFFER_END();
}
/*Reading RTCAnSRBU*/
void RTCA_Read_SubCnt_Buffer(void)
{
    /*Wait until previous read operation to RTCAnSRBU is completed*/
    while(__RTCA_GET_TRANSFER_COMPLETE_STAT());

    __RTCA_ENABLE_TRANSFER_TRIGGER();

    while(__RTCA_GET_TRANSFER_COMPLETE_STAT() == 0);

    __RTCA_GET_SUBCOUNTER_READ_BUFFER();

}
