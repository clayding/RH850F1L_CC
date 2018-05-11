#ifndef LIN_H
#define LIN_H

#include "rh850f1l_rlin.h"

/******************************************************************************/
/**######  #       ### #     #  #####        #     #    #    ######  #######***/ 
/**#     # #        #  ##    # #     #       #     #   # #   #     #    #   ***/ 
/**#     # #        #  # #   #       #       #     #  #   #  #     #    #   ***/ 
/**######  #        #  #  #  #  #####        #     # #     # ######     #   ***/ 
/**#   #   #        #  #   # #       #       #     # ####### #   #      #   ***/ 
/**#    #  #        #  #    ## #     #       #     # #     # #    #     #   ***/ 
/**#     # ####### ### #     #  #####         #####  #     # #     #    #   ***/
/******************************************************************************/
void lin3_init(void);
void lin3_master_excute(void);
void lin3_slave_excute(void);



/******************************************************************************/
/*******************######  #       ### #     #  ##### ************************/ 
/*******************#     # #        #  ##    # #     #************************/ 
/*******************#     # #        #  # #   #       #************************/ 
/*******************######  #        #  #  #  #  ##### ************************/ 
/*******************#   #   #        #  #   # # #      ************************/ 
/*******************#    #  #        #  #    ## #      ************************/ 
/*******************#     # ####### ### #     # #######************************/ 
/******************************************************************************/

/*Note:
All the below definitions defined according to the requirement of the Gearchief*/

struct uiLin2Config {
    uint8_t uiBreak_delim_width;/*<Transmission Break Delimiter (High Level) Width Select
                                0 0: 1 Tbit, 0 1: 2 Tbits,1 0: 3 Tbits,1 1: 4 Tbits>*/
    uint8_t uiBreak_width;/*<Transmission Break (Low Level) Width Select
                            0 0 0 0: 13 Tbits
                            0 0 0 1: 14 Tbits
                            0 0 1 0: 15 Tbits
                            :
                            1 1 1 0: 27 Tbits
                            1 1 1 1: 28 Tbits>*/
    uint8_t uiInter_byte_space;/*<Inter-Byte Space Select
                            0 0: 0 Tbit, 0 1: 1 Tbit,1 0: 2 Tbits,1 1: 3 Tbits>*/
    uint8_t uiResp_space; /*<Inter-Byte Space (Header)/Response Space Select
                            0 0 0: 0 Tbit
                            0 0 1: 1 Tbit
                            0 1 0: 2 Tbits
                            0 1 1: 3 Tbits
                            1 0 0: 4 Tbits
                            1 0 1: 5 Tbits
                            1 1 0: 6 Tbits
                            1 1 1: 7 Tbits>*/
    uint8_t uiWu_tx_ll_width;//Wake-up Transmission Low Level Width
};

struct uiLin2InitStruct {
    uint8_t uiLinm;//Channel Name(RLIN20,RLIN21,RLIN22, … …, RLIN29)
    uint16_t uiBaudrate;//lin2 baudrate 1- 20K
    struct uiLin2Config uiLin2Config;
    uint8_t uiInt_en_mask;//LIN Interrupt Enable mask
    uint8_t err_en_mask;//LIN Error Detection Enable mask
};

/****************************TEST AREA*****************************************/
void lin2_init(void);
void lin2_master_excute(void);


void lin_test_excute(void);
#endif //LIN_H
