#ifndef LIB_H
#define LIB_H

#include <stdint.h>

void clamp_value(float *value, float min_value, float max_value);

void round_value(float *value, uint8_t num_digits);

#endif
