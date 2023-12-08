#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "lib.h"

bool string_starts_with(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
    {
        return false;
    }

    while (*substr != '\0')
    {
        if ((*string == '\0') || (*string != *substr))
        {
            return false;
        }

        string++;
        substr++;
    }

    return true;
}

bool string_ends_with(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
    {
        return false;
    }

    size_t substr_length = strlen(substr);
    size_t string_length = strlen(string);

    size_t offset_idx = string_length - substr_length;

    string += offset_idx;

    int comparison = strncmp(string, substr, substr_length);

    return (comparison == 0);
}

char *string_find_first_not_of(char *string, char *substr)
{
    if (string == NULL || substr == NULL)
    {
        return NULL;
    }

    while (*string != '\0')
    {
        if (*string != *substr)
        {
            return string;
        }

        string++;
        substr++;
    }

    return NULL;
}

char *string_n_copy(char *dest, char *src, size_t count)
{
    if (dest == NULL || src == NULL || count == 0)
    {
        return NULL;
    }

    char *result = NULL;

    while (*src != '\0')
    {
        *dest = *src;
    }

    return result;
}
