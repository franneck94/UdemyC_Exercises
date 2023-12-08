# Exercise

In this exercise, you have to use the datatypes **double** and **int** for certain computations.

## Calculate Pi

With the following formula, you can compute $\frac{\pi}{4}$.  
Implement the formula in the function with $n$ = **num_iterations**.  
Use a for-loop to sum up the values.

$x = \frac{\pi}{4} = \sum_{k=0}^n \frac{1}{(4k + 1)} - \frac{1}{(4k + 3)}$

At the end multiply by 4 before you return the value.  
So the returned value will be an approximation of $\pi$ and not $\frac{\pi}{4}$.

Implement this formula with a user-defined number of iterations.

## Decimal to Binary

Implement the logic that prints out the binary representation of a positive decimal number.

E.g. the decimal number 142 would be 10001110 in binary.

If you do not know how the binary system works, refer to the Wikipedia [link](https://en.wikipedia.org/wiki/Binary_number).  
Since this knowledge is not only important for this exercise but in general for a programmer.

### Hint

To compute $2^i$ you can use:

```cpp
#include <math.h>

pow(2, i)
```

## Main Function

```cpp
int main()
{
    // calculate_pi
    uint32_t num_iterations = 1000000;
    double pi_calculated = 0.0;

    double pi = 3.14159265358979323846;
    printf("pi (calculated): %lf\n", pi_calculated);
    printf("pi (correct): %lf\n", pi);

    // print_dec_to_bin
    uint8_t dec = 142;

    return 0;
}
```
