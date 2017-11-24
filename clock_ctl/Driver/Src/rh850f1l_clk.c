/**
  ******************************************************************************
  * @file    rh850f1l_clk.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   24-November-2017
  * @brief   Clock Control module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and Clock Control (RCC) peripheral:
  *           + Initialization and de-initialization functions
  *           + Clock Control functions
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rh850f1l_clk.h"
#include "rh850f1l_wp.h"

#define CLOCK_WP_CMD_REG    PROTCMD0
#define CLOCK_WP_STAT_REG   PROTS0

#define MOSCENTRG_MASK       ((uint32_t)(0x01 << 0))
#define MOSCDISTRG_MASK      ((uint32_t)(0x01 << 1))
#define MOSCCLKACT_MASK      ((uint32_t)(0x01 << 2))
#define MOSCAMPSEL_MASK      ((uint32_t)(0x03))

#define ROSCCLKACT_MASK      ((uint32_t)(0x01 << 2))

#define __MOSCE_CLK_ENABLE() do{ \
                                WP_Opt_Reg clk_wp_reg; \
                                clk_wp_reg.dst_protect_stat_reg = CLOCK_WP_STAT_REG; \
                                clk_wp_reg.dst_protect_cmd_reg  = CLOCK_WP_CMD_REG; \
                                clk_wp_reg.dst_protect_reg = MOSCE; \
                               /*(__IO uint32_t *)MOSCE &= MOSCENTRG_MASK;*/ \
                               Write_Protected_Process(clk_wp_reg,MOSCENTRG_MASK); \
                             }while(0)

#define __MOSCE_CLK_DISABLE() do{ \
                                *(__IO uint32_t *)MOSCE &= MOSCDISTRG_MASK; \
                              }while(0)
#define __MOSCC_CLK_READ()   (*(__IO uint32_t *)MOSCC & MOSCAMPSEL_MASK)

#define __MOSCC_CLK_WRITE(value) do{ \
                                   __IO uint32_t tmp_val; \
                                   tmp_val = value & MOSCAMPSEL_MASK; \
                                   *(__IO uint32_t *)MOSCC &= tmp_val; \
                            }while(0)

void Clock_MOSC_Config(MOSC_OPT_Type opt)
{
    if(opt == MOSC_ENABLE && Clock_MOSC_Get_Status() == OSC_INACTIVE){
        __MOSCE_CLK_ENABLE();
        //Wait for stabilization TDO
        Clock_MOSC_Get_Status();

    }
    else if(opt == MOSC_DISABLE) //opt == MOSC_DISABLE
        __MOSCE_CLK_DISABLE(); //TODO
    else
        return;
}

MOSC_STATUS_Type Clock_MOSC_Get_Status(void)
{
    uint32_t bit_mask = *(__I uint32_t *)MOSCS & MOSCCLKACT_MASK;
    if(bit_mask == MOSCCLKACT_MASK)
        return OSC_ACTIVED;
    else
        return OSC_INACTIVE;
}

MOSC_AMP_GAIN_Type Clock_MOSC_Control(OperateDirection optd, MOSC_AMP_GAIN_Type val)
{
    switch(optd)
    {
        case OPT_WRITE:
            __MOSCC_CLK_WRITE(val);
        case OPT_READ:
        default:
            return (MOSC_AMP_GAIN_Type)__MOSCC_CLK_READ();//whether read or write,read back finally
    }
}

ROSCSTATUS_Type Clock_ROSC_Get_Status(void)
{
    uint32_t bit_mask = *(__I uint32_t *)ROSCS & ROSCCLKACT_MASK;
    if(bit_mask == ROSCCLKACT_MASK)
        return OSC_ACTIVED;
    else
        return OSC_INACTIVE;
}
