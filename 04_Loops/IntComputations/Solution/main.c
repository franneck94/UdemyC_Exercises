#include <stdint.h>
#include <stdio.h>

int main()
{
    uint32_t number = 0;

    printf("Please enter a unsigned integer: ");
    scanf("%u", &number);

    // sum_of_digits
    uint32_t num_digits = 0;

    uint32_t temp1 = number;

    while (temp1 > 0)
    {
        temp1 /= 10;
        num_digits++;
    }

    printf("sum_of_digits: %u\n", num_digits);

    // cross_sum
    uint32_t cross_sum = 0;

    uint32_t temp2 = number;

    while (temp2 > 0)
    {
        cross_sum += temp2 % 10;

        temp2 /= 10;
    }

    printf("cross_sum: %d\n", cross_sum);
}
