#include <assert.h>
#include <stdint.h>
#include <stdio.h>

#include "lib.h"

void tests();

int main()
{
    uint32_t lower_value = 3;
    uint32_t upper_value = 5;

    printf("sum: %u\n", recursive_sum(lower_value, upper_value));
    printf("product: %u\n", recursive_product(lower_value, upper_value));

    tests();

    return 0;
}

void tests()
{
    assert(recursive_sum(0, 0) == 0);
    assert(recursive_sum(0, 1) == 1);
    assert(recursive_sum(3, 4) == 7);
    assert(recursive_sum(4, 4) == 4);
    assert(recursive_sum(4, 3) == 0);

    assert(recursive_product(0, 0) == 0);
    assert(recursive_product(0, 1) == 0);
    assert(recursive_product(3, 4) == 12);
    assert(recursive_product(4, 4) == 4);
    assert(recursive_product(4, 3) == 0);
    assert(recursive_product(1, 5) == 120);
}
