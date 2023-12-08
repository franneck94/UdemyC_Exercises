# Exercise

In this exercise we will implement the following computations as recusrsive functions:

- sum of the numbers between (lower_value, upper_value)
- product of the numbers between (lower_value, upper_value)

E.g.

recursive_sum(1, 10) => 45  
recursive_product(1, 10) => 3628800  

## Main Function

```cpp
int main()
{
    uint32_t lower_value = 3;
    uint32_t upper_value = 5;

    printf("recursive_sum: %u\n", recursive_sum(lower_value, upper_value));
    printf("recursive_product: %u\n",
           recursive_product(lower_value, upper_value));

    tests();

    return 0;
}
```
