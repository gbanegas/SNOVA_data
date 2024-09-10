//
// Created by obiwan on 09/09/24.
//

#ifndef SNOVA_MUL_GF16_MODIFIED_H
#define SNOVA_MUL_GF16_MODIFIED_H
#include "gf16_init.h"  // Include the header with the on-the-fly GF16 functions

// Use the on-the-fly multiplication function
#define gf16_get_mul(a, b) (gf16_multiply((a), (b)))

// Use the on-the-fly inversion function
#define inv(gf16) (gf16_inverse((gf16)))

// GF(16) addition is XOR
#define gf16_get_add(a, b) ((a) ^ (b))

typedef uint8_t gf16_t;


#endif //SNOVA_MUL_GF16_MODIFIED_H
