// Objective: Save points every 1.1^power
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]){
  // int Npasos = 0;
  // if (argv[1] == NULL){
  //   Npasos = atoi(argv[1]); //00000;
  // }else{
  //   Npasos = 100000;
  // }
  const int Nsteps = 1000000000; //00000;
  int countTime2Save = 0;
  double base = 1.1;
  int tau     =  0;
  int xxpnt   =  0;
  int tt0 = round(pow(base, xxpnt));
  int tt0_old = -1;
  printf("//============================================================//\n");
  printf("// Times to save in the form of base^n, for a base = %g \n\n", base);
  printf("{ ");
  while ( tt0 < Nsteps){
    tt0 = round(pow(base, xxpnt));
    if (tt0 != tt0_old){
      tau = tt0;
      countTime2Save++;
      // printf("tau = %d, %g, count = %d, exponent =%d \n", tau, log10( (float)tau), countTime2Save, xxpnt);
      // printf("%d \n", tau );
      printf("%d, ", tau );
    }
    tt0_old = tt0;
    xxpnt++;
  }
  printf("\b\b }; \n\n");
  printf("const int Np2save = %d ; \n", countTime2Save);
  printf("int time2save[Np2save] = \n\n");
  printf("// TODO: OTHER ARRAYS TO USE Np2save for mean, variance, etc \n\n");
  printf("int Nsteps = %d;\n\n", tau+1);
  // CONDITION TO PRINT
  printf("// CONDITION TO PRINT\n");
  printf("  // TODO: For each trial ttnext=0;\n  if ( ns == time2save[ttnext] ) { \n    // SAVE THE POINT \n    ttnext ++;\n  }\n"
  );

  printf("//============================================================//\n");

  return EXIT_SUCCESS;
}

