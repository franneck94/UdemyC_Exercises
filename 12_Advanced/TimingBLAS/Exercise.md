# Exercise

Create the compilation unit Timer.h/.c

Implement the following functions in Timer.h/.c:

```cpp
double get_timing_milliseconds(const clock_t *time_start, const clock_t *time_end);

double get_timing_microseconds(const clock_t *time_start, const clock_t *time_end);

double get_timing_nanoseconds(const clock_t *time_start, const clock_t *time_end);
```

- get_timing_milliseconds
  - Return the time in milliseconds based on the **time_start** and **time_end** input parameter
- get_timing_microseconds
  - Return the time in microseconds based on the **time_start** and **time_end** input parameter
- get_timing_nanoseconds
  - Return the time in nanoseconds based on the **time_start** and **time_end** input parameter

## Main Function

```cpp
int main()
{
    Matrix *m1 = createMatrix(249, 249, +1.0f);
    Matrix *m2 = createMatrix(249, 249, -1.0f);

    const clock_t time_start = clock();

    Matrix *m3 = multiplyMatrix(m1, m2);

    const clock_t time_end = clock();

    printf("ms: %lf\n", get_timing_milliseconds(&time_start, &time_end));
    printf("us: %lf\n", get_timing_microseconds(&time_start, &time_end));
    printf("ns: %lf\n", get_timing_nanoseconds(&time_start, &time_end));

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);

    return 0;
}
```
