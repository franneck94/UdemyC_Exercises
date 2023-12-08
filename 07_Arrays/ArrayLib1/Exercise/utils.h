#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdint.h>

void print_int8_array(const int8_t *array, const size_t length);

void print_int32_array(const int32_t *array, const size_t length);

void print_uint8_array(const uint8_t *array, const size_t length);

void print_uint32_array(const uint32_t *array, const size_t length);

void print_float_array(const float *array, const size_t length);

void print_double_array(const double *array, const size_t length);

void clear_console();

void sleep_console(int ms);

int32_t ranges_are_same(const int32_t *a, const int32_t *b, const size_t len);

#endif /* UTILS_H */
