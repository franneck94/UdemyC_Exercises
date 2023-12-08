#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "lib.h"

void tests();

int main()
{
    float value = 2.0f;

    clamp_value(&value, -1.34567f, 1.24567f);
    printf("%.16f\n", value);

    round_value(&value, 3);
    printf("%.16f\n", value);

    round_value(&value, 2);
    printf("%.16f\n", value);

    round_value(&value, 1);
    printf("%.16f\n", value);

    tests();

    return 0;
}

void tests()
{
    float value = 2.0f;
    clamp_value(&value, -2.0F, 2.0F);
    assert(value == 2.0F);
    clamp_value(&value, -1.0F, 1.0F);
    assert(value == 1.0F);

    float value2 = 0.0f;
    clamp_value(&value2, -1.0F, 1.0F);
    assert(value2 == 0.0F);

    float value3 = 1.55f;
    round_value(&value3, 1);
    assert(value3 == 1.5F);
}
