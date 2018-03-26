#include "lin.h"

#define LIN3_INDEX_USED     1
#define LIN3_MASTER_TEST    0
#define LIN3_SLAVE_TEST     !LIN3_MASTER_TEST

void (*lin3_func_excute)(void);

void lin3_init(void)
{
    LIN3_InitTypeDef lin31;

    memset(&lin31,0,sizeof(lin31));

    lin31.linn = LIN3_INDEX_USED;
#if LIN3_MASTER_TEST
    lin31.mode = LIN3_MASTER;
#else //LIN3_SLAVE_TEST
    lin31.mode = LIN3_SLAVE_FIXED;
#endif
    lin31.baudrate = 19200;
#if LIN3_MASTER_TEST
    lin31.cfg_param.break_delim_width = 0x00;// 2Tbits
    lin31.cfg_param.break_width = 0x01;// 14 Tbits
#else
    lin31.cfg_param.rx_break_detect_width = 1;//1: Low-level width of 10.5 Tbits or longer is detected
#endif
    lin31.cfg_param.inter_byte_space = 0x01; //1 Tbit
    lin31.cfg_param.resp_space = 0x01;// 1 Tbit
    lin31.cfg_param.wu_tx_ll_width = 0x01;//2Tbits;

    lin31.int_out_sel = 1;/*RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and
                        RLIN3n status interrupt are used.*/
    lin31.int_en_mask = LIN3_EN_HDR_TX_INT_MASK | LIN3_ERR_DETECT_INT_MASK;

#if LIN3_MASTER_TEST
    lin31.int_en_mask |= LIN3_FRM_WU_TX_INT_MASK | LIN3_FRM_WU_RX_INT_MASK;
#else
    lin31.int_en_mask |= LIN3_RES_WU_TX_INT_MASK | LIN3_RES_WU_RX_INT_MASK;
#endif

    lin31.timeout_err_sel = 0;// Response timeout error

    lin31.err_en_mask = LIN3_FRM_ERR_DETECT_MASK | LIN3_TIO_ERR_DETECT_MASK | LIN3_BIT_ERR_DETECT_MASK;//LIN Error Detection Enable mask
#if LIN3_MASTER_TEST
    lin31.err_en_mask |= LIN3_PHB_ERR_DETECT_MASK;
#else
    lin31.err_en_mask |= LIN3_IDP_ERR_DETECT_MASK;
#endif

    LIN3_Init(&lin31);

#if LIN3_MASTER_TEST
    lin3_func_excute = lin3_master_excute;
#else
    lin3_func_excute = lin3_slave_excute;
#endif
}

void lin3_self_mode_init(void)
{
    LIN3_InitTypeDef lin31;

    memset(&lin31,0,sizeof(lin31));

    lin31.linn = LIN3_INDEX_USED;
    lin31.mode = LIN3_MASTER;
    lin31.baudrate = 19200;

    lin31.cfg_param.break_delim_width = 0x01;// 2Tbits
    lin31.cfg_param.break_width = 0x01;// 14 Tbits
    lin31.cfg_param.inter_byte_space = 0x01; //1 Tbit
    lin31.cfg_param.resp_space = 0x01;// 1 Tbit
    lin31.cfg_param.wu_tx_ll_width = 0x01;//2Tbits;

    lin31.int_out_sel = 1;/*RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and
                        RLIN3n status interrupt are used.*/
    lin31.int_en_mask = LIN3_EN_HDR_TX_INT_MASK | LIN3_ERR_DETECT_INT_MASK |
        LIN3_FRM_WU_TX_INT_MASK;
    lin31.timeout_err_sel = 0;// Response timeout error

    lin31.err_en_mask = LIN3_FRM_ERR_DETECT_MASK | LIN3_PHB_ERR_DETECT_MASK | LIN3_BIT_ERR_DETECT_MASK;//LIN Error Detection Enable mask

    RLIN3_Self_Mode_Init(&lin31);
}


void lin3_master_excute(void)
{
    __IO uint8_t resp_data[10] = "abcdefg";
    LIN3_Frm_InfoTypeDef lin3_frm;

    memset(&lin3_frm,0,sizeof(lin3_frm));

    lin3_frm.frm_id = 0x30;
    lin3_frm.frm_sep = 0;
    lin3_frm.resp_dir = 1;//response direction 1:transmit 0:receive

    LIN3_Master_Process(LIN3_INDEX_USED,&lin3_frm,7,resp_data);
}

void lin3_slave_excute(void)
{
    __IO uint8_t resp_data[10] = "12345678";

    LIN3_Frm_InfoTypeDef lin3_frm;

    memset(&lin3_frm,0,sizeof(lin3_frm));

    lin3_frm.resp_dir = 0;// 1:transmit 0:receive

    LIN3_Slave_Process(LIN3_INDEX_USED,&lin3_frm,7,resp_data);
}

extern uint8_t lin_master_sent_count;//defined in main.c

void lin3_test_excute()
{
#if LIN3_MASTER_TEST
    if(lin_master_sent_count){
		INFOR("Master send....\n");
		lin3_master_excute();
		lin_master_sent_count--;
	}
#else
	lin3_slave_excute();
#endif
}
