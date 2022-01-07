#include <stdio.h>
#include <stdlib.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

#include <gsl/gsl_histogram.h>


int main(){
  printf("#Exponential distribution\n");
  const gsl_rng_type * T;
  gsl_rng *r;
  T = gsl_rng_default;
  r = gsl_rng_alloc(T);

  gsl_histogram *h;
  double auxMSD = 100;
  h = gsl_histogram_alloc (auxMSD+1);
  gsl_histogram_set_ranges_uniform (h, -0.5, auxMSD+0.5);

  FILE *ofileHis; // =  fopen("rw.his_1e1", "w");
  char auxflnName[50];
  sprintf(auxflnName, "rw_exponential.his" );
  ofileHis = fopen(auxflnName, "w");


  double mu = 1.0;
  const int Nsteps = 1000000;
  double rndval = 0;
  for (int ns = 0; ns < Nsteps; ns++) {
    rndval = gsl_ran_exponential(r, mu);
    printf("%g\n", rndval);
    gsl_histogram_increment(h, rndval);
  }

  double sum = gsl_histogram_sum(h);
  if (sum > 0.0)  
    gsl_histogram_scale(h, 1.0 / sum);
  
  gsl_histogram_fprintf (ofileHis, h, "%g", "%g");
  gsl_histogram_free (h);


  return EXIT_SUCCESS;
}
