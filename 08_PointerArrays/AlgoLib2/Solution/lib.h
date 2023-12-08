#ifndef LIB_H
#define LIB_H

#include <stdint.h>

void iota(int32_t *array, size_t length, int32_t start_value);

int32_t *inclusive_scan(int32_t *array, size_t length);

#endif
