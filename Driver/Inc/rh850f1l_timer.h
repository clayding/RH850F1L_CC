/**
  ******************************************************************************
  * @file    rh850f1l_timer.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of Timer Registers module.
  ******************************************************************************
  */

#ifndef RH850F1L_TIMER_H
#define RH850F1L_TIMER_H
#include "rh850f1l.h"

 typedef enum{
     OSTM_INTERVAL_MODE,//Interval timer mode
     OSTM_COMPARE_MODE, // Free-run compare mode
 }OSTM_OPERATE_MODE_Type;

 typedef enum{
     OSTM_START_INT_DISABLE,
     OSTM_START_INT_ENABLE = !OSTM_START_INT_DISABLE,
 }OSTM_START_INT_STAT_Type;


 tyepdef enum{
     TAUB_CK0,TAUB_CK1,TAUB_CK2,TAUB_CK3,
 }TAUB_CLK_SEL_Type;

 tyepdef enum{
     TAUB_MAS_MASTER,
     TAUB_MAS_SLAVE,
 }TAUB_MAS_Type;

 typedef enum{
     TAUB_STS_SW_TRIG,//Software trigger
     TAUB_STS_EDGE_TIN_TRIG,//Valid edge of the TAUBTTINm input signal

     /*Valid edge of the TAUBTTINm input signal is used as the start trigger and
     the reverse edge is used as the stop trigger.*/
     TAUB_STS_EDGE_TIN_TRIG2,

     TAUB_STS_INT_TRIG_MASTER,//INTTAUBnIm is the start trigger of the master channel

     /*INTTAUBnIm of upper channel (m – 1) is the start trigger regardless of master setting*/
     TAUB_STS_UPPER_INT_TRIG_MASTER,

     /*Dead-time output signal of the TAUBTTOUTm generation unit*/
     TAUB_STS_DEAD_TIME_SIG,

     /*Up/down output trigger signal of the master channel.*/
     TAUB_UP_DOWN_TRIG,
 }TAUB_STS_Type;

//the operation mode TAUBnMD[4:1]
#define TAUB_INTERVAL_MODE      (0 << 1) //Interval timer mode
#define TAUB_JUD_MODE           (1 << 1) //Judge mode
#define TAUB_CAP_MODE,          (2 << 1) //Capture mode
#define TAUB_EVET_CNT_MODE      (3 << 1) //Event count mode
#define TAUB_ONE_CNT_MODE       (4 << 1) //One-count mode
#define TAUB_CAP_ONECNT_MODE    (6 << 1) //Capture and one-count mode
#define TAUB_JUD_ONECNT_MODE,   (7 << 1) //Judge and one-count mode
#define TAUB_CNT_UPDOWN_MODE,   (9 << 1) //Count-up/-down mode
#define TAUB_PUL_ONECNT_MODE,   (10 << 1)//Pulse one-count mode
#define TAUB_CNT_CAP_MODE,      (11 << 1)//Count capture mode
#define TAUB_GATE_CNT_MODE,     (12 << 1)//Gate count mode
#define TAUB_CAP_GATECNT_MODE,  (13 << 1)//Capture and gate count mode

 #define IS_TAUB_OPT_MODE(_MODE_)   ((_MODE_ == TAUB_INTERVAL_MODE) ||
                                     (_MODE_ == TAUB_JUD_MODE) ||
                                     (_MODE_ == TAUB_CAP_MODE) ||
                                     (_MODE_ == TAUB_EVET_CNT_MODE) ||
                                     (_MODE_ == TAUB_ONE_CNT_MODE) ||
                                     (_MODE_ == TAUB_CAP_ONECNT_MODE) ||
                                     (_MODE_ == TAUB_JUD_ONECNT_MODE) ||
                                     (_MODE_ == TAUB_CNT_UPDOWN_MODE) ||
                                     (_MODE_ == TAUB_PUL_ONECNT_MODE) ||
                                     (_MODE_ == TAUB_CNT_CAP_MODE) ||
                                     (_MODE_ == TAUB_GATE_CNT_MODE) ||
                                     (_MODE_ == TAUB_CAP_GATECNT_MODE))
enum{
    //Interval timer mode ,Capture mode,Count capture mode
    INTTAUBnIm_NOT_OUTPUT,
    INTTAUBnIm_OUTPUT = 1,
    //One-count mode,Pulse one-count mode
    DISABLE_DETECTION = INTTAUBnIm_NOT_OUTPUT,
    ENABLE_DETECTION =  1,
    //Judge mode,Judge and one-count mode
    TAUBnCNTm_LE_TAUBnCDRm = INTTAUBnIm_NOT_OUTPUT, //LE less than or equal-- <=
    TAUBnCNTm_GT_TAUBnCDRm = 1,//GT greater than -- >
}

enum{
    TAUB_TIS_FALL_EDGE,
    TAUB_TIS_RISE_EDGE,

    //low-width measurement selection
    TAUB_TIS_FALL_RISE,//Start trigger: falling edge,Stop trigger (capture): rising edge

    //high-width measurement selection
    TAUB_TIS_RISE_FALL,//Start trigger: rising edge,Stop trigger (capture): falling edge
};

enum{
    TAUB_CSF_CNT_UP,
    TAUB_CSF_CNT_DOWN,

    TAUB_OVF_NO_OCCUR = 0,
    TAUB_OVF_OCCURED = 1,
};

void OSTM_Init();
void OSTM_Delay(__IO uint32_t delay_us);
void OSTM_Cmp_Reload(const uint32_t new_value);


#endif//RH850F1L_TIMER_H
