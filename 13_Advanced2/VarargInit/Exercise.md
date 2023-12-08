# Exercise

Implement a variadic function for our Vector and Matrix library:

- setVectorValues
  - Input Parameters
    - The vector
    - The number of elements to set
    - The values to set (variadic)
- setMatrixValues
  - Input Parameters
    - The matrix
    - The number of elements to set
    - The values to set (variadic)

Note:

Check inside the function if the number of elements to set is larger than the number of elements of the vetor/matrix.  
In general, you can use the vararg summation code from the main course as a starting point.  
Dont forget to include
```cpp
#include <stdarg.h>
```

## Main Function

```cpp
int main()
{
    Vector *v1 = createVector(5, 0.0f);
    setVectorValues(v1, 5, 1.0, 2.0, 3.0, 4.0, 5.0);
    printVector(v1);

    Matrix *m1 = createMatrix(2, 3, 0.0f);
    setMatrixValues(m1, 6, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
    printMatrix(m1);

    freeVector(v1);
    freeMatrix(m1);

    return 0;
}
```
