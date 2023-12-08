#include <stdio.h>

int main()
{
    float x = -2.0f;
    float y = -3.0f;

    // 1.)
    float z1 = (x * x) + (y * y) - (x * y) + 2.0f;
    printf("z1 = %f\n", z1);

    // 2.)
    float z2 = (x - y) * (x - y) * (x - y) - 3.0f;
    printf("z2 = %f\n", z2);

    // 3.)
    float numerator = 2.0f * (x * x * x) - 0.5f * (x * x) - x + 4.0f;
    float z3 = numerator / y;
    printf("z3 = %f\n", z3);

    return 0;
}
