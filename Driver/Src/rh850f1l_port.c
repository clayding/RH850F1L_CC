/**
  ******************************************************************************
  * @file    rh850f1l_port.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   29-November-2017
  * @brief   Port Function driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of port:
  *           + Initialization and de-initialization functions
  *           + Port functions
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "rh850f1l_port.h"
#include "rh850f1l_wp.h"


static uintptr_t unused = 0;
static uint16_t  unuse = 0;

typedef enum{
  PMC_TYPE,PIPC_TYPE,PM_TYPE,PIBC_TYPE,PFC_TYPE,PFCE_TYPE,PFCAE_TYPE,//Pin function Configration
  PBDC_TYPE,PPR_TYPE,P_TYPE,PNOT_TYPE,//Pin data input /output
  PU_TYPE,PD_TYPE,PIS_TYPE,//configration of electrical character

  PMCSR_TYPE ,PMSR_TYPE,
  PSR_TYPE,
  PDSC_TYPE,PODC_TYPE,
}REG_ADDR_INDEX_Type;
//map[group num, real position in reg_addr]
uint8_t reg_group_arr[] = {
  0,1,2,    //0~2
  0,0,0,0,0,//unused
  3,4,5,6,7,//8~12
  0,0,0,0,0,//unused
  8,        //group 18
  0,        //unused
  9,        //group 20
 };
volatile uint16_t* reg_arr_16[][10] = {
  &PMC0,  &PMC1, &PMC2, &PMC8, &PMC9, &PMC10,  &PMC11,  &PMC12, &PMC18, &PMC20,//PMC_TYPE
  &PIPC0, &unuse,&unuse,&unuse,&unuse,&PIPC10, &PIPC11, &unuse, &unuse, &unuse,//PIPC_TYPE
  &PM0,   &PM1,  &PM2,  &PM8,  &PM9,  &PM10,   &PM11,   &PM12,  &PM18,  &PM20,//PM_TYPE
  &PIBC0, &PIBC1,&PIBC2,&PIBC8,&PIBC9,&PIBC10, &PIBC11, &PIBC12,&PIBC18,&PIBC20,//PIBC_TYPE
  &PFC0,  &PFC1, &unuse,&PFC8, &PFC9, &PFC10,  &PFC11,  &PFC12, &PFC18, &PFC20,//PFC_TYPE
  &PFCE0, &unuse,&unuse,&PFCE8,&PFCE9,&PFCE10, &PFCE11, &PFCE12,&unuse, &unuse,//PFCE_TYPE
  &PFCAE0,&unuse,&unuse,&unuse,&unuse,&PFCAE10,&PFCAE11,&unuse, &unuse, &unuse,//PFCAE_TYPE

  &PBDC0, &PBDC1,&PBDC2,&PBDC8,&PBDC9,&PBDC10, &PBDC11, &PBDC12,&PBDC18,&PBDC20,//PBDC_TYPE
  &PPR0,  &PPR1, &PPR2, &PPR8, &PPR9, &PPR10,  &PPR11,  &PPR12, &PPR18, &PPR20,//PPR_TYPE
  &P0,    &P1,   &P2,   &P8,   &P9,   &P10,    &P11,    &P12,   &P18,   &P20,//P_TYPE
  &PNOT0, &PNOT1,&PNOT2,&PNOT8,&PNOT9,&PNOT10, &PNOT11, &PNOT12,&PNOT18,&PNOT20,//PNOT_TYPE
  

  &PU0,   &PU1,  &PU2,  &PU8,  &PU9,  &PU10,   &PU11,   &PU12,  &PU18,  &PU20,//PU_TYPE
  &PD0,   &unuse,&unuse,&PD8,  &PD9,  &PD10,   &PD11,   &unuse, &unuse, &unuse,//PD_TYPE
  &PIS0,  &PIS1, &PIS2, &unuse,&unuse,&PIS10,  &PIS11,  &PIS12, &unuse, &PIS20,//PIS_TYPE
};

volatile uintptr_t* reg_arr_32[][10] ={
  &PMCSR0,&PMCSR1,&PMCSR2,&PMCSR8,&PMCSR9,&PMCSR10,&PMCSR11,&PMCSR12,&PMCSR18,&PMCSR20,//PMCSR_TYPE
  &PMSR0, &PMSR1, &PMSR2, &PMSR8, &PMSR9, &PMSR10, &PMSR11, &PMSR12, &PMSR18, &PMSR20,//PMSR_TYPE
  &PSR0,  &PSR1,  &PSR2,  &PSR8,  &PSR9,  &PSR10,  &PSR11,  &PSR12,  &PSR18,  &PSR20,//PSR_TYPE
  &PDSC0, &unused,&unused,&unused,&unused,&PDSC10, &PDSC11, &PDSC12, &unused, &unused,//PDSC_TYPE
  &PODC0, &PODC1, &PODC2, &PODC8, &PODC9, &PODC10, &PODC11, &PODC12, &PODC18, &PODC20,//PODC_TYPE
};


#define __GET_TARGET_REG(tar_reg,reg_name,index)  do{ \
                                                    uint8_t arr_index = reg_group_arr[index]; \
                                                    if(reg_name >= PMCSR_TYPE) \
                                                      tar_reg = reg_arr_32[reg_name - PMCSR_TYPE][arr_index]; \
                                                    else \
                                                      tar_reg = reg_arr_16[reg_name][arr_index]; \
                                                  }while(0)



void Port_Init(Port_Group_Index_Type portx,Port_InitTypeDef *Port_InitStruct)
{
  __IO uint16_t pinpos = 0x00,bitpos = 0x00,mask_bit = 0x00,last_bit = 0x00;

  last_bit = Port_InitStruct->pin_mask;
  for(pinpos = 0x00;pinpos < 0x0F && (last_bit >> pinpos);pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

   /*Get the pin mask bit position,make sure make_bit  is valid*/
    mask_bit = READ_BIT(&Port_InitStruct->pin_mask, bitpos);

    if(mask_bit == 0) //Invalid ,next loop
      continue;

    /*Port initialization:Set the initial port values.(The port is set to input mode
     *and the input buffer is disabled.)*/

    //Step 1  Specify PIBCn.PIBCn_m bit = 0   Input buffer disable
    Port_InputBuf_Ctl_Bit_Config(portx,INPUT_BUF_DISABLED,mask_bit);
    //Step 2 Specify PBDCn.PBDCn_m bit = 0    Bidirectional mode disbaled
    Port_Bidirection_Ctl_Bit_Config(portx,BIDIRECTION_MODE_DISABLED,mask_bit);
    //Step 3 Specify PMn.PMn_m bit = 1        Input mode
    Port_IO_Mode_Bit_Config(portx,PORT_INPUT_MODE,mask_bit);
    //Step 4 Specify PMCn.PMCn_m bit = 0      Port mode
    Port_Mode_Ctl_Bit_Config(portx,PORT_MODE,mask_bit);
    //Step 5 Specify PIPCn.PIPCn_m bit = 0    I/O mode is selected by PMn.PMn_m(Software I/O control)
    Port_IP_Bit_Config(portx,SOFT_AF_MODE,mask_bit);
    
    if(Port_InitStruct->io_mode == PORT_OUTPUT_MODE){
      Port_Char_Bit_Config(portx,OUTPUT_LDS,mask_bit);
      Port_Char_Bit_Config(portx,OUTPUT_PP,mask_bit);
      Port_Bidirection_Ctl_Bit_Config(portx,BIDIRECTION_MODE_ENABLED,mask_bit);
      Port_Write_OutputData_Bit(portx,mask_bit,1);
      Port_IO_Mode_Bit_Config(portx,PORT_OUTPUT_MODE,mask_bit);
    }else if(Port_InitStruct->io_mode == PORT_INPUT_MODE){
    } 

  }

}

/*********************************Pin Function Configuration****************************/

/* @brief -直接设定 Pn的port mode（单个bit操作）
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param mask_bit -需要操作的单个bit
 */
void Port_Mode_Ctl_Bit_Config(Port_Group_Index_Type portx,PortOptMode_Type opt_mode,uint16_t mask_bit)
{
  __IO uint16_t bitpos = mask_bit,current_bit = 0x00;
  __IO uint16_t* target_reg = NULL;//address of target register

#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
  //assset_param(IS_Port_Group(portx));
#endif

  __GET_TARGET_REG(target_reg,PMC_TYPE,portx);

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(target_reg,bitpos);

  if(current_bit == 0x00 && opt_mode != PORT_MODE)//PMCn_m需要被置位
    SET_BIT(target_reg, bitpos);
  if(current_bit != 0x00 && opt_mode == PORT_MODE)//PMCn_m需要被清零
    CLEAR_BIT(target_reg,bitpos);

}
/* @brief -直接设定 Pn的port mode（多个bit操作）
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param mask -需要操作的bits
 */
void Port_Mode_Ctl_Config(Port_Group_Index_Type portx,PortOptMode_Type opt_mode,uint16_t mask)
{
  __IO uint16_t pinpos = 0x00,bitpos = 0x00,mask_bit = 0x00,last_bit = mask;

  for(pinpos = 0x00;pinpos < 0x0F && (last_bit >> pinpos);pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(&last_bit, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
      if(opt_mode == PORT_MODE){
        Port_Mode_Ctl_Bit_Config(portx,PORT_MODE,mask_bit);
      }else{//opt_mode != PORT_MODE
        Port_Mode_Ctl_Bit_Config(portx,(PortOptMode_Type)!PORT_MODE,mask_bit);
      }
    }
  }
}

/* @brief -间接设定 Pn的port mode（多个bit操作）Optional
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param mask -需要操作的bits
 */
void Port_Mode_Ctl_Set(Port_Group_Index_Type portx,uint16_t mask)
{
  /* Configure the 16 High pin bits */


  /* Configure the 16 Low pin bits */

}
/* @brief -间接设定 Pn的port mode（多个bit操作）Optional
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param mask -需要操作的bits
 */
void Port_Mode_Ctl_Reset()
{
    /* Configure the 16 High pin bits */


  /* Configure the 16 Low pin bits */
}

/* @brief -设定或者清除PIPCx寄存器的某个bit（单个位操作）
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param opt_mode - PORT_MODE, Non_PORT_MODE,SOFT_AF_MODE,DIRECT_AF_MODE,Non_AF_MODE
 * @param mask_bit -需要操作的单个bit
 */
void Port_IP_Bit_Config(Port_Group_Index_Type portx,PortOptMode_Type opt_mode,uint16_t mask_bit)
{
  __IO uint16_t bitpos = mask_bit,current_bit = 0x00;
  __IO uint16_t *target_reg  = NULL;
#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
  //assset_param(IS_Port_Group(portx));
#endif

  __GET_TARGET_REG(target_reg,PIPC_TYPE,portx);

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(target_reg,bitpos);

  if(current_bit == 0x00 && opt_mode == DIRECT_AF_MODE)//PIPCn_m需要被置位
    SET_BIT(target_reg,bitpos);
  if(current_bit != 0x00 && opt_mode == SOFT_AF_MODE)//PIPCn_m需要被清零
    CLEAR_BIT(target_reg,bitpos);
}
/* @brief -设定或者清除PIPCx寄存器的某个bit（单个位操作）
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param opt_mode - PORT_MODE, Non_PORT_MODE,SOFT_AF_MODE,DIRECT_AF_MODE,Non_AF_MODE
 * @param mask_bit -需要操作的单个bit
 */
void Port_IP_Config(Port_Group_Index_Type portx,PortOptMode_Type opt_mode,uint16_t mask)
{
  __IO uint16_t pinpos = 0x00,bitpos = 0x00,mask_bit = 0x00,last_bit = mask;

  for (pinpos = 0x00; pinpos < 0x0F && (last_bit >> pinpos); pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(&last_bit, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
      if(opt_mode == SOFT_AF_MODE){
        Port_IP_Bit_Config(portx,SOFT_AF_MODE,mask_bit);
      }else if(opt_mode == DIRECT_AF_MODE){
        Port_IP_Bit_Config(portx,DIRECT_AF_MODE,mask_bit);
      }
    }
  }
}

void Port_IO_Mode_Bit_Config(Port_Group_Index_Type portx,uint16_t io_mode,uint16_t mask_bit)
{
  __IO uint16_t bitpos = mask_bit,current_bit = 0x00;
  __IO uint16_t *target_reg = NULL;

#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  __GET_TARGET_REG(target_reg,PM_TYPE,portx);

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(target_reg,bitpos);

  if(current_bit == 0x00 && io_mode == PORT_INPUT_MODE)//PMn_m需要被置位
    SET_BIT(target_reg,bitpos);
  if(current_bit != 0x00 && io_mode == PORT_OUTPUT_MODE)//PMn_m需要被清零
    CLEAR_BIT(target_reg,bitpos);
}

void Port_IO_Mode_Config(Port_Group_Index_Type portx,uint16_t io_mode,uint16_t mask)
{
  __IO uint16_t pinpos = 0x00,bitpos = 0x00,mask_bit = 0x00,last_bit = mask;

  for(pinpos = 0x00;pinpos < 0x0F && (last_bit >> pinpos);pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(&last_bit, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
      Port_IP_Bit_Config(portx,io_mode,mask_bit);
    }
  }
}

void Port_InputBuf_Ctl_Bit_Config(Port_Group_Index_Type portx,InputBuf_Ctl_Type ibc_t,uint16_t mask_bit)
{
  __IO uint16_t bitpos = mask_bit,current_bit = 0x00;
  __IO uint16_t *target_reg = NULL;
  __IO uint8_t addr_index = 0;
#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  __GET_TARGET_REG(target_reg,PIBC_TYPE,portx);
  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(target_reg,bitpos);

  if(current_bit == 0x00 && ibc_t == INPUT_BUF_ENABLED)//PIBCn_m需要被置位
    SET_BIT(target_reg,bitpos);
  if(current_bit != 0x00 && ibc_t == INPUT_BUF_DISABLED)//PIBCn_m需要被清零
    CLEAR_BIT(target_reg,bitpos);
}

void Port_InputBuf_Ctl_Config(Port_Group_Index_Type portx,InputBuf_Ctl_Type ibc_t,uint16_t mask)
{
  __IO uint16_t pinpos = 0x00,bitpos = 0x00,mask_bit = 0x00,last_bit = mask;

  for(pinpos = 0x00;pinpos < 0x0F && (last_bit >> pinpos);pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(&last_bit, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
        Port_IP_Bit_Config(portx,ibc_t,mask_bit);
    }
  }
}

/******************************Pin Data Input/Output***********************************/

void Port_Bidirection_Ctl_Bit_Config(Port_Group_Index_Type portx,Bidirect_Mode_Ctl_Type bmc_t,uint16_t mask_bit)
{
  __IO uint16_t bitpos = mask_bit,current_bit = 0x00;
  __IO uint16_t *target_reg = NULL;
  __IO uint8_t arr_index;
#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  __GET_TARGET_REG(target_reg,PBDC_TYPE,portx);


  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(target_reg,bitpos);

  if(current_bit == 0x00 && bmc_t == BIDIRECTION_MODE_ENABLED)//PBDCn_m需要被置位
    SET_BIT(target_reg,bitpos);
  if(current_bit != 0x00 && bmc_t == BIDIRECTION_MODE_DISABLED)//PBDCCn_m需要被清零
    CLEAR_BIT(target_reg,bitpos);
}

void Port_Bidirection_Ctl_Config(Port_Group_Index_Type portx,Bidirect_Mode_Ctl_Type bmc_t,uint16_t mask)
{
  __IO uint16_t pinpos = 0x00,bitpos = 0x00,mask_bit = 0x00,last_bit = mask;

  for(pinpos = 0x00;pinpos < 0x0F && (last_bit >> pinpos);pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(&last_bit, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
      Port_IP_Bit_Config(portx,bmc_t,mask_bit);
    }
  }
}

/**
  * @brief  Reads the specified data port bit.
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  * @param  mask_bit:  specifies the port bit to read.
  *   This parameter can be PORT_PIN_x where x can be (0..15).
  * @retval The output port pin value.
  */
uint8_t Port_Read_Data_Bit(Port_Group_Index_Type portx, uint16_t mask_bit)
{
  __IO uint8_t bitstatus = 0x00;
  __IO uint16_t *target_reg = NULL;
#if ASSERT_EN
  //assert_param(IS_Port_Group(portx));
  assert_param(IS_Port_Pin(mask_bit));
#endif

  __GET_TARGET_REG(target_reg,PPR_TYPE,portx);

  if (READ_BIT(target_reg, mask_bit) != (uint32_t)Bit_RESET){
    bitstatus = (uint8_t)Bit_SET;
  }else{
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified Port data port.
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  * @retval Port output data port value.
  */
uint16_t Port_Read_Data(Port_Group_Index_Type portx)
{
  __IO uint16_t *target_reg = NULL;
#if ASSERT_EN
  /* Check the parameters */
  //assert_param(IS_Port_Group(portx));
#endif
  __GET_TARGET_REG(target_reg,PPR_TYPE,portx);

  return READ_REG(target_reg);
}


/**
  * @brief  Reads the specified output data port bit.
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  * @param  mask_bit:  specifies the port bit to read.
  *   This parameter can be PORT_PIN_x where x can be (0..15).
  * @retval The output port pin value.
  */
uint8_t Port_Read_OutputData_Bit(Port_Group_Index_Type portx, uint16_t mask_bit)
{
  __IO uint8_t bitstatus = 0x00;
  __IO uint16_t *target_reg = NULL;
#if ASSERT_EN
  //assert_param(IS_Port_Group(portx));
  assert_param(IS_Port_Pin(mask_bit));
#endif

  __GET_TARGET_REG(target_reg,P_TYPE,portx);

  if (READ_BIT(target_reg,mask_bit) != (uint32_t)Bit_RESET){
    bitstatus = (uint8_t)Bit_SET;//Outputs low level
  }else{
    bitstatus = (uint8_t)Bit_RESET;//Outputs low level
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified Port output data port.
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  * @retval Port output data port value.
  */
uint16_t Port_Read_OutputData(Port_Group_Index_Type portx)
{
  __IO uint16_t *target_reg = NULL;
#if ASSERT_EN
  /* Check the parameters */
  assert_param(IS_Port_Group(portx));
#endif
  __GET_TARGET_REG(target_reg,P_TYPE,portx);

  return READ_REG(target_reg);
}

/**
  * @brief  Write the specified data to output  port bit.
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  * @param  mask_bit:  specifies the port bit to write.
  *   This parameter can be PORT_PIN_x where x can be (0..15).
  *
  */
void Port_Write_OutputData_Bit(Port_Group_Index_Type portx, uint16_t mask_bit,BitAction bit_val)
{
  __IO uint16_t *target_reg = NULL;

#if ASSERT_EN
  assert_param(IS_Port_Group(portx));
  assert_param(IS_Port_Pin(mask_bit));
#endif

  __GET_TARGET_REG(target_reg,P_TYPE,portx);
  if(bit_val != Bit_RESET){
    SET_BIT(target_reg,mask_bit);
  }else{
    CLEAR_BIT(target_reg,mask_bit);
  }

}

/**
  * @brief  Write the specified data to output port..
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  *
  */
void Port_Write_OutputData(Port_Group_Index_Type portx,uint16_t data)
{
  __IO uint16_t *target_reg = NULL;
#if ASSERT_EN
  /* Check the parameters */
  assert_param(IS_Port_Group(portx));
#endif
  __GET_TARGET_REG(target_reg,P_TYPE,portx);

  if(data ==(uint16_t)0x00){
    CLEAR_REG(target_reg);
  }else{
    WRITE_REG(target_reg,data);
  
  }
}

/*Configuration of Electrical Characteristics*/

void Port_Char_Bit_Config(Port_Group_Index_Type portx,Elect_Char_Type echar_t,uint16_t mask_bit)
{
  __IO uint16_t bitpos = mask_bit,current_bit = 0x00;
  __IO uint16_t *target_reg = NULL;
  __IO uintptr_t *target_reg_32 = NULL;
#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  switch(echar_t){
    case INPUT_NPU:
    case INPUT_PU:
      __GET_TARGET_REG(target_reg,PU_TYPE,portx);

      /*获取当前bitpos的置位信息*/
      current_bit = READ_BIT(target_reg,bitpos);

      if(current_bit == 0x00 && echar_t == INPUT_PU)//PUn_m需要被置位
        SET_BIT(target_reg,bitpos);
      if(current_bit != 0x00 && echar_t == INPUT_NPU)//PUn_m需要被清零
        CLEAR_BIT(target_reg,bitpos);
      break;
    case INPUT_NPD:
    case INPUT_PD:
      __GET_TARGET_REG(target_reg,PD_TYPE,portx);
      /*获取当前bitpos的置位信息*/
      current_bit = READ_BIT(target_reg,bitpos);

      if(current_bit == 0x00 && echar_t == INPUT_PD)//PDn_m需要被置位
        SET_BIT(target_reg,bitpos);
      if(current_bit != 0x00 && echar_t == INPUT_NPD)//PDn_m需要被清零
        CLEAR_BIT(target_reg,bitpos);
      break;
    case OUTPUT_PP:
    case OUPUT_OD:
      __GET_TARGET_REG(target_reg_32,PODC_TYPE,portx);
      /*获取当前bitpos的置位信息*/
      current_bit = READ_BIT(target_reg,bitpos);

      if(current_bit == 0x00 && echar_t == OUPUT_OD)//PODCn_m需要被置位
        SET_BIT(target_reg_32,bitpos);
      if(current_bit != 0x00 && echar_t == OUTPUT_PP)//PODCn_m需要被清零
        CLEAR_BIT(target_reg_32,bitpos);
      break;
    case OUTPUT_LDS:
    case OUTPUT_HDS:
      __GET_TARGET_REG(target_reg_32,PDSC_TYPE,portx);
      /*获取当前bitpos的置位信息*/
      current_bit = READ_BIT(target_reg_32,bitpos);

      if(current_bit == 0x00 && echar_t == OUTPUT_HDS)//PDSCn_m需要被置位
        SET_BIT(target_reg_32,bitpos);
      if(current_bit != 0x00 && echar_t == OUTPUT_LDS)//PDSCn_m需要被清零
        CLEAR_BIT(target_reg_32,bitpos);
      break;
    default:
      break;
  }
}
