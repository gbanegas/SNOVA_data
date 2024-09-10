
#include <stdint.h>
#ifndef GF16_INIT_H
#define GF16_INIT_H
#include "gf16.h"

// GF(16) irreducible polynomial: x^4 + x + 1
#define GF16_MOD 0x13

// Perform GF(16) addition (XOR for binary fields)
uint8_t gf16_add(uint8_t a, uint8_t b) {
    return a ^ b;
}

// Perform GF(16) multiplication on the fly
uint8_t gf16_multiply(uint8_t a, uint8_t b) {
    uint8_t result = 0;
    while (b) {
        if (b & 1) {
            result ^= a;  // Add (XOR) the current a to the result
        }
        b >>= 1;
        a <<= 1;
        if (a & 0x10) {  // Reduce modulo GF16_MOD if degree exceeds 3
            a ^= GF16_MOD;
        }
    }
    return result;
}

// Perform GF(16) inversion using the Extended Euclidean Algorithm
uint8_t gf16_inverse(uint8_t a) {
    if (a == 0) return 0;  // Inversion of 0 is undefined
    uint8_t t0 = 0, t1 = 1, r0 = GF16_MOD, r1 = a;
    while (r1 != 0) {
        uint8_t q = r0 / r1;
        uint8_t r = r0 % r1;
        r0 = r1;
        r1 = r;
        uint8_t temp = t0 ^ gf16_multiply(q, t1);
        t0 = t1;
        t1 = temp;
    }
    return t0;
}

#endif
