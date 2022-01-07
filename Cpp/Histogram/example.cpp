#include <iostream>
#include <gsl/gsl_randist.h>


using namespace std;

int main(int argc, char **argv){
  cout <<" HISTOGRAM" <<endl;
  int Npoints=201;  // XXX: I want an impar number of points
  int N=10000
  double freq[Npoints];
  double bins[Npoints];
  double p[N];

  long unsigned int seed = 100;
  const gsl_rng_type *T; T = gsl_rng_default;
  gsl_rng *r; r = gsl_rng_alloc(T);
  gsl_rng_set(r,seed);
  
  for (int i=0; i < N; i++){
    p[i] = 2.0*gsl_ran_gaussian(r, 1);
  }


  for (int i=0; i < Npoints; i++){
    freq[i] = 0.0;
  }



  for (int i=0; i < Npoints; i++){
    cout<< freq[i] <<endl;
  }
}
