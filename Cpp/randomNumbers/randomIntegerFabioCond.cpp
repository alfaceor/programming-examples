#include <stdio.h>
#include <stdlib.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967296 

int main(int argc, char* argv[]) {
  int N = 1000000;
  int base10print=10;
  int Npossibilities = 12;
  unsigned int rnd = 12345 ;
  FILE *ofile = fopen("randomIntegerFabioCond.dat", "w");
  unsigned int stp=0;
  for (int i =0; i< N; i++){
    rnd =  ( (MULTIPLIER*rnd + INCREMENT) % MODULUS );
    stp = rnd >> 28;
    if (stp >= Npossibilities){
      //if (stp == 12)
      //  printf("ops stp = %u\n", stp );
      i--;
    }else {
      fprintf(ofile, "%u \n",  stp);
    }
  }
  fclose(ofile);
  return 0;
}
