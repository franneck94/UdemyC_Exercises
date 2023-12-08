# Exercise

In this exercise, you have to use the datatype **char** to convert/check certain char values.

Implement the following checks:

- is numeric character
- is alpha character
- is alpha numeric character
- is upper case character
- is lower case character

Meaning of the function names:

- Numeric: 0-9 (digits)
- Alpha: a-z, A-Z (alphabeth characters)
- Upper Case: A-Z
- Lower Case: a-z

Note:

The shift from **Upper Case** to **Lower Case** is 32 in the ASCII table.  

E.g. 'A' -> 'a' by adding 32  
E.g. 'a' -> 'A' by subtracting 32  

You do not have to look up the ASCII table for this exercise, but you can do so.

Afterward, implement the following conversion:

- to upper case character
- to lower case character

## Main Function

```cpp
int main()
{
    char character;

    printf("Please enter any ASCII character: ");
    scanf("%c", &character);

    // is numeric

    // is upper case

    // is lower case

    // is alpha

    // is alpha numeric

    // to upper case

    // to lower case

    return 0;
}
```
