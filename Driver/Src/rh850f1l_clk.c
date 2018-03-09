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
#define __MOSCST_CLK_CONFIG(value)          do { \
                                                uint32_t tmp_val; \
                                                tmp_val = value & MOSCCLKST_MASK; \
                                                MOSCST = tmp_val; \
                                            }while(0)

#define __SOSCST_CLK_CONFIG(value)  do { \
                                        uint32_t tmp_val; \
                                        tmp_val = value & SOSCCLKST_MASK; \
                                        SOSCST = tmp_val; \
                                    }while(0)

#define __SET_FOUTDIV_RATIO(value)  do { \
                                        uint32_t tmp_val; \
                                        tmp_val = value & FOUT_DIV_MASK; \
                                        FOUTDIV = tmp_val;\
                                    }while(0)

#define __GET_FOUTDIV_STATUS()      (FOUTSTAT & (FOUTSYNC_MASK | FOUTCLKACT_MASK))

typedef struct{
    DOMAIN_CLK_Type index;
    SET_CLK_DOMAIN_RET_Type (*Domain_Set_Func)(WP_Opt_Reg*);
}DOMAIN_SET_Ref;

#define SET_DOMAIN_ISO_FUNC_DECLARE(index) static SET_CLK_DOMAIN_RET_Type \
                                            C_ISO_##index##_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
#define SET_DOMAIN_AWO_FUNC_DECLARE(index) static SET_CLK_DOMAIN_RET_Type \
                                            C_AWO_##index##_Domain_Set(WP_Opt_Reg *wp_reg_ptr)

SET_DOMAIN_AWO_FUNC_DECLARE(AWDTA);
SET_DOMAIN_AWO_FUNC_DECLARE(ARTCA);
SET_DOMAIN_AWO_FUNC_DECLARE(AFOUT);
SET_DOMAIN_ISO_FUNC_DECLARE(CPUCLK);
SET_DOMAIN_ISO_FUNC_DECLARE(IPERI1);
SET_DOMAIN_ISO_FUNC_DECLARE(IPERI2);
SET_DOMAIN_ISO_FUNC_DECLARE(ILIN);
SET_DOMAIN_ISO_FUNC_DECLARE(ICAN);
SET_DOMAIN_ISO_FUNC_DECLARE(ICANOSC);


DOMAIN_SET_Ref dsf[] = {
    {AWDTA, C_AWO_AWDTA_Domain_Set},
    {ARTCA, C_AWO_ARTCA_Domain_Set},
    {AFOUT, C_AWO_AFOUT_Domain_Set},
    {CPUCLK,C_ISO_CPUCLK_Domain_Set},
    {IPERI1,C_ISO_IPERI1_Domain_Set},
    {IPERI2,C_ISO_IPERI2_Domain_Set},
    {ILIN,C_ISO_ILIN_Domain_Set},
    {ICAN,  C_ISO_ICAN_Domain_Set},
    {ICANOSC,C_ISO_ICANOSC_Domain_Set},
};

static MOSC_AMP_GAIN_Type Clock_MOSC_Control(OperateDirection optd, MOSC_AMP_GAIN_Type val);

void Clock_MOSC_Config(OSC_OPT_Type opt)
{
    if(Clock_OSC_Get_Status(M_OSC_TYPE) == OSC_INACTIVE) {
        __MOSCST_CLK_CONFIG(MOSC_STABLE_TIME);//set this register when MOSC stopped
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

void Clock_SOSC_Config(OSC_OPT_Type opt)
{
    if(Clock_OSC_Get_Status(S_OSC_TYPE) == OSC_INACTIVE) {
        __SOSCST_CLK_CONFIG(SOSC_STABLE_TIME);//set this register when SOSC stopped
        if(opt == OSC_ENABLE) {
            WP_Opt_Reg clk_wp_reg; \
            clk_wp_reg.dst_protect_stat_reg_addr = &PROTS0; \
            clk_wp_reg.dst_protect_cmd_reg_addr  = &PROTCMD0; \
            clk_wp_reg.dst_protect_reg_addr = &SOSCE; \
            __OSCE_CLK_ENABLE(clk_wp_reg,SOSCENTRG_MASK);
            //Wait for stabilization TDO
            while(Clock_OSC_Get_Status(S_OSC_TYPE) == OSC_INACTIVE);

            return ;// Now the SOSC is actived
        }
    }
    if(opt == OSC_DISABLE) //opt == OSC_DISABLE
        __OSCE_CLK_DISABLE(SOSCE,SOSCDISTRG_MASK); //TODO
}

OSC_STATUS_Type Clock_OSC_Get_Status(X_OSC_Type otp)
{
    uint32_t bit_mask  = 0;
    uint32_t act_mask  = 0;
    if(otp == M_OSC_TYPE) { //Status about Main OSC
        bit_mask = MOSCS & MOSCCLKACT_MASK;
        act_mask = MOSCCLKACT_MASK;
    }
    if(otp == S_OSC_TYPE){
        bit_mask = SOSCS & SOSCCLKACT_MASK;
        act_mask = SOSCCLKACT_MASK;
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
                    (PLLC_PA_MASK & ((PLLC_PAR/2) << PLLC_PA_BITOFFSET)) |
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

SET_CLK_DOMAIN_RET_Type Clock_Domain_Set(DOMAIN_CLK_Type index)
{
    WP_Opt_Reg clk_wp_reg;
    if(index <= AFOUT){
        clk_wp_reg.dst_protect_cmd_reg_addr = &PROTCMD0;
        clk_wp_reg.dst_protect_stat_reg_addr= &PROTS0;
    }else if(index < DOMAIN_CLK_TYPE_MAX){
        clk_wp_reg.dst_protect_cmd_reg_addr = &PROTCMD1;
        clk_wp_reg.dst_protect_stat_reg_addr= &PROTS1;
    }
    do{
        int i = 0;
        for(; i < ARRAY_SIZE(dsf);i++){
            if(dsf[i].index == index){
                SET_CLK_DOMAIN_RET_Type ret;
                ret = dsf[i].Domain_Set_Func(&clk_wp_reg);
                return ret;
            }
        }

    }while(0);

    return SET_OTHER_FAIL;
}

SET_CLK_DOMAIN_RET_Type C_ISO_CPUCLK_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Step 1 Set up a source clock*/
    val_.src_clk_ctl_val = CPUCLK_SRC_CPLLCLK;//Source Clock Setting for C_ISO_CPUCLK
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,CPUCLK,S_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(CPUCLK,S_CTL_MASK))) != ERROR);//Select a source clock
    if(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,CPUCLK,S_ACT) & STR_CONCAT2(CPUCLK,S_ACT_MASK))) { //Confirm completion of selection
        return SET_SRC_CLK_FAIL;
    }
    /*Step 2 Set up a clock divider*/
    val_.clk_divider_val = CPUCLK_CTL_DIVI_1;//CKSC_CPUCLKS_CTL selection /1 (Default)
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,CPUCLK,D_CTL);
    while(Write_Protected_Process(*ptr,(val_.clk_divider_val & STR_CONCAT2(CPUCLK,D_CTL_MASK))) != ERROR);//Select a clock divider

    if(val_.clk_divider_val != (STR_CONCAT3(CKSC_,CPUCLK,D_ACT) & STR_CONCAT2(CPUCLK,D_ACT_MASK))) { //Confirm completion of selection
        return SET_CLK_DIVIDER_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;

}

SET_CLK_DOMAIN_RET_Type C_ISO_IPERI1_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Source Clock Setting for C_ISO_PERI1*/
    val_.src_clk_ctl_val = IPERI1_SRC_CPUCLK2;//Source Clock Setting for C_ISO_CPUCLK
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,IPERI1,S_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(IPERI1,S_CTL_MASK))) != ERROR);//Select a source clock
    if(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,IPERI1,S_ACT) & STR_CONCAT2(IPERI1,S_ACT_MASK))) { //Confirm completion of selection
        return SET_SRC_CLK_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;

}

SET_CLK_DOMAIN_RET_Type C_ISO_IPERI2_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Source Clock Setting for C_ISO_PERI2*/
    val_.src_clk_ctl_val = IPERI2_SRC_PPLLCLK2;//Source Clock Setting for C_ISO_CPUCLK
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,IPERI2,S_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(IPERI2,S_CTL_MASK))) != ERROR);//Select a source clock
    if(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,IPERI2,S_ACT) & STR_CONCAT2(IPERI2,S_ACT_MASK))) { //Confirm completion of selection
        return SET_SRC_CLK_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;

}


SET_CLK_DOMAIN_RET_Type C_ISO_ILIN_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Step 1 Source Clock Setting for C_ISO_LIN*/
    val_.src_clk_ctl_val = ILIN_SRC_CPUCLK2;//Source Clock Setting for C_ISO_LIN
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,ILIN,S_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(ILIN,S_CTL_MASK))) != ERROR);//Select a source clock
    while(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,ILIN,S_ACT) & STR_CONCAT2(ILIN,S_ACT_MASK))) { //Confirm completion of selection
        //return SET_SRC_CLK_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;

    /*Step 2 Set up a clock divider The setting of this register is only applicable to RLIN30*/
    val_.clk_divider_val = ILIN_CTL_DIVI_1;//CKSC_ILINS_CTL selection /1 (default)
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,CPUCLK,D_CTL);
    while(Write_Protected_Process(*ptr,(val_.clk_divider_val & STR_CONCAT2(CPUCLK,D_CTL_MASK))) != ERROR);//Select a clock divider

    if(val_.clk_divider_val != (STR_CONCAT3(CKSC_,CPUCLK,D_ACT) & STR_CONCAT2(CPUCLK,D_ACT_MASK))) { //Confirm completion of selection
        return SET_CLK_DIVIDER_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;

}

SET_CLK_DOMAIN_RET_Type C_ISO_ICAN_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Source Clock Setting for C_ISO_CAN*/
    val_.src_clk_ctl_val = ICAN_SRC_CPUCLK;//Source Clock Setting for C_ISO_CAN
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,ICAN,S_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(ICAN,S_CTL_MASK))) != ERROR);//Select a source clock
    while(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,ICAN,S_ACT) & STR_CONCAT2(ICAN,S_ACT_MASK))) { //Confirm completion of selection
        //return SET_SRC_CLK_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;

}

SET_CLK_DOMAIN_RET_Type C_ISO_ICANOSC_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Set up a clock divider*/
    val_.clk_divider_val = ICANOSC_DIV_MAINOSC_1;//CKSC_ICANOSCD_CTL MainOSC /1
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,ICANOSC,D_CTL);
    while(Write_Protected_Process(*ptr,(val_.clk_divider_val & STR_CONCAT2(ICANOSC,D_CTL_MASK))) != ERROR);//Select a clock divider

    while(val_.clk_divider_val != (STR_CONCAT3(CKSC_,ICANOSC,D_ACT) & STR_CONCAT2(ICANOSC,D_ACT_MASK))) { //Confirm completion of selection
        //return SET_CLK_DIVIDER_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;

}

void Clock_Fout_Config(void)
{
    uint32_t mask = 0,flag = FOUTCLKACT_MASK ;//| FOUTSYNC_MASK;

    __SET_FOUTDIV_RATIO(0x01);//set the clock division ratio to 1

    mask = __GET_FOUTDIV_STATUS();

    while((mask & flag) != flag) {
        //Frequency output is stopped or
        //The clock divider is in the process of synchronization
    }


}

SET_CLK_DOMAIN_RET_Type C_AWO_AFOUT_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Source Clock Setting for C_AWO_FOUT*/
    val_.src_clk_ctl_val = AFOUT_SRC_MOSC;//Source Clock Setting for C_AWO_FOUT
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,AFOUT,S_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(AFOUT,S_CTL_MASK))) != ERROR);//Select a source clock
    if(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,AFOUT,S_ACT) & STR_CONCAT2(AFOUT,S_ACT_MASK))) { //Confirm completion of selection
        return SET_SRC_CLK_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;
}


SET_CLK_DOMAIN_RET_Type C_AWO_AWDTA_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Set up a clock divider*/
    val_.src_clk_ctl_val = AWDTA_LSOSC_1;//Source Clock Setting for C_AWO_WDTA
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,AWDTA,D_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(AWDTA,D_CTL_MASK))) != ERROR);//Select a source clock
    if(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,AWDTA,D_ACT) & STR_CONCAT2(AWDTA,D_ACT_MASK))) { //Confirm completion of selection
        return SET_SRC_CLK_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;
}

SET_CLK_DOMAIN_RET_Type C_AWO_ARTCA_Domain_Set(WP_Opt_Reg *wp_reg_ptr)
{
    WP_Opt_Reg *ptr = wp_reg_ptr;
    SET_CLK_DOMAIN_Struct val_;
    /*Source Clock Setting for C_AWO_RTCA*/
    val_.src_clk_ctl_val = ARTCA_SUBOSC;//Source Clock Setting for C_AWO_RTCA
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,ARTCA,S_CTL);
    while(Write_Protected_Process(*ptr,(val_.src_clk_ctl_val & STR_CONCAT2(ARTCA,S_CTL_MASK))) != ERROR);//Select a source clock
    while(val_.src_clk_ctl_val != (STR_CONCAT3(CKSC_,ARTCA,S_ACT) & STR_CONCAT2(ARTCA,S_ACT_MASK))) { //Confirm completion of selection
        //return SET_SRC_CLK_FAIL;
    }

    val_.clk_divider_val = ARTCA_CTL_DIVI_1;//CKSC_ARTCAS_CTL selection /1 (Default)
    ptr->dst_protect_reg_addr = &STR_CONCAT3(CKSC_,ARTCA,D_CTL);
    while(Write_Protected_Process(*ptr,(val_.clk_divider_val & STR_CONCAT2(ARTCA,D_CTL_MASK))) != ERROR);//Select a clock divider

    while(val_.clk_divider_val != (STR_CONCAT3(CKSC_,ARTCA,D_ACT) & STR_CONCAT2(ARTCA,D_ACT_MASK))) { //Confirm completion of selection
        //return SET_CLK_DIVIDER_FAIL;
    }
    return SET_CLK_DOMAIN_SUCCESS;
}
