/**
  ******************************************************************************
  * @file    rh850f1l_rlin.c
  * @author  Automotive Business Division
  * @version V1.0.0
  * @date   8-March-2018
  * @brief   RLIN3 module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of RLIN3 peripheral:
  *           + Initialization and de-initialization functions
  *           + RLIN3 functions
  ******************************************************************************
  */
#include "rh850f1l_rlin.h"

static __IO bool tx_continue = TRUE;
static __IO bool tx_buf_complete = TRUE;
static __IO bool rx_available = FALSE;
static void UART_Baudrate_Generator(uint8_t uartn,uint32_t baudrate);


void UART_Init(UART_InitTypeDef* UART_InitStruct)
{
    uint8_t val = 0;
    uint8_t uartn = UART_InitStruct->uartn;

    //Set a baud rate
    UART_Baudrate_Generator(uartn,UART_InitStruct->baudrate);
    //Sets noise filter ON/OFF
    __RLIN3_SET_UART_MODE(uartn,LIN3_LRDNFS_MASK|LIN3_LMD_MASK,UART_InitStruct->noi_filter_off | 0x01);
    //Enables error detection.
    __RLIN3_ENABLE_ERR_DETECT(uartn,LIN3_FERE_MASK|LIN3_OERE_MASK|LIN3_BERE_MASK,
        UART_InitStruct->err_dct_un.err_dct);
    //Configures data format.
    val = UART_InitStruct->word_length | (UART_InitStruct->stop_bits << LIN3_USBLS_OFFSET) |
        (UART_InitStruct->parity << LIN3_UPS_OFFSET);
    __RLIN3_SET_UART_CONFIG(uartn,LIN3_USBLS_MASK|LIN3_UPS_MASK|LIN3_UBLS_MASK,val);

    //Sets an interrupt generation timing to the completion of transmission.
    __RLIN3_SET_OPTION_REG(uartn,LIN3_UTIGTS_MASK,UART_InitStruct->opt_un.option);

    //Exits from LIN reset mode.
    __RLIN3_SET_UART_CTL(uartn,LIN3_OM0_MASK,1);
    while(__RLIN3_GET_UART_MODE_STAT(uartn,LIN3_OMM0_MASK) == 0);
    //Sets the transmission enable bit (UTOE bit) and reception enable bit(UROE) to 1
    __RLIN3_ENABEL_OPERATION(uartn,LIN3_UROE_MASK|LIN3_UTOE_MASK,3);

}

 /*
  *@brief:Set a baud rate
    UART baud rate is calculated with the following formula:
    UART baud rate = = {LIN communication clock source frequency} *
    (RLN3nLWBR.LPRS[2:0] selected clock) / (RLN3nLBRP01 + 1) /
    {RLN3nLWBR.NSPB[3:0] selected count} [bps]
  */
void UART_Baudrate_Generator(uint8_t uartn,uint32_t baudrate)
{
    __IO uint8_t val = 0;
    UART_BaudrateTypedef br_st;

    //default baudrate 115200
    br_st.bit_sample_cnt = UART_BAUDRATE_SAMPLE_CNT_16;
    br_st.prescaler_clk = UART_PRESCALER_CLK_DIV_1;
    br_st.br_prescaler = 21;

    val = (br_st.bit_sample_cnt << LIN3_NSPB_OFFSET) | (br_st.prescaler_clk
        << LIN3_LPRS_OFFSET);

    __RLIN3_SELECT_WAKEUP_BAUDRATE(uartn,LIN3_NSPB_MASK | LIN3_LPRS_MASK,val);
    __RLIN3_SET_BAUDRATE_PRE01(uartn,br_st.br_prescaler);
}

uint8_t UART_Send_Data(uint8_t uartn,uint8_t* data, uint8_t data_len)
{
    __IO uint8_t cnt = 0,exp_bit_flag = 0,len = data_len;
	__IO uint16_t val = 0;
    //enabled or disabled expansion bit operation -- 9 bit
    exp_bit_flag = __RLIN3_GET_OPTION_REG(uartn,LIN3_UEBE_MASK);
	if(exp_bit_flag){
        len = data_len / 2;
        if(data_len % 2)  len++;
    }

    for(cnt = 0;cnt < len;cnt++){
        while(!tx_continue);
        if(exp_bit_flag){
			if((data_len %2) && (cnt == len -1))
				val = data[cnt];
			else
            	val = (data[cnt++] | (data[cnt] << 8)) & 0x1FF;
        }else{
           val = data[cnt];
        }
		__RLIN3_WRITE_TX_DATA(uartn,val);
        tx_continue = 0;
    }

    return cnt;
}


int32_t UART_Send_Data_Buf(uint8_t uartn,uint8_t* data, uint32_t data_len)
{
    __IO uint32_t sent_len = 0,len = 0,data_index = 0,buf_index = 1;

    while(sent_len < data_len && __RLIN3_GET_UART_TX_CTL(uartn,LIN3_RTS_MASK) == 0){
        uint8_t i = 1;

        __RLIN3_WRITE_DATA_BUF0(uartn,0);
        for(;i < 9;i++){
            __RLIN3_WRITE_DATA_BUF(uartn,i,0);
    	}
        len = ((data_len - sent_len) / 9)?9:(data_len - sent_len);
        // Sets the UART buffer data length and whether the start of transmission must be waited.
        __RLIN3_SET_DATA_FIELD_CONFIG(uartn,LIN3_MDL_MASK,len);

        //The RLN3nLUDB0 register is used only if 9-byte transmission is specified
        if(len == 9){
            __RLIN3_WRITE_DATA_BUF0(uartn,data[data_index++]);
        }
        //Specifies the data to be transmitted in the UART data 0 buffer register (RLN3nLUDB0) and the
        //LIN data buffer b register (RLN3nLDBRb). (b =1 to 8)
        for(;data_index < sent_len + len;data_index++){
            __RLIN3_WRITE_DATA_BUF(uartn,buf_index++,data[data_index]);
    	}

        //Sets the UART buffer transmission start bit (RTS)
        __RLIN3_SET_UART_TX_CTL(uartn,LIN3_RTS_MASK,1 << LIN3_RTS_OFFSET);

        buf_index = 1;
        sent_len += len;
        tx_buf_complete = FALSE;
        while(__RLIN3_GET_UART_STAT(uartn,LIN3_FTC_MASK) == 0 && tx_buf_complete == FALSE);

		__RLIN3_SET_UART_TX_CTL(uartn,LIN3_RTS_MASK,0 << LIN3_RTS_OFFSET);

    }
    return sent_len;
}


uint8_t UART_Recv_Data(uint8_t uartn,uint16_t* data)
{
    uint8_t exp_bit_flag = 0;
    uint16_t recv_data = 0;

    recv_data = __RLIN3_READ_RX_DATA(uartn);
    exp_bit_flag = __RLIN3_GET_OPTION_REG(uartn,LIN3_UEBE_MASK);

	*data = recv_data;

	rx_available = FALSE;
    return exp_bit_flag;
}

bool UART_Get_Rx_State(void)
{
	return rx_available;
}

#pragma interrupt RLIN30SendIntHandler(channel = 26, enable = false, callt = false, fpu = false)
void RLIN30SendIntHandler(unsigned long eiic)
{
        tx_continue = 1;
        if(__RLIN3_GET_UART_STAT(0,LIN3_FTC_MASK)){
            __RLIN3_SET_UART_STAT(0,LIN3_FTC_MASK,0);
			tx_buf_complete = TRUE;
		}
}

#pragma interrupt RLIN30RecvCompleteIntHandler(channel = 27, enable = false, callt = false, fpu = false)
void RLIN30RecvCompleteIntHandler(unsigned long eiic)
{
	rx_available = TRUE;
}
