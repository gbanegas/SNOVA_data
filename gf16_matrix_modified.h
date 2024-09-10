
#ifndef GF16M_H
#define GF16M_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "gf16_init.h"  // Use the new on-the-fly GF16 functions

// Matrix element access based on rank (for GF16)
#if RANK == 2
#define get_gf16m(gf16m, x, y) (gf16m[(((x) << 1) ^ (y))])
#define set_gf16m(gf16m, x, y, value) (gf16m[(((x) << 1) ^ (y))] = value)
#elif RANK == 3
#define get_gf16m(gf16m, x, y) (gf16m[(((x)*3) + (y))])
#define set_gf16m(gf16m, x, y, value) (gf16m[(((x)*3) + (y))] = value)
#elif RANK == 4
#define get_gf16m(gf16m, x, y) (gf16m[(((x) << 2) ^ (y))])
#define set_gf16m(gf16m, x, y, value) (gf16m[(((x) << 2) ^ (y))] = value)
#endif

typedef gf16_t gf16m_t[RANK_SQ];

#endif
