#include "../include/core_utils.h"
#include <cassert>
#include <stdint.h>
#include <iostream>

int main() {
	int32_t a = 0b11111101010100000011110000010101;
	int8_t b[16] = {1, -2, 3, 4, -5, 6, 7, -8, 9, 10, -11, 12, 13, 14, -15, 16};
	int8_t r;
	inner_product_bitwise(&r, &a, b);
	assert(r == 19);

}
