/**
  ******************************************************************************
  * @file    board.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    24-November-2017
  * @brief   Header file of RH850/F1L Start Kit.
  ******************************************************************************
  */
#ifndef BOARD_H_
#define BOARD_H_

#include "rh850f1l_clk.h"
#include "rh850f1l_port.h"
#include "rh850f1l_ext.h"
#include "rh850f1l_timer.h"
#include "rh850f1l_wdta.h"
#include "rh850f1l_rtc.h"
#include "rh850f1l_rscan.h"
#include "rh850f1l_rlin.h"

void Board_MCU_Init();

void System_Clock_Config(void);

#endif //BOARD_H_
