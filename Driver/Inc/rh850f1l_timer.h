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

/*************************************TAUB declaration Start*******************/
 typedef enum{
     TAUB_CK0,TAUB_CK1,TAUB_CK2,TAUB_CK3,
 }TAUB_CLK_SEL_Type;

 typedef enum{
     TAUB_MAS_MASTER,
     TAUB_MAS_SLAVE,
 }TAUB_MAS_Type;

 typedef enum{
     TAUB_STS_SW_TRIG,//Software trigger
     TAUB_STS_EDGE_TIN_TRIG,//Valid edge of the TAUBTTINm input signal

     /*Valid edge of the TAUBTTINm input signal is used as the start trigger and
     the reverse edge is used as the stop trigger.*/
     TAUB_STS_EDGE_TIN_TRIG2,

     TAUB_STS_PROHIBITED, //Setting prohibited

     TAUB_STS_INT_TRIG_MASTER,//INTTAUBnIm is the start trigger of the master channel

     /*INTTAUBnIm of upper channel (m – 1) is the start trigger regardless of master setting*/
     TAUB_STS_UPPER_INT_TRIG_MASTER,

     /*Dead-time output signal of the TAUBTTOUTm generation unit*/
     TAUB_STS_DEAD_TIME_SIG,

     /*Up/down output trigger signal of the master channel.*/
     TAUB_UP_DOWN_TRIG,
 }TAUB_STS_Type;

//the operation mode TAUBnMD[4:1]
#define TAUB_INTERVAL_MODE      (0) //Interval timer mode
#define TAUB_JUD_MODE           (1) //Judge mode
#define TAUB_CAP_MODE           (2) //Capture mode
#define TAUB_EVET_CNT_MODE      (3) //Event count mode
#define TAUB_ONE_CNT_MODE       (4) //One-count mode
#define TAUB_MD_PROHIBITED1     (5) //Setting prohibited
#define TAUB_CAP_ONECNT_MODE    (6) //Capture and one-count mode
#define TAUB_JUD_ONECNT_MODE    (7) //Judge and one-count mode
#define TAUB_MD_PROHIBITED2     (8) //Setting prohibited
#define TAUB_CNT_UPDOWN_MODE    (9) //Count-up/-down mode
#define TAUB_PUL_ONECNT_MODE    (10)//Pulse one-count mode
#define TAUB_CNT_CAP_MODE       (11)//Count capture mode
#define TAUB_GATE_CNT_MODE      (12)//Gate count mode
#define TAUB_CAP_GATECNT_MODE   (13)//Capture and gate count mode

 #define IS_TAUB_OPT_MODE(_MODE_)   ((_MODE_ == TAUB_INTERVAL_MODE) ||  \
                                     (_MODE_ == TAUB_JUD_MODE) ||   \
                                     (_MODE_ == TAUB_CAP_MODE) ||   \
                                     (_MODE_ == TAUB_EVET_CNT_MODE) ||  \
                                     (_MODE_ == TAUB_ONE_CNT_MODE) ||   \
                                     (_MODE_ == TAUB_CAP_ONECNT_MODE) ||    \
                                     (_MODE_ == TAUB_JUD_ONECNT_MODE) ||    \
                                     (_MODE_ == TAUB_CNT_UPDOWN_MODE) ||    \
                                     (_MODE_ == TAUB_PUL_ONECNT_MODE) ||    \
                                     (_MODE_ == TAUB_CNT_CAP_MODE) ||   \
                                     (_MODE_ == TAUB_GATE_CNT_MODE) ||  \
                                     (_MODE_ == TAUB_CAP_GATECNT_MODE))
typedef enum{
    //Interval timer mode ,Capture mode,Count capture mode
    INTTAUBnIm_NOT_OUTPUT,
    INTTAUBnIm_OUTPUT = 1,
    //One-count mode,Pulse one-count mode
    DISABLE_DETECTION = INTTAUBnIm_NOT_OUTPUT,
    ENABLE_DETECTION =  1,
    //Judge mode,Judge and one-count mode
    TAUBnCNTm_LE_TAUBnCDRm = INTTAUBnIm_NOT_OUTPUT, //LE less than or equal-- <=
    TAUBnCNTm_GT_TAUBnCDRm = 1,//GT greater than -- >
}TAUB_MD_LOW1BIT_Type;

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

#define TAUB0_ADDR          ((volatile struct __tag39 *)&TAUB0)

#define TAUB_CDRn_ADDR(_CH_)    (((uint16_t*)&TAUB0_ADDR->CDR0) + 2*_CH_)
#define TAUB_CNTn_ADDR(_CH_)    (((uint16_t*)&TAUB0_ADDR->CNT0) + 2*_CH_)
#define TAUB_CMURn_ADDR(_CH_)   (((uint8_t*)&TAUB0_ADDR->CMUR0) + 3*_CH_)
#define TAUB_CSRn_ADDR(_CH_)    (((uint8_t*)&TAUB0_ADDR->CSR0)  + 3*_CH_)
#define TAUB_CSCn_ADDR(_CH_)    (((uint8_t*)&TAUB0_ADDR->CSC0)  + 3*_CH_)
#define TAUB_CMORn_ADDR(_CH_)   (((uint16_t*)&TAUB0_ADDR->CMOR0) + 2*_CH_)


#define TAUB_PRS0_OFFSET    (0)
#define TAUB_PRS1_OFFSET    (4)
#define TAUB_PRS2_OFFSET    (8)
#define TAUB_PRS3_OFFSET    (12)
#define TAUB_PRSn_OFFSET(n)    (4*n) //n: [0,3]
#define TAUB_PRS0_MASK      ((uint16_t)0x0F))
#define TAUB_PRS1_MASK      ((uint16_t)(0x0F << TAUB_PRS1_OFFSET))
#define TAUB_PRS2_MASK      ((uint16_t)(0x0F << TAUB_PRS2_OFFSET))
#define TAUB_PRS3_MASK      ((uint16_t)(0x0F << TAUB_PRS3_OFFSET))


#define TAUB_CMOR_CKS_OFFSET    (14)
#define TAUB_CMOR_CCS0_OFFSET   (12)
#define TAUB_CMOR_MAS_OFFSET    (11)
#define TAUB_CMOR_STS_OFFSET    (8)
#define TAUB_CMOR_COS_OFFSET    (6)
#define TAUB_CMOR_MD_OFFSET     (0)

#define TAUB_CMOR_CKS_MASK  ((uint16_t)(0x03 << 14)) //Selects the operation clock
#define TAUB_CMOR_CCS0_MASK ((uint16_t)(0x01 << 12)) //Selects the count clock for the TAUBnCNTm counter

/*Master or slave channel during synchronous channel operation.This bit is only
valid for even channels (CHm_even). For odd channels (CHm_odd), it is fixed to 0.*/
#define TAUB_CMOR_MAS_MASK  ((uint16_t)(0x01 << 11))
#define TAUB_CMOR_STS_MASK  ((uint16_t)(0x07 << 8))//Selects the external start trigger

/*Specifies when the capture register TAUBnCDRm and the overflow flag TAUBnCSRm.TAUBnOVF
of channel m are updated.These bits are only valid if channel m is in capture function
(capture mode and capture & one-count mode).*/
#define TAUB_CMOR_COS_MASK  ((uint16_t)(0x03 << 6))

#define TAUB_CMOR_MD_MASK   ((uint16_t)0x1F) //Specifies the operation mode,14 modes

#define TAUB_CSR_CSF_MASK   ((uint16_t)0x02)
#define TAUB_CSR_OVF_MASK   ((uint16_t)0x01)

/*These bits can only be rewritten when all counters using CKx are stopped
 _DIV_: 0~15, then CKn clock = PCLK/ 2^_DIV */
#define __SET_TAUB_PRESCALER(_PRS_OFFSET_,_DIV_)    do { \
                                                        MODIFY_REG(&(TAUB0_ADDR->TPS), \
                                                            (uint16_t)(0x0F <<_PRS_OFFSET_), \
                                                            _DIV_ << _PRS_OFFSET_); \
                                                    }while(0)

/*return _RET_: 0~15*/
#define __GET_TAUB_PRESCALER(_RET_,_PRS_OFFSET_)    do{ \
                                                        _RET_ = (TAUB0_ADDR->TPS >> _PRS_OFFSET_ & 0xF); \
                                                    }while(0)


#define __SET_TAUB_CDR(_CH_,_VALUE_)                do{ \
                                                        WRITE_REG(TAUB_CDRn_ADDR(_CH_),_VALUE_ & 0xFFFF); \
                                                    }while(0)
#define __GET_TAUB_CDR(_RET_,_CH_)                  do{ \
                                                        _RET_ = READ_REG(TAUB_CDRn_ADDR(_CH_)); \
                                                    }while(0)
/*Get data from the channel m counter register.Read-only*/
#define __GET_TAUB_CNT(_RET,_CH_)                   do{ \
                                                        _RET_ = READ_REG(TAUB_CNTn_ADDR(_CH_)); \
                                                    }while(0)

#define __SET_TAUB_CMOR_CKS(_CH_,_VALUE_)           do{ \
                                                        MODIFY_REG(TAUB_CMORn_ADDR(_CH_),\
                                                                TAUB_CMOR_CKS_MASK, \
                                                                _VALUE_ << TAUB_CMOR_CKS_OFFSET); \
                                                    }while(0)
#define __SET_TAUB_CMOR_CCS0(_CH_,_VALUE_)          do{ \
                                                        MODIFY_REG(TAUB_CMORn_ADDR(_CH_),\
                                                                TAUB_CMOR_CCS0_MASK, \
                                                                _VALUE_ << TAUB_CMOR_CCS0_OFFSET); \
                                                    }while(0)
#define __SET_TAUB_CMOR_MAS(_CH_,_VALUE_)           do{ \
                                                        MODIFY_REG(TAUB_CMORn_ADDR(_CH_),\
                                                                TAUB_CMOR_MAS_MASK, \
                                                                _VALUE_ << TAUB_CMOR_MAS_OFFSET); \
                                                    }while(0)

#define __SET_TAUB_CMOR_STS(_CH_,_VALUE_)           do{ \
                                                        MODIFY_REG(TAUB_CMORn_ADDR(_CH_),\
                                                                TAUB_CMOR_STS_MASK, \
                                                                _VALUE_ << TAUB_CMOR_STS_OFFSET); \
                                                    }while(0)
#define __SET_TAUB_CMOR_COS(_CH_,_VALUE_)           do{ \
                                                        MODIFY_REG(TAUB_CMORn_ADDR(_CH_),\
                                                                TAUB_CMOR_COS_MASK, \
                                                                _VALUE_ << TAUB_CMOR_COS_OFFSET); \
                                                    }while(0)
#define __SET_TAUB_CMOR_MD(_CH_,_VALUE_)            do{ \
                                                        MODIFY_REG(TAUB_CMORn_ADDR(_CH_),\
                                                                TAUB_CMOR_MD_MASK, \
                                                                _VALUE_ << TAUB_CMOR_MD_OFFSET); \
                                                    }while(0)

#define __GET_TAUB_CMOR(_RET_,_CH_)                 do{ \
                                                        _RET_ = READ_REG(TAUB_CMORn_ADDR(_CH_));\
                                                    }while(0)

#define __SET_TAUB_CMUR(_CH_,_VALUE_)               do{ \
                                                        WRITE_REG(TAUB_CMURn_ADDR(_CH_),_VALUE_ & 0x03); \
                                                    }while(0)

#define __GET_TAUB_CMUR(_RET_,_CH_)                 do{ \
                                                        _RET_ = READ_BIT(TAUB_CMURn_ADDR(_CH_),0x03); \
                                                    }while(0)

/* indicates the count direction and the overflow status of the counter for channel _CH_*/
#define __GET_TAUB_CSR(_RET_,_CH_)                  do{ \
                                                        _RET_ = READ_BIT(TAUB_CSRn_ADDR(_CH_),0x03); \
                                                    }while(0)

#define __CLEAR_OVERPLOW_FLAG(_CH_)                 do{ \
                                                        if(!(READ_BIT(TAUB_CSCn_ADDR(_CH_)0x01))) \
                                                            SET_BIT(TAUB_CSCn_ADDR(_CH_),0x01); \
                                                    }while(0)

#define __START_COUNTER(_CH_)                       do{ \
                                                        if(!(TAUB0_ADDR->TE & (0x01 << _CH_))) \
                                                            MODIFY_REG(&(TAUB0_ADDR->TS), \
                                                                (0x01 << _CH_),(0x01 << _CH_)); \
                                                    }while(0)
#define __STOP_COUNTER(_CH_)                        do{ \
                                                        if(TAUB0_ADDR->TE & (0x01 << _CH_)) \
                                                            MODIFY_REG(&(TAUB0_ADDR->TT), \
                                                                (0x01 << _CH_),(0x01 << _CH_)); \
                                                    }while(0)
#define __GET_COUNTER_TE(_RET_,_CH_)                do{ \
                                                        _RET_ = TAUB0_ADDR->TE & (0x01 << _CH_); \
                                                    }while(0)

/*return _RET_ 0 -- write successfully ,otherwise failed*/
#define __ENABLE_RELOAD_DATA(_CH_,_BOOL_,RET_)          do{ \
                                                            __GET_COUNTER_TE(_RET_,_CH_); \
                                                            /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                            if(_RET_) break; \
                                                            if(_BOOL_ == TRUE)/*enable*/ \
                                                                TAUB0_ADDR->RDE |= (0x01 << _CH_); \
                                                            else /*disable*/\
                                                                TAUB0_ADDR->RDE &= ~(0x01 << _CH_); \
                                                        }while(0)
/*_RET_ 0 -- Disabled  1 -- Enabled*/
#define __GET_RELOAD_DATA_STAT(_RET_,_CH_)              do{ \
                                                            _RET_ = TAUB0_ADDR->RDE & (0x01 << _CH_); \
                                                        }while(0)

/*Selects the control channel for simultaneous rewrite.0 -- Master channel 1-- Another upper channel
 return _RET_ 0 -- write successfully ,otherwise failed*/
#define __SET_RELOAD_DATA_CTL_CH(_CH_,_VALUE_,_RET_)    do{ \
                                                            __GET_COUNTER_TE(_RET_,_CH_); \
                                                            /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                            if(_RET_) break; \
                                                            if(_VALUE_) \
                                                                TAUB0_ADDR->RDS |= (0x01 << _CH_); \
                                                            else \
                                                                TAUB0_ADDR->RDS &= ~(0x01 << _CH_); \
                                                        }while(0)

#define __GET_RELOAD_DATA_STAT(_RET_,_CH_)              do{ \
                                                            _RET_ = TAUB0_ADDR->RDS & (0x01 << _CH_); \
                                                        }while(0)
/*Selects when the signal that controls simultaneous rewrite is generated
  return _RET_ 0 -- write successfully ,otherwise failed*/
#define __SET_RELAOD_DATA_MODE(_CH_,_VALUE_,_RET_)      do{ \
                                                            __GET_COUNTER_TE(_RET_,_CH_); \
                                                            /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                            if(_RET_) break; \
                                                            if(_VALUE_) \
                                                                TAUB0_ADDR->RDM |= (0x01 << _CH_); \
                                                            else \
                                                                TAUB0_ADDR->RDM &= ~(0x01 << _CH_); \
                                                        }while(0)

#define __GET_RELOAD_DATA_MODE(_RET_,_CH_)              do{ \
                                                            _RET_ = TAUB0_ADDR->RDM & (0x01 << _CH_); \
                                                        }while(0)

/*Specifies the channel that generates the INTTAUBnIm signal that triggers simultaneous
rewrite. return _RET_:0 -- write successfully ,otherwise failed*/
#define __SET_RELAOD_DATA_CTL(_CH_,_VALUE_,_RET_)       do{ \
                                                            __GET_COUNTER_TE(_RET_,_CH_); \
                                                            /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                            if(_RET_) break; \
                                                            if(_VALUE_) \
                                                                TAUB0_ADDR->RDC |= (0x01 << _CH_); \
                                                            else \
                                                                TAUB0_ADDR->RDC &= ~(0x01 << _CH_); \
                                                        }while(0)

#define __GET_RELOAD_DATA_CTL(_RET_,_CH_)               do{ \
                                                            _RET_ = TAUB0_ADDR->RDC & (0x01 << _CH_); \
                                                        }while(0)

/*Triggers the simultaneous rewrite enabling state.Write-only*/
#define __ENABLE_RELOAD_DATA_TRIGGER(_CH_)              do{ \
                                                            TAUB0_ADDR->RDT |= (0x01 << _CH_); \
                                                        }while(0)

/*This flag register indicates the simultaneous rewrite status Read-only*/
#define __GET_RELOAD_STAT(_RET_,_CH_)                   do{ \
                                                            _RET_ = TAUB0_ADDR->RSF & (0x01 << _CH_); \
                                                        }while(0)

/*Enables and disables independent channel output mode*/
#define __ENABLE_INDEPENDENT_OUTPUT(_CH_,_BOOL_)        do{ \
                                                            if(_BOOL_ == TRUE) /*enable*/ \
                                                                TAUB0_ADDR->TOE |= (0x01 << _CH_); \
                                                            else /*disable*/ \
                                                                TAUB0_ADDR->TOE &= ~(0x01 << _CH_); \
                                                        }while(0)
/*Get independent channel output mode state,_RET_ :0 -- Disabled  1 -- Enabled*/
#define __GET_INDEPENDENT_OUTPUT_STAT(_RET_,_CH_)       do{ \
                                                            _RET_ = TAUB0_ADDR->TOE & (0x01 << _CH_); \
                                                        }while(0)

/*Specifies the level of TAUBTTOUTm _VALUE_ :0 -- low level 1-- high level
   return _RET_:0 -- write successfully ,otherwise failed*/
#define __SET_TOUT_LEVEL(_CH_,_VALUE_,_RET_)            do{ \
                                                            __GET_INDEPENDENT_OUTPUT_STAT(_RET_,_CH_); \
                                                            /*Only TAUBnTOm bits for which TOE is disabled
                                                            (TAUBnTOEm = 0) can be written*/ \
                                                            if(_RET_) break; \
                                                            if(_VALUE_) /*Set high level*/ \
                                                                TAUB0_ADDR->TO |= (0x01 << _CH_); \
                                                            else /*Set low level*/ \
                                                                TAUB0_ADDR->TO &= ~(0x01 << _CH_); \
                                                        }while(0)
/*Reads the level of TAUBTTOUTm _VALUE_,_RET_ :0 -- low level  1 -- high level*/
#define __GET_TOUT_LEVEL(_RET_,_CH_)                    do{ \
                                                            _RET_ = TAUB0_ADDR->TO & (0x01 << _CH_); \
                                                        }while(0)

/*Specifies the output mode of each channel,__VALUE_: 0-- Independent channel output mode
  1-- Synchronous channel output mode*/
#define __SET_OUTPUT_MODE(_CH_,_VALUE_,_RET_)           do{ \
                                                            __GET_COUNTER_TE(_RET_,_CH_); \
                                                            /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                            if(_RET_) break; \
                                                            if(_VALUE_) \
                                                                TAUB0_ADDR->TOM |= (0x01 << _CH_); \
                                                            else \
                                                                TAUB0_ADDR->TOM &= ~(0x01 << _CH_); \
                                                        }while(0)
/*Read the output mode of each channel,return _RET_: 0-- Independent channel output mode
 1-- Synchronous channel output mode*/
 #define __GET_OUTPUT_MODE(_RET_,_CH_)                  do{ \
                                                            _RET_ = TAUB0_ADDR->TOM & (0x01 << _CH_); \
                                                        }while(0)

/*Specifies the output mode of each channel in combination with TAUBnTOMm,
_VALUE_: 0-- Operation mode 1 1-- Operation mode 2*/
#define __SET_OUTPUT_CONFIG(_CH_,_VALUE_,_RET_)         do{ \
                                                            __GET_COUNTER_TE(_RET_,_CH_); \
                                                            /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                            if(_RET_) break; \
                                                            if(_VALUE_) \
                                                                TAUB0_ADDR->TOC |= (0x01 << _CH_); \
                                                            else \
                                                                TAUB0_ADDR->TOC &= ~(0x01 << _CH_); \
                                                        }while(0)
/*Reads the output mode of each channel in combination with TAUBnTOMm,
return _RET_: 0-- Operation mode 1  1-- Operation mode 2*/
#define __GET_OUTPUT_CONFIG(_RET_,_CH_)                 do{ \
                                                            _RET_ = TAUB0_ADDR->TOC & (0x01 << _CH_); \
                                                        }while(0)

/*Specifies the output logic of the channel output bit (TAUBnTO.TAUBnTOm),
  _VALUE_: 0-- Positive logic 1-- Negative logic*/
#define __SET_OUTPUT_LEVEL(_CH_,_VALUE_,_RET_)          do{ \
                                                            if(_VALUE_) \
                                                                TAUB0_ADDR->TOL |= (0x01 << _CH_); \
                                                            else \
                                                                TAUB0_ADDR->TOL &= ~(0x01 << _CH_); \
                                                        }while(0)
/*Reads the output logic of the channel output bit (TAUBnTO.TAUBnTOm),
  _VALUE_: 0-- Positive logic 1-- Negative logic*/
#define __GET_OUTPUT_LEVEL(_RET_,_CH_)                  do{ \
                                                            _RET_ = TAUB0_ADDR->TOL & (0x01 << _CH_); \
                                                        }while(0)
typedef uint8_t TAUB_Md_High7Bit_TypeDef;

typedef struct{
    TAUB_CLK_SEL_Type clk_sel;  //Selects the operation clock
    uint8_t cnt_clk4cnt_counter;//Selects the count clock for the TAUBnCNTm counter
    TAUB_MAS_Type mas;
    TAUB_STS_Type sts;
    uint8_t cos;//Specifies when the capture register TAUBnCDRm and the overflow flag TAUBnCSRm.TAUBnOVF of channel m are updated
    union{
        uint8_t md;
        struct{
            TAUB_Md_High7Bit_TypeDef high7bit:7;
            TAUB_MD_LOW1BIT_Type low1bit:1;
        }md_bits;
    }md_un;
}TAUB_ChMode_TypeDef;
/*************************************TAUB declaration End*********************/

void OSTM_Init();
void OSTM_Delay(__IO uint32_t delay_us);
void OSTM_Cmp_Reload(const uint32_t new_value);
uint8_t OSTM_Count_State_Get(void* unit);

void TAUB_Init(uint8_t channel,TAUB_ChMode_TypeDef *mode);


#endif//RH850F1L_TIMER_H
