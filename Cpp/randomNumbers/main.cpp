#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

void generateRandomNumber(gsl_rng *r, double sigma){
	double randomaux;
	randomaux	= gsl_ran_gaussian(r,sigma);
	printf("%f\n",randomaux);
}

int main(int argc, char* argv[]) {
	int N=atoi(argv[1]);
	double sigma=atof(argv[2]);

	const gsl_rng_type * T1;
	gsl_rng *r1;
	
	T1	= gsl_rng_default;
	r1	= gsl_rng_alloc(T1);

	for (int i=0; i<N; i++){
		generateRandomNumber(r1,sigma);
	}

}
