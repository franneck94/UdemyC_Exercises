#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Matrix.h"
#include "Timer.h"
#include "Vector.h"

int main()
{
    Matrix *m1 = createMatrix(500, 500, +1.0f);
    Matrix *m2 = createMatrix(500, 500, -1.0f);

    double total_time = 0.0;
    uint32_t num_runs = 100;

    for (uint32_t run_idx = 0; run_idx < num_runs; run_idx++)
    {
        const clock_t time_start = clock();
        Matrix *m3 = multiplyMatrix(m1, m2);
        const clock_t time_end = clock();

        total_time += get_timing_milliseconds(&time_start, &time_end);
        freeMatrix(m3);
    }

    printf("Mean execution time: %lf ms", total_time / (double)(num_runs));

    freeMatrix(m1);
    freeMatrix(m2);

    return 0;
}
