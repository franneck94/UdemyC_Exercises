#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
#include "Vector.h"

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
