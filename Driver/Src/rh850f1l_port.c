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

#define _REGX(index) index
#define REGX(reg_name,index)  reg_name##_REGX(index)


void Port_Init(Port_InitTypeDef *Port_InitStruct)
{

}

/*********************************Pin Function Configuration****************************/

/* @brief -直接设定 Pn的port mode（单个bit操作）
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param mask_bit -需要操作的单个bit
 */
void Port_Mode_Ctl_Bit_Config(Port_Group_Index_Type portx,PortOptMode_Type opt_mode,uint16_t mask_bit)
{
  uint16_t bitpos = mask_bit,current_bit = 0x00;

#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(REGX(PMC,portx),bitpos);

  if(current_bit == 0x00 && opt_mode != PORT_MODE)//PMCn_m需要被置位
    SET_BIT(REG(PMC,portx),bitpos);
  if(current_bit != 0x00 && opt_mode == PORT_MODE)//PMCn_m需要被清零
    CLEAR_BIT(REG(PMC,portx),bitpos);

}
/* @brief -直接设定 Pn的port mode（多个bit操作）
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param mask -需要操作的bits
 */
void Port_Mode_Ctl_Config(Port_Group_Index_Type portx,PortOptMode_Type opt_mode,uint16_t mask)
{
  uint16_t pinpos = 0x00,bitpos = 0x00,current_bit = 0x00,mask_bit = 0x00;

  for(pinpos = 0x00;pinpos < 0x0F;pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(mask, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
      if(opt_mode == PORT_MODE){
        Port_Mode_Ctl_Bit_Config(portx,PORT_MODE,mask_bit);
      }else{//opt_mode != PORT_MODE
        Port_Mode_Ctl_Bit_Config(portx,Non_PORT_MODE,mask_bit);
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
  uint16_t bitpos = mask_bit,current_bit = 0x00;

#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(REGX(PIPC,portx),bitpos);

  if(current_bit == 0x00 && opt_mode == DIRECT_AF_MODE)//PIPCn_m需要被置位
    SET_BIT(REG(PIPC,portx),bitpos);
  if(current_bit != 0x00 && opt_mode == SOFT_AF_MODE)//PIPCn_m需要被清零
    CLEAR_BIT(REG(PIPC,portx),bitpos);
}
/* @brief -设定或者清除PIPCx寄存器的某个bit（单个位操作）
 * @param portx - the index “n” (n = 0 to 2, 8 to 12, 18,and 20)
 * @param opt_mode - PORT_MODE, Non_PORT_MODE,SOFT_AF_MODE,DIRECT_AF_MODE,Non_AF_MODE
 * @param mask_bit -需要操作的单个bit
 */
void Port_IP_Config(Port_Group_Index_Type portx,PortOptMode_Type opt_mode,uint16_t mask)
{
  uint16_t pinpos = 0x00,bitpos = 0x00,current_bit = 0x00,mask_bit = 0x00;

  for(pinpos = 0x00;pinpos < 0x0F;pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(mask, bitpos);

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
  uint16_t bitpos = mask_bit,current_bit = 0x00;

#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(REGX(PM,portx),bitpos);

  if(current_bit == 0x00 && opt_mode == PORT_INPUT_MODE)//PMn_m需要被置位
    SET_BIT(REG(PM,portx),bitpos);
  if(current_bit != 0x00 && opt_mode == PORT_OUTPUT_MODE)//PMn_m需要被清零
    CLEAR_BIT(REG(PM,portx),bitpos);
}

void Port_IO_Mode_Config(Port_Group_Index_Type portx,uint16_t io_mode,uint16_t mask)
{
  uint16_t pinpos = 0x00,bitpos = 0x00,current_bit = 0x00,mask_bit = 0x00;

  for(pinpos = 0x00;pinpos < 0x0F;pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(mask, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
      Port_IP_Bit_Config(portx,io_mode,mask_bit);
    }
  }
}

void Port_InputBuf_Ctl_Bit_Config(Port_Group_Index_Type portx,InputBuf_Ctl_Type ibc_t,uint16_t mask_bit)
{
  uint16_t bitpos = mask_bit,current_bit = 0x00;

#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(REGX(PIBC,portx),bitpos);

  if(current_bit == 0x00 && ibc_t == INPUT_BUF_ENABLED)//PIBCn_m需要被置位
    SET_BIT(REG(PIBC,portx),bitpos);
  if(current_bit != 0x00 && ibc_t == INPUT_BUF_DISNABLED)//PIBCn_m需要被清零
    CLEAR_BIT(REG(PIBC,portx),bitpos);


void Port_InputBuf_Ctl_Config(Port_Group_Index_Type portx,InputBuf_Ctl_Type ibc_t,uint16_t mask)
{
  uint16_t pinpos = 0x00,bitpos = 0x00,current_bit = 0x00,mask_bit = 0x00;

  for(pinpos = 0x00;pinpos < 0x0F;pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(mask, bitpos);

    if(mask_bit != 0x00){// need to be set or clear
        Port_IP_Bit_Config(portx,ibc_t,mask_bit);
      }
    }
  }
}

/******************************Pin Data Input/Output***********************************/

void Port_Bidirection_Ctl_Bit_Config(Port_Group_Index_Type portx,Bidirect_Mode_Ctl_Type bmc_t,uint16_t mask_bit)
{
  uint16_t bitpos = mask_bit,current_bit = 0x00;

#if ASSERT_EN
  assert_param(IS_Port_Pin(bitpos));
#endif

  /*获取当前bitpos的置位信息*/
  current_bit = READ_BIT(REGX(PBDC,portx),bitpos);

  if(current_bit == 0x00 && bmc_t == INPUT_BUF_ENABLED)//PBDCn_m需要被置位
    SET_BIT(REG(PBDC,portx),bitpos);
  if(current_bit != 0x00 && bmc_t == INPUT_BUF_DISABLED)//PBDCCn_m需要被清零
    CLEAR_BIT(REG(PBDC,portx),bitpos);
}

void Port_Bidirection_Ctl_Config(Port_Group_Index_Type portx,Bidirect_Mode_Ctl_Type bmc_t,uint16_t mask)
{
  uint16_t pinpos = 0x00,bitpos = 0x00,current_bit = 0x00,mask_bit = 0x00;

  for(pinpos = 0x00;pinpos < 0x0F;pinpos++){//find which bits of the pin to be set,max 15
    bitpos = ((uint16_t)0x01) << pinpos; //set the pinpos bit ,example pinpos = 15,the bitpos is 0x0F

    //Get the pin mask bit position/*
    mask_bit = READ_BIT(mask, bitpos);

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
  uint8_t bitstatus = 0x00;

#if ASSERT_EN
  assert_param(IS_Port_Group(portx));
  assert_param(IS_Port_Pin(mask_bit));
#endif

  if ((REG(PPR,portx) & mask_bit) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
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
#if ASSERT_EN
  /* Check the parameters */
  assert_param(IS_Port_Group(portx));
#endif
  return ((uint16_t)REG(PPR,portx));
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
  uint8_t bitstatus = 0x00;

#if ASSERT_EN
  assert_param(IS_Port_Group(portx));
  assert_param(IS_Port_Pin(mask_bit));
#endif

  if ((REG(P,portx) & mask_bit) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;//Outputs low level
  }
  else
  {
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
#if ASSERT_EN
  /* Check the parameters */
  assert_param(IS_Port_Group(portx));
#endif
  return ((uint16_t)REG(P,portx));
}

/**
  * @brief  Write the specified data to output  port bit.
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  * @param  mask_bit:  specifies the port bit to read.
  *   This parameter can be PORT_PIN_x where x can be (0..15).
  * @retval The output port pin value.
  */
uint8_t Port_Write_OutputData_Bit(Port_Group_Index_Type portx,  uint16_t mask_bit,BitAction bit_val)
{

#if ASSERT_EN
  assert_param(IS_Port_Group(portx));
  assert_param(IS_Port_Pin(mask_bit));
#endif

  if(bit_val != Bit_RESET){
    SET_BIT(REG(P,portx),mask_bit);
  }else{
    CLEAR_BIT(REG(P,portx),mask_bit);
  }

}

/**
  * @brief  Write the specified data to output port..
  * @param  portx: where x can be (0 to 2, 8 to 12, 18,and 20).
  * @retval Port output data port value.
  */
uint16_t Port_Write_OutputData(Port_Group_Index_Type portx,uint16_t data)
{
#if ASSERT_EN
  /* Check the parameters */
  assert_param(IS_Port_Group(portx));
#endif
  if(data ==(uint16_t)0x00){
    CLEAR_REG(REG(P,portx));
  }else{
    WRITE_REG(REG(P,portx),data);
  
  }
}

/*Configuration of Electrical Characteristics*/


