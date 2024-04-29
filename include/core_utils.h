#pragma once
#include <stdint.h>

// computes inner product r = a^T * b
// where a is a 32 bit integer which holds 16 2-bit values
// where b is a 16 elements 8 bit array
// where r is a single 8 bit array for the output
void inner_product_bitwise(int8_t* r, int32_t* a, int8_t* b);
