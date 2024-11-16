#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "lib.h"
#include "utils.h"

void test_cases();

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

    test_cases(); // This should not fail

    return 0;
}

void test_cases()
{
    size_t length = 6;
    int32_t array[] = {1, 1, 2, 3, 3, 4};
    int32_t array_cpy[] = {1, 1, 2, 3, 3, 4};
    int32_t array_del[] = {1, 2, 3, 4};

    rotate_left(array_cpy, length);
    assert(ranges_are_same(array, array_cpy, length) == false);
    rotate_right(array_cpy, length);
    assert(ranges_are_same(array, array_cpy, length) == true);

    remove_duplicates(array_cpy, &length);
    assert(ranges_are_same(array_cpy, array_del, length) == true);
    assert(ranges_are_same(array, array_del, length) == false);

    size_t length2 = 7;
    int32_t array2[] = {1, 1, 1, 2, 3, 3, 4};
    int32_t array_cpy2[] = {1, 1, 1, 2, 3, 3, 4};
    int32_t array_del2[] = {1, 2, 3, 4};

    rotate_left(array_cpy2, length);
    assert(ranges_are_same(array2, array_cpy2, length2) == false);
    rotate_right(array_cpy2, length);
    assert(ranges_are_same(array2, array_cpy2, length2) == true);

    remove_duplicates(array_cpy2, &length2);
    assert(ranges_are_same(array_cpy2, array_del2, length2) == true);
    assert(ranges_are_same(array2, array_del2, length2) == false);
}
