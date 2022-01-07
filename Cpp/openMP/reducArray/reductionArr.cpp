#include <stdio.h>

int main(int argc, char *argv[]){
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
