/**
  ******************************************************************************
  * @file    rh850f1l.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file.
  ******************************************************************************
  */
#ifndef RH850F1L_H_
#define RH850F1L_H_

#include <stdint.h>
#include <types.h>
#include <assert.h>
#include <iodefine.h>
#include <io.h>
#include <reg.h>
#include <ctype.h>
#include <debug.h>
#include <printf.h>

#include <rh850f1l_conf.h>
/**
* @}
*/

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  ERROR = 0,
  SUCCESS = !ERROR
} ErrorStatus;

typedef enum
{
    OPT_WRITE = 0,          //write operation
    OPT_READ = !OPT_WRITE,  //read operation
}OperateDirection;

typedef enum {
  Bit_RESET = 0,
  Bit_SET,
} BitAction;
/**
  * @}
  */

#define STR_CONCAT2(s1,s2)      (s1##s2)
#define STR_CONCAT3(s1,s2,s3)   (s1##s2##s3)
#define ARRAY_SIZE(arr)         (sizeof(arr)/sizeof(arr[0]))
#endif //RH850F1L_H
