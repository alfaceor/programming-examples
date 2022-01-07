/*
Objective: write a file in a for with a corresponding number of trials, with a condition
*/
// g++ -std=c++11 -Wall -Wextra -pedantic -fopenmp critical.cpp
#include <stdio.h>

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967295 //4294967296 


void init_array_zero(double *arr, const int dim){
  for (int i=0; i<dim; i++){
    arr[i] = 0.0;
  }
}

void print_array(double *arr, const int dim){
  for (int i=0; i<dim; i++){
    printf("%g ", arr[i] );
  }
  printf("\n");
}


int main(){
  const int Ntrials = 10000;
  const int Nsteps  = 20;
  unsigned int rnd = 119182;
  int base10ton = 1;
  unsigned int stpDir = 0;
  double x_mean[Nsteps];
  init_array_zero(x_mean, Nsteps);
  print_array(x_mean, Nsteps);

  #pragma omp parallel for
  for (int nt=0; nt < Ntrials; nt++){
    int ns =0;
    while( ns < Nsteps ){
      // Roll a dice and choose
      // rnd = (MULTIPLIER *rnd + INCREMENT) % MODULUS;
      // stpDir= rnd >> 27;
      x_mean[ns] =  ns*nt;
      ns++;
    }
   #pragma omp critical
   if ( (nt+1) % base10ton == 0 ){
     printf("trials = %d : ", nt+1);
     base10ton = 10*base10ton;
     print_array(x_mean, Nsteps);
   }
  }
  print_array(x_mean, Nsteps);
// trials = 1
// trials = 10
// trials = 5100
// trials = 8000
// trials = 10000
  /*  
  #pragma omp parallel for
  for (int i = 0; i < 20; ++i)
    std::cout << "unsynchronized(" << i << ") ";
  std::cout << std::endl;
  #pragma omp parallel for
  for (int i = 0; i < 20; ++i)
    #pragma omp critical
    std::cout << "critical(" << i << ") ";
  std::cout << std::endl;
  #pragma omp parallel for ordered
  for (int i = 0; i < 20; ++i)
    #pragma omp ordered
    std::cout << "ordered(" << i << ") ";
  std::cout << std::endl;
  */
  return 0;
}
