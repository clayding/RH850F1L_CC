/**
  ******************************************************************************
  * @file    rh850f1l_wp.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of Write-Protected Registers module.
  ******************************************************************************
  */
#ifndef RH850F1L_WP_H
#define RH850F1L_WP_H

#include "rh850f1l.h"


typedef struct{
    __IO uintptr_t* dst_protect_reg_addr; //he protected register
    __IO uintptr_t* dst_protect_cmd_reg_addr;//the protection command register
    __IO uintptr_t* dst_protect_stat_reg_addr;//he protection status register
}WP_Opt_Reg;

/*@brief: Excute writing Procedure to the specific Write-Protected Register*/
ErrorStatus  Write_Protected_Process(WP_Opt_Reg dst_reg,uint32_t dst_val);

#endif //RH850F1L_WP_H
