#include <stdint.h>
#include <stdio.h>

int main()
{
    uint32_t number = 0;

    printf("Please enter a unsinged integer: ");
    scanf("%u", &number);

    // sum_of_digits
    uint32_t num_digits = 0;

    printf("sum_of_digits: %u\n", num_digits);

    // cross_sum
    uint32_t cross_sum = 0;

    printf("cross_sum: %d\n", cross_sum);
}
