#include <stdio.h>
#include <stdlib.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967296 

// #include <gsl/gsl_math.h>
// #include <gsl/gsl_randist.h>
// #include <gsl/gsl_rng.h>

// void generateRandomNumber(gsl_rng *r, double sigma){
// 	double randomaux;
// 	randomaux	= gsl_ran_gaussian(r,sigma);
// 	printf("%f\n",randomaux);
// }

int main(int argc, char* argv[]) {
  unsigned int rnd = 12345 ;
  int Nsteps = 10;
  printf("%u \n", 17 % 10);
  printf("%u \n", 22 % 10);
  for (int i =0; i< Nsteps; i++){
    rnd =  ( (MULTIPLIER*rnd + INCREMENT) % MODULUS );
    printf("%u \n", rnd);
  }
  return 0;
}
