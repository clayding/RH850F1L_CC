/**
  ******************************************************************************
  * @file    rh850f1l_ext.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   10-December-2017
  * @brief   Exception/Interrupt module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and Ext/Int peripheral:
  *           + Initialization and de-initialization functions
  *           + Exception/Interrupt functions
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rh850f1l_ext.h"
#include "rh850f1l_wp.h"
#include "rh850f1l_clk.h"
#include "rh850f1l_timer.h"
#include "rh850f1l_WDTA.h"

#define EIINT_ICXX_MASK ((uint16_t)(0x01 << 15))
#define EIINT_RFXX_MASK ((uint16_t)(0x01 << 12))
#define EIINT_MKXX_MASK ((uint16_t)(0x01 << 7))
#define EIINT_TBXX_MASK ((uint16_t)(0x01 << 6))
#define EIINT_PXXX_MASK ((uint16_t)0x07)

#define SELB_INTC_BIT0_MASK   ((uint16_t)0x01)
#define SELB_INTC_BIT1_MASK   ((uint16_t)(0x01 << 1))
#define SELB_INTC_BIT2_MASK   ((uint16_t)(0x01 << 2))
#define SELB_INTC_BIT3_MASK   ((uint16_t)(0x01 << 3))
#define SELB_INTC_BIT4_MASK   ((uint16_t)(0x01 << 4))
#define SELB_INTC_BIT5_MASK   ((uint16_t)(0x01 << 5))
#define SELB_INTC_BIT6_MASK   ((uint16_t)(0x01 << 6))
#define SELB_INTC_BIT7_MASK   ((uint16_t)(0x01 << 7))
#define SELB_INTC_BIT8_MASK   ((uint16_t)(0x01 << 8))
#define SELB_INTC_BIT9_MASK   ((uint16_t)(0x01 << 9))
#define SELB_INTC_BIT10_MASK  ((uint16_t)(0x01 << 10))
#define SELB_INTC_BIT11_MASK  ((uint16_t)(0x01 << 11))
/*Reserved
#define SELB_INTC_BIT12_MASK  ((uint16_t)(0x01 << 12))
#define SELB_INTC_BIT13_MASK  ((uint16_t)(0x01 << 13))
#define SELB_INTC_BIT14_MASK  ((uint16_t)(0x01 << 14))
#define SELB_INTC_BIT15_MASK  ((uint16_t)(0x01 << 15))*/

#define FCLA0INTLm_MASK       ((uint8_t)(0x01 << 2))
#define FCLA0INTFm_MASK       ((uint8_t)(0x01 << 1))
#define FCLA0INTRm_MASK       ((uint8_t)0x01)

/*Get the type of interrupt detection. Read only.
  retval ret - return the bits*/
#define __GET_EIINT_ICXX_CTL(ret,_REG_ADDR_)  do{ \
                                                ret = READ_BIT(_REG_ADDR_,EIINT_ICXX_MASK); \
                                              }while(0)
/*Get an interrupt request flag.0: No interrupt request is made.1: Interrupt request is made. */
#define __GET_EIINT_RFXX_CTL(ret, _REG_ADDR_) do{ \
                                                ret = READ_BIT(_REG_ADDR_,EIINT_RFXX_MASK); \
                                              } while (0)
/*Set an interrupt request flag,Setting the RFxxx bit to 1 generates an EI level maskable interrupt n
(EIINTn), just as when an interrupt request is acknowledged*/
#define __SET_EIINT_RFXX_CTL(_REG_ADDR_,val)   do{ \
                                                if(val != 0) \
                                                  SET_BIT(_REG_ADDR_,EIINT_RFXX_MASK); \
                                                else \
                                                  CLEAR_BIT(_REG_ADDR_,EIINT_RFXX_MASK); \
                                              }while(0)
/*Get the interrupt request mask bit state,0-enable ,1-disable*/
#define __GET_EIINT_MKXX_CTL(ret, _REG_ADDR_) do{ \
                                                ret = READ_BIT(_REG_ADDR_,EIINT_MKXX_MASK); \
                                              }while (0)
/*Set the interrupt request mask bit state,0-enable ,1-disable*/
#define __SET_EIINT_MKXX_CTL(_REG_ADDR_, val)  do{                                          \
                                                if (val != 0) \
                                                  SET_BIT(_REG_ADDR_,EIINT_MKXX_MASK); \
                                                else \
                                                  CLEAR_BIT(_REG_ADDR_,EIINT_MKXX_MASK); \
                                              } while (0)
/*Get the way to determine the interrupt vector.0-Direct Vector Method,1-Table Reference Method*/
#define __GET_EIINT_TBXX_CTL(ret, _REG_ADDR_) do{ \
                                                ret = READ_BIT(_REG_ADDR_,EIINT_TBXX_MASK); \
                                              } while (0)
/*Select the way to determine the interrupt vector. 0-Direct Vector Method,1-Table Reference Method*/
#define __SET_EIINT_TBXX_CTL(_REG_ADDR_,val) do{                                          \
                                                if (val != 0) \
                                                  SET_BIT(_REG_ADDR_,EIINT_TBXX_MASK); \
                                                else \
                                                  CLEAR_BIT(_REG_ADDR_,EIINT_TBXX_MASK); \
                                              } while (0)

/*Get the interrupt priority,with 0 as the highest and 7 as the lowest.*/
#define __GET_EIINT_PXXX_CTL(ret, _REG_ADDR_) do{ \
                                                ret = READ_BIT(_REG_ADDR_,EIINT_PXXX_MASK); \
                                              } while (0)
/*specify the interrupt priority as one of 8 levels, with 0 as the highest and 7 as the lowest(default).*/
#define __SET_EIINT_PXXX_CTL(_REG_ADDR_, val)  do{ \
                                                uint16_t tmp = 0xFFF8; \
                                                tmp += val & EIINT_PXXX_MASK; \
                                                (*_REG_ADDR_) &= tmp;  ; \
                                              } while (0)

/*ch_group : 0-8,offset : 0-31.Example IMR5EIMK163, ch_group -> 5,offset = (163 - 5*32)*/
#define __GET_EIINT_IMRm(ret,ch_group,offset)   do{ \
                                                  ret = IMR##ch_group & (0x01 << offset) \
                                                }while(0)

//the mapping of filter control register and input signal (INPUT_SIGNAL_Type)
__IO uint8_t *filter_ctl_reg[] = {
  &FCLA0CTL0_NMI,
  &FCLA0CTL0_INTPL,&FCLA0CTL1_INTPL,&FCLA0CTL2_INTPL,&FCLA0CTL3_INTPL,&FCLA0CTL4_INTPL,&FCLA0CTL5_INTPL,
  &FCLA0CTL6_INTPL,&FCLA0CTL7_INTPL,&FCLA0CTL0_INTPH,&FCLA0CTL1_INTPH,&FCLA0CTL2_INTPH,&FCLA0CTL3_INTPH,
  &FCLA0CTL4_INTPH,&FCLA0CTL5_INTPH,&FCLA0CTL6_INTPH,&FCLA0CTL7_INTPH,
};

void Inp12Handler(unsigned long eiic);
void (*Eiit_Handler_Ptr)(void);
void (*Eiit_Handler_Ptr_2)(void);
static uintptr_t Eiit_Get_Address_By_Channel(uint8_t channel_no);

void Eiit_Init(Eiint_InitTypeDef *Eiint_InitStruct)
{
    __IO uint16_t* eiit_addr = (__IO uint16_t*)0xFFFF9000;

    if(Eiint_InitStruct->eiint_ch/0x120) return;// if chnanl number > 287(max),invalid,
    eiit_addr =(__IO uint16_t*)Eiit_Get_Address_By_Channel(Eiint_InitStruct->eiint_ch);
    __SET_EIINT_MKXX_CTL(eiit_addr,Eiint_InitStruct->eiint_process);
    __SET_EIINT_TBXX_CTL(eiit_addr,Eiint_InitStruct->eiint_refer_method);
    __SET_EIINT_PXXX_CTL(eiit_addr,Eiint_InitStruct->eiint_priority);
    if(Eiint_InitStruct->eiint_ext_int)
        Eiit_Filter_Ctl_Operate(EXT_INTP12, OPT_WRITE,&Eiint_InitStruct->eiint_detect);
/*
    eiit_addr =(__IO uint16_t*)Eiit_Get_Address_By_Channel(76);
    __SET_EIINT_MKXX_CTL(eiit_addr,Eiint_InitStruct->eiint_process);
    __SET_EIINT_TBXX_CTL(eiit_addr,Eiint_InitStruct->eiint_refer_method);
    __SET_EIINT_PXXX_CTL(eiit_addr,Eiint_InitStruct->eiint_priority);

    eiit_addr =(__IO uint16_t*)Eiit_Get_Address_By_Channel(134);
    __SET_EIINT_MKXX_CTL(eiit_addr,Eiint_InitStruct->eiint_process);
    __SET_EIINT_TBXX_CTL(eiit_addr,Eiint_InitStruct->eiint_refer_method);
    __SET_EIINT_PXXX_CTL(eiit_addr,Eiint_InitStruct->eiint_priority);*/


  /*__SET_EIINT_MKXX_CTL(P_12,Eiint_InitStruct->eiint_process);
  __SET_EIINT_TBXX_CTL(P_12,Eiint_InitStruct->eiint_refer_method);
  __SET_EIINT_PXXX_CTL(P_12,Eiint_InitStruct->eiint_priority);
  Eiit_Filter_Ctl_Operate(EXT_INTP12, OPT_WRITE,&Eiint_InitStruct->eiint_detect);

  __SET_EIINT_MKXX_CTL(OSTM0,Eiint_InitStruct->eiint_process);
  __SET_EIINT_TBXX_CTL(OSTM0,Eiint_InitStruct->eiint_refer_method);
  __SET_EIINT_PXXX_CTL(OSTM0,Eiint_InitStruct->eiint_priority);

  __SET_EIINT_MKXX_CTL(TAUB0I0,Eiint_InitStruct->eiint_process);
  __SET_EIINT_TBXX_CTL(TAUB0I0,Eiint_InitStruct->eiint_refer_method);
  __SET_EIINT_PXXX_CTL(TAUB0I0,Eiint_InitStruct->eiint_priority);*/



  __EI();
}


uintptr_t Eiit_Get_Address_By_Channel(uint8_t channel_no)
{

    static uintptr_t int_base_addr = 0xFFFF9000;
    static uintptr_t int_addr =(uintptr_t)&int_base_addr;
    uintptr_t offset_addr = 0;// prevent from invalid operate

    int_base_addr = 0xFFFF9000;
    if(channel_no >> 5)
        int_base_addr += 0x1000;//to be 0xFFFFA000

    offset_addr = channel_no *2;
    int_addr = int_base_addr + offset_addr;

    return int_addr;
}
 /* @brief this function is used to select an EI level maskable interrupt.When two interrupt sources
 * are assigned to one interrupt channel, SELB_INTC1_REG selects which interrupt sources is enabled;
 * When two interrupt sources are assigned to one interrupt channel, SELB_INTC2_REG
 * selects which interrupt sources is enabled.
 * @param bita - SET to 1 or RESET to zero
 * @mask_bit -single bit to set
 */
 void Eiit_Sel_Bit_Set(EIINT_SEL_Type sel_t, BitAction bita, uint16_t mask_bit)
 {
   __IO uint16_t bitpos = mask_bit, current_bit = 0x00;
   __IO uint16_t *target_reg = NULL; //address of target register

   if (bitpos == 0x00)
     return;

   if (sel_t == SELB_INTC1_REG){
     if (bitpos >> 12) return; //highest bit is 11,so above 11 bit invalid
     target_reg = &SELB_INTC1;
   }else if (sel_t == SELB_INTC2_REG){
    if (bitpos >> 11) return; //highest bit is 10,so above 10 bit invalid
    target_reg = &SELB_INTC2;
  }

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(target_reg, bitpos);

  if (current_bit == 0x00 && bita == Bit_SET) //bitpos需要被置位
    SET_BIT(target_reg, bitpos);
  if (current_bit != 0x00 && bita == Bit_RESET) //bitpos需要被清零
    CLEAR_BIT(target_reg, bitpos);
}

/* @brief this function is used to select an EI level maskable interrupt.When two interrupt sources
 * are assigned to one interrupt channel, SELB_INTC1_REG selects which interrupt sources is enabled;
 * When two interrupt sources are assigned to one interrupt channel, SELB_INTC2_REG
 * selects which interrupt sources is enabled.
 * @param bita - SET to 1 or RESET to zero
 * @mask -multiple bits to set
 */
void Eiint_Sel_Set(EIINT_SEL_Type sel_t, BitAction bita, uint16_t mask)
{
  __IO uint16_t pinpos = 0x00, bitpos = 0x00, mask_bit = 0x00, last_bit = mask;

  for(;pinpos < 0x10 && (last_bit >> pinpos);pinpos++){
    bitpos = 0x01 << pinpos;

    mask_bit = READ_BIT(&last_bit, bitpos);

    if(mask_bit == 0x00)
      continue;

    Eiit_Sel_Bit_Set(sel_t,bita,mask_bit);
  }
}
/* @brief Get an EI level maskable interrupt.When two interrupt sources
 * are assigned to one interrupt channel, SELB_INTC1_REG selects which interrupt sources is enabled;
 * When two interrupt sources are assigned to one interrupt channel, SELB_INTC2_REG
 * selects which interrupt sources is enabled.
 * @mask -multiple bits to set
 * @retval return the bits .
 */
uint16_t Eiint_Sel_Get(EIINT_SEL_Type sel_t,uint16_t mask)
{
  __IO uint16_t ret = 0x00,*target_reg = NULL;
#if ASSERT_EN
  assert_param(mask);
#endif
  if (sel_t == SELB_INTC1_REG){
    target_reg = &SELB_INTC1;
  }else if (sel_t == SELB_INTC2_REG){
    target_reg = &SELB_INTC2;
  }

  ret = READ_BIT(target_reg,mask);

  return ret;
}
/* @brief -Set(Write) or Get(Read) filter control register FCLA0CTLm_<name>
 * @param in_sig - the input signal defined in Table 6.10 ,INTP0 .....
 * @param trig_io -the pointer to collection of edge/level detection,high/low level detection,falling/rising edge detection
 */
void Eiit_Filter_Ctl_Operate(INPUT_SIGNAL_Type in_sig, OperateDirection opt_dir,uint8_t *trig_io)
{
  __IO uint8_t *target_reg = NULL, *trigger_method = trig_io;

  target_reg = filter_ctl_reg[in_sig];

  if(opt_dir == OPT_READ){ //out paramter
    *trigger_method = READ_BIT(target_reg,0xff);
    return;
  }

  if(opt_dir == OPT_WRITE){ //in parameter
    if(*trigger_method & LEVEL_DETECTION){
      SET_BIT(target_reg,FCLA0INTLm_MASK);
      if(*trigger_method & HIGH_LEVEL_DETECT)
        SET_BIT(target_reg, FCLA0INTRm_MASK);
      else
        CLEAR_BIT(target_reg, FCLA0INTRm_MASK);
    }else{ //if(trigger_method & EDGE_DETECTION)
      CLEAR_BIT(target_reg,FCLA0INTLm_MASK);
      if (*trigger_method & RISE_EDGE_ENABLE)
        SET_BIT(target_reg, FCLA0INTRm_MASK);
      else //if(trigger_method & RISE_EDGE_DISABLE)
        CLEAR_BIT(target_reg, FCLA0INTRm_MASK);
      if(*trigger_method & FALL_EDGE_ENABLE)
        SET_BIT(target_reg, FCLA0INTFm_MASK);
      else //if(trigger_method & FALL_EDGE_DISABLE)
        CLEAR_BIT(target_reg, FCLA0INTFm_MASK);
    }
  }
}

static uint8_t i = 0;
#pragma interrupt TAUD0CH0IntHandler(channel = 0, enable = false, callt = false, fpu = false)
void TAUD0CH0IntHandler(unsigned long eiic)
{
    //Eiit_Handler_Ptr();
    __SET_TAUD_LEVEL_TO_TOUT(1,i);
    i = !i;
}

#pragma interrupt WDTA0IntHandler(channel = 32, enable = false, callt = false, fpu = false)
void WDTA0IntHandler(unsigned long eiic)
{
    static int count = 0;
    WDTA_Reload(_WDTA0);
    if(++count / 5){
    	Eiit_Handler_Ptr_2();
	count = 0;
    }
}

#pragma interrupt WDTA1IntHandler(channel = 33, enable = false, callt = false, fpu = false)
void WDTA1IntHandler(unsigned long eiic)
{
    static int count = 0;
    WDTA_Reload(_WDTA1);
    if(++count / 5){
    	Eiit_Handler_Ptr();
	    count = 0;
    }
}

#pragma interrupt TAUD0CH1IntHandler(channel = 39, enable = false, callt = false, fpu = false)
void TAUD0CH1IntHandler(unsigned long eiic)
{
    Eiit_Handler_Ptr_2();
}

extern __IO uint32_t uw_tick;
#pragma interrupt OSTMIntHandler(channel = 76, enable = false, callt = false, fpu = false)
void OSTMIntHandler(unsigned long eiic)
{
  uw_tick++;
  OSTM_Cmp_Reload(CPUCLK2);
}

#pragma interrupt Inp12Handler(channel = 123, enable = false, callt = false, fpu = false)
void Inp12Handler(unsigned long eiic)
{
  Eiit_Handler_Ptr();
}

#pragma interrupt TAUB0CH0IntHandler(channel = 134, enable = false, callt = false, fpu = false)
void TAUB0CH0IntHandler(unsigned long eiic)
{
    //Eiit_Handler_Ptr();
}

#pragma interrupt TAUB0CH1IntHandler(channel = 135, enable = false, callt = false, fpu = false)
void TAUB0CH1IntHandler(unsigned long eiic)
{
    Eiit_Handler_Ptr_2();
}

#pragma interrupt TAUB0CH02ntHandler(channel = 136, enable = false, callt = false, fpu = false)
void TAUB0CH2IntHandler(unsigned long eiic)
{

}
