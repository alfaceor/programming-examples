#include <stdio.h>

int main(int argc, char *argv[]){

  const int Ntrials = 100000;

  //============================================================//
  // Times to save in the form of base^n, for a base = 1.1 
  const int Nsteps = 1052;
  const int Np2save = 59 ; 
  int time2save[Np2save] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 26, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 117, 129, 142, 156, 172, 189, 208, 229, 252, 277, 304, 335, 368, 405, 446, 490, 539, 593, 653, 718, 790, 869, 956, 1051 }; 

  
  // TODO: OTHER ARRAYS TO USE Np2save for mean, variance, etc 
  
  double x_mean[Np2save] = {0};


  const int N = 100000;
  int a[N];
  int S[N] = {0};
  for (int i=0; i < N; i++){
    a[i] = i + 1;
  }
  int sum = 0;
  #pragma omp parallel
  {
    int S_private[N] = {0}; // For each thread create a local variable
    #pragma omp for
    for (int n=0 ; n<N ; ++n ) {
      for (int m=0; m<=n; ++m){
        S_private[n] += a[m];
      }
    }
    #pragma omp critical
    {
      for(int n=0; n<N; ++n) {
        S[n] += S_private[n];
      }
    }
  }
  //for (int i = 0; i< N; i++)
  //  printf("%d ", S[i]);
  //printf("\n");
  return 0;
}


//  if ( ns == time2save[ttnext] ) { 
//      // SAVE THE POINT 
//          ttnext ++;
//  }


