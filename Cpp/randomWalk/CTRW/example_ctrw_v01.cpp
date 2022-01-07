#include <stdio.h>
#include <stdlib.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967295 //4294967296 

int main(){
  const int Nsteps = 1000000;
  unsigned int rndint = 0;
  double rndfloat = 0.0;
  double x = 0.0;
  for (int ns = 0; ns < Nsteps; ns++){
    rndint   =  ( (MULTIPLIER*rndint + INCREMENT) % MODULUS );
    rndfloat = ((float)rndint)/MODULUS;
    //printf("%u\t%f\n",rndint, rndfloat);
    x = x + rndfloat;
    printf("%d %f\n", ns, x);
  }
  return EXIT_SUCCESS;
}
