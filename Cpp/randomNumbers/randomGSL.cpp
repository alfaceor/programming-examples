#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
//#define   MODULUS     4294967296 
#define   MODULUS     4294967295 

using namespace std;
int main(int argc, char* argv[]) {
  int N = 1000000000;
  int Npossibilities = 12;
  double rnd=0;
  int stp=0;
  double pBB=0.7;
  int maxnumber = MODULUS;
  double    aux = pBB*MODULUS;
  long int intpBB = (long int) ceil(aux) ;
  printf("pBB = %g, MODULUS = %d, maxnumber=%ld, aux=%g,  intpBB= %d\n", pBB, MODULUS, maxnumber, aux, intpBB);

  const gsl_rng_type * T;
  gsl_rng *r;
  T = gsl_rng_default;
  r = gsl_rng_alloc(T);
    // fprintf(ofile, "%lu \n",  gsl_rng_uniform_int (r, Npossibilities));

  //  FILE *ofile = fopen("randomCongruential.dat", "w");
  int countA     = 0;
  int countB     = 0;
  int countTotal = 0;
  for (int i =0; i< N; i++){
    // rnd =  ( (MULTIPLIER*rnd + INCREMENT) % MODULUS );
    rnd = gsl_rng_uniform(r);
    if (rnd < pBB){
      countA++;
      countTotal++;
    } else {
      countB++;
      countTotal++;
    }
    //fprintf(ofile, "%u \n",  rnd);
  }

  printf("A = %d, B = %d, Total = %d", countA, countB, countTotal);
  //  fclose(ofile);
  return 0;
}
