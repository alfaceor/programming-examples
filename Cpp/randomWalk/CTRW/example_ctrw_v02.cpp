#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967295 //4294967296 


int main(){
  const int Nsteps = 10000000;
  unsigned int rndint = 0;
  double rndfloat = 0.0;
  double x = 0.0;
  const gsl_rng_type *T;
  gsl_rng *r;
  T = gsl_rng_default;
  r = gsl_rng_alloc(T);
  for (int ns = 0; ns < Nsteps; ns++){
    // rndint   =  ( (MULTIPLIER*rndint + INCREMENT) % MODULUS );
    // rndfloat = ((float)rndint)/MODULUS;
    // printf("%u\t%f\n",rndint, rndfloat);
    rndfloat = gsl_ran_gaussian(r, 1);
    x = x + rndfloat;
    if ( ns % 100 == 0)
      printf("%d %f %f\n", ns, x, rndfloat);
  }
  return EXIT_SUCCESS;
}
