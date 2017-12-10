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

#define __GET_EIINT_ICXX_CTL(ret,target_reg)  do{ \
                                                ret = (IC_##target_reg) & EIINT_ICXX_MASK; \
                                              }while(0);

#define __GET_EIINT_RFXX_CTL(ret, target_reg) do{ \
                                                ret = (IC_##target_reg) & EIINT_RFXX_MASK; \
                                              } while (0);

#define __SET_EIINT_RFXX_CTL(target_reg,st) do{ \
                                              uint16_t tmp  = set & EIINT_RFXX_MASK; \
                                              if(tmp != (uint16_t)0x00) \
                                                IC_##target_reg |=  EIINT_RFXX_MASK; \
                                              else \
                                                IC_##target_reg &= ~EIINT_RFXX_MASK; \
                                              }while(0);

#define __GET_EIINT_MKXX_CTL(ret, target_reg) do{ \
                                                ret = (IC_##target_reg) & EIINT_MKXX_MASK; \
                                              }while (0);

#define __SET_EIINT_MKXX_CTL(target_reg, st) do{                                          \
                                              uint16_t tmp = set & EIINT_MKXX_MASK; \
                                              if (tmp != (uint16_t)0x00) \
                                                IC_##target_reg |= EIINT_MKXX_MASK; \
                                              else \
                                                IC_##target_reg &= ~EIINT_MKXX_MASK; \
                                              } while (0);

#define __GET_EIINT_TBXX_CTL(ret, target_reg) do{ \
                                                ret = (IC_##target_reg) & EIINT_TBXX_MASK; \
                                              } while (0);

#define __SET_EIINT_TBXX_CTL(target_reg, st) do{                                          \
                                              uint16_t tmp = set & EIINT_TBXX_MASK; \
                                              if (tmp != (uint16_t)0x00) \
                                                IC_##target_reg |= EIINT_TBXX_MASK; \
                                              else \
                                                IC_##target_reg &= ~EIINT_TBXX_MASK; \
                                              } while (0);

											  
#define __GET_EIINT_PXXX_CTL(ret, target_reg) do{ \
                                                ret = (IC_##target_reg) & EIINT_PXXX_MASK; \
                                              } while (0);
#define __SET_EIINT_PXXX_CTL(target_reg, st) do{                                          \
                                              uint16_t tmp = set & EIINT_TBXX_MASK; \
                                              if (tmp != (uint16_t)0x00) \
                                                IC_##target_reg |= EIINT_TBXX_MASK; \
                                              else \
                                                IC_##target_reg &= ~EIINT_TBXX_MASK; \
                                              } while (0);

/*ch_group : 0-8,offset : 0-31.Example IMR5EIMK163, ch_group -> 5,offset = (163 - 5*32)*/
#define __GET_EIINT_IMRm(ret,ch_group,offset)   do{ \
                                                  ret = IMR##ch_group & (0x01 << offset) \
                                                }while(0);

void Eiit_Sel_Bit_Set(EIINT_SEL_Type sel_t, BitAction bita,uint16_t mask_bit)
{
  __IO uint16_t bitpos = mask_bit, current_bit = 0x00;
  __IO uint16_t *target_reg = NULL; //address of target register

  if(bitpos == 0x00) return;

  if (sel_t == SELB_INTC1_REG){
    if(bitpos >> 12) return;//highest bit is 11
    target_reg = &SELB_INTC1;
  }else if(sel_t == SELB_INTC2_TYPE){
    if (bitpos >> 11) return; //highest bit is 10
    target_reg == &SELB_INTC2;
  }

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(target_reg, bitpos);

  if (current_bit == 0x00 && bita == Bit_SET) //bitpos需要被置位
    SET_BIT(target_reg, bitpos);
  if (current_bit != 0x00 && bita == Bit_RESET) //bitpos需要被清零
    CLEAR_BIT(target_reg, bitpos);
}

void Eiint_Sel_Set(EIINT_SEL_Type sel_t, BitAction bita, uint16_t mask)
{
  __IO uint16_t pinpos = 0x00, bitpos = 0x00, mask_bit = 0x00, last_bit = mask;

  for(;pinpos < 0x0f && (last_bit >> pinpos);pinpos++){
    bitpos = 0x01 << pinpos;

    mask_bit = READ_BIT(&last_bit, bitpos);

    if(mask_bit == 0x00)
      continue;
    
    Eiit_Sel_Bit_Set(sel_t,bita,mask_bit);
  }
}

uint16_t Eiint_Sel_Get(EIINT_SEL_Type sel_t uint16_t mask)
{
  uint16_t ret = 0x00;
#if ASSERT_EN
  assert_param(mask);
#endif
  if (sel_t == SELB_INTC1_REG){
    target_reg = &SELB_INTC1;
  }else if (sel_t == SELB_INTC2_TYPE){
    target_reg == &SELB_INTC2;
  }

  ret = READ_BIT(target_reg,mask);

  return ret;
}
