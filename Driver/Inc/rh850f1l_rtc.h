/**
  ******************************************************************************
  * @file    rh850f1l_rtc.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    19-January-2018
  * @brief   Header file of Real-Time Clock Registers module.
  ******************************************************************************
  */

#ifndef RH850F1L_RTC_H
#define RH850F1L_RTC_H

#include "rh850f1l.h"

#define _RTCA0_BASE     RTCA0
#define _CTL0		    CTL0.UINT8
#define _CTL1		    CTL1.UINT8
#define _CTL2		    CTL2.UINT8

#define RTCAnCE_MASK        ((uint8_t)0x01 << 7)
#define RTCAnCEST_MASK      ((uint8_t)0x01 << 6)
#define RTCAnAMPM_MASK      ((uint8_t)0x01 << 5)
#define RTCAnSLSB_MASK      ((uint8_t)0x01 << 4)

#define RTCAnEN1HZ_MASK     ((uint8_t)0x01 << 5)
#define RTCAnENALM_MASK     ((uint8_t)0x01 << 4)
#define RTCAnEN1S_MASK      ((uint8_t)0x01 << 3)
#define RTCAnCT_MASK        ((uint8_t)0x07)

#define RTCAnWUST_MASK      ((uint8_t)0x01 << 5)
#define RTCAnWSST_MASK      ((uint8_t)0x01 << 4)
#define RTCAnRSST_MASK      ((uint8_t)0x01 << 3)
#define RTCAnRSUB_MASK      ((uint8_t)0x01 << 2)
#define RTCAnWST_MASK       ((uint8_t)0x01 << 1)
#define RTCAnWAIT_MASK      ((uint8_t)0x01)

/************************************CTL0***************************************/
/*Starts/stops the sub-counter RTCAnSUBC operation*/
#define __RTCA_ENABLE_SUBCOUNTER()          SET_BIT(&(_RTCA0_BASE._CTL0), RTCAnCE_MASK)
#define __RTCA_DISABLE_SUBCOUNTER()         CLEAR_BIT(&(_RTCA0_BASE._CTL0), RTCAnCE_MASK)

/*Get the operation enabled/stopped status of the sub-counter*/
#define __RTCA_GET_SUBCOUNTER_STAT()        READ_BIT(&(_RTCA0_BASE._CTL0),RTCAnCEST_MASK)

/*Selects the format of the hours counter RTCAnHOURC and the alarm hour
 *setting register RTCAnALH*/
#define __RTCA_SET_HOUR_FORMAT(_FORMAT_)        do{ \
                                                    if(_FORMAT_) \
                                                        SET_BIT(&(_RTCA0_BASE._CTL0), RTCAnAMPM_MASK); \
                                                    else \
                                                        CLEAR_BIT(&(_RTCA0_BASE._CTL0), RTCAnAMPM_MASK); \
                                                }while(0)

#define __RTCA_GET_HOUR_FORMAT()                (_RTCA0_BASE._CTL0 & RTCAnAMPM_MASK)
/*Selects the operation mode:
  0: 32.768 kHz mode 1: Frequency selection mode*/
#define __RTCA_SET_OPERATE_MODE(_MODE_)         do{ \
                                                    if(_MODE_) \
                                                        SET_BIT(&(_RTCA0_BASE._CTL0), RTCAnSLSB_MASK); \
                                                    else \
                                                        CLEAR_BIT(&(_RTCA0_BASE._CTL0), RTCAnSLSB_MASK); \
                                                }while(0)

#define __RTCA_GET_OPERATE_MODE()         (_RTCA0_BASE._CTL0 & RTCAnSLSB_MASK)

/************************************CTL1***************************************/
/*Enables/stops 1-Hz pGulse output (RTCAT1HZ):*/
#define __RTCA_ENABLE_1HZ_PULSE_OUTPUT()        SET_BIT(&(_RTCA0_BASE._CTL1), RTCAnEN1HZ_MASK)
#define __RTCA_DISABLE_1HZ_PULSE_OUTPUT()       CLEAR_BIT(&(_RTCA0_BASE._CTL1), RTCAnEN1HZ_MASK)

/*Enables/disables alarm interrupt request generation (RTCATINTAL*/
#define __RTCA_ENABLE_ALARM_INT()               SET_BIT(&(_RTCA0_BASE._CTL1), RTCAnENALM_MASK)
#define __RTCA_DISABLE_ALARM_INT()              CLEAR_BIT(&(_RTCA0_BASE._CTL1), RTCAnENALM_MASK)

/*Enables/disables 1-second interrupt request generation (RTCATINT1S)*/
#define __RTCA_ENABLE_1S_INT()                  SET_BIT(&(_RTCA0_BASE._CTL1), RTCAnEN1S_MASK)
#define __RTCA_DISABLE_1S_INT()                 CLEAR_BIT(&(_RTCA0_BASE._CTL1), RTCAnEN1S_MASK)

/*Specifies the fixed interval interrupt request (RTCATINTR) setting*/
#define __RTCA_SET_FIXED_INTERVAL(_INTERVAL_)   SET_BIT(&(_RTCA0_BASE._CTL1), _INTERVAL_ & RTCAnCT_MASK)

/************************************CTL2***************************************/
#define __RTCA_Get_SUBU_WRITE_STAT()            (_RTCA0_BASE._CTL2 & RTCAnWUST_MASK)
#define __RTCA_Get_SCMP_WRITE_STAT()            (_RTCA0_BASE._CTL2 & RTCAnWSST_MASK)
#define __RTCA_GET_TRANSFER_COMPLETE_STAT()     (_RTCA0_BASE._CTL2 & RTCAnRSST_MASK)
#define __RTCA_GET_TRANSFER_TRIGGER_STAT()      (_RTCA0_BASE._CTL2 & RTCAnRSUB_MASK)
#define __RTCA_ENABLE_TRANSFER_TRIGGER()        SET_BIT(&(_RTCA0_BASE._CTL2),RTCAnRSUB_MASK)
#define __RTCA_GET_ALL_COUNTER_STAT()           (_RTCA0_BASE._CTL2 & RTCAnWST_MASK)
#define __RTCA_RESTART_ALL_COUNTER()            CLEAR_BIT(&(_RTCA0_BASE._CTL2),RTCAnWAIT_MASK)
#define __RTCA_STOP_ALL_COUNTER()               SET_BIT(&(_RTCA0_BASE._CTL2),RTCAnWAIT_MASK)


/*Sub-counter value.The sub-counter only operates while RTCAnCTL0.RTCAnCEST = 1.*/
#define __RTCA_GET_SUBCOUNTER_VALUE()           (_RTCA0_BASE.SUBC & 0x3FFFFF)
/*Get the sub-counter value at the time of the last RTCAnSUBC read*/
#define __RTCA_GET_SUBCOUNTER_READ_BUFFER()     (_RTCA0_BASE.SRBU & 0x3FFFFF)

/*Set or get the sub-counter compare value in frequency selection mode*/
#define __RTCA_SET_SUBCOUNTER_CMP(_VALUE_)      SET_BIT(&(_RTCA0_BASE.SCMP), _VALUE_ & 0x3FFFFF)
#define __RTCA_GET_SUBCOUNTER_CMP()             (_RTCA0_BASE.SCMP & 0x3FFFFF)

/* When writing register or bits about hour, only the following decimal values in BCD are allowed:
 * 12-hour format (RTCAnCTL0.RTCAnAMPM = 0): 01 to 12 or 21 to 32
 * 24-hour format (RTCAnCTL0.RTCAnAMPM = 1):00 to 23
 */
#define IS_HOUR_VALUE(_VALUE_)  do{ \
                                    uint8_t hour_format = __RTCA_GET_HOUR_FORMAT(); \
                                    if(hour_format && _VALUE_ > 23) return -1; \
                                    if(!hour_format && (_VALUE_ < 1 ||(_VALUE_ > 12 && _VALUE_ < 21) || _VALUE_ >32)) \
                                        return -1; \
                                }while(0)
typedef enum{
    RTCA_NO_INT_GENERATE,	//No interrupt request generation
    RTCA_EVERY_250MS,		//Every 0.25, 0.5, 0.75 and 1 second
    RTCA_EVERY_500MS,		//Every 0.5 and 1 second
    RTCA_EVERY_1SEC,		//Every 1 second
    RTCA_EVERY_1MIN,		//Every 1 minute 00 seconds
    RTCA_EVERY_1HOUR,		//Every 1 hour 00 minutes 00 seconds
    RTCA_EVERY_1DAY,		//Every 1 day 00 hours 00 minutes 00 seconds
    RTCA_EVERY_1MON,		//Every 1 month first day 00 hours 00 minutes 00 seconds
}RTCA_FIXED_INTERVAL_Type;

typedef enum{
    RTCA_SEC_COUNT,
    RTCA_MIN_COUNT,
    RTCA_HOUR_COUNT,
    RTCA_WEEK_COUNT,
    RTCA_DAY_COUNT,
    RTCA_MON_COUNT,
    RTCA_YEAR_COUNT,
}RTCA_CLOCK_COUNTER_Type;

typedef enum{
    RTCA_MIN_ALARM_TIME,
    RTCA_HOUR_ALARM_TIME,
    RTCA_WEEK_ALARM_TIME,
}RTCA_ALARM_TIME_Type;

typedef union {
    uint8_t err_correct;
    struct{
        uint8_t times_per_min:1;//Specifies how often clock error correction is performed per minute
        uint8_t decre:1;//Specifies whether the sub-counter value is incremented or decremented
        uint8_t correct_val:6;//Error correction value
    }correct_struct;
}RTCA_CLK_ERR_CORRECTION_Union;

typedef struct{
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
}RTCA_TIME_TypeDef;

typedef struct{
    uint8_t weekday;
    uint8_t day;
    uint8_t month;
    uint8_t year;
}RTCA_CALENDAR_TypeDef;

typedef struct{
    RTCA_TIME_TypeDef time;
    RTCA_CALENDAR_TypeDef calendar;
}RTCA_TIME_CAL_TypeDef;

typedef struct{
    RTCA_TIME_CAL_TypeDef time_cal;
    RTCA_CLK_ERR_CORRECTION_Union err_correct;
    uint32_t cmp_val;
}RTCA_INIT_TypeDef,RTCA_UPDATE_TypeDef;


void RTCA_Init(RTCA_INIT_TypeDef Rtca_InitStruct);

#endif //RH850F1L_RTC_H
