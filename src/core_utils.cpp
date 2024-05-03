#include "core_utils.h"
#include <stdint.h>
#include <iostream>
#include <stdio.h>

void inner_product_bitwise_inplace(int8_t* r, int32_t a, int8_t* b) {

    *r = 0;
    int prod;
    for(int i = 0; i < 16; ++i){
        prod = (a & 3) == 0 ? 0 : ((a & 3) == 1 ? 1 : -1);
        *r += b[15 - i] * prod;
        a = a >> 2;
    }

    return;
}

int8_t inner_product_bitwise(int32_t a, int8_t* b){
    int8_t r = 0;
    inner_product_bitwise_inplace(&r, a, b);
    return r;
}


void matrix_vector_bitwise(int8_t* r, int32_t* W, int8_t* x, int heigth, int width){

    int entries = width / 16;

    for(int i = 0; i < heigth; ++i){
        r[i] = 0;
    }

    for(int i = 0; i < heigth; ++i){
        for(int j = 0; j < entries; ++j){
            r[i] += inner_product_bitwise(W[j + i * entries], &x[j * 16]);
        }
    }

    return;
}
