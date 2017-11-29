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

/*Clock Oscillator registers mask or value*/
#define ROSCCLKACT_MASK     ((uint32_t)(0x01 << 2))
#define ROSCCLK_FREQUENCY   (8*1024*1024) //Hi IntOSC frequency8MHz

#define MOSCENTRG_MASK      ((uint32_t)(0x01))
#define MOSCDISTRG_MASK     ((uint32_t)(0x01 << 1))
#define MOSCCLKACT_MASK     ((uint32_t)(0x01 << 2))
#define MOSCAMPSEL_MASK     ((uint32_t)(0x03))
#define MOSCCLKST_MASK      ((uint32_t)0x0FFFF)
#define STABLIZATION_TIME   (2*ROSCCLK_FREQUENCY/1000) //when HI OSC actived,about 2ms

#define PLLENTRG_MASK       ((uint32_t)0x01 << 0)
#define PLLDISTRG_MASK      ((uint32_t)0x01 << 1)
#define PLLCLKACT_MASK      ((uint32_t)0x01 << 2)

#define PLLC_OUTBSEL_OFFSET 16
#define PLLC_OUTBSEL_MASK   ((uint32_t)0x01 << PLLC_OUTBSEL_OFFSET) //bit 16
#define PLLC_M_BITOFFSET    11
#define PLLC_M_MASK         ((uint32_t)0x03 << PLLC_M_BITOFFSET) //bit 12,11
#define PLLC_PA_BITOFFSET   8
#define PLLC_PA_MASK        ((uint32_t)0x07 << PLLC_PA_BITOFFSET)  //bit 10,9,8
#define PLLC_N_BITOFFSET    0
#define PLLC_N_MASK         ((uint32_t)0x3F << PLLC_N_BITOFFSET)  //bit 5,4,3,2,1,0
#define PLLC_MASK           (PLLC_OUTBSEL_MASK | PLLC_M_MASK| PLLC_PA_MASK | PLLC_N_MASK)
/*MainOSC 16MHz outsel =0 ,Mr = 2 -- > M Bit[12:11] = 01,pa = 4,Nr = 40 --> N Bit[5:0] = 10 0111*/ 
#define PLLC_OUTBSEL        00
#define PLLC_MR             2 //16 MHz ≤ fX ≤ 24 MHz
#define PLLC_PAR            4 //60 MHz to 80 MHz
#define PLLC_NR             40

/*Clock Selector registers mask*/

#define CPUCLKS_CTL_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_CTL Bit Mask
#define CPUCLKS_ACT_MASK    ((uint32_t)0x03) //CKSC_CPUCLKS_ACT Bit Mask
#define CPUCLKD_CTL_MASK
#define CPUCLKD_ACT_MASK


#define __OSCE_CLK_ENABLE(wp_reg,mask) do{ \
                                            /*MOSCE &= MOSCENTRG_MASK;*/ \
                                            while(Write_Protected_Process(wp_reg,mask) != ERROR); \
                                        }while(0)

#define __OSCE_CLK_DISABLE(reg,mask)    do { \
                                            reg = mask; \
                                        }while(0)
#define __OSCC_CLK_READ(reg,mask)   (reg & mask)

/*specify amplification gain of the MainOSC,or 
set the PLL output clock frequencies fPPLLCLK and fCPLLCLK*/
#define __OSCC_CLK_WRITE(reg,mask,value)    do { \
                                                uint32_t tmp_val; \
                                                tmp_val = value & mask; \
                                                reg = tmp_val; \
                                            }while(0)
/*Set MainOSC stabilization time,Note: set this register when MainOSC is stopped*/
#define __MOSCST_CLK_CONFIG(value)  do { \
                                        uint32_t tmp_val; \
                                        tmp_val = value & MOSCCLKST_MASK; \
                                        MOSCST = tmp_val; \
                                    }while(0)

#define __SET_SRC_CLK(index,value) do { \
                                        WP_Opt_Reg clk_wp_reg; \
                                        clk_wp_reg.dst_protect_stat_reg_addr = &PROTCMD1; \
                                        clk_wp_reg.dst_protect_cmd_reg_addr  = &PROTS1; \
                                        clk_wp_reg.dst_protect_reg_addr = &STR_CONCAT3(CKSC_,domain_clk_type[index],S_CTL); \
                                        while(Write_Protected_Process(wp_reg,(value & STR_CONCAT2(domain_clk_type[index],_MASK))) != ERROR); \
                                    }while(0)


#define __SET_SRC_CLK_CONFIRM(index)     (STR_CONCAT3(CKSC_,domain_clk_type[index],S_ACT) & STR_CONCAT2(domain_clk_type[index],_MASK))

#define __SET_CLK_DIVI(index,value)    do { \
                                            WP_Opt_Reg clk_wp_reg; \
                                            clk_wp_reg.dst_protect_stat_reg_addr = &PROTCMD1; \
                                            clk_wp_reg.dst_protect_cmd_reg_addr  = &PROTS1; \
                                            clk_wp_reg.dst_protect_reg_addr = &STR_CONCAT3(CKSC_,domain_clk_type[index],S_CTL); \
                                            while(Write_Protected_Process(clk_wp_reg,(value & STR_CONCAT2(domain_clk_type[index],_MASK))) != ERROR); \
                                        }while(0)

#define __SET_CLK_DIVI_CONFIRM(index)    (STR_CONCAT3(CKSC_,domain_clk_type[index],D_ACT) & STR_CONCAT2(domain_clk_type[index],_MASK))

static MOSC_AMP_GAIN_Type Clock_MOSC_Control(OperateDirection optd, MOSC_AMP_GAIN_Type val);


void Clock_MOSC_Config(OSC_OPT_Type opt)
{   
    if(Clock_OSC_Get_Status(M_OSC_TYPE) == OSC_INACTIVE) {
        __MOSCST_CLK_CONFIG(STABLIZATION_TIME);//set this register when MOSC stopped
        //__OSCC_CLK_WRITE(MOSCC,MOSCAMPSEL_MASK,MOSC_AMP_MID_LOW);//the external resonator is 16MHz
        Clock_MOSC_Control(OPT_WRITE,MOSC_AMP_MID_LOW);//the external resonator is 16MH
        if(opt == OSC_ENABLE) {
            WP_Opt_Reg clk_wp_reg; \
            clk_wp_reg.dst_protect_stat_reg_addr = &PROTS0; \
            clk_wp_reg.dst_protect_cmd_reg_addr  = &PROTCMD0; \
            clk_wp_reg.dst_protect_reg_addr = &MOSCE; \
            __OSCE_CLK_ENABLE(clk_wp_reg,MOSCENTRG_MASK);
            //Wait for stabilization TDO
            while(Clock_OSC_Get_Status(M_OSC_TYPE) == OSC_INACTIVE);

            return ;// Now the MOSC is actived
        }
    }
    if(opt == OSC_DISABLE) //opt == OSC_DISABLE
        __OSCE_CLK_DISABLE(MOSCE,MOSCDISTRG_MASK); //TODO
}

OSC_STATUS_Type Clock_OSC_Get_Status(X_OSC_Type otp)
{
    uint32_t bit_mask  = 0;
    uint32_t act_mask  = 0;
    if(otp == M_OSC_TYPE) { //Status about Main OSC
        bit_mask = MOSCS & MOSCCLKACT_MASK;
        act_mask = MOSCCLKACT_MASK;
    }
    if(otp == PLL_TYPE) { //Status about PLL
        bit_mask = PLLS & PLLCLKACT_MASK;
        act_mask = PLLCLKACT_MASK;
    }
    if(otp == R_OSC_TYPE) { //Status about Hi IntOSC
        bit_mask = ROSCS & ROSCCLKACT_MASK;
        act_mask = ROSCCLKACT_MASK;
    }
    if(bit_mask == act_mask)//Vertify active status
        return OSC_ACTIVED;
    
    return OSC_INACTIVE;
}

MOSC_AMP_GAIN_Type Clock_MOSC_Control(OperateDirection optd, MOSC_AMP_GAIN_Type val)
{
    switch(optd)
    {
        case OPT_WRITE:
            __OSCC_CLK_WRITE(MOSCC,MOSCAMPSEL_MASK,val);//the external resonator is 16MHz
        case OPT_READ:
        default:
            return (MOSC_AMP_GAIN_Type)__OSCC_CLK_READ(MOSCC,MOSCAMPSEL_MASK);//whether read or write,read back finally
    }
}

void Clock_PLL_Config(OSC_OPT_Type opt)
{
    //Before starting PLL using PLLENTRG, confirm that MainOSC is operating
    if(Clock_OSC_Get_Status(PLL_TYPE) == OSC_INACTIVE) {
        uint32_t pllc_val = (PLLC_OUTBSEL_MASK &(PLLC_OUTBSEL << PLLC_OUTBSEL_OFFSET)) | 
                    (PLLC_M_MASK & ((PLLC_MR - 1) << PLLC_M_BITOFFSET)) |
                    (PLLC_PA_MASK & (PLLC_PAR << PLLC_PA_BITOFFSET)) |
                    (PLLC_N_MASK & ((PLLC_NR - 1) << PLLC_N_BITOFFSET));

        __OSCC_CLK_WRITE(PLLC,PLLC_MASK,pllc_val);
        if(Clock_OSC_Get_Status(M_OSC_TYPE) == OSC_ACTIVED &&
            opt == OSC_ENABLE) { 
            WP_Opt_Reg clk_wp_reg;
            clk_wp_reg.dst_protect_stat_reg_addr = &PROTS1;
            clk_wp_reg.dst_protect_cmd_reg_addr  = &PROTCMD1;
            clk_wp_reg.dst_protect_reg_addr = &PLLE;
            __OSCE_CLK_ENABLE(clk_wp_reg,PLLENTRG_MASK);
             //Wait for stabilization TDO
            while(Clock_OSC_Get_Status(PLL_TYPE) == OSC_INACTIVE);
        }
    }else {//opt == OSC_DISABLE

    }
}

SET_CLK_DOMAIN_RET_Type Clock_Domain_Set(DOMAIN_CLK_Type index,SET_CLK_DOMAIN_Struct val)
{
    WP_Opt_Reg clk_wp_reg; 
    clk_wp_reg.dst_protect_stat_reg_addr = &PROTCMD1;
    clk_wp_reg.dst_protect_cmd_reg_addr  = &PROTS1;
    switch(index)
    {
        case CPUCLK:
            clk_wp_reg.dst_protect_reg_addr = &STR_CONCAT3(CKSC_,CPUCLK,S_CTL);
            break;
        case IPERI1:
             clk_wp_reg.dst_protect_reg_addr = &STR_CONCAT3(CKSC_,IPERI1,S_CTL);
            break;
        case IPERI2:
             clk_wp_reg.dst_protect_reg_addr = &STR_CONCAT3(CKSC_,IPERI2,S_CTL);
            break;
    }
#if 0
    /*Step 1 Set up a source clock*/
    __SET_SRC_CLK(index,val.src_clk_ctl_val);//Select a source clock
    if(val.src_clk_val != __SET_SRC_CLK_CONFIRM(index)) { //Confirm completion of selection
        return SET_SRC_CLK_FAIL;
    }
    /*Step 2 Set up a clock divider*/
    clk_wp_reg.dst_protect_reg_addr = &STR_CONCAT3(CKSC_,domain_clk_type[index],D_CTL);
    __SET_CLK_DIVI(index,val.clk_divider_val);//Select a clock divider

    if(val.clk_divider_val != __SET_CLK_DIVI_CONFIRM(index)) { //Confirm completion of selection
        return SET_CLK_DIVIDER_FAIL
    }
#endif
    return SET_CLK_DOMAIN_SUCCESS;
}