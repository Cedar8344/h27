#include "randlib.h"
#include <immintrin.h>

//copy from randall.c

/* Return a random value, using hardware operations.  */

static unsigned long long
hardware_rand64 (void)
{
  unsigned long long int x;
  while (! _rdrand64_step (&x))
    continue;
  return x;
}

//interface from .h
extern unsigned long long rand64 (void)
{
    return hardware_rand64();
}
