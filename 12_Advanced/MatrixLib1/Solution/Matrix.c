#include <float.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

#include "Matrix.h"

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Matrix *createMatrix(const size_t num_rows,
                     const size_t num_cols,
                     const float value)
{
    Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));

    if (matrix == NULL)
    {
        return NULL;
    }

    float *data = (float *)malloc(num_rows * num_cols * sizeof(float));

    if (data == NULL)
    {
        free(matrix);
        return NULL;
    }

    for (size_t i = 0; i < num_cols * num_rows; i++)
    {
        data[i] = value;
    }

    matrix->data = data;
    matrix->num_cols = num_cols;
    matrix->num_rows = num_rows;

    return matrix;
}

Matrix *freeMatrix(Matrix *matrix)
{
    if (matrix == NULL)
    {
        return NULL;
    }

    if (matrix->data != NULL)
    {
        free(matrix->data);
        matrix->data = NULL;
    }

    free(matrix);

    return NULL;
}

/**********************/
/*  HELPER FUNCTIONS  */
/**********************/

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j)
{
    return i * num_cols + j;
}

size_t matrixNumElements(const Matrix *matrix)
{
    return matrix->num_cols * matrix->num_rows;
}

bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2)
{
    return ((matrix1->num_rows == matrix2->num_rows) &&
            (matrix1->num_cols == matrix2->num_cols));
}

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printMatrix(const Matrix *matrix)
{
    printf("[");

    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        if (i == 0)
        {
            printf("[");
        }
        else
        {
            printf(" [");
        }

        for (size_t j = 0; j < matrix->num_cols - 1; j++)
        {
            const size_t idx = matrixIndex(matrix->num_cols, i, j);

            printf("%f, ", matrix->data[idx]);
        }

        const size_t idx =
            matrixIndex(matrix->num_cols, i, matrix->num_cols - 1);

        if (i < (matrix->num_rows - 1))
        {
            printf("%f]\n", matrix->data[idx]);
        }
        else
        {
            printf("%f", matrix->data[idx]);
        }
    }

    printf("]]\n\n");
}
