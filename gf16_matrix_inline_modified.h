
#ifndef GF16M_INLINE_H
#define GF16M_INLINE_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "gf16_init.h"  // Use the new on-the-fly GF16 functions

// Matrix operations are now based on on-the-fly GF16 arithmetic

// Perform matrix element-wise multiplication and addition in GF16
#define POD(entry, a, b, c, d, e, f, g, h, i, j)                          \
    gf16_multiply(                                                        \
        get_gf16m(entry, a, b),                                           \
        gf16_add(                                                         \
            gf16_multiply(get_gf16m(entry, c, d), get_gf16m(entry, e, f)),\
            gf16_multiply(get_gf16m(entry, g, h), get_gf16m(entry, i, j)) \
        )                                                                 \
    )

#ifdef __cplusplus
extern "C" {
#endif

// Zeroing the GF16 Matrix a
static inline void gf16m_set_zero(gf16m_t a) {
    memset(a, 0, RANK_SQ);
}

// Adding GF16 Matrices. c = a + b
static inline void gf16m_add(gf16m_t a, gf16m_t b, gf16m_t c) {
    for (int i = 0; i < RANK_SQ; i++) {
        c[i] = gf16_add(a[i], b[i]);
    }
}

// Invertibility by adding a scalar
static inline void be_invertible_by_add_aS(gf16m_t source) {
    gf16m_t temp;
    if (gf16m_det(source) == 0) {
        for (uint8_t a = 1; a < 16; ++a) {
            be_aS(temp, a);
            gf16m_add(temp, source, source);
            if (gf16m_det(source) != 0) {
                return;
            }
        }
    }
}

#ifdef __cplusplus
}
#endif

#endif
