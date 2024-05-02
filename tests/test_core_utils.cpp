#include "../include/core_utils.h"
#include <cassert>
#include <stdint.h>
#include <iostream>

int main() {
	int32_t a = 0b11111101010100000011110000010101;
	int8_t b[16] = {1, -2, 3, 4, -5, 6, 7, -8, 9, 10, -11, 12, 13, 14, -15, 16};
	int8_t r;
	inner_product_bitwise_inplace(&r, a, b);
	assert(r == 19);
	assert(r == inner_product_bitwise(a, b));


	int32_t W[4] = {0b00011101001100110001000001010101, 0b00011100110000110101000101111100, static_cast<int32_t>(0b11000001111100001101000111111101), 0b01111100010000111111111111000111};

	int8_t x[32] = {  3,  -1,   8,   5,   7,   4,  -4,  -9, -10,   3,   5,  10,  -6,
        -3,  -4,  -9,   6,   3,   6,   2,  -3,   8,  10,  -4,  -3,  -4,
         7,   2,   7,   2,  -1,  10};
	int8_t Wx[2] = {-13, -4};
	int8_t res[2];
	matrix_vector_bitwise(res, W, x, 2, 32);
	assert(res[0] == Wx[0]);
	assert(res[1] == Wx[1]);


}
