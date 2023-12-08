# Exercise

Implement the following functions:

```cpp
bool string_starts_with(char *string, char *substr);

bool string_ends_with(char *string, char *substr);

char *string_find_first_not_of(char *string, char *substr);

char *string_n_copy(char *dest, char *src, size_t count);
```

- string_starts_with
  - Return true if the **string** starts with **substr**
  - E.g. **string** = "jan schaffranek", **substr** = "jan" => true
  - E.g. **string** = "jan schaffranek", **substr** = "an" => false
- string_ends_with
  - Return true if the **string** ends with **substr**
  - E.g. **string** = "jan schaffranek", **substr** = "anek" => true
  - E.g. **string** = "jan schaffranek", **substr** = "ane" => false
- string_find_first_not_of
  - Return the position of the **string** where the first character after the starting **substr** is
  - E.g. **string** = "jan schaffranek", **substr** = "jan s" => "chaffranek"
  - E.g. **string** = "jan schaffranek", **substr** = "ja" => "n schaffranek"
- string_n_copy
  - Copy the content of **src** to **dest** with a maximal length of **count**

Note: Make sure that the input pointer is valid.

## Main Function

```cpp
int main()
{
    char text[50] = "jan schaffranek";
    char copy[50] = {'\0'};

    printf("string_starts_with: %d\n", string_starts_with(text, "jan"));
    printf("string_ends_with: %d\n", string_ends_with(text, "anek"));

    printf("string_starts_with: %d\n", string_starts_with(text, "an"));
    printf("string_ends_with: %d\n", string_ends_with(text, "ane"));

    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "jan "));
    printf("string_find_first_not_of: %s\n", string_find_first_not_of(text, "an "));

    return 0;
}
```
