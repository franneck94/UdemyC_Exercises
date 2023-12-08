#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

/**********************/
/* DEFINES AND TYPES  */
/**********************/
typedef struct Vector
{
    float *data;
    size_t length;
} Vector;

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Vector *createVector(const size_t length, const float value);

Vector *freeVector(Vector *vector);

void setVectorValues(Vector *const vector, size_t count, ...);

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printVector(const Vector *const vector);

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Vector *addVector(const Vector *const vec1, const Vector *const vec2);

Vector *subVector(const Vector *const vec1, const Vector *const vec2);

float multiplyVector(const Vector *const vec1, const Vector *const vec2);

Vector *multiplyScalar(const Vector *const vec, const float scalar);

Vector *divideScalar(const Vector *const vec, const float scalar);

float meanVector(const Vector *const vector);

float minVector(const Vector *const vector);

float maxVector(const Vector *const vector);

float vectorEuclidNorm(const Vector *const vector);

#endif // VECTOR_H
