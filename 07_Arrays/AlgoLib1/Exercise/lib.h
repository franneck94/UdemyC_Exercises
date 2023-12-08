#ifndef LIB_H
#define LIB_H

#include <stdbool.h>
#include <stdint.h>

bool all_of(int32_t *array, size_t length, int32_t value);

bool any_of(int32_t *array, size_t length, int32_t value);

bool none_of(int32_t *array, size_t length, int32_t value);

size_t count(int32_t *array, size_t length, int32_t value);

#endif
