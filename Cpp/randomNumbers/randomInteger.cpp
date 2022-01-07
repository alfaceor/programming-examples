#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

using namespace std;
int main(int argc, char* argv[]) {
	int N=100000000; //atoi(argv[1]);
  int Npossibilities = 12;

	const gsl_rng_type * T;
	gsl_rng *r;
	T	= gsl_rng_default;
	r	= gsl_rng_alloc(T);
  FILE *ofile = fopen("randomInteger.dat", "w");

	for (int i=0; i<N; i++){
    // fprintf(ofile, "%lu \n",  gsl_rng_uniform_int (r, Npossibilities));
    gsl_rng_uniform_int (r, Npossibilities);
	}
  fclose(ofile);
  return 0;
}





