# Exercise

Add const pointer to the code wherever it is appropriate.

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
