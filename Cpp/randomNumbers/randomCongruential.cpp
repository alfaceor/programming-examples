#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
//#define   MODULUS     4294967296 
#define   MODULUS     4294967295 

using namespace std;
int main(int argc, char* argv[]) {
  int N = 1000000000;
  int Npossibilities = 12;
  int rnd = 12345 ;
  int stp=0;
  double pBB=0.7;
  int maxnumber = MODULUS;
  double    aux = pBB*MODULUS;
  long int intpBB = (long int) ceil(aux) ;
  printf("pBB = %g, MODULUS = %d, maxnumber=%ld, aux=%g,  intpBB= %d\n", pBB, MODULUS, maxnumber, aux, intpBB);

  //  FILE *ofile = fopen("randomCongruential.dat", "w");
  int countA     = 0;
  int countB     = 0;
  int countTotal = 0;
  for (int i =0; i< N; i++){
    rnd =  ( (MULTIPLIER*rnd + INCREMENT) % MODULUS );
    if (rnd < intpBB){
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
