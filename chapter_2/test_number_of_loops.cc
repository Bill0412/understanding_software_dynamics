// Sample mystery program to measure how long an add takes. Flawed.
// Copyright 2021 Richard L. Sites

#include <stdint.h>
#include <stdio.h>
#include <time.h> // time()
#include "../book_files/timecounters.h"


int main(int argc, const char **argv)
{
  volatile uint64_t sum = 0;

  time_t t = time(NULL); // A number that the compiler does not know
  int incr = t & 255;    // Unknown increment 0..255

  for (int kIterations = 1; kIterations <= 1e9; kIterations *= 10)
  {
    int64_t startcy = GetCycles();
    for (int i = 0; i < kIterations; ++i)
    {
      sum += incr;
    }
    int64_t elapsed = GetCycles() - startcy;
    double felapsed = elapsed;

    fprintf(stdout, "%d iterations, %lu cycles, %4.2f cycles/iteration\n",
            kIterations, elapsed, felapsed / kIterations);
  }

  return 0;
}
