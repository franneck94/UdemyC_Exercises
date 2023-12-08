#include <stdint.h>

#include "lib.h"

void clamp_value(float *value, float min_value, float max_value)
{
    if (*value < min_value)
    {
        *value = min_value;
    }
    else if (*value > max_value)
    {
        *value = max_value;
    }
}

void round_value(float *value, uint8_t num_digits)
{
    float multiplier = 1.0f;

    for (uint8_t i = 0; i < num_digits; i++)
    {
        multiplier *= 10.0f;
    }

    uint32_t temp = (uint32_t)((*value) * multiplier);

    *value = (float)(temp) / multiplier;
}
