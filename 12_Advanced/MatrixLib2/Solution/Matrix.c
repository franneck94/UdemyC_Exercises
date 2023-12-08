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

Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value)
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
    return ((matrix1->num_rows == matrix2->num_rows) && (matrix1->num_cols == matrix2->num_cols));
}

bool matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2)
{
    return (matrix1->num_cols == matrix2->num_rows);
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

        const size_t idx = matrixIndex(matrix->num_cols, i, matrix->num_cols - 1);

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

/**********************/
/*  MATH FUNCTIONS    */
/**********************/

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
    if (matrix1 == NULL || matrix2 == NULL || !matrixSameSize(matrix1, matrix2))
    {
        return NULL;
    }

    Matrix *result = createMatrix(matrix1->num_rows, matrix1->num_cols, 0.0f);

    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < matrix1->num_rows; i++)
    {
        for (size_t j = 0; j < matrix1->num_cols; j++)
        {
            const size_t idx = matrixIndex(matrix1->num_cols, i, j);

            result->data[idx] = matrix1->data[idx] + matrix2->data[idx];
        }
    }

    return result;
}

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
    if (matrix1 == NULL || matrix2 == NULL || !matrixSameSize(matrix1, matrix2))
    {
        return NULL;
    }

    Matrix *result = createMatrix(matrix1->num_rows, matrix1->num_cols, 0.0f);

    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < matrix1->num_rows; i++)
    {
        for (size_t j = 0; j < matrix1->num_cols; j++)
        {
            const size_t idx = matrixIndex(matrix1->num_cols, i, j);

            result->data[idx] = matrix1->data[idx] - matrix2->data[idx];
        }
    }

    return result;
}

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
    if (matrix1 == NULL || matrix2 == NULL || !matrixMultiplyPossible(matrix1, matrix2))
    {
        return NULL;
    }

    Matrix *result = createMatrix(matrix1->num_rows, matrix2->num_cols, 0.0f);

    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < matrix1->num_rows; i++)
    {
        for (size_t j = 0; j < matrix2->num_cols; j++)
        {
            const size_t index_ij = matrixIndex(matrix2->num_cols, i, j);
            result->data[index_ij] = 0.0f;

            for (size_t k = 0; k < matrix2->num_rows; k++)
            {
                const size_t index_ik = matrixIndex(matrix2->num_rows, i, k);
                const size_t index_kj = matrixIndex(matrix2->num_cols, k, j);

                result->data[index_ij] =
                    result->data[index_ij] + matrix1->data[index_ik] * matrix2->data[index_kj];
            }
        }
    }

    return result;
}

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar)
{
    if (matrix == NULL)
    {
        return NULL;
    }

    Matrix *result = createMatrix(matrix->num_rows, matrix->num_cols, 0.0f);

    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            const size_t idx = matrixIndex(matrix->num_cols, i, j);

            result->data[idx] = matrix->data[idx] * scalar;
        }
    }

    return result;
}

Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar)
{
    if (matrix == NULL || scalar == 0.0f)
    {
        return NULL;
    }

    Matrix *result = createMatrix(matrix->num_rows, matrix->num_cols, 0.0f);

    if (result == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < matrix->num_rows; i++)
    {
        for (size_t j = 0; j < matrix->num_cols; j++)
        {
            const size_t idx = matrixIndex(matrix->num_cols, i, j);

            result->data[idx] = matrix->data[idx] / scalar;
        }
    }

    return result;
}
