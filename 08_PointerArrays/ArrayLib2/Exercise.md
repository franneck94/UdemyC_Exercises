# Exercise

Implement the following functions:

```cpp
bool array_equal(int32_t *array1, size_t length1, int32_t *array2, size_t length2);

void array_clamp(int32_t *array, size_t length, int32_t min_value, int32_t max_value);

void array_reverse(int32_t *array, size_t length);

void array_fill_n(int32_t *array, size_t length, size_t n, int32_t value);
```

- array_equal
  - Check if two arrays have always the same values
- array_clamp
  - Clamp the values of the array to the range [**min_value**, **max_value**]
- array_reverse
  - Reverse the values of the array inplace (do not create a new array)
- array_fill_n
  - Fill only **n** entries of the array with the **value**

Note: Make sure that the input pointers are valid.

## Main Function

```cpp
int main()
{
    int32_t array1[] = {-3, -2, -1, 0, 1, 2, 3};
    int32_t array2[] = {-3, -2, -1, 0, 1, 2, 4};
    size_t length = 7;

    printf("array_equal: %d\n", array_equal(array1, length, array2, length));

    array_clamp(array1, length, -1, 1);
    print_int32_array(array1, length);

    array_fill_n(array2, length, 5, -1337);
    print_int32_array(array2, length);

    array_reverse(array1, length);
    print_int32_array(array1, length);

    return 0;
}
```
