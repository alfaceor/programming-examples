#include <stdio.h>
#include <time.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967295 //4294967296 

int main(int argc, char *argv[]){

  time_t tstart, tend;
  tstart  = time(0);
  const int Ntrials = 5000000;

  //============================================================//
  // Times to save in the form of base^n, for a base = 1.1 
  const int Nsteps = 1052;
  const int Np2save = 59 ; 
  int time2save[Np2save] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 26, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 117, 129, 142, 156, 172, 189, 208, 229, 252, 277, 304, 335, 368, 405, 446, 490, 539, 593, 653, 718, 790, 869, 956, 1051 }; 

  
  // TODO: OTHER ARRAYS TO USE Np2save for mean, variance, etc 
  
  double x_mean   [Np2save] = {0};

  #pragma omp parallel
  {
    double x_mean_pri   [Np2save] = {0};
    #pragma omp for
    for (int nt=0; nt < Ntrials; nt++){
      int x      = 0;
      int ns     = 0;
      int ttnext = 0;
      // TODO: Define random seed for each nt
      unsigned int rnd = nt*127;
      while ( ns < Nsteps ){
        rnd = (MULTIPLIER *rnd + INCREMENT) % MODULUS;
        x = rnd >> 27;
        if ( ns == time2save[ttnext] ) { 
          x_mean_pri   [ttnext] += x;
          ttnext++;
        }
        ns ++;
      }
    }

    #pragma omp critical
    {
      for(int n=0; n<Np2save; ++n) {
        //time2save[n] += time2save_pri[n];
        x_mean[n]    += x_mean_pri[n];
      }
    }
  }
  // Write file average
  FILE *ofile = fopen("openmpSaida.dat", "w");
  for(int np=0; np<Np2save; ++np) {
    //time2save[n] = time2save[n]/Ntrials;
    x_mean[np]    = x_mean[np]/((float) Ntrials);
    fprintf(ofile, "%d %e\n", time2save[np], x_mean[np]);
  }
  fclose(ofile);

  //for (int i = 0; i< N; i++)
  //  printf("%d ", S[i]);
  //printf("\n");
  tend = time(0); 
  printf("Simulation time = %lf, expectation = %g hrs \n", difftime(tend,tstart), Ntrials*difftime(tend,tstart)/(Ntrials*3600.));
  return 0;
} 
