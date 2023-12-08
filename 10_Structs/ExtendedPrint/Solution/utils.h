#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

void print_int8_array(const int8_t *array, const size_t length);

void print_int32_array(const int32_t *array, const size_t length);

void print_uint8_array(const uint8_t *array, const size_t length);

void print_uint32_array(const uint32_t *array, const size_t length);

void print_float_array(const float *array, const size_t length);

void print_double_array(const double *array, const size_t length);

void clear_console();

void sleep_console(int ms);

#endif /* UTILS_H */
