# Exercise

Implement the following checks from Chapter 3 as functions:

- is numeric character
- is alpha character
- is alpha_numeric character
- is upper case character
- is lower case character

- to upper case character
- to lower case character

Make sure that you reuse as many functions as possible.

## Main Function

```cpp
int main()
{
    char character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    printf("is_numeric: %d\n", is_numeric(character));
    printf("is_alpha: %d\n", is_alpha(character));
    printf("is_alpha_numeric: %d\n", is_alpha_numeric(character));
    printf("is_upper_case: %d\n", is_upper_case(character));
    printf("is_lower_case: %d\n", is_lower_case(character));

    printf("to_upper_case: %c\n", to_upper_case(character));
    printf("to_lower_case: %c\n", to_lower_case(character));

    test_cases(); // These tests should not fail!

    return 0;
}
```
