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

#define RTCAnCE_MASK        ((uint8_t)0x01 << 7)
#define RTCAnCEST_MASK      ((uint8_t)0x01 << 6)
#define RTCAnAMPM_MASK      ((uint8_t)0x01 << 5)
#define RTCAnSLSB_MASK      ((uint8_t)0x01 << 4)

#define RTCAnEN1HZ_MASK     ((uint8_t)0x01 << 5)
#define RTCAnENALM_MASK     ((uint8_t)0x01 << 4)
#define RTCAnEN1S_MASK      ((uint8_t)0x01 << 3)

/*Starts/stops the sub-counter RTCAnSUBC operation*/
#define __RTCA_ENABLE_SUB_COUNTER()         SET_BIT(_RTCA0_BASE.CTL0, RTCAnCE_MASK)
#define __RTCA_DISABLE_SUB_COUNTER()        CLEAR_BIT(_RTCA0_BASE.CTL0, RTCAnCE_MASK)

/*Get the operation enabled/stopped status of the sub-counter*/
#define __RTCA_GET_SUB_COUNTER_STAT()       READ_BIT(_RTCA0_BASE.CTL0,RTCAnCEST_MASK)

/*Selects the format of the hours counter RTCAnHOURC and the alarm hour
 *setting register RTCAnALH*/
#define __RTCA_SELECT_HOUR_FORMAT(_FORMAT_)     do{ \
                                                    if(_FORMAT_) \
                                                        SET_BIT(_RTCA0_BASE.CTL0, RTCAnAMPM_MASK); \
                                                    else \
                                                        CLEAR_BIT((_RTCA0_BASE.CTL0, RTCAnAMPM_MASK); \
                                                }while(0)
/*Selects the operation mode:
  0: 32.768 kHz mode 1: Frequency selection mode*/
#define __RTCA_SET_OPERATE_MODE(_MODE_)         do{ \
                                                    if(_MODE_) \
                                                        SET_BIT(_RTCA0_BASE.CTL0, RTCAnSLSB_MASK); \
                                                    else \
                                                        CLEAR_BIT((_RTCA0_BASE.CTL0, RTCAnSLSB_MASK); \
                                                }while(0)

/*Enables/stops 1-Hz pulse output (RTCAT1HZ):*/
#define __RTCA_ENABLE_1HZ_PULSE_OUTPUT()        SET_BIT(_RTCA0_BASE.CTL1, RTCAnEN1HZ_MASK)
#define __RTCA_DISABLE_1HZ_PULSE_OUTPUT()       CLEAR_BIT(_RTCA0_BASE.CTL1, RTCAnEN1HZ_MASK)

/*Enables/disables alarm interrupt request generation (RTCATINTAL*/
#define __RTCA_ENABLE_ALARM_INT()               SET_BIT(_RTCA0_BASE.CTL1, RTCAnENALM_MASK)
#define __RTCA_DISABLE_ALARM_INT()              CLEAR_BIT(_RTCA0_BASE.CTL1, RTCAnENALM_MASK)

/*Enables/disables 1-second interrupt request generation (RTCATINT1S)*/
#define __RTCA_ENABLE_1S_INT()                  SET_BIT(_RTCA0_BASE.CTL1, RTCAnEN1S_MASK)
#define __RTCA_DISABLE_1S_INT()                 CLEAR_BIT(_RTCA0_BASE.CTL1, RTCAnEN1S_MASK)





#endif //RH850F1L_RTC_H
