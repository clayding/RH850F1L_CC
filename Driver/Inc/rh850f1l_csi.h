/**
  ******************************************************************************
  * @file    rh850f1l_csi.h
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date    28-March-2018
  * @brief   Header file of CSIG module.
  ******************************************************************************
  */
#ifndef RH850F1L_RLIN_H
#define RH850F1L_RLIN_H
#include "rh850f1l.h"

#define _CTL0   CTL0
#define _CTL1   CTL1
#define _CTL2   CTL2
#define _STR0   STR0
#define _STCR0  STCR0
#define _BCTL0  BCTL0
#define _CFG0   CFG0
#define _TX0W   TX0W
#define _TX0H   TX0H
#define _RX0    RX0
/*CSIGnCTL0 - CSIGn Control Register 0*/
#define CSI_CSIGnPWR_OFFSET         7 //Controls operation clock.
#define CSI_CSIGnTXE_OFFSET         6 //Enables/disables transmission.
#define CSI_CSIGnRXE_OFFSET         5 //Enables/disables reception

#define CSI_CSIGnPWR_MASK           ((uint8_t)(0x01 << CSIG_CSIGnPWR_OFFSET))
#define CSI_CSIGnTXE_MASK           ((uint8_t)(0x01 << CSIG_CSIGnTXE_OFFSET))
#define CSI_CSIGnRXE_MASK           ((uint8_t)(0x01 << CSIG_CSIGnRXE_OFFSET))
#define CSI_CSIGnMBS_MASK           ((uint8_t)0x01)//This bit must be set to 1 (the value after reset is 0)

/*CSIGnCTL1 - CSIGn Control Register 1*/
#define CSI_CSIGnCKR_OFFSET         17 //CSIGTSCK clock inversion function
#define CSI_CSIGnSLIT_OFFSET        16 //Selects the timing of interrupt INTCSIGTIC
#define CSI_CSIGnEDLE_OFFSET        7  //Enables/disables extended data length (EDL) mode
#define CSI_CSIGnDCS_OFFSET         5  //Enables/disables data consistency check
#define CSI_CSIGnLBM_OFFSET         3  //Controls loop-back mode (LBM)
#define CSI_CSIGnSIT_OFFSET         2  //Selects interrupt delay mode
#define CSI_CSIGnHSE_OFFSET         1 //Enables/disables handshake function

#define CSI_CSIGnCKR_MASK           ((uint32_t)(0x01 << CSIG_CSIGnCKR_OFFSET))
#define CSI_CSIGnSLIT_MASK          ((uint32_t)(0x01 << CSIG_CSIGnSLIT_OFFSET))
#define CSI_CSIGnEDLE_MASK          ((uint32_t)(0x01 << CSIG_CSIGnEDLE_OFFSET))
#define CSI_CSIGnDCS_MASK           ((uint32_t)(0x01 << CSIG_CSIGnDCS_OFFSET))
#define CSI_CSIGnLBM_MASK           ((uint32_t)(0x01 << CSIG_CSIGnLBM_OFFSET))
#define CSI_CSIGnSIT_MASK           ((uint32_t)(0x01 << CSIG_CSIGnLBM_OFFSET))
#define CSI_CSIGnHSE_MASK           ((uint32_t)(0x01 << CSIG_CSIGnSIT_OFFSET))
#define CSI_CSIGnSSE_MASK           ((uint32_t)0x01) //Enables/disables slave select function

/*CSIGnCTL2 - CSIGn Control Register 2*/
#define CSI_CSIGnPRS_OFFSET         13  //

#define CSI_CSIGnPRS_MASK           ((uint16_t)(0x07 << CSIG_CSIGnPRS_OFFSET))
#define CSI_CSIGnBRS_MASK           ((uint16_t)0xFFF) //Selects the transfer clock frequency

/*CSIGnSTR0 - CSIGn Status Register 0  read-only*/
#define CSI_CSIGnTSF_OFFSET         7 //Transfer Status Flag
#define CSI_CSIGnDCE_OFFSET         3 //Data Consistency Check Error Flag
#define CSI_CSIGnPE_OFFSET          1 //Parity Error Flag

#define CSI_CSIGnTSF_MASK           ((uint32_t)(0x01 << CSIG_CSIGnTSF_OFFSET))
#define CSI_CSIGnDCE_MASK           ((uint32_t)(0x01 << CSIG_CSIGnDCE_OFFSET))
#define CSI_CSIGnPE_MASK            ((uint32_t)(0x01 << CSIG_CSIGnPE_OFFSET))
#define CSI_CSIGnOVE_MASK           ((uint32_t)0x01)//Overrun Error Flag

/*CSIGnSTCR0 - CSIGn Status Clear Register 0*/
#define CSI_CSIGnDCEC_OFFSET        3 //Controls the data consistency error flag clear command
#define CSI_CSIGnPEC_OFFSET         1 //Controls the parity error flag clear command

#define CSI_CSIGnDCEC_MASK          ((uint16_t)(0x01 << CSI_CSIGnDCEC_OFFSET))
#define CSI_CSIGnPEC_MASK           ((uint16_t)(0x01 << CSI_CSIGnPEC_OFFSET))
#define CSI_CSIGnOVEC_MASK          ((uint16_t)0x01) //Controls the overrun error flag clear command

/*CSIGnBCTL0 - CSIGn Rx-Only Mode Control Register 0*/
#define CSI_CSIGnSCE_MASK           ((uint18_t)0x01) //Disables/enables the start of the next data reception by reading CSIGnRX0

/*CSIGnCFG0 - CSIGn Configuration Register 0*/
#define CSI_CSIGnPS_OFFSET          28 //Specifies parity
#define CSI_CSIGnDLS_OFFSET         24 //Specifies data length
#define CSI_CSIGnDIR_OFFSET         18 //Selects the serial data direction.
#define CSI_CSIGnDAP_OFFSET         16 //Data Phase Selection

#define CSI_CSIGnPS_MASK            ((uint32_t)(0x03 << CSI_CSIGnPS_OFFSET))
#define CSI_CSIGnDLS_MASK           ((uint32_t)(0x0F << CSI_CSIGnDLS_OFFSET))
#define CSI_CSIGnDIR_MASK           ((uint32_t)(0x01 << CSI_CSIGnDIR_OFFSET))
#define CSI_CSIGnDAP_MASK           ((uint32_t)(0x01 << CSI_CSIGnDAP_OFFSET))

/*CSIGnTX0W - CSIGn Transmission Register 0 for Word Access*/
#define CSI_CSIGnEDL_OFFSET         29 //Specifies the extended data length

#define CSI_CSIGnEDL_MASK           ((uint32_t)(0x03 << CSI_CSIGnEDL_OFFSET))
#define CSI_CSIGnTX_MASK            ((uint32_t)0xFF)//Data to be transmitted

/*CSIGnTX0H - CSIGn Transmission Register 0 for Half Word Access*/
//#define CSI_CSIGnTX_MASK            ((uint32_t)0xFF) //duplicated with the CSIGnTX0W

/*CSIGnRX0 - CSIGn Reception Register 0  read-only*/
#define CSI_CSIGnRX_MASK            ((uint32_t)0xFF) //Received Data

/*CSIGnEMU - CSIGn Emulation Register*/
#define CSI_CSIGnSVSDIS_OFFSET      7
#define CSI_CSIGnSVSDIS_MASK        ((uint8_t)0x01 << CSI_CSIGnSVSDIS_OFFSET)

#define CSIGN_ADDR(_UNIT_)          ((volatile struct __tag36 *)(((uint8_t*)(&_CSIG0))+  0x2000*(_UNIT_)))
#define CSIGN_VAL(_UNIT_)           (*((volatile struct __tag36 *)(((uint8_t*)(&_CSIG0))+  0x2000*(_UNIT_))))

/*CSIGnCTL0 - CSIGn Control Register 0*/
#define __CSIG_SET_CTL0(_N_,_MASK_,_VAULE_)     MODIFY_REG(CSIGN_VAL(_N_)._CTL0.UINT8,_MASK_,_VALUE_)
#define __CSIG_GET_CTL0(_N_,_MASK_)             (CSIGN_VAL(_N_)._CTL0.UINT8 & _MASK_)

/*CSIGnCTL1 - CSIGn Control Register 1*/
#define __CSIG_SET_CTL1(_N_,_MASK_,_VAULE_)     MODIFY_REG(CSIGN_VAL(_N_)._CTL1,_MASK_,_VALUE_)
#define __CSIG_GET_CTL1(_N_,_MASK_)             (CSIGN_VAL(_N_)._CTL1 & _MASK_)

/*CSIGnCTL2 - CSIGn Control Register 2*/
#define __CSIG_SET_CTL2(_N_,_MASK_,_VAULE_)     MODIFY_REG(CSIGN_VAL(_N_)._CTL2,_MASK_,_VALUE_)
#define __CSIG_GET_CTL2(_N_,_MASK_)             (CSIGN_VAL(_N_)._CTL2 & _MASK_)

/*CSIGnSTR0 - CSIGn Status Register 0 -- read-only */
#define __CSIG_GET_STAT(_N_,_MASK_)             (CSIGN_VAL(_N_)._STR0 & _MASK_)

/*CSIGnSTCR0 - CSIGn Status Clear Register 0*/
#define __CSIG_CLEAR_STAT(_N_,_MASK_,_OFFSET_)  MODIFY_REG(CSIGN_VAL(_N_)._STCR0,_MASK_,0x01 << _OFFSET_)

/*CSIGnBCTL0 - CSIGn Rx-Only Mode Control Register 0  _VALUE_ 0-- disable 1- enable*/
#define __CSIG_ENABLE_NEXT_RECEPT(_N_,_VAULE_)  (CSIGN_VAL(_N_)._BCTL0.UINT8 = _VALUE_ & CSI_CSIGnSCE_MASK)

/*CSIGnCFG0 - CSIGn Configuration Register 0*/
#define __CSIG_SET_CFG0(_N_,_MASK_,_VAULE_)     MODIFY_REG(CSIGN_VAL(_N_)._CFG0,_MASK_,_VALUE_)
#define __CSIG_GET_CFG0(_N_,_MASK_)             (CSIGN_VAL(_N_)._CFG0 & _MASK_)

/*CSIGnTX0W - CSIGn Transmission Register 0 for Word Access*/
#define __CSIG_SET_TX0W(_N_,_MASK_,_VAULE_)     MODIFY_REG(CSIGN_VAL(_N_)._TX0W,_MASK_,_VALUE_)
#define __CSIG_GET_TX0W(_N_,_MASK_)             (CSIGN_VAL(_N_)._TX0W & _MASK_)

/*CSIGnTX0H - CSIGn Transmission Register 0 for Half Word Access*/
#define __CSIG_WRITE_DATA(_N_,_DATA_)           (CSIGN_VAL(_N_)._TX0H =  _DATA_ & 0xFFFF)

/*CSIGnRX0 - CSIGn Reception Register 0 -- read-only*/
#define __CSIG_READ_DATA(_N_)                   (CSIGN_VAL(_N_)._RX0)

/** @defgroup csi_mode
  * @{
  */
#define CSI_MODE_MASTER                ((uint16_t)0x0000)
#define CSI_MODE_SLAVE                 ((uint16_t)(0x07 << CSI_CSIGnPRS_OFFSET))
/**
  * @}
  */

/** @defgroup csi_data_size
  * @{
  */
#define CSI_DATASIZE_16b               ((uint16_t)0x0000)
#define CSI_DATASIZE_EXTEND            ((uint16_t)(0x01 << CSI_CSIGnEDL_OFFSET))
/**
  * @}
  */

/** @defgroup csi_clock_polarity
  * @{
  */

#define CSI_CPOL_HIGH                  ((uint32_t)0x0000)
#define CSI_CPOL_LOW                   ((uint32_t)(0x01 << CSI_CSIGnCKR_OFFSET))
/**
  * @}
  */

/** @defgroup csi_clock_phase
  * @{
  */
#define CSI_CPHA_1Edge                ((uint32_t)(0x01 << CSI_CSIGnCKR_OFFSET))
#define CSI_CPHA_2Edge                ((uint32_t)0x0000)
/**
  * @}
  */

/** @defgroup csi_baudrate_prescaler
  * @{
  */
#define SPI_BaudRatePrescaler_1         ((uint16_t)0x0000)
#define SPI_BaudRatePrescaler_2         ((uint16_t)(0x01 << CSI_CSIGnPRS_OFFSET))
#define SPI_BaudRatePrescaler_4         ((uint16_t)(0x02 << CSI_CSIGnPRS_OFFSET))
#define SPI_BaudRatePrescaler_8         ((uint16_t)(0x03 << CSI_CSIGnPRS_OFFSET))
#define SPI_BaudRatePrescaler_16        ((uint16_t)(0x04 << CSI_CSIGnPRS_OFFSET))
#define SPI_BaudRatePrescaler_32        ((uint16_t)(0x05 << CSI_CSIGnPRS_OFFSET))
#define SPI_BaudRatePrescaler_64        ((uint16_t)(0x06 << CSI_CSIGnPRS_OFFSET))
/**
  * @}
  */

/** @defgroup SPI_MSB_LSB_transmission
  * @{
  */
#define CSI_FirstBit_MSB                ((uint16_t)0x0000)
#define CSI_FirstBit_LSB                ((uint16_t)(0x01 << CSI_CSIGnDIR_OFFSET))
/**
  * @}
  */

typedef struct{
    uint16_t mode;                  /*!< Specifies the SPI operating mode.
                                         This parameter can be a value of @ref csi_mode */

    uint16_t data_size;             /*!< Specifies the CSI data size.
                                        This parameter can be a value of @ref csi_data_size */

    uint16_t cpol;                  /*!< Specifies the serial clock steady state.
                                        This parameter can be a value of @ref csi_clock_polarity */

    uint16_t cpha;                  /*!< Specifies the clock active edge for the bit capture.
                                        This parameter can be a value of @ref SPI_Clock_Phase */

    uint16_t nss;                   /*!< Specifies whether the NSS signal is managed by
                                        hardware (NSS pin) or by software using the SSI bit.
                                        This parameter can be a value of @ref SPI_Slave_Select_management */

    uint16_t prescaler;             /*!< Specifies the Baud Rate prescaler value which will be
                                        used to configure the transmit and receive SCK clock.
                                        This parameter can be a value of @ref SPI_BaudRate_Prescaler.
                                        @note The communication clock is derived from the master
                                              clock. The slave clock does not need to be set. */

    uint16_t first_bit;             /*!< Specifies whether data transfers start from MSB or LSB bit.
                                        This parameter can be a value of @ref SPI_MSB_LSB_transmission */

}CSIG_InitTypeDef;
