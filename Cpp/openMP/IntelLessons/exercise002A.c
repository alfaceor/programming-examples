#include "omp.h"

static long num_steps = 1000000000;
double step;
#define NUM_THREADS 2

int main()
{
  double  pi=0.0;
  step = 1.0/(double) num_steps;
  //int n_threads=4;
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  { 
    double x=0.0,sum=0.0;
    int ID,nthrds,i;
    ID=omp_get_thread_num();
    nthrds = omp_get_num_threads();
    //if (ID ==0) nthreads = nthrds;
    // ID = omp_get_thread_num();
    // nthrds = omp_get_num_threads();
    //for (i=0; i<num_steps; i++){
    for (i=ID; i<num_steps; i=i+nthrds){
      x = (i+0.5)*step;
      sum += 4.0/(1.0+ x*x);
    }
    #pragma omp atomic
    pi += step*sum;
  }
  printf("pi = %f\n",pi);
}
