# Exercise

Implement the following functions:

```cpp
void unique_elements(int32_t *array, size_t length);

void remove_duplicates(int32_t *array, size_t *length);

void rotate_left(int32_t *array, size_t length);

void rotate_right(int32_t *array, size_t length);
```

- Unique Elements
  - Print out all unique elements (no duplicates) in the array
- Remove Duplicates
  - Remove all duplicates in the array
  - By Remove I mean
    - move  the element to the end of the array and decrease the length of the array by one, hence the value is not used anymore
- Rotate Left
  - Rotate all elements of the array to the left
  - Rotate Left: [1, 2, 3] => [2, 3, 1]  
- Rotate Right
  - Rotate all elements of the array to the right
  - Rotate Right: [1, 2, 3] => [3, 1, 2]  

Note: Make sure that the input pointers are valid.

## Main Function

```cpp
int main()
{
    int32_t array[] = {1, 1, 2, 3, 3, 4};
    size_t length = 6;

    printf("unique_elements: \n");
    unique_elements(array, length);

    remove_duplicates(array, &length);
    print_int32_array(array, length);

    rotate_left(array, length);
    print_int32_array(array, length);

    rotate_right(array, length);
    print_int32_array(array, length);

    return 0;
}
```
