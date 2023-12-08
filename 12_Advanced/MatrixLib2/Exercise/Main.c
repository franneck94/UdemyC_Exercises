#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
#include "Vector.h"

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
