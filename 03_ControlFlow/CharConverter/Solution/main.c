#include <stdbool.h>
#include <stdio.h>

int main()
{
    char character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    // is numeric
    bool is_numeric = false;

    if ((character >= '0') && (character <= '9'))
    {
        is_numeric = true;
    }

    printf("is numeric: %d\n", is_numeric);

    // is upper case
    bool is_upper_case = false;

    if ((character >= 'A') && (character <= 'Z'))
    {
        is_upper_case = true;
    }

    printf("is upper case: %d\n", is_upper_case);

    // is lower case
    bool is_lower_case = false;

    if ((character >= 'a') && (character <= 'z'))
    {
        is_lower_case = true;
    }

    printf("is lower case: %d\n", is_lower_case);

    // is alpha
    bool is_alpha = false;

    if (is_upper_case || is_lower_case)
    {
        is_alpha = true;
    }

    printf("is alpha: %d\n", is_alpha);

    // is alpha numeric
    bool is_alpha_numeric = false;

    if (is_alpha || is_numeric)
    {
        is_alpha_numeric = true;
    }

    printf("is alpha numeric: %d\n", is_alpha_numeric);

    // to upper case
    char upper_case_character = character;

    if (is_lower_case)
    {
        upper_case_character = character - 32;
    }

    printf("to upper case: %c\n", upper_case_character);

    // to lower case
    char lower_case_character = character;

    if (is_upper_case)
    {
        lower_case_character = character + 32;
    }

    printf("to lower case: %c\n", lower_case_character);

    return 0;
}
