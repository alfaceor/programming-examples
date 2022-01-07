#include "omp.h"

static long num_steps = 1000000000;
double step;

int main()
{
  double  pi=0.0;
  step = 1.0/(double) num_steps;
  double x =0.0, sum=0.0;
  int i=0;
  #pragma omp parallel for reduction (+:sum)
  for (i=0; i<num_steps; i++){
    x = (i+0.5)*step;
    sum += 4.0/(1.0+ x*x);
  }
  pi = step*sum;
  printf("pi = %f\n",pi);
}
