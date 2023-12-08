#ifndef LIB_H
#define LIB_H

#include <stdbool.h>
#include <stdint.h>

bool string_starts_with(char *string, char *substr);

bool string_ends_with(char *string, char *substr);

char *string_find_first_not_of(char *string, char *substr);

char *string_n_copy(char *dest, char *src, size_t count);

#endif
