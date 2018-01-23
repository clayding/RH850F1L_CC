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

/****************************TAUB and TAUD declaration Start*******************/
#define _TAUB0                      (0)
#define _TAUB0_ADDR                 ((volatile struct __tag39 *)&TAUB0)

#define _TAUB0_CDRn_ADDR(_CH_)      (((uint16_t*)&_TAUB0_ADDR->CDR0) + 2*_CH_)
#define _TAUB0_CNTn_ADDR(_CH_)      (((uint16_t*)&_TAUB0_ADDR->CNT0) + 2*_CH_)
#define _TAUB0_CMURn_ADDR(_CH_)     (((uint8_t*) &_TAUB0_ADDR->CMUR0) + 3*_CH_)
#define _TAUB0_CSRn_ADDR(_CH_)      (((uint8_t*) &_TAUB0_ADDR->CSR0)  + 3*_CH_)
#define _TAUB0_CSCn_ADDR(_CH_)      (((uint8_t*) &_TAUB0_ADDR->CSC0)  + 3*_CH_)
#define _TAUB0_CMORn_ADDR(_CH_)     (((uint16_t*)&_TAUB0_ADDR->CMOR0) + 2*_CH_)


#define _TAUB0_PRS0_OFFSET          (0)
#define _TAUB0_PRS1_OFFSET          (4)
#define _TAUB0_PRS2_OFFSET          (8)
#define _TAUB0_PRS3_OFFSET          (12)
#define _TAUB0_PRSn_OFFSET(n)       (4*n) //n: [0,3]
#define _TAUB0_PRS0_MASK            ((uint16_t)0x0F))
#define _TAUB0_PRS1_MASK            ((uint16_t)(0x0F << _TAUB0_PRS1_OFFSET))
#define _TAUB0_PRS2_MASK            ((uint16_t)(0x0F << _TAUB0_PRS2_OFFSET))
#define _TAUB0_PRS3_MASK            ((uint16_t)(0x0F << _TAUB0_PRS3_OFFSET))


#define _TAUB0_CMOR_CKS_OFFSET      (14)
#define _TAUB0_CMOR_CCS0_OFFSET     (12)
#define _TAUB0_CMOR_MAS_OFFSET      (11)
#define _TAUB0_CMOR_STS_OFFSET      (8)
#define _TAUB0_CMOR_COS_OFFSET      (6)
#define _TAUB0_CMOR_MD_OFFSET       (0)

#define _TAUB0_CMOR_CKS_MASK        ((uint16_t)(0x03 << 14)) //Selects the operation clock
#define _TAUB0_CMOR_CCS0_MASK       ((uint16_t)(0x01 << 12)) //Selects the count clock for the TAUBnCNTm counter

/*Master or slave channel during synchronous channel operation.This bit is only
valid for even channels (CHm_even). For odd channels (CHm_odd), it is fixed to 0.*/
#define _TAUB0_CMOR_MAS_MASK        ((uint16_t)(0x01 << 11))
#define _TAUB0_CMOR_STS_MASK        ((uint16_t)(0x07 << 8))//Selects the external start trigger

/*Specifies when the capture register TAUBnCDRm and the overflow flag TAUBnCSRm.TAUBnOVF
of channel m are updated.These bits are only valid if channel m is in capture function
(capture mode and capture & one-count mode).*/
#define _TAUB0_CMOR_COS_MASK        ((uint16_t)(0x03 << 6))

#define _TAUB0_CMOR_MD_MASK         ((uint16_t)0x1F) //Specifies the operation mode,14 modes

#define _TAUB0_CSR_CSF_MASK         ((uint16_t)0x02)
#define _TAUB0_CSR_OVF_MASK         ((uint16_t)0x01)

/******************************************************************************/
#define _TAUD0                      (0)
#define _TAUD0_ADDR                 ((volatile struct __tag38 *)&TAUD0)

#define _TAUD0_CDRn_ADDR(_CH_)      (((uint16_t*)&_TAUD0_ADDR->CDR0) + 2*_CH_)
#define _TAUD0_CNTn_ADDR(_CH_)      (((uint16_t*)&_TAUD0_ADDR->CNT0) + 2*_CH_)
#define _TAUD0_CMURn_ADDR(_CH_)     (((uint8_t*) &_TAUD0_ADDR->CMUR0) + 3*_CH_)
#define _TAUD0_CSRn_ADDR(_CH_)      (((uint8_t*) &_TAUD0_ADDR->CSR0)  + 3*_CH_)
#define _TAUD0_CSCn_ADDR(_CH_)      (((uint8_t*) &_TAUD0_ADDR->CSC0)  + 3*_CH_)
#define _TAUD0_CMORn_ADDR(_CH_)     (((uint16_t*)&_TAUD0_ADDR->CMOR0) + 2*_CH_)


#define _TAUD0_PRS0_OFFSET          (0)
#define _TAUD0_PRS1_OFFSET          (4)
#define _TAUD0_PRS2_OFFSET          (8)
#define _TAUD0_PRS3_OFFSET          (12)
#define _TAUD0_PRSn_OFFSET(n)       (4*n) //n: [0,3]
#define _TAUD0_PRS0_MASK            ((uint16_t)0x0F))
#define _TAUD0_PRS1_MASK            ((uint16_t)(0x0F << _TAUD0_PRS1_OFFSET))
#define _TAUD0_PRS2_MASK            ((uint16_t)(0x0F << _TAUD0_PRS2_OFFSET))
#define _TAUD0_PRS3_MASK            ((uint16_t)(0x0F << _TAUD0_PRS3_OFFSET))


#define _TAUD0_CMOR_CKS_OFFSET       (14)
#define _TAUD0_CMOR_CCS0_OFFSET      (12)
#define _TAUD0_CMOR_MAS_OFFSET       (11)
#define _TAUD0_CMOR_STS_OFFSET       (8)
#define _TAUD0_CMOR_COS_OFFSET       (6)
#define _TAUD0_CMOR_MD_OFFSET        (0)

#define _TAUD0_CMOR_CKS_MASK         ((uint16_t)(0x03 << 14)) //Selects the operation clock
#define _TAUD0_CMOR_CCS0_MASK        ((uint16_t)(0x01 << 12)) //Selects the count clock for the TAUBnCNTm counter

/*Master or slave channel during synchronous channel operation.This bit is only
valid for even channels (CHm_even). For odd channels (CHm_odd), it is fixed to 0.*/
#define _TAUD0_CMOR_MAS_MASK         ((uint16_t)(0x01 << 11))
#define _TAUD0_CMOR_STS_MASK         ((uint16_t)(0x07 << 8))//Selects the external start trigger

/*Specifies when the capture register TAUDnCDRm and the overflow flag TAUDnCSRm.TAUDnOVF
of channel m are updated.These bits are only valid if channel m is in capture function
(capture mode and capture & one-count mode).*/
#define _TAUD0_CMOR_COS_MASK         ((uint16_t)(0x03 << 6))

#define _TAUD0_CMOR_MD_MASK          ((uint16_t)0x1F) //Specifies the operation mode,14 modes

#define _TAUD0_CSR_CSF_MASK          ((uint16_t)0x02)
#define _TAUD0_CSR_OVF_MASK          ((uint16_t)0x01)


/*These bits can only be rewritten when all counters using CKx are stopped
 _DIV_: 0~15, then CKn clock = PCLK/ 2^_DIV */
#define __SET_TAU_PRESCALER(_UNIT_,_PRS_OFFSET_,_DIV_)  do { \
                                                            MODIFY_REG(&(_UNIT_##_ADDR->TPS), \
                                                                (uint16_t)(0x0F <<_PRS_OFFSET_), \
                                                                _DIV_ << _PRS_OFFSET_); \
                                                        }while(0)

/*return _RET_: 0~15*/
#define __GET_TAU_PRESCALER(_UNIT_,_RET_,_PRS_OFFSET_)  do{ \
                                                            _RET_ = (_UNIT_##_ADDR->TPS >> _PRS_OFFSET_ & 0xF); \
                                                        }while(0)


#define __SET_TAU_CDR(_UNIT_,_CH_,_VALUE_)              do{ \
                                                            WRITE_REG(_UNIT_##_CDRn_ADDR(_CH_),_VALUE_ & 0xFFFF); \
                                                        }while(0)

#define __GET_TAU_CDR(_UNIT_,_RET_,_CH_)                do{ \
                                                            _RET_ = READ_REG(_UNIT_##_CDRn_ADDR(_CH_)); \
                                                        }while(0)
/*Get data from the channel m counter register.Read-only*/
#define __GET_TAU_CNT(_UNIT_,_RET,_CH_)                 do{ \
                                                            _RET_ = READ_REG(_UNIT_##_CNTn_ADDR(_CH_)); \
                                                        }while(0)

#define __SET_TAU_CMOR_CKS(_UNIT_,_CH_,_VALUE_)         do{ \
                                                            MODIFY_REG(_UNIT_##_CMORn_ADDR(_CH_),\
                                                                    _UNIT_##_CMOR_CKS_MASK, \
                                                                    _VALUE_ << _UNIT_##_CMOR_CKS_OFFSET); \
                                                        }while(0)
#define __SET_TAU_CMOR_CCS0(_UNIT_,_CH_,_VALUE_)        do{ \
                                                            MODIFY_REG(_UNIT_##_CMORn_ADDR(_CH_),\
                                                                    _UNIT_##_CMOR_CCS0_MASK, \
                                                                    _VALUE_ << _UNIT_##_CMOR_CCS0_OFFSET); \
                                                        }while(0)
#define __SET_TAU_CMOR_MAS(_UNIT_,_CH_,_VALUE_)         do{ \
                                                            MODIFY_REG(_UNIT_##_CMORn_ADDR(_CH_),\
                                                                    _UNIT_##_CMOR_MAS_MASK, \
                                                                    _VALUE_ << _UNIT_##_CMOR_MAS_OFFSET); \
                                                        }while(0)

#define __SET_TAU_CMOR_STS(_UNIT_,_CH_,_VALUE_)         do{ \
                                                            MODIFY_REG(_UNIT_##_CMORn_ADDR(_CH_),\
                                                                    _UNIT_##_CMOR_STS_MASK, \
                                                                    _VALUE_ << _UNIT_##_CMOR_STS_OFFSET); \
                                                        }while(0)
#define __SET_TAU_CMOR_COS(_UNIT_,_CH_,_VALUE_)         do{ \
                                                            MODIFY_REG(_UNIT_##_CMORn_ADDR(_CH_),\
                                                                    _UNIT_##_CMOR_COS_MASK, \
                                                                    _VALUE_ << _UNIT_##_CMOR_COS_OFFSET); \
                                                        }while(0)
#define __SET_TAU_CMOR_MD(_UNIT_,_CH_,_VALUE_)          do{ \
                                                            MODIFY_REG(_UNIT_##_CMORn_ADDR(_CH_),\
                                                                    _UNIT_##_CMOR_MD_MASK, \
                                                                    _VALUE_ << _UNIT_##_CMOR_MD_OFFSET); \
                                                        }while(0)

#define __GET_TAU_CMOR(_UNIT_,_RET_,_CH_)               do{ \
                                                            _RET_ = READ_REG(_UNIT_##_CMORn_ADDR(_CH_));\
                                                        }while(0)

#define __SET_TAU_CMUR(_UNIT_,_CH_,_VALUE_)             do{ \
                                                            WRITE_REG(_UNIT_##_CMURn_ADDR(_CH_),_VALUE_ & 0x03); \
                                                        }while(0)

#define __GET_TAU_CMUR(_UNIT_,_RET_,_CH_)               do{ \
                                                            _RET_ = READ_BIT(_UNIT_##_CMURn_ADDR(_CH_),0x03); \
                                                        }while(0)

/* indicates the count direction and the overflow status of the counter for channel _CH_*/
#define __GET_TAU_CSR(_UNIT_,_RET_,_CH_)                do{ \
                                                            _RET_ = READ_BIT(_UNIT_##_CSRn_ADDR(_CH_),0x03); \
                                                        }while(0)

#define __CLEAR_OVERPLOW_FLAG(_UNIT_,_CH_)              do{ \
                                                            if(!(READ_BIT(_UNIT_##_CSCn_ADDR(_CH_)0x01))) \
                                                                SET_BIT(_UNIT_##_CSCn_ADDR(_CH_),0x01); \
                                                        }while(0)

#define __START_COUNTER(_UNIT_,_CH_MASK_)               do{ \
                                                            if((_UNIT_##_ADDR->TE & _CH_MASK_) != _CH_MASK_) \
                                                                SET_BIT(&(_UNIT_##_ADDR->TS),_CH_MASK_); \
                                                        }while(0)

#define __STOP_COUNTER(_UNIT_,_CH_)                     do{ \
                                                            if(_UNIT_##_ADDR->TE & _CH_MASK_ != 0x00 ) \
                                                                CLEAR_BIT(&(_UNIT_##_ADDR->TT),_CH_MASK_); \
                                                        }while(0)

#define __GET_COUNTER_TE(_UNIT_ADDR_,_RET_,_CH_MASK_)   do{ \
                                                            _RET_ = _UNIT_ADDR_->TE & _CH_MASK_; \
                                                        }while(0)

/*return _RET_ 0 -- write successfully ,otherwise failed*/
#define __ENABLE_RELOAD_DATA(_UNIT_,_CH_,_BOOL_,_RET_)  do{ \
                                                            __GET_COUNTER_TE(_UNIT_##_ADDR,_RET_,0x01 << _CH_); \
                                                            /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                            if(_RET_) break; \
                                                            if(_BOOL_ == TRUE)/*enable*/ \
                                                                _UNIT_##_ADDR->RDE |= (0x01 << _CH_); \
                                                            else /*disable*/\
                                                                _UNIT_##_ADDR->RDE &= ~(0x01 << _CH_); \
                                                        }while(0)
/*_RET_ 0 -- Disabled  1 -- Enabled*/
#define __GET_RELOAD_DATA_STAT(_UNIT_,_RET_,_CH_)       do{ \
                                                            _RET_ = _UNIT_##_ADDR->RDE & (0x01 << _CH_); \
                                                        }while(0)

/*Selects the control channel for simultaneous rewrite.0 -- Master channel 1-- Another upper channel
 return _RET_ 0 -- write successfully ,otherwise failed*/
#define __SET_RELOAD_DATA_CTL_CH(_UNIT_,_CH_,_VALUE_,_RET_) do{ \
                                                                __GET_COUNTER_TE(_UNIT_##_ADDR,_RET_,0x01 <<_CH_); \
                                                                /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                                if(_RET_) break; \
                                                                if(_VALUE_) \
                                                                    _UNIT_##_ADDR->RDS |= (0x01 << _CH_); \
                                                                else \
                                                                    _UNIT_##_ADDR->RDS &= ~(0x01 << _CH_); \
                                                            }while(0)

#define __GET_RELOAD_DATA_CTL_CH(_UNIT_,_RET_,_CH_)         do{ \
                                                                _RET_ = _UNIT_##_ADDR->RDS & (0x01 << _CH_); \
                                                            }while(0)
/*Selects when the signal that controls simultaneous rewrite is generated
  return _RET_ 0 -- write successfully ,otherwise failed*/
#define __SET_RELAOD_DATA_MODE(_UNIT_,_CH_,_VALUE_,_RET_)   do{ \
                                                                __GET_COUNTER_TE(_UNIT_##_ADDR,_RET_,0x01 << _CH_); \
                                                                /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                                if(_RET_) break; \
                                                                if(_VALUE_) \
                                                                    _UNIT_##_ADDR->RDM |= (0x01 << _CH_); \
                                                                else \
                                                                    _UNIT_##_ADDR->RDM &= ~(0x01 << _CH_); \
                                                            }while(0)

#define __GET_RELOAD_DATA_MODE(_UNIT_,_RET_,_CH_)           do{ \
                                                                _RET_ = _UNIT_##_ADDR->RDM & (0x01 << _CH_); \
                                                            }while(0)

/*Specifies the channel that generates the INTTAUBnIm signal that triggers simultaneous
rewrite. return _RET_:0 -- write successfully ,otherwise failed*/
#define __SET_RELAOD_DATA_CTL(_UNIT_,_CH_,_VALUE_,_RET_)    do{ \
                                                                __GET_COUNTER_TE(_UNIT_##_ADDR,_RET_,0x01 << _CH_); \
                                                                /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                                if(_RET_) break; \
                                                                if(_VALUE_) \
                                                                    _UNIT_##_ADDR->RDC |= (0x01 << _CH_); \
                                                                else \
                                                                    _UNIT_##_ADDR->RDC &= ~(0x01 << _CH_); \
                                                            }while(0)

#define __GET_RELOAD_DATA_CTL(_UNIT_,_RET_,_CH_)            do{ \
                                                                _RET_ = _UNIT_##_ADDR->RDC & (0x01 << _CH_); \
                                                            }while(0)

/*Triggers the simultaneous rewrite enabling state.Write-only*/
#define __ENABLE_RELOAD_DATA_TRIGGER(_UNIT_,_CH_)           do{ \
                                                                _UNIT_##_ADDR->RDT |= (0x01 << _CH_); \
                                                            }while(0)

/*This flag register indicates the simultaneous rewrite status Read-only*/
#define __GET_RELOAD_STAT(_UNIT_,_RET_,_CH_)                do{ \
                                                                _RET_ = _UNIT_##_ADDR->RSF & (0x01 << _CH_); \
                                                            }while(0)

/*Enables and disables independent channel output mode*/
#define __ENABLE_INDEPENDENT_OUTPUT(_UNIT_,_CH_,_BOOL_)     do{ \
                                                                if(_BOOL_ == TRUE) /*enable*/ \
                                                                    _UNIT_##_ADDR->TOE |= (0x01 << _CH_); \
                                                                else /*disable*/ \
                                                                    _UNIT_##_ADDR->TOE &= ~(0x01 << _CH_); \
                                                            }while(0)
/*Get independent channel output mode state,_RET_ :0 -- Disabled  1 -- Enabled*/
#define __GET_INDEPENDENT_OUTPUT_STAT(_UNIT_,_RET_,_CH_)    do{ \
                                                                _RET_ = _UNIT_##_ADDR->TOE & (0x01 << _CH_); \
                                                            }while(0)

/*Specifies the level of TAUBTTOUTm _VALUE_ :0 -- low level 1-- high level
   return _RET_:0 -- write successfully ,otherwise failed*/
#define __SET_TOUT_LEVEL(_UNIT_,_CH_,_VALUE_,_RET_)         do{ \
                                                                __GET_INDEPENDENT_OUTPUT_STAT(_UNIT_,_RET_,_CH_); \
                                                                /*Only TAUBnTOm bits for which TOE is disabled
                                                                (TAUBnTOEm = 0) can be written*/ \
                                                                if(_RET_) break; \
                                                                if(_VALUE_) /*Set high level*/ \
                                                                    _UNIT_##_ADDR->TO |= (0x01 << _CH_); \
                                                                else /*Set low level*/ \
                                                                    _UNIT_##_ADDR->TO &= ~(0x01 << _CH_); \
                                                            }while(0)
/*Reads the level of TAUBTTOUTm _VALUE_,_RET_ :0 -- low level  1 -- high level*/
#define __GET_TOUT_LEVEL(_UNIT_,_RET_,_CH_)                 do{ \
                                                                _RET_ = _UNIT_##_ADDR->TO & (0x01 << _CH_); \
                                                            }while(0)

/*Specifies the output mode of each channel,__VALUE_: 0-- Independent channel output mode
  1-- Synchronous channel output mode*/
#define __SET_OUTPUT_MODE(_UNIT_,_CH_,_VALUE_,_RET_)        do{ \
                                                                __GET_COUNTER_TE(_UNIT_##_ADDR,_RET_,0x01 << _CH_); \
                                                                /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                                if(_RET_) break; \
                                                                if(_VALUE_) \
                                                                    _UNIT_##_ADDR->TOM |= (0x01 << _CH_); \
                                                                else \
                                                                    _UNIT_##_ADDR->TOM &= ~(0x01 << _CH_); \
                                                            }while(0)
/*Read the output mode of each channel,return _RET_: 0-- Independent channel output mode
 1-- Synchronous channel output mode*/
 #define __GET_OUTPUT_MODE(_UNIT_,_RET_,_CH_)               do{ \
                                                                _RET_ = _UNIT_##_ADDR->TOM & (0x01 << _CH_); \
                                                            }while(0)

/*Specifies the output mode of each channel in combination with TAUBnTOMm,
_VALUE_: 0-- Operation mode 1 1-- Operation mode 2*/
#define __SET_OUTPUT_CONFIG(_UNIT_,_CH_,_VALUE_,_RET_)      do{ \
                                                                __GET_COUNTER_TE(_UNIT_##_ADDR,_RET_,0x01 << _CH_); \
                                                                /*only be written when TAUBnTE.TAUBnTEm = 0.*/ \
                                                                if(_RET_) break; \
                                                                if(_VALUE_) \
                                                                    _UNIT_##_ADDR->TOC |= (0x01 << _CH_); \
                                                                else \
                                                                    _UNIT_##_ADDR->TOC &= ~(0x01 << _CH_); \
                                                            }while(0)
/*Reads the output mode of each channel in combination with TAUBnTOMm,
return _RET_: 0-- Operation mode 1  1-- Operation mode 2*/
#define __GET_OUTPUT_CONFIG(_UNIT_,_RET_,_CH_)              do{ \
                                                                _RET_ = _UNIT_##_ADDR->TOC & (0x01 << _CH_); \
                                                            }while(0)

/*Specifies the output logic of the channel output bit (TAUBnTO.TAUBnTOm),
  _VALUE_: 0-- Positive logic 1-- Negative logic*/
#define __SET_OUTPUT_LEVEL(_UNIT_,_CH_,_VALUE_,_RET_)       do{ \
                                                                if(_VALUE_) \
                                                                    _UNIT_##_ADDR->TOL |= (0x01 << _CH_); \
                                                                else \
                                                                    _UNIT_##_ADDR->TOL &= ~(0x01 << _CH_); \
                                                            }while(0)
/*Reads the output logic of the channel output bit (TAUBnTO.TAUBnTOm),
  _VALUE_: 0-- Positive logic 1-- Negative logic*/
#define __GET_OUTPUT_LEVEL(_UNIT_,_RET_,_CH_)               do{ \
                                                                _RET_ = _UNIT_##_ADDR->TOL & (0x01 << _CH_); \
                                                            }while(0)

#define __ENABLE_DEAD_TIME(_UNIT_,_CH_,_BOOL_)              do{ \
                                                                if(_BOOL_ == TRUE) /*enable*/ \
                                                                    _UNIT_##_ADDR->TDE |= (0x01 << _CH_); \
                                                                else /*disable*/ \
                                                                    _UNIT_##_ADDR->TDE &= ~(0x01 << _CH_); \
                                                            }while(0)
/*_VALUE_ 0: Positive phase period 1: Negative phase period*/
#define __SET_PHASE_PERIOD(_UNIT_,_CH_,_VALUE_)             do{ \
                                                                if(_VALUE_) /*negative phase period*/ \
                                                                    _UNIT_##_ADDR->TDL |= (0x01 << _CH_); \
                                                                else /*disable*/ \
                                                                    _UNIT_##_ADDR->TDL &= ~(0x01 << _CH_); \
                                                            }while(0)

/*_VALUE_ 0:When detecting the duty cycle of an upper even channel (duty dead time output)
 *        1:When detecting the TIN input edge of a lower odd channel (one-phase dead time output)*/
#define __SET_TAUD_TIME_ADD_DEAD_TIME(_CH_,_VALUE_)         do{ \
                                                                if(_VALUE_) /*enable*/ \
                                                                    _TAUD0_ADDR->TDM |= (0x01 << _CH_); \
                                                                else /*disable*/ \
                                                                    _TAUD0_ADDR->TDM &= ~(0x01 << _CH_); \
                                                            }while(0)

/*************TAUDn Real-time/Modulation Output Registers**********************/
//enables/disables real-time output
#define __ENABLE_TAUD_REAL_TIME_OUTPUT(_CH_,_BOOL_)         do{ \
                                                                if(_BOOL_ == TRUE) /*enable real-time output*/ \
                                                                    _TAUD0_ADDR->TRE |= (0x01 << _CH_); \
                                                                else /*disable real-time output*/ \
                                                                    _TAUD0_ADDR->TRE &= ~(0x01 << _CH_); \
                                                            }while(0)

/* controls the real-time output trigger of each channel
 * _VALUE_ 0: Next upper channel with this bit set to 1
 *        1: Channel m
 */
#define __SET_TAUD_TRIGGER_CHANNEL(_CH_,_VALUE_)            do{ \
                                                                if(_VALUE_) /*enable*/ \
                                                                    _TAUD0_ADDR->TRC |= (0x01 << _CH_); \
                                                                else /*disable*/ \
                                                                    _TAUD0_ADDR->TRC &= ~(0x01 << _CH_); \
                                                            }while(0)
/*Sets a value which is output to TAUDTTOUTm*/
#define __SET_TAUD_LEVEL_TO_TOUT(_CH_,_VALUE_)              do{ \
                                                                if(_VALUE_) /*enable*/ \
                                                                    _TAUD0_ADDR->TRO |= (0x01 << _CH_); \
                                                                else /*disable*/ \
                                                                    _TAUD0_ADDR->TRO &= ~(0x01 << _CH_); \
                                                            }while(0)
/* enables/disables modulation output for timer output and real-time output
 * _VAULE_  0: disable  1:enable*/
#define __ENABEL_TAUD_MODULATION_OUTPUT(_CH_,_BOOL_)        do{ \
                                                                if(_BOOL_ == TRUE) /*enable real-time output*/ \
                                                                    _TAUD0_ADDR->TME |= (0x01 << _CH_); \
                                                                else /*disable real-time output*/ \
                                                                    _TAUD0_ADDR->TME &= ~(0x01 << _CH_); \
                                                            }while(0)
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

 //the operation mode TAUBnMD[4:1]
#define TAUD_INTERVAL_MODE      (0) //Interval timer mode
#define TAUD_JUD_MODE           (1) //Judge mode
#define TAUD_CAP_MODE           (2) //Capture mode
#define TAUD_EVET_CNT_MODE      (3) //Event count mode
#define TAUD_ONE_CNT_MODE       (4) //One-count mode
#define TAUD_MD_PROHIBITED1     (5) //Setting prohibited
#define TAUD_CAP_ONECNT_MODE    (6) //Capture and one-count mode
#define TAUD_JUD_ONECNT_MODE    (7) //Judge and one-count mode
#define TAUD_MD_PROHIBITED2     (8) //Setting prohibited
#define TAUD_CNT_UPDOWN_MODE    (9) //Count-up/-down mode
#define TAUD_PUL_ONECNT_MODE    (10)//Pulse one-count mode
#define TAUD_CNT_CAP_MODE       (11)//Count capture mode
#define TAUD_GATE_CNT_MODE      (12)//Gate count mode
#define TAUD_CAP_GATECNT_MODE   (13)//Capture and gate count mode

#define IS_TAUD_OPT_MODE(_MODE_)    ((_MODE_ == TAUD_INTERVAL_MODE) ||  \
                                      (_MODE_ == TAUD_JUD_MODE) ||   \
                                      (_MODE_ == TAUD_CAP_MODE) ||   \
                                      (_MODE_ == TAUD_EVET_CNT_MODE) ||  \
                                      (_MODE_ == TAUD_ONE_CNT_MODE) ||   \
                                      (_MODE_ == TAUD_CAP_ONECNT_MODE) ||    \
                                      (_MODE_ == TAUD_JUD_ONECNT_MODE) ||    \
                                      (_MODE_ == TAUD_CNT_UPDOWN_MODE) ||    \
                                      (_MODE_ == TAUD_PUL_ONECNT_MODE) ||    \
                                      (_MODE_ == TAUD_CNT_CAP_MODE) ||   \
                                      (_MODE_ == TAUD_GATE_CNT_MODE) ||  \
                                      (_MODE_ == TAUD_CAP_GATECNT_MODE))
typedef enum{
    //Interval timer mode ,Capture mode,Count capture mode
    INTTAUnIm_NOT_OUTPUT,
    INTTAUnIm_OUTPUT = 1,
    //One-count mode,Pulse one-count mode
    DISABLE_DETECTION = INTTAUnIm_NOT_OUTPUT,
    ENABLE_DETECTION =  1,
    //Judge mode,Judge and one-count mode
    TAUnCNTm_LE_TAUBnCDRm = INTTAUnIm_NOT_OUTPUT, //LE less than or equal-- <=
    TAUnCNTm_GT_TAUBnCDRm = 1,//GT greater than -- >
}TAU_MD_LOW1BIT_Type,TAUB_MD_LOW1BIT_Type,TAUD_MD_LOW1BIT_Type;

typedef enum{
    TAU_TIS_FALL_EDGE,
    TAU_TIS_RISE_EDGE,
    //low-width measurement selection
    TAU_TIS_FALL_RISE,//Start trigger: falling edge,Stop trigger (capture): rising edge
    //high-width measurement selection
    TAU_TIS_RISE_FALL,//Start trigger: rising edge,Stop trigger (capture): falling edge
}TAU_TIN_DETECT_Type;

enum{
    TAU_CSF_CNT_UP,
    TAU_CSF_CNT_DOWN,

    TAU_OVF_NO_OCCUR = 0,
    TAU_OVF_OCCURED = 1,
};



typedef enum{
    TAU_CK0,TAU_CK1,TAU_CK2,TAU_CK3,
}TAU_CLK_SEL_Type,TAUB_CLK_SEL_Type,TAUD_CLK_SEL_Type;

typedef enum{
    TAUB_MAS_MASTER,
    TAUB_MAS_SLAVE,
}TAU_MAS_Type,TAUB_MAS_Type,TAUD_MAS_Type;

typedef enum{
    TAU_STS_SW_TRIG,//Software trigger
    TAU_STS_EDGE_TIN_TRIG,//Valid edge of the TAU(B/D)TTINm input signal

    /*Valid edge of the TAU(B/D)TTINm input signal is used as the start trigger and
    the reverse edge is used as the stop trigger.*/
    TAU_STS_EDGE_TIN_TRIG2,

    TAU_STS_PROHIBITED, //Setting prohibited

    TAU_STS_INT_TRIG_MASTER,//INTTAU(B/D)nIm is the start trigger of the master channel

    /*INTTAU(B/D)nIm of upper channel (m – 1) is the start trigger regardless of master setting*/
    TAU_STS_UPPER_INT_TRIG_MASTER,

    /*Dead-time output signal of the TAU(B/D)TTOUTm generation unit*/
    TAU_STS_DEAD_TIME_SIG,

    /*Up/down output trigger signal of the master channel.*/
    TAU_UP_DOWN_TRIG,
}TAU_STS_Type,TAUB_STS_Type,TAUD_STS_Type;

typedef uint8_t TAU_Md_High7Bit_TypeDef;


typedef enum{
    TAU_MASTER_CH_CTL,//0: Master channel
    TAU_UPPER_CH_CTL,//1: Another upper channel
}TAU_CH_CTL_Type,TAUB_CH_CTL_Type,TAUD_CH_CTL_Type; //Selects the control channel for simultaneous rewrite

typedef enum{
    TAU_MASTER_START_CNT,
    TAU_TOPOf_TRIANGLE_WAVE,
}TAU_WHEN_SIG_GEN_Type,TAUB_WHEN_SIG_GEN_Type,TAUD_WHEN_SIG_GEN_Type;//Selects when the signal that triggers simultaneous rewrite is generated

typedef enum{
    TAU_IS_TRIG_CH,
    TAU_NOT_TRIG_CH = !TAU_IS_TRIG_CH,
}TAU_AS_TRIG_CH,TAUB_AS_TRIG_CH,TAUD_AS_TRIG_CH;

typedef struct{
    TAU_CH_CTL_Type ch_ctl;//
    TAU_WHEN_SIG_GEN_Type sig_gen;//
    TAU_AS_TRIG_CH is_trig_ch;//
}TAU_SIMULREWR_CFG_TypeDef,TAUB_SIMULREWR_CFG_TypeDef,TAUD_SIMULREWR_CFG_TypeDef;//simultaneous rewrite configration

/*channel output modes*/
typedef enum{
    TAUB_BY_SOFTWARE_MODE,
    TAUB_INDEPENDENT_OUTPUT_MODE_1,
    TAUB_INDEPENDENT_OUTPUT_MODE_2,
    TAUB_SYNCHRONOUS_OUTPUT_MODE_1,
    TAUB_SYNCHRONOUS_OUTPUT_MODE_2,
}TAUB_CH_OUTPUT_MODE_Type;
/*************************************TAUB declaration End*********************/
/*************************************TAUD declaration Start*********************/
/*channel output modes*/
typedef enum{
    TAUD_BY_SOFTWARE_MODE,
    /*independent output mode*/
    TAUD_INDEPENDENT_OUTPUT_MODE_1,
    TAUD_INDEPENDENT_OUTPUT_MODE_1_WITH_REAL_TIME,//with real-time output
    TAUD_INDEPENDENT_OUTPUT_MODE_2,
    /*Synchronous output mode*/
    TAUD_SYNCHRONOUS_OUTPUT_MODE_1,
    TAUD_SYNCHRONOUS_OUTPUT_MODE_1_WITH_NON_COMP,//with non-complementary modulation output
    TAUD_SYNCHRONOUS_OUTPUT_MODE_2,
    TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_DEAD_TIME,//with dead time output
    TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_ONE_PHASE,//with one-phase PWM output
    TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_COMP,//with complementary modulation output
    TAUD_SYNCHRONOUS_OUTPUT_MODE_2_WITH_NON_COMP,//with non-complementary modulation output
}TAUD_CH_OUTPUT_MODE_Type;
/*************************************TAUD declaration End*********************/


typedef struct{
    uint8_t ch_no;
    TAU_CLK_SEL_Type clk_sel;  //Selects the operation clock
    uint8_t cnt_clk4cnt_counter;//Selects the count clock for the TAUBnCNTm counter
    uint8_t clk_div;
    uint16_t cdr;
    TAU_MAS_Type mas;
    TAU_STS_Type sts;
    uint8_t cos;//Specifies when the capture register TAUBnCDRm and the overflow flag TAUBnCSRm.TAUBnOVF of channel m are updated
    union{
        uint8_t md;
        struct{
            TAU_MD_LOW1BIT_Type low1bit:1;
            TAU_Md_High7Bit_TypeDef high7bit:7;
        }md_bits;
    }md_un;
    TAU_TIN_DETECT_Type tin_detect;
    uint8_t enable_sim_cfg;//Enables/disables simultaneous rewrite of the data register of channel ch_no
    TAU_SIMULREWR_CFG_TypeDef sim_cfg;
    union{
        TAUB_CH_OUTPUT_MODE_Type taub_mode;
        TAUD_CH_OUTPUT_MODE_Type taud_mode;
    }ch_output_mode;
}TAU_ChMode_TypeDef,TAUB_ChMode_TypeDef,TAUD_ChMode_TypeDef;


/**********Set noise filters for corresponding port pin functions**************/
#define DNFA_TAUB0IEN   DNFATAUB0IEN
#define DNFA_TAUD0IEN   DNFATAUD0IEN


#define __ENBALE_DIGITAL_NOISE_ELIMI(_UNIT_,_CH_,_VALUE_)       do{ \
                                                                    if(_VALUE_) \
                                                                        DNFA##_UNIT_##IEN |= (1 << _CH_); \
                                                                    else \
                                                                        DNFA##_UNIT_##IEN &= ~(1 << _CH_); \
                                                                }while(0)



void OSTM_Init();
void OSTM_Delay(__IO uint32_t delay_us);
void OSTM_Cmp_Reload(const uint32_t new_value);
uint8_t OSTM_Count_State_Get(void* unit);

void TAUB_Independent_Init(TAUB_ChMode_TypeDef *mode);
void TAUB_Set_Channel_Output_Mode(uint8_t channel_num,TAUB_CH_OUTPUT_MODE_Type out_mode);

void TAUD_Independent_Init(TAUD_ChMode_TypeDef *mode);
void TAUD_Set_Channel_Output_Mode(uint8_t channel_num,TAUD_CH_OUTPUT_MODE_Type out_mode);


#endif//RH850F1L_TIMER_H
