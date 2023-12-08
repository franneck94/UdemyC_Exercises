#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdint.h>

#include "Vector.h"

/**********************/
/* DEFINES AND TYPES  */
/**********************/

typedef enum
{
    AXIS_0,
    AXIS_1,
} Axis;

typedef struct
{
    float *data;
    size_t num_rows;
    size_t num_cols;
} Matrix;

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value);

Matrix *freeMatrix(Matrix *matrix);

void setMatrixValues(Matrix *const matrix, size_t count, ...);

/**********************/
/*  HELPER FUNCTIONS  */
/**********************/

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j);

size_t matrixNumElements(const Matrix *const matrix);

bool matrixSameSize(const Matrix *const matrix1, const Matrix *const matrix2);

bool matrixMultiplyPossible(const Matrix *const matrix1, const Matrix *const matrix2);

bool matrixMultiplyByVectorPossible(const Matrix *const matrix, const Vector *const vector);

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printMatrix(const Matrix *const matrix);

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Matrix *addMatrix(const Matrix *const matrix1, const Matrix *const matrix2);

Matrix *subMatrix(const Matrix *const matrix1, const Matrix *const matrix2);

Matrix *multiplyMatrix(const Matrix *const matrix1, const Matrix *const matrix2);

Matrix *multiplyMatrixByScalar(const Matrix *const matrix, const float scalar);

Matrix *divideMatrixByScalar(const Matrix *const matrix, const float scalar);

Vector *minMatrix(const Matrix *const matrix, const Axis axis);

Vector *maxMatrix(const Matrix *const matrix, const Axis axis);

Vector *meanMatrix(const Matrix *const matrix, const Axis axis);

Matrix *matrixTranspose(const Matrix *const matrix);

Vector *multiplyMatrixByVector(const Matrix *const matrix, const Vector *const vector);

#endif // MATRIX_H
