#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "lib.h"

void test_cases();

int main()
{
    char text[50] = "jan schaffranek";

    printf("string_starts_with: %d\n", string_starts_with(text, "jan"));
    printf("string_ends_with: %d\n", string_ends_with(text, "anek"));

    printf("string_starts_with: %d\n", string_starts_with(text, "an"));
    printf("string_ends_with: %d\n", string_ends_with(text, "and"));

    printf("string_find_first_not_of: %s\n",
           string_find_first_not_of(text, "jan "));
    printf("string_find_first_not_of: %s\n",
           string_find_first_not_of(text, "an "));

    test_cases();

    return 0;
}

void test_cases()
{
    assert(string_ends_with("anna", "a") == true);
    assert(string_ends_with("anna", "na") == true);
    assert(string_ends_with("anna", "ann") == false);

    assert(string_starts_with("anna", "a") == true);
    assert(string_starts_with("anna", "na") == false);
    assert(string_starts_with("anna", "ann") == true);
}
