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

#define MOSCCLKST_MASK      ((uint32_t)0x0FFFF)
#define STABLIZATION_TIME   (2*ROSCCLK_FREQUENCY/1000) //when HI OSC actived,about 2ms


#define ROSCCLKACT_MASK      ((uint32_t)(0x01 << 2))

#define __MOSCE_CLK_ENABLE() do{ \
                                WP_Opt_Reg clk_wp_reg; \
                                clk_wp_reg.dst_protect_stat_reg_addr = &CLOCK_WP_STAT_REG; \
                                clk_wp_reg.dst_protect_cmd_reg_addr  = &CLOCK_WP_CMD_REG; \
                                clk_wp_reg.dst_protect_reg_addr = &MOSCE; \
                               /*MOSCE &= MOSCENTRG_MASK;*/ \
                               while(Write_Protected_Process(clk_wp_reg,MOSCENTRG_MASK) != ERROR); \
                             }while(0)

#define __MOSCE_CLK_DISABLE() do{ \
                                MOSCE = MOSCDISTRG_MASK; \
                              }while(0)
#define __MOSCC_CLK_READ()   (MOSCC & MOSCAMPSEL_MASK)

/*specify amplification gain of the MainOSC*/
#define __MOSCC_CLK_WRITE(value) do{ \
                                   uint32_t tmp_val; \
                                   tmp_val = value & MOSCAMPSEL_MASK; \
                                   MOSCC = tmp_val; \
                            }while(0)
/*Set MainOSC stabilization time,Note: set this register when MainOSC is stopped*/
#define __MOSCST_CLK_CONFIG(value) do{ \
                                    uint32_t tmp_val; \
                                    tmp_val = value & MOSCCLKST_MASK; \
                                    MOSCST = tmp_val; \
                                    }while(0)

void Clock_MOSC_Config(MOSC_OPT_Type opt)
{   
    if(Clock_MOSC_Get_Status() == OSC_INACTIVE)
    {
        __MOSCST_CLK_CONFIG(STABLIZATION_TIME);//set this register when MOSC stopped
        __MOSCC_CLK_WRITE(MOSC_AMP_MID_LOW);//the external resonator is 16MHz
        if(opt == MOSC_ENABLE){
            __MOSCE_CLK_ENABLE();
            //Wait for stabilization TDO
            while(Clock_MOSC_Get_Status() == OSC_INACTIVE);

            return ;// Now the MOSC is actived
        }
    }
    if(opt == MOSC_DISABLE) //opt == MOSC_DISABLE
        __MOSCE_CLK_DISABLE(); //TODO
}

MOSC_STATUS_Type Clock_MOSC_Get_Status(void)
{
    uint32_t bit_mask = MOSCS & MOSCCLKACT_MASK;
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

ROSCSTATUS_Type Clock_ROSC_Get_Status()
{
    uint32_t bit_mask = ROSCS & ROSCCLKACT_MASK;
    if(bit_mask == ROSCCLKACT_MASK)
        return OSC_ACTIVED;
    else
        return OSC_INACTIVE;
}