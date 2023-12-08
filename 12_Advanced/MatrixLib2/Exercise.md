# Exercise

Implement the following functions for a **matrix** library:

```cpp
bool matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2);

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar);

Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar);
```

- addMatrix
  - Add two matrices, check if the dimensions match with **matrixSameSize**
- subMatrix
  - Subtract two matrices, check if the dimensions match with **matrixSameSize**
- multiplyMatrix
  - Multiply two matrices, check if the dimensions match with **matrixMultiplyPossible**
- multiplyMatrixByScalar
  - Multiply matrix element-wise with a scalar value
  - See how-to on wikipedia: [See at Definition](https://de.wikipedia.org/wiki/Matrizenmultiplikation)
- divideMatrixByScalar
  - Divide matrix element-wise with a scalar value, check for division-by-zero

Hint:
You can use the **vector** library as a starting point!

## Main Function

```cpp
int main()
{
    Matrix *m1 = createMatrix(3, 3, -1.0f);
    Matrix *m2 = createMatrix(3, 3, +1.0f);

    Matrix *m3 = addMatrix(m1, m2);
    printMatrix(m1);
    printf("+\n");
    printMatrix(m2);
    printf("=\n");
    printMatrix(m3);

    Matrix *m4 = subMatrix(m3, m1);
    printMatrix(m3);
    printf("-\n");
    printMatrix(m1);
    printf("=\n");
    printMatrix(m4);

    Matrix *m5 = multiplyMatrix(m1, m2);
    printMatrix(m1);
    printf("*\n");
    printMatrix(m2);
    printf("=\n");
    printMatrix(m5);

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);
    freeMatrix(m4);
    freeMatrix(m5);

    return 0;
}
```
