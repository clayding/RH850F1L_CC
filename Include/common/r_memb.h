#ifndef R_MEMB_H
#define R_MEMB_H

//#include "cc.h"
#include "memb.h"

#define R_MEMB(name, structure, num) \
        char CC_CONCAT(name,_memb_count)[num]; \
        structure CC_CONCAT(name,_memb_mem)[num]; \
        struct memb name = {sizeof(structure), num, \
                                     CC_CONCAT(name,_memb_count), \
                                     (void *)CC_CONCAT(name,_memb_mem)} 

#endif //R_MEMB_H