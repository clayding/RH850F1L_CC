#include "lin.h"

void lin3_init(void)
{
    LIN3_InitTypeDef lin31;

    memset(&lin31,0,sizeof(lin31));

    lin31.linn = 0;
    lin31.mode = LIN3_MASTER;
    lin31.baudrate = 19200;

    lin31.cfg_param.break_delim_width = 0x00;// 2Tbits
    lin31.cfg_param.break_width = 0x0F;// 14 Tbits
    lin31.cfg_param.inter_byte_space = 0x01; //1 Tbit
    lin31.cfg_param.resp_space = 0x01;// 1 Tbit
    lin31.cfg_param.wu_tx_ll_width = 0x01;//2Tbits;

    lin31.int_out_sel = 1;/*RLIN3n transmission interrupt, RLIN3n successful reception interrupt, and
                        RLIN3n status interrupt are used.*/
    lin31.int_en_mask = LIN3_EN_HDR_TX_INT_MASK | LIN3_ERR_DETECT_INT_MASK |
        LIN3_FRM_WU_TX_INT_MASK;
    lin31.timeout_err_sel = 1;// Response timeout error

    lin31.err_en_mask = LIN3_FRM_ERR_DETECT_MASK | LIN3_TIO_ERR_DETECT_MASK |
        LIN3_PHB_ERR_DETECT_MASK | LIN3_BIT_ERR_DETECT_MASK;//LIN Error Detection Enable mask

    LIN3_Init(&lin31);
}

void lin3_self_mode_init(void)
{
    LIN3_InitTypeDef lin31;

    memset(&lin31,0,sizeof(lin31));

    lin31.linn = 1;
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
    lin31.timeout_err_sel = 1;// Response timeout error

    lin31.err_en_mask = LIN3_FRM_ERR_DETECT_MASK | LIN3_PHB_ERR_DETECT_MASK | LIN3_BIT_ERR_DETECT_MASK;//LIN Error Detection Enable mask

    RLIN3_Self_Mode_Init(&lin31);
}


void lin3_master_excute(void)
{
    LIN3_Frm_InfoTypeDef lin3_frm;

    memset(&lin3_frm,0,sizeof(lin3_frm));

    lin3_frm.frm_id = 0x31;
    lin3_frm.frm_sep = 0;
    lin3_frm.resp_dir = 1;

    LIN3_Master_Process(0,&lin3_frm,7,"abcdefg");
}
