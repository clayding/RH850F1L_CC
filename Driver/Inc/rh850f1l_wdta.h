/**
  ******************************************************************************
  * @file    rh850f1l_wdta.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    15-January-2018
  * @brief   Header file of Window Watchdog Timer Registers module.
  ******************************************************************************
  */

#ifndef RH850F1L_WDTA_H
#define RH850F1L_WDTA_H

#include "rh850f1l.h"

#define _WDTA0_BASE     WDTA0
#define _WDTA1_BASE     WDTA1

/*Writing ACH to this register generates a WDTA trigger and starts or restarts
 *the WDTA counter when the VAC function is not used (start-up option OPWDVAC = 0).
 */
#define __ENABLE_WDTA(_UNIT_)                   do{ \
                                                    _UNIT_##_BASE.WDTE = 0xAC; \
                                                }while(0);

/*Get the result whether the WDTAn is started or stopped*/
#define __GET_WDTA_ENBALE_STAT(_UINT_,_RET_)    do{ \
                                                    _RET_ = _UNIT_##_BASE.WDTE; \
                                                }while(0);

/*Writing a correct activation code to this register generates a WDTA trigger
 *and starts or restarts the WDTA counter when the VAC function is used
 *(start-up option OPWDVAC = 1)
 */
#define __ENABLE_WDTA_VAC(_UNIT_,_VAC_)         do{ \
                                                    _UNIT_##_BASE.EVAC = _VAC_; \
                                                }while(0);

/*2CH is returned (in software trigger start mode, before the activation of WDTAn).
 *The variable activation code written last is read (after the activation of WDTAn
 */
#define __GET_WDTA_VAC_ENBALE_STAT(_UINT_,_RET_)    do{ \
                                                        _RET_ = _UNIT_##_BASE.EVAC; \
                                                    }while(0);

/*Get the reference value for calculating the activation code of the VAC function*/
#define __GET_WDTA_REFER_VALUE(_UNIT_)              _UNIT_##_BASE.REF

/*specifies the overflow interval time, 75% interrupt enable/disable, the error
 *mode, and the window-open period.*/
#define __SET_WDTA_MODE(_UNIT_,_MODE_)              (_UNIT_##_BASE.MD = _MODE_)

typedef enum{
    _WDTA0,
    _WDTA1,
}WDTA_UNIT_Type;

typedef enum{
    WDTA_OVF_LEVEL_0,
    WDTA_OVF_LEVEL_1,
    WDTA_OVF_LEVEL_2,
    WDTA_OVF_LEVEL_3,
    WDTA_OVF_LEVEL_4,
    WDTA_OVF_LEVEL_5,
    WDTA_OVF_LEVEL_6,
    WDTA_OVF_LEVEL_7,
}WDTA_OVF_Type;//the overflow interval time

typedef enum{
    WDTA_INIT_DISABLE,
    WDTA_INIT_ENABLE = !WDTA_INIT_DISABLE,
}WDTA_INIT_ENABLE_Type;

typedef enum{
    WDTA_NMI_REQUEST_MODE,
    WDTA_RESET_MODE,
}WDTA_ERROR_MODE_Type;

typedef enum{
    WDTA_WS_25_PERCENT,
    WDTA_WS_50_PERCENT,
    WDTA_WS_75_PERCENT,
    WDTA_WS_100_PERCENT,
}WDTA_WIN_OPEN_PERIOD_Type;

typedef struct{
    WDTA_OVF_Type inter_time;
    WDTA_INIT_ENABLE_Type int_en;
    WDTA_ERROR_MODE_Type err_mode;
    WDTA_WIN_OPEN_PERIOD_Type ws;
}WDTA_MODE_TypeDef;



void WDTA_Start(WDTA_UNIT_Type unit, WDTA_MODE_TypeDef *mode);
void WDTA_Mode_Config(WDTA_UNIT_Type unit, WDTA_MODE_TypeDef *mode);
void WDTA_Reload(WDTA_UNIT_Type unit);


#endif //RH850F1L_WDTA_H
