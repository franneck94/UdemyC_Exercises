# Exercise

In this exercise, you have to implement the following time computations:

- clamp_value
  - **value** as an in- and output parameter
  - **min_value** and **max_valuie** as the value range
  - the function will check whether:
    - The **value** is below **min_value**
      - If true: set to **min_value**
    - The **value** is above **max_valuie**
      - If true: set to **max_valuie**
  - E.g. -2.5 with **min_value** = -2.0 and **max_valuie** = 2.0 => clamp to -2.0
  - E.g. 2.5 with **min_value** = -2.0 and **max_valuie** = 2.0 => clamp to 2.0
- round_value
  - **value** as an in- and output parameter
  - **num_digits** as input parameter that will define to how many digits to round (to be more precise we will cut off the digits)
  - E.g. 1.23456 with 1 digits => 1.20000
  - E.g. 1.23456 with 2 digits => 1.23000
  - E.g. 1.23456 with 3 digits => 1.23400

## Main Function

```cpp
int main()
{
    float value = 2.0f;

    clamp_value(...);
    printf("%f\n", value);

    round_value(...);
    printf("%f\n", value);

    return 0;
}
```
