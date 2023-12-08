#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void print_int8_array(const int8_t *array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("%d\n", array[length - 1]);
}

void print_int32_array(const int32_t *array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%d, ", array[i]);
    }

    printf("%d\n", array[length - 1]);
}

void print_uint8_array(const uint8_t *array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%u, ", array[i]);
    }

    printf("%u\n", array[length - 1]);
}

void print_uint32_array(const uint32_t *array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%u, ", array[i]);
    }

    printf("%u\n", array[length - 1]);
}

void print_float_array(const float *array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%f, ", array[i]);
    }

    printf("%f\n", array[length - 1]);
}

void print_double_array(const double *array, const size_t length)
{
    for (size_t i = 0; i < length - 1; i++)
    {
        printf("%lf, ", array[i]);
    }

    printf("%lf\n", array[length - 1]);
}

void clear_console()
{
#if defined _WIN32
    system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    (void)system("clear");
#elif defined(__APPLE__)
    (void)system("clear");
#else
    (void)system("clear");
#endif
}

void sleep_console(int ms)
{
#ifdef _WIN32
    Sleep((DWORD)(ms));
#else
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
#endif
    usleep(ms * 1000);
#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#endif
}

#endif /* UTILS_H */
