#include "core_utils.h"
#include <stdint.h>
#include <iostream>

void inner_product_bitwise(int8_t* r, int32_t* a, int8_t* b) {

    *r = 0;
    int prod;
    for(int i = 0; i < 16; ++i){
        prod = (*a & 3) == 0 ? 0 : ((*a & 3) == 1 ? 1 : -1);
        *r += b[15 - i] * prod;
        *a = *a >> 2;
    }

    return;


}
