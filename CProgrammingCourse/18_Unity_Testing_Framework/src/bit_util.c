#include "bit_util.h"

unsigned char mask_bits(unsigned char val, unsigned char mask) {
    return val & mask;
}

unsigned char set_bits(unsigned char val, unsigned char mask) {
    return val | mask;
}