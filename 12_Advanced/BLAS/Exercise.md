# Exercise

Implement the following functions for our **vector**:

```cpp
float vectorEuclidNorm(const Vector *vector);
```

- vectorEuclidNorm
  - Example for 2d vector: $\vec{v} = \begin{pmatrix}x \\ y\end{pmatrix} = \sqrt{x^2 + y^2}$
  - Generalized formula: $\vec{v} = \begin{pmatrix}x_1 \\ \vdots \\ x_n\end{pmatrix} = \sqrt{\sum_{i = 1}^n x_i^2}$

Implement the following functions for our **matrix**:

```cpp
Matrix *matrixTranspose(const Matrix *matrix);

bool matrixMultiplyByVectorPossible(const Matrix *matrix, const Vector *vector);

Vector *multiplyMatrixByVector(const Matrix *matrix, const Vector *vector);
```

- matrixTranspose
  - Adapt the transpose function from the main course to our matrix data structure
  - Note the index mapping is:
  ```cpp
  result[j][i] = matrix[i][j]
  ```
- multiplyMatrixByVector
  - $\underset{m}{\vec{v_{2}} } =  \underset{m\times n}{M_1} \times 
\underset{n}{\vec{v_{1}}}$
  - More information: [see here](https://mathinsight.org/matrix_vector_multiplication)

## Main Function

```cpp
int main()
{
    Matrix *m1 = createMatrix(2, 3, -1.0f);
    m1->data[0] = 1;
    m1->data[1] = 2;
    m1->data[2] = 3;
    m1->data[3] = 4;
    m1->data[4] = 5;
    m1->data[5] = 6;
    printf("M1:\n");
    printMatrix(m1);

    Vector *v1 = createVector(3, 2.0f);
    v1->data[0] = 1;
    v1->data[1] = 2;
    v1->data[2] = 3;
    printf("v1:\n");
    printVector(v1);

    float v1_norm = vectorEuclidNorm(v1);
    printf("v1_norm: %f\n", v1_norm);

    Matrix *m2 = matrixTranspose(m1);
    printf("M_T:\n");
    printMatrix(m2);

    Vector *v2 = multiplyMatrixByVector(m1, v1);
    printf("M1 * v1 = \n");
    printVector(v2);

    freeMatrix(m1);
    freeMatrix(m2);
    freeVector(v1);
    freeVector(v2);

    return 0;
}
```
