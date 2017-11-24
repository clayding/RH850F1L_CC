/**
  ******************************************************************************
  * @file    rh850f1l_wp.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   24-November-2017
  * @brief   Clock Control module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of Writing Procedure to Write-Protected Registers:
  *           + Initialization and de-initialization functions
  *           + Write-Protected functions
  ******************************************************************************
  */
#include "rh850f1l_wp.h"

#define FIXED_VALUE_TO_CMD_REG  ((uint32_t)0xA5)
#define PROTSnERR_MASK          ((uint32_t)(0x01 << 0))

#define __WP_PROTECT_CMD_ENABLE(cmd_reg) do{ \
                                           *(__IO uint32_t *)cmd_reg = FIXED_VALUE_TO_CMD_REG; \
                                         }while(0)
#define __WP_PROTECT_STAT_READ(stat_reg) (*(__IO uint32_t *)stat_reg & PROTSnERR_MASK)

ErrorStatus  Write_Protected_Process(WP_Opt_Reg dst_reg,uint32_t dst_val)
{
    uint8_t step_count = 2;//step 2
    uint32_t value_to_write = dst_val;

    //Step 1 Write the fixed value 0000 00A5H to the protection command register
    __WP_PROTECT_CMD_ENABLE(dst_reg.dst_protect_cmd_reg);

    //Step 2 Write the desired value to the protected register
    //Step 3 Write the bit-wise inversion of the desired value to the protected register
    //Step 4 Write the desired value to the protected register
    for(;step_count < 5;step_count++){
        *(__IO uint32_t *)dst_reg.dst_protect_reg = value_to_write;
        value_to_write = ~value_to_write;
    }

    //Step 5 Verify that the desired value has been written to the protected register
    return (ErrorStatus)__WP_PROTECT_STAT_READ(dst_reg.dst_protect_stat_reg);
}
