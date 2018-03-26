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

typedef struct{
    __IO bool tx_continue;     //uart transmit could continue
    __IO bool tx_buf_complete; //uart transmit using buffer completely
    __IO bool rx_available;  // uart receive an available data
}UART_tx_rx_StateTypeDef;

UART_tx_rx_StateTypeDef uart_stat[MAX_UART_NUM];

static void UART_TxRx_State_Init(uint8_t uartn);
static void UART_Baudrate_Generator(uint8_t uartn,uint32_t baudrate);


void UART_Init(UART_InitTypeDef* UART_InitStruct)
{
    uint8_t val = 0;
    uint8_t uartn = UART_InitStruct->uartn;

    //Set a baud rate
    UART_Baudrate_Generator(uartn,UART_InitStruct->baudrate);
    //Sets noise filter ON/OFF
    __RLIN3_SET_UART_MODE(uartn,LIN3_LRDNFS_MASK|LIN3_LMD_MASK,
        UART_InitStruct->noi_filter_off | ((uint8_t)UART_MODE));
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

	UART_TxRx_State_Init(uartn);

}

void UART_TxRx_State_Init(uint8_t uartn)
{

    if(uartn >= MAX_UART_NUM){
        ERROR("the uart:%d not supported, the max uart index:%d\n",
            uartn,MAX_UART_NUM - 1);
        return;
    }

    uart_stat[uartn].tx_continue = TRUE;     //uart transmit could continue
    uart_stat[uartn].tx_buf_complete = TRUE; //uart transmit using buffer completely
    uart_stat[uartn].rx_available = FALSE;  // uart receive an available data
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
    UART_BaudrateTypeDef br_st;

    memset(&br_st,0,sizeof(br_st));
    //default baudrate 115200
    br_st.bit_sample_cnt = BAUDRATE_SAMPLE_CNT_16;
    br_st.prescaler_clk = PRESCALER_CLK_DIV_1;
    br_st.brp_un.brp = 21;

    val = (br_st.bit_sample_cnt << LIN3_NSPB_OFFSET) | (br_st.prescaler_clk
        << LIN3_LPRS_OFFSET);

    __RLIN3_SELECT_WAKEUP_BAUDRATE(uartn,LIN3_NSPB_MASK | LIN3_LPRS_MASK,val);
    __RLIN3_SET_BAUDRATE_PRE01(uartn,br_st.brp_un.brp);
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
		while(!uart_stat[uartn].tx_continue);
        if(exp_bit_flag){
			if((data_len %2) && (cnt == len -1))
				val = data[cnt];
			else
            	val = (data[cnt++] | (data[cnt] << 8)) & 0x1FF;
        }else{
           val = data[cnt];
        }
		__RLIN3_WRITE_TX_DATA(uartn,val);
        uart_stat[uartn].tx_continue = FALSE;
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
        uart_stat[uartn].tx_buf_complete = FALSE;
        while(__RLIN3_GET_UART_STAT(uartn,LIN3_FTC_MASK) == 0 && uart_stat[uartn].tx_buf_complete == FALSE);

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

	uart_stat[uartn].rx_available = FALSE;
    return exp_bit_flag;
}

bool UART_Get_Rx_State(uint8_t uartn)
{
	return uart_stat[uartn].rx_available;
}



/**************************LIN3 function****************************************/
__IO static uint32_t s1 = 0,s2 =0;

typedef struct{
    __IO bool m_hdr_sent;   //lin master header   sent     completely
    __IO bool m_frm_sent;  //lin master frame/wake-up sent completely
    __IO bool m_frm_recept;//lin master frame/wake-up sent recepted completed
    __IO bool s_hdr_recept; //lin slave  header   recepted completely
    __IO bool s_resp_sent;  //lin slave  response sent     completely
    __IO bool s_resp_recept;//lin slave  response recepted completed
}LIN3_tx_rx_StateTypeDef;

LIN3_tx_rx_StateTypeDef lin3_stat[MAX_LIN_NUM];

void LIN3_TxRx_State_Init(uint8_t linn);
static void LIN3_Baudrate_Generator(uint8_t linn,LIN3_Mode mode,uint32_t baudrate);
static void LIN3_Enable_Int(uint8_t linn,uint8_t int_out,uint8_t int_mask);
static void LIN3_Enable_Err_Detect(uint8_t linn,uint8_t timeout_err_sel,uint8_t err_mask);
static void LIN3_Set_Frame_Config(uint8_t linn,LIN3_Mode mode,LIN3_ConfigurationTypeDef *cfg_param_p);

static int8_t LIN3_Master_Send_Header(uint8_t linn,uint8_t id);
static void LIN3_Master_Send_Resp(uint8_t linn);
static int8_t LIN3_Master_Recv_Resp(uint8_t linn,uint8_t *recv_data);
static int8_t LIN3_Slave_Recv_Header(uint8_t linn);
static void LIN3_Slave_Send_Resp(uint8_t linn,uint8_t,uint8_t*);
static int8_t LIN3_Slave_Recv_Resp(uint8_t linn,uint8_t* recv_data);
static uint8_t LIN3_Resp_Data_Checksum(uint8_t *data,uint8_t data_len);

static uint8_t LIN3_ID_Parity_Calculate(uint8_t id);

void LIN3_Init(LIN3_InitTypeDef* LIN3_InitStruct)
{
    __IO uint8_t linn  = 0;
    LIN3_Mode mode = LIN3_MASTER;//default LIN3_MASTER

    linn = LIN3_InitStruct->linn;
    mode = LIN3_InitStruct->mode;
    INFOR("LIN3%d mode:%s\n",linn,(mode == 0?"Master":"Slave"));
    LIN3_Baudrate_Generator(linn,mode,LIN3_InitStruct->baudrate);
    //Sets noise filter ON/OFF
    __RLIN3_SET_LIN_MODE(linn,LIN3_LRDNFS_MASK,LIN3_InitStruct->noi_filter_off);
    //Enables interrupt
    LIN3_Enable_Int(linn,LIN3_InitStruct->int_out_sel,
        LIN3_InitStruct->int_en_mask);
    //Enables error detection
    LIN3_Enable_Err_Detect(linn,LIN3_InitStruct->timeout_err_sel,
        LIN3_InitStruct->err_en_mask);
    //Sets frame configuration parameters
    LIN3_Set_Frame_Config(linn,mode,&LIN3_InitStruct->cfg_param);
    //Transitions to LIN master mode/LIN slave mode
    __RLIN3_SET_LIN_MODE(linn,LIN3_LMD_MASK,(uint8_t)mode);
    //Exits from LIN reset mode.
    __RLIN3_SET_LIN_CTL(linn,LIN3_OM0_MASK,1);
    while(__RLIN3_GET_LIN_MODE_STAT(linn,LIN3_OMM0_MASK) == 0);
    //Transitions to LIN operation mode
    __RLIN3_SET_LIN_CTL(linn,LIN3_OM1_MASK,1 << LIN3_OM1_OFFSET);
    while(__RLIN3_GET_LIN_MODE_STAT(linn,LIN3_OMM1_MASK) == 0);

    LIN3_TxRx_State_Init(linn);
}

void LIN3_TxRx_State_Init(uint8_t linn)
{
    if(linn >= MAX_LIN_NUM){
        ERROR("the lin:%d not supported, the max lin index:%d\n",
            linn,MAX_LIN_NUM - 1);
        return;
    }

    lin3_stat[linn].m_hdr_sent = FALSE;
    lin3_stat[linn].m_frm_sent = FALSE;
    lin3_stat[linn].m_frm_recept = FALSE;
    lin3_stat[linn].s_hdr_recept = FALSE;
    lin3_stat[linn].s_resp_sent = FALSE;
    lin3_stat[linn].s_resp_recept = FALSE;
}

void LIN3_TxRx_State_Reset(uint8_t linn)
{
    LIN3_TxRx_State_Init(linn);
}

void LIN3_Baudrate_Generator(uint8_t linn,LIN3_Mode mode,uint32_t baudrate)
{
    __IO uint8_t val = 0;
    LIN3_BaudrateTypeDef br_st;
    memset(&br_st,0,sizeof(br_st));

    if(mode == LIN3_SLAVE_AUTO){
        /*For a LIN slave with auto baud rate, set the NSPB[3:0] bits to “0011B”
        (4 samplings) or “0100B” (8 samplings).*/
        br_st.bit_sample_cnt = BAUDRATE_SAMPLE_CNT_4;
        //TODO.....
    }else{
        /*For a LIN slave with fixed baud rate, set the NSPB[3:0] bit to “0000B”
        (16 samplings) or “1111B” (16 samplings)
        In LIN master mode (LIN/UART mode select bits in LIN mode register = 00B),
        set these bits to 0000B or 1111B (16 sampling) */
        br_st.bit_sample_cnt = BAUDRATE_SAMPLE_CNT_16_;

        //default fa is 307200 Hz,40MHz / 307200 = 130.2
        br_st.prescaler_clk = PRESCALER_CLK_DIV_2;
        br_st.brp_un.bits.brp0 = 64;//64 + 1 = 65

        switch(baudrate){
            case 19200:
                br_st.lin_sys_clk = 0;//fa
                break;
            case 2400:
                br_st.lin_sys_clk = 2;//fc
                break;
            case 10417:
                br_st.prescaler_clk = PRESCALER_CLK_DIV_8;
                br_st.brp_un.brp = 29;
                if(mode == LIN3_MASTER){
                    br_st.brp_un.brp = br_st.brp_un.brp << 8;
                }
                br_st.lin_sys_clk = 3;//fd
                break;
            default://default 9600:
                br_st.lin_sys_clk = 1;//fb
                break;
        }
    }

    val = (br_st.bit_sample_cnt << LIN3_NSPB_OFFSET) | (br_st.prescaler_clk
        << LIN3_LPRS_OFFSET);

    __RLIN3_SELECT_WAKEUP_BAUDRATE(linn,LIN3_NSPB_MASK | LIN3_LPRS_MASK,val);
    __RLIN3_SET_BAUDRATE_PRE01(linn,br_st.brp_un.brp);

    //Configure the RLN3nLMD register when LIN reset mode)
    __RLIN3_SET_LIN_MODE(linn,LIN3_LCKS_MASK,br_st.lin_sys_clk << LIN3_LCKS_OFFSET);
}

void LIN3_Enable_Int(uint8_t linn,uint8_t int_out_sel,uint8_t int_mask)
{
    if(!int_out_sel){
        //RLIN3n interrupt is used.
        __RLIN3_SET_LIN_MODE(linn,LIN3_LIOS_MASK,0);
    }else{
        // RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and
        // RLIN3n status interrupt are used.
        __RLIN3_SET_LIN_MODE(linn,LIN3_LIOS_MASK,1 << LIN3_LIOS_OFFSET);
        __RLIN3_CONFIG_INT(linn,int_mask);
    }
}

void LIN3_Enable_Err_Detect(uint8_t linn,uint8_t timeout_err_sel,uint8_t err_mask)
{
    //enable frame error detection,timeout error detection,Physical bus error detection
    //bit error detection
    __RLIN3_CONFIG_ERR_DETECT(linn,err_mask);

    //Timeout Error Select-- 0: Frame timeout error,1: Response timeout error
    __RLIN3_ENABLE_ERR_DETECT(linn,LIN3_LTES_MASK,timeout_err_sel << LIN3_LTES_OFFSET);
}

void LIN3_Set_Frame_Config(uint8_t linn,LIN3_Mode mode,LIN3_ConfigurationTypeDef *cfg_param_p)
{
    if(mode == LIN3_MASTER){
    //config the lin break field
        __RLIN3_SET_BREAK_FIELD_CONFIG(linn,LIN3_BDT_MASK| LIN3_BLT_MASK,
            cfg_param_p->break_delim_width << LIN3_BDT_OFFSET | cfg_param_p->break_width);
    }else{ //LIN3_SLAVE_AUTO or LIN3_SLAVE_FIXED
        __RLIN3_SET_BREAK_FIELD_CONFIG(linn,LIN3_LBLT_MASK, cfg_param_p->rx_break_detect_width);
    }
    //config the lin space
    __RLIN3_SET_LIN_SPACE(linn,LIN3_IBS_MASK | LIN3_IBHS_MASK,
        cfg_param_p->inter_byte_space << LIN3_IBS_OFFSET | cfg_param_p->resp_space);
    //config the lin wake-up
    __RLIN3_SET_WAKEUP_CONIFG(linn,LIN3_WUTL_MASK,cfg_param_p->wu_tx_ll_width << LIN3_WUTL_OFFSET);
}
int8_t LIN3_Master_Process(uint8_t linn,LIN3_Frm_InfoTypeDef *info_p,uint8_t resp_len,uint8_t *resp_data)
{
    __IO uint8_t mask = 0, val = 0;
	__IO int8_t recv_len = resp_len;

    //Configures the RLN3nLDFC register,the checksum mode, response direction and
    mask = LIN3_LCS_MASK | LIN3_RCDS_MASK | LIN3_RFDL_MASK;
    /*In response reception,repeats the transmission of inter-byte spaces as many times as the data
    length specified in bits RFDL[3:0] in the RLN3nLDFC register),so the resp_len mut be specified*/
    val = (info_p->cs_meth << LIN3_LCS_OFFSET) | (info_p->resp_dir << LIN3_RCDS_OFFSET) |
        resp_len;

    if(info_p->resp_dir == 1){//Response Field Communication Direction: transmission
        __IO uint8_t i = 0;
        for(;i < resp_len;i++){
            __RLIN3_WRITE_DATA_BUF(linn,(i+1),resp_data[i]);
        }
        LIN3_Resp_Data_Checksum(resp_data,resp_len);

    }
    __RLIN3_SET_DATA_FIELD_CONFIG(linn,mask,val);

    LIN3_Master_Send_Header(linn,info_p->frm_id);

    if(info_p->resp_dir == 1){ //Response Field Communication Direction: transmission
        LIN3_Master_Send_Resp(linn);
    }else{ //Response Field Communication Direction: reception
        recv_len = LIN3_Master_Recv_Resp(linn,resp_data);
    }
    if(recv_len > 0){//dump the sent/recv data
        uint8_t dump_data[9] = {0};
        memcpy(&dump_data,resp_data,resp_len);
        dump_data[resp_len] = '\0';
        INFOR("lin3%d master id:0x%x %s response len:%d data:%s\n",linn,info_p->frm_id,
            info_p->resp_dir == 1 ?"send":"recv",resp_len,dump_data);
    }

    LIN3_TxRx_State_Reset(linn);

    return recv_len;
}

int8_t LIN3_Master_Send_Header(uint8_t linn,uint8_t id)
{
    __IO uint8_t idp = 0;

    idp = LIN3_ID_Parity_Calculate(id);
    idp &= 0x03;
    INFOR("Master send header\n");
    __RLIN3_SET_ID_BUF(linn,(idp << LIN3_IDP0_OFFSET) | id);

    //frame transmission or wake-up transmission/reception started
    __RLIN3_SET_LIN_TX_CTL(linn,LIN3_FTS_MASK,1);

    while(lin3_stat[linn].m_hdr_sent == FALSE);//failed after 10ms delay

    return 0;//Successful
}

void LIN3_Master_Send_Resp(uint8_t linn)
{

    if(__RLIN3_GET_DATA_FIELD_CONFIG(linn,LIN3_FSM_MASK)){
        //Frame separate mode is set.
        __RLIN3_SET_LIN_TX_CTL(linn,LIN3_RTS_MASK,1 << LIN3_RTS_OFFSET);
    }/*else{
        //Frame separate mode is not set.
        //Waits for an interrupt request
    }*/

    // wait for frame or wake-up transmission completed
    while(__RLIN3_GET_LIN_STAT(linn,LIN3_FTC_MASK) == 0);
    //clear the flag
    __RLIN3_SET_LIN_STAT(linn,LIN3_FTC_MASK,0);
}

int8_t LIN3_Master_Recv_Resp(uint8_t linn,uint8_t *recv_data)
{
    __IO uint8_t recv_len = 0,i = 0;

    //Wait for response received
    while(lin3_stat[linn].m_frm_recept == FALSE);
	if(__RLIN3_GET_LIN_ERR_STAT(linn,LIN3_FTER_MASK)){
		ERROR("Frame/response timeout error has been detected.\n");
		return -1;
	}

    //wait for the successful data 1 reception flag set.
	while(__RLIN3_GET_LIN_STAT(linn,LIN3_D1RC_MASK) == 0);
    //wait for the Frame Transmission/wake-up transmission/reception is stopped
	while(__RLIN3_GET_LIN_TX_CTL(linn,LIN3_FTS_MASK));
	//Wait for the successful frame/wake-up reception flag set.
    while(__RLIN3_GET_LIN_STAT(linn,LIN3_FRC_MASK) == 0);

    recv_len = __RLIN3_GET_DATA_FIELD_CONFIG(linn,LIN3_RFDL_MASK);

    for(;i < recv_len;i++){
        recv_data[i] =  __RLIN3_READ_DATA_BUF(linn,i + 1) ;
    }

    __RLIN3_SET_LIN_STAT(linn,LIN3_D1RC_MASK,0);
    //clear the flag
    __RLIN3_SET_LIN_STAT(linn,LIN3_FRC_MASK,0);

    return recv_len;
}

int8_t LIN3_Slave_Process(uint8_t linn, LIN3_Frm_InfoTypeDef *info_p,uint8_t resp_len,uint8_t *resp_data)
{
    __IO uint8_t mask = 0, val = 0,recv_len = resp_len;
    __IO uint8_t frm_id = 0;

    //Configures the RLN3nLDFC register,the checksum mode, response direction and response Field Length
    mask = LIN3_LCS_MASK | LIN3_RCDS_MASK | LIN3_RFDL_MASK;
    /*In response reception,repeats the transmission of inter-byte spaces as many times as the data
    length specified in bits RFDL[3:0] in the RLN3nLDFC register),so the resp_len mut be specified*/
    val = (info_p->cs_meth << LIN3_LCS_OFFSET) | (info_p->resp_dir << LIN3_RCDS_OFFSET) |
        resp_len;

    if(info_p->resp_dir == 1){//Response Field Communication Direction: transmission
        __IO uint8_t i = 0;
        for(;i < resp_len;i++){
            __RLIN3_WRITE_DATA_BUF(linn,(i+1),resp_data[i]);
        }

    }
    __RLIN3_SET_DATA_FIELD_CONFIG(linn,mask,val);

    frm_id = LIN3_Slave_Recv_Header(linn);

    if(frm_id == -1) return -1;

    if(info_p->resp_dir == 1){ //Response Field Communication Direction: transmission
        LIN3_Slave_Send_Resp(linn,resp_len,resp_data);
    }else{ //Response Field Communication Direction: reception
        recv_len = LIN3_Slave_Recv_Resp(linn,resp_data);
    }
    if(recv_len > 0){
        __IO uint8_t dump_data[10] = {0};
        memcpy(dump_data,resp_data,resp_len);
        dump_data[resp_len] = '\0';
        INFOR("lin3%d %s id:0x%x response len:%d data:%s\n",linn,info_p->resp_dir == 1 ?
            "send to":"recv from",frm_id,resp_len,dump_data);
    }
    LIN3_TxRx_State_Reset(linn);

    return recv_len;
}


int8_t LIN3_Slave_Recv_Header(uint8_t linn)
{
    __IO uint8_t id = 0;
    //Header reception/wake-up transmission/reception is started.
    __RLIN3_SET_LIN_TX_CTL(linn,LIN3_FTS_MASK,1);

    //Checks the RLN3nLST register, and clears flags.
    //wait for header reception complete interrupt and Successful Header Reception Flag
    INFOR("Wait for frame header....\n");
    while(lin3_stat[linn].s_hdr_recept == FALSE);
    //wait for Header reception has been completed.
    while(__RLIN3_GET_LIN_STAT(linn,LIN3_HTRC_MASK) == 0);
    //chear the flag
    __RLIN3_SET_LIN_STAT(linn,LIN3_HTRC_MASK,0);

    id = __RLIN3_GET_ID_BUF(linn);
    //ID parity detection enabled
    if(__RLIN3_GET_ERR_DETECT(linn,LIN3_IPERE_MASK)){
        /*When the IPERE bit in the RLN3nLEDE register is 1 (ID parity detection
        enabled), the received value and the value calculated internally are compared.
        If they do not match, IPER (ID parity error flag) is set.*/
        if(__RLIN3_GET_LIN_ERR_STAT(linn,LIN3_IPER_MASK)){
            ERROR("lin:%d ID parity compared internally not matched.",linn);
            return -1;
        }
    }else{ //ID parity detection disabled
        uint8_t idp = 0;

        idp = id >> LIN3_IDP0_OFFSET;
        id &= 0x3F;
        //Checks the RLN3nLIDB register, and prepares a response
        if(idp != LIN3_ID_Parity_Calculate(id)){
            ERROR("lin:%d ID parity error has been detected.",linn);
            return -1;
        }
    }

    return id & 0x3F;
}

void LIN3_Slave_Send_Resp(uint8_t linn,uint8_t resp_len,uint8_t* resp_data)
{
	/*__RLIN3_SET_LIN_TX_CTL(linn,LIN3_LNRR_MASK,1 << LIN3_LNRR_OFFSET);
	return;//No LIN Response Request*/

	// Sets the RTS bit in the RLN3nLTRC register to 1(response transmission/
	//reception started)
    __RLIN3_SET_LIN_TX_CTL(linn,LIN3_RTS_MASK,1 << LIN3_RTS_OFFSET);

    while(lin3_stat[linn].s_resp_sent == FALSE);//wait for interruption

    // wait for frame or wake-up transmission completed
    while(__RLIN3_GET_LIN_STAT(linn,LIN3_FTC_MASK) == 0);
    //clear the flag
    __RLIN3_SET_LIN_STAT(linn,LIN3_FTC_MASK,0);
}

int8_t LIN3_Slave_Recv_Resp(uint8_t linn,uint8_t* recv_data)
{
    __IO uint8_t recv_len = 0,i = 0;

    //Sets the response transmission/reception start bit (RTS bit) to 1
    __RLIN3_SET_LIN_TX_CTL(linn,LIN3_RTS_MASK,1 << LIN3_RTS_OFFSET);

    while(lin3_stat[linn].s_resp_recept == FALSE);//wait for recepted interruption

    //wait for the successful data 1 reception flag set.
	//while(__RLIN3_GET_LIN_STAT(linn,LIN3_D1RC_MASK) == 0);
    //wait for the successful response/wake-up reception flag set
	while(__RLIN3_GET_LIN_TX_CTL(linn,LIN3_RTS_MASK));
	//Wait for frame or wake-up receive completed
    while(__RLIN3_GET_LIN_STAT(linn,LIN3_FRC_MASK) == 0);

    recv_len = __RLIN3_GET_DATA_FIELD_CONFIG(linn,LIN3_RFDL_MASK);

    for(;i < recv_len;i++){
        recv_data[i] =  __RLIN3_READ_DATA_BUF(linn,i + 1) ;
    }

    __RLIN3_SET_LIN_STAT(linn,LIN3_D1RC_MASK,0);
    //clear the flag
    __RLIN3_SET_LIN_STAT(linn,LIN3_FRC_MASK,0);

    return recv_len;

}

uint8_t LIN3_ID_Parity_Calculate(uint8_t id)
{
    __IO uint8_t idp0 = 0,idp1 = 0;

    idp0 = (id & 0x01) ^((id >> 1) & 0x01) ^ ((id >> 2) & 0x01) ^ ((id >> 4) & 0x01);
    idp1 = ((id >> 1) & 0x01) ^ ((id >> 3) & 0x01) ^ ((id >> 4) & 0x01) ^ ((id >> 5) & 0x01);
    idp1 = !idp1;

    //INFOR("id:0x%x,idp0:%d,idp1:%d\n",id,idp0,idp1);
    idp0 |= idp1 << 1;

    return idp0;// bit 1:idp1 bit0:idp0
}

uint8_t LIN3_Resp_Data_Checksum(uint8_t *data,uint8_t data_len)
{
    uint8_t i = 0;
    __IO uint16_t sum = 0;

    for(;i < data_len;i++){
        sum += data[i];
        if(sum >> 8){
            sum =   (sum &0xff) + (sum >> 8);
        }
    }

    sum = 0xff - sum;
    INFOR("The checksum of data is 0x%x\n",sum);

    return sum;
}

void RLIN3_Self_Mode_Init(LIN3_SelfModeInitTypeDef *LIN3_InitStruct)
{
    __IO uint8_t linn  = 0;
    LIN3_Mode mode = LIN3_MASTER;//default LIN3_MASTER

    linn = LIN3_InitStruct->linn;
    mode = LIN3_InitStruct->mode;
    //Transition to LIN reset mode
    //Set the OM0 bit in the RLN3nLCUC register to 0 (LIN reset mode).
    //Read the OMM0 bit in the RLN3nLMST register; verify that it is 0 (LIN reset mode)
    while(__RLIN3_GET_LIN_MODE_STAT(linn,LIN3_OMM0_MASK)){
        __RLIN3_SET_LIN_CTL(linn,LIN3_OM0_MASK,0);
    }

    //Select a LIN mode
    //LMD bits in RLN3nLMD = 00B (LIN master mode) or 11B (LIN slave mode [fixed baud rate])
    __RLIN3_SET_LIN_MODE(linn,LIN3_LMD_MASK,(uint8_t)mode);

    //1st write: RLN3nLSTC register = 1010 0111B (A7H)
    //2nd write: RLN3nLSTC register = 0101 1000B (58H)
    //3rd write: RLN3nLSTC register = 0000 0001B (01H)
    __RLIN3_ENTER_SELF_TEST(linn);

    //Verify the transition to LIN self-test mode
    //Read the LSTM bit in the RLN3nLSTC register; verify that it is 1 (LIN self-test mode)

    if(__RLIN3_GET_SELF_TEST_STAT(linn) == 0){
        ERROR("Transition to LIN reset mode failed\n");
        return;
    }

    LIN3_Baudrate_Generator(linn,mode,LIN3_InitStruct->baudrate);
    //Sets noise filter ON/OFF
    __RLIN3_SET_LIN_MODE(linn,LIN3_LRDNFS_MASK,LIN3_InitStruct->noi_filter_off);
    //Enables interrupt
    LIN3_Enable_Int(linn,LIN3_InitStruct->int_out_sel,
        LIN3_InitStruct->int_en_mask);
    //Enables error detection
    LIN3_Enable_Err_Detect(linn,LIN3_InitStruct->timeout_err_sel,
        LIN3_InitStruct->err_en_mask);
    //Sets frame configuration parameters
    LIN3_Set_Frame_Config(linn,mode,&LIN3_InitStruct->cfg_param);
    //Transitions to LIN master mode/LIN slave mode
    __RLIN3_SET_LIN_MODE(linn,LIN3_LMD_MASK,(uint8_t)mode);
    //Exits from LIN reset mode.
    __RLIN3_SET_LIN_CTL(linn,LIN3_OM0_MASK,1);
    while(__RLIN3_GET_LIN_MODE_STAT(linn,LIN3_OMM0_MASK) == 0);
}


/******************************************************************************/
#pragma interrupt RLIN30SendIntHandler(channel = 26, enable = false, callt = false, fpu = false)
void RLIN30SendIntHandler(unsigned long eiic)
{
    if(!uart_stat[0].tx_continue)
        uart_stat[0].tx_continue = TRUE;
    /*if(__RLIN3_GET_UART_STAT(0,LIN3_FTC_MASK)){
        __RLIN3_SET_UART_STAT(0,LIN3_FTC_MASK,0);
		tx_buf_complete = TRUE;
	}*/
    if(!lin3_stat[0].m_hdr_sent)
	    lin3_stat[0].m_hdr_sent = TRUE;
	if(!lin3_stat[0].s_resp_sent)
	    lin3_stat[0].s_resp_sent = TRUE;
}

#pragma interrupt RLIN30RecvCompleteIntHandler(channel = 27, enable = false, callt = false, fpu = false)
void RLIN30RecvCompleteIntHandler(unsigned long eiic)
{
    if(!uart_stat[0].rx_available)
        uart_stat[0].rx_available = TRUE;//uart received data
    if(!lin3_stat[0].s_hdr_recept)
        lin3_stat[0].s_hdr_recept = TRUE;
    if(!lin3_stat[0].s_resp_recept)
        lin3_stat[0].s_resp_recept = TRUE;
    if(!lin3_stat[0].m_frm_recept)
        lin3_stat[0].m_frm_recept = TRUE;
}

#pragma interrupt RLIN30StatusIntHandler(channel = 28, enable = false, callt = false, fpu = false)
void RLIN30StatusIntHandler(unsigned long eiic)
{
	if(!lin3_stat[0].m_frm_recept)
		lin3_stat[0].m_frm_recept = TRUE;
	//while(1);
}


#pragma interrupt RLIN31SendIntHandler(channel = 113, enable = false, callt = false, fpu = false)
void RLIN31SendIntHandler(unsigned long eiic)
{
    if(!uart_stat[1].tx_continue)
        uart_stat[1].tx_continue = TRUE;
    /*if(__RLIN3_GET_UART_STAT(1,LIN3_FTC_MASK)){
        __RLIN3_SET_UART_STAT(1,LIN3_FTC_MASK,0);
		uart_stat[1].tx_buf_complete = TRUE;
	}*/
    if(!lin3_stat[1].m_hdr_sent)
	    lin3_stat[1].m_hdr_sent = TRUE;
    if(!lin3_stat[1].s_resp_sent)
	    lin3_stat[1].s_resp_sent = TRUE;

}

#pragma interrupt RLIN31RecvCompleteIntHandler(channel = 114, enable = false, callt = false, fpu = false)
void RLIN31RecvCompleteIntHandler(unsigned long eiic)
{
    if(!uart_stat[1].rx_available)
        uart_stat[1].rx_available = TRUE;//uart received data
    if(!lin3_stat[1].s_hdr_recept)
        lin3_stat[1].s_hdr_recept = TRUE;
    if(!lin3_stat[1].s_resp_recept)
        lin3_stat[1].s_resp_recept = TRUE;
    if(!lin3_stat[1].m_frm_recept)
        lin3_stat[1].m_frm_recept = TRUE;
}

#pragma interrupt RLIN31StatusIntHandler(channel = 115, enable = false, callt = false, fpu = false)
void RLIN31StatusIntHandler(unsigned long eiic)
{
	//while(1);
}
