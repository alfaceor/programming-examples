#include <stdio.h>
#include <stdlib.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967296 

int main(int argc, char* argv[]) {
  int N = 100000000;
  int Npossibilities = 12;
  unsigned int rnd = 12345 ;
  FILE *ofile = fopen("randomIntegerFabio.dat", "w");
  unsigned int stp=0;
  for (int i =0; i< N; i++){
    rnd =  ( (MULTIPLIER*rnd + INCREMENT) % MODULUS );
    stp = rnd >> 30;
    //fprintf(ofile, "%u \n",  rnd);
  }
  fclose(ofile);
  return 0;
}
