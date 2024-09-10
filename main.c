#include <stdint.h>
#include <stdio.h>
#include "gf16.h"
#include "gf16_init.h"

#define GF16_MOD 0x13  // The irreducible polynomial x^4 + x + 1 in binary form (0b10011)

// Perform GF(16) addition (same as XOR for binary fields)
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
        b >>= 1;  // Shift b right
        a <<= 1;  // Multiply a by x
        if (a & 0x10) {  // If degree exceeds 3, reduce modulo GF16_MOD
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

// Test GF(16) multiplication and inversion on the fly
void test_gf16_operations() {
    uint8_t a = 7, b = 3;  // Example values
    uint8_t result_mult = gf16_multiply(a, b);
    uint8_t result_inv = gf16_inverse(a);
    uint8_t result_add = gf16_add(a, b);

    printf("GF(16) multiplication of %d and %d: %d\n", a, b, result_mult);
    printf("GF(16) inversion of %d: %d\n", a, result_inv);
    printf("GF(16) addition of %d and %d: %d\n", a, b, result_add);
}

void test_gf6_op_old(){
    uint8_t a = 7, b = 3;  // Example values
    uint8_t result_mult = gf16_get_mul(a, b);
    uint8_t result_inv = inv(a);
    uint8_t result_add = gf16_get_add(a, b);

    printf("GF(16) multiplication of %d and %d: %d\n", a, b, result_mult);
    printf("GF(16) inversion of %d: %d\n", a, result_inv);
    printf("GF(16) addition of %d and %d: %d\n", a, b, result_add);
}

int main(){

    test_gf16_operations();
    init_gf16_tables();
    test_gf6_op_old();

    return 0;
}