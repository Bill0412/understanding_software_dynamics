// Sample mystery program to measure how long an add takes. Flawed.
// Copyright 2021 Richard L. Sites

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "../book_files/timecounters.h"

static const int kIterations = 1000 * 1000000;

int main(int argc, const char **argv)
{
    int64_t a = 0x1234567890abcdef;
    int64_t b = 0x0fedcba987654321;
    volatile int64_t c;

    int64_t startcy = GetCycles();
    for (int i = 0; i < kIterations; ++i)
    {
        c = a + b;
    }
    int64_t elapsed = GetCycles() - startcy;

    double felapsed = elapsed;
    fprintf(stdout, "%d iterations, %lu cycles, %4.2f cycles/iteration\n",
            kIterations, elapsed, felapsed / kIterations);
    return 0;
}
