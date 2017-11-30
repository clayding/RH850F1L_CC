/**
  ******************************************************************************
  * @file    rh850f1l_port.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    29-November-2017
  * @brief   Header file of Pin Function.
  ******************************************************************************
  */
#ifndef RH850F1L_PORT_H
#define RH850F1L_PORT_H

#include "rh850f1l.h"

#define PIN_Index_0   ((uint8_t)0x00)
#define PIN_Index_1   ((uint8_t)0x01)
#define PIN_Index_2   ((uint8_t)0x02)
#define PIN_Index_3   ((uint8_t)0x03)
#define PIN_Index_4   ((uint8_t)0x04)
#define PIN_Index_5   ((uint8_t)0x05)
#define PIN_Index_6   ((uint8_t)0x06)
#define PIN_Index_7   ((uint8_t)0x07)
#define PIN_Index_8   ((uint8_t)0x08)
#define PIN_Index_9   ((uint8_t)0x09)
#define PIN_Index_10  ((uint8_t)0x0A)
#define PIN_Index_11  ((uint8_t)0x0B)
#define PIN_Index_12  ((uint8_t)0x0C)
#define PIN_Index_13  ((uint8_t)0x0D)
#define PIN_Index_14  ((uint8_t)0x0E)
#define PIN_Index_15  ((uint8_t)0x0F)
 

#define PORT_PIN_0     ((uint16_t)0x01 << PIN_Index_0 )
#define PORT_PIN_1     ((uint16_t)0x01 << PIN_Index_1 )
#define PORT_PIN_2     ((uint16_t)0x01 << PIN_Index_2 )
#define PORT_PIN_3     ((uint16_t)0x01 << PIN_Index_3 )
#define PORT_PIN_4     ((uint16_t)0x01 << PIN_Index_4 )
#define PORT_PIN_5     ((uint16_t)0x01 << PIN_Index_5 )
#define PORT_PIN_6     ((uint16_t)0x01 << PIN_Index_6 )
#define PORT_PIN_7     ((uint16_t)0x01 << PIN_Index_7 )
#define PORT_PIN_8     ((uint16_t)0x01 << PIN_Index_8 )
#define PORT_PIN_9     ((uint16_t)0x01 << PIN_Index_9 )
#define PORT_PIN_10    ((uint16_t)0x01 << PIN_Index_10)
#define PORT_PIN_11    ((uint16_t)0x01 << PIN_Index_11)
#define PORT_PIN_12    ((uint16_t)0x01 << PIN_Index_12)
#define PORT_PIN_13    ((uint16_t)0x01 << PIN_Index_13)
#define PORT_PIN_14    ((uint16_t)0x01 << PIN_Index_14)
#define PORT_PIN_15    ((uint16_t)0x01 << PIN_Index_15)

#define IS_Port_Pin(PIN)  (((PIN) == PORT_PIN_0) || \
                              ((PIN) == PORT_PIN_1) || \
                              ((PIN) == PORT_PIN_2) || \
                              ((PIN) == PORT_PIN_3) || \
                              ((PIN) == PORT_PIN_4) || \
                              ((PIN) == PORT_PIN_5) || \
                              ((PIN) == PORT_PIN_6) || \
                              ((PIN) == PORT_PIN_7) || \
                              ((PIN) == PORT_PIN_8) || \
                              ((PIN) == PORT_PIN_9) || \
                              ((PIN) == PORT_PIN_10) || \
                              ((PIN) == PORT_PIN_11) || \
                              ((PIN) == PORT_PIN_12) || \
                              ((PIN) == PORT_PIN_13) || \
                              ((PIN) == PORT_PIN_14) || \
                              ((PIN) == PORT_PIN_15))


#define PORT_OUTPUT_MODE   ((uint16_t)0x0001)
#define PORT_INPUT_MODE    ((uint16_t)0x0002)



typedef enum{
  PORT_MODE,     // Port mode
  SOFT_AF_MODE,  // software I/O control alternative mode
  DIRECT_AF_MODE,//direct I/O control alternative mode
  Non_PORT_MODE,//not Port mode
  Non_AF_MODE = PORT_MODE,
}PortOptMode_Type;

typedef struct{
  uint16_t port_pin;
  PortOptMode_Type opt_mode;
}Port_InitTypeDef;

typedef enum{ //14
  PortGroupNum0,
  PortGroupNum1,
  PortGroupNum2,
  PortGroupNum8 = 8,
  PortGroupNum9,
  PortGroupNum10,
  PortGroupNum11,
  PortGroupNum12,
  PortGroupNum18 = 18,
  PortGroupNum20 = 20,
  JPortGroupNum0,APortGroupNum0,APortGroupNum1,IPortGroupNum0,
}Port_Group_Index_Type;

#define  PortGroup0 = ((uint32_t)0x01 << PortGroupNum0 )
#define  PortGroup1 = ((uint32_t)0x01 << PortGroupNum1 )
#define  PortGroup2 = ((uint32_t)0x01 << PortGroupNum2 )
#define  PortGroup8 = ((uint32_t)0x01 << PortGroupNum8 )
#define  PortGroup9 = ((uint32_t)0x01 << PortGroupNum9 )
#define  PortGroup10= ((uint32_t)0x01 << PortGroupNum10 )
#define  PortGroup11= ((uint32_t)0x01 << PortGroupNum11 )
#define  PortGroup12= ((uint32_t)0x01 << PortGroupNum12 )
#define  PortGroup18= ((uint32_t)0x01 << PortGroupNum18 )
#define  PortGroup20= ((uint32_t)0x01 << PortGroupNum20 )
#define  JPortGroup0= ((uint32_t)0x01 << JPortGroupNum0 )
#define  APortGroup0= ((uint32_t)0x01 << APortGroupNum0 )
#define  APortGroup1= ((uint32_t)0x01 << APortGroupNum1 )
#define  IPortGroup0= ((uint32_t)0x01 << IPortGroupNum0 )

#define IS_Port_Group(index)  ((((uint32_t)(0x01 << index)) == PortGroup0) || \
                               (((uint32_t)(0x01 << index)) == PortGroup1) || \
                               (((uint32_t)(0x01 << index)) == PortGroup2) || \
                               (((uint32_t)(0x01 << index)) == PortGroup8) || \
                               (((uint32_t)(0x01 << index)) == PortGroup9) || \
                               (((uint32_t)(0x01 << index)) == PortGroup10) || \
                               (((uint32_t)(0x01 << index)) == PortGroup11) || \
                               (((uint32_t)(0x01 << index)) == PortGroup12) || \
                               (((uint32_t)(0x01 << index)) == PortGroup18) || \
                               (((uint32_t)(0x01 << index)) == PortGroup20) || \
                               (((uint32_t)(0x01 << index)) == JPortGroup0) || \
                               (((uint32_t)(0x01 << index)) == APortGroup0) || \
                               (((uint32_t)(0x01 << index)) == APortGroup1) || \
                               (((uint32_t)(0x01 << index)) == IPortGroup0))

typedef enum{
  INPUT_BUF_DISABLED,
  INPUT_BUF_ENABLED = !INPUT_BUF_DISABLED,
}InputBuf_Ctl_Type;


typedef enum{
  BIDIRECTION_MODE_DISABLED,
  BIDIRECTION_MODE_ENABLED = !BIDIRECTION_MODE_DISABLED,
}Bidirect_Mode_Ctl_Type;

typedef enum
{ Bit_RESET = 0,
  Bit_SET,
}BitAction;



#endif //RH850F1L_PORT_H