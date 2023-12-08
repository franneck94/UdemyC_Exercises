#include <math.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    // calculate_pi
    uint32_t num_iterations = 1000000;
    double pi_calculated = 0.0;

    for (uint32_t k = 0; k < num_iterations; k++)
    {
        double fraction1 = 1.0 / (4.0 * k + 1.0);
        double fraction2 = 1.0 / (4.0 * k + 3.0);

        pi_calculated += fraction1 - fraction2;
    }

    pi_calculated *= 4.0;

    double pi = 3.14159265358979323846;
    printf("pi (calculated): %.16lf\n", pi_calculated);
    printf("pi (correct): %.16lf\n", pi);

    // print_dec_to_bin
    uint8_t dec = 142;

    printf("Binary: 0b");
    for (int8_t i = 7; i >= 0; i--)
    {
        uint8_t current_exponent = pow(2, i);

        if (current_exponent <= dec)
        {
            printf("1");

            dec -= current_exponent;
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}
