#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_histogram.h>
#include <vector>

using namespace std;

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967295 //4294967296 

double gsl_ran_powerLaw(gsl_rng *r, double mu, double lmax){
  double x0 = 1.0;
  double x0_1mmu =  pow(x0,   1.0 - mu);
  double x1_1mmu =  pow(lmax, 1.0 - mu);
  double C;
  if (mu == 1)
    C = 1.0/log(lmax/x0);
  else
    C = (1.0 - mu)/( x1_1mmu - x0_1mmu);
  double u;
  u = gsl_rng_uniform(r);

  return pow( u/C , 1.0/(- mu));

}

int main(){
  // Parameters to run
  //vector <string> strMuList = {"0.5", "1.0", "1.5", "2.0", "2.5", "3.0", "4.0" };
  // vector <string> strMuList = { "0.1", "0.2", "0.3", "0.4", "0.5", "0.6", "0.7", "0.8", "0.9", "1.0", "1.1", "1.2", "1.3", "1.4", "1.5", "1.6", "1.7", "1.8", "1.9", "2.0", "2.2" };
  vector <string> strMuList = { "0.1", "0.3", "0.5", "0.7", "0.9", "1.0", "1.1", "1.3", "1.5", "1.7", "1.9", "2.0", "2.1", "2.3" };
  const int Nsteps  = 10000;
  const int Ntrials = 10000;
  double lmax;

  // Histogram parameters
  size_t n;
  n = 16;
  //const double range[n] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 521, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
  double range[n];
  for (int i=0; i<n; i++){
    range[i] = (double) pow(2.0, i);
  }
  // Auxiliar variables
  unsigned int rndint = 0;
  int sign = 0;
  double rndfloat = 0.0;
  double x = 0.0;
  double x_mean[Nsteps] = {0.0};
  double x_var [Nsteps] = {0.0};
  //for (int i=0; i<Nsteps; i++)
  //  printf("%d %g %g\n", i, x_mean[i], x_var[i]);

  const gsl_rng_type *T;
  gsl_rng *r;
  T = gsl_rng_default;
  r = gsl_rng_alloc(T);

  // -- Output filename
  string strMu = "";
  char str_aux[100];
  double mu = 0;

  /********************** BEGIN SIMULATION **********************/ 
  for (int i=0; i<strMuList.size(); i++){
    strMu = strMuList[i]; // "4.0";
    printf("mu = %s\n", strMu.c_str());
    mu = atof(strMu.c_str());
    sprintf(str_aux, "randomWalk_mu_%s.dat", strMu.c_str());
    FILE *ofile = fopen(str_aux, "w");
    fprintf(ofile, "#t x eta\n");

    gsl_histogram *heta = gsl_histogram_alloc(n-1);
    gsl_histogram_set_ranges(heta, range, n);

    gsl_histogram *hx = gsl_histogram_alloc(n-1);
    gsl_histogram_set_ranges(hx, range, n);
    
    for (int nt = 0; nt < Ntrials; nt++){
      //printf(" %d", nt);
      x = 0.0;
      for (int ns = 0; ns < Nsteps; ns++){
        rndint   =  ( (MULTIPLIER*rndint + INCREMENT) % MODULUS );
        // rndfloat = ((float)rndint)/MODULUS;
        sign = rndint >> 31;
        if (sign == 0 ) sign = -1;
        // printf("%d\n", sign);
        lmax = 500;
        rndfloat = gsl_ran_powerLaw(r, mu, lmax);
        //rndfloat = gsl_ran_gaussian(r, 1);
        x = x + sign*rndfloat;
        gsl_histogram_increment(heta, rndfloat);
        gsl_histogram_increment(hx, abs(x));
        x_mean[ns] += x;
        x_var [ns] += x*x;
        
        //if ( ns % 100 == 0)
        //  fprintf(ofile, "%d %f %f\n", ns, x, rndfloat);
      }
      //printf("%g %g %g %d\n", x, x_mean[Nsteps-1], rndfloat, sign);
    }

    //  sprintf(str_aux, "stats_mu_%s.dat", strMu.c_str());
    //  FILE *ofileStats = fopen(str_aux, "w");
    //  for (int ns = 0; ns < Nsteps; ns++){
    //    x_mean[ns] = x_mean[ns]/Ntrials;
    //    x_var [ns] = x_var [ns]/Ntrials - x_mean[ns]*x_mean[ns];
    //    fprintf(ofileStats, "%d %g %g\n", ns, x_mean[ns], x_var[ns]);
    //  }
    //  printf("%d %g %g\n", Nsteps-1, x_mean[Nsteps-1], x_var[Nsteps-1]);
    //  fclose(ofileStats);
    
    // double Aeta = 0.0;
    // for (int i=0; i<n-1; i++)
    //   Aeta = (range[i+1] - range[i])* heta->bin[i];
    // printf("Aeta = %g", Aeta);
    //
    double sumeta;
    sumeta = gsl_histogram_sum(heta);
    printf( "mu = %g, sum eta = %g \n", mu, sumeta);
    // gsl_histogram_scale( heta, 1.0/sumeta);
    sprintf(str_aux, "histoeta_mu_%s.dat", strMu.c_str());
    FILE *ofileHiseta = fopen(str_aux, "w");
    gsl_histogram_fprintf(ofileHiseta, heta, "%g", "%g");
    gsl_histogram_free(heta);
    fclose(ofileHiseta);

    // double sumx;
    // sumx = gsl_histogram_sum(hx);
    // gsl_histogram_scale( hx, 1.0/sumx);
    // double Ax = 0.0;
    // for (int i=0; i<n-1; i++)
    //   Ax = (range[i+1] - range[i])*hx->bin[i];
    sprintf(str_aux, "histox_mu_%s.dat", strMu.c_str());
    FILE *ofileHisx = fopen(str_aux, "w");
    gsl_histogram_fprintf(ofileHisx, hx, "%g", "%g");
    gsl_histogram_free(hx);
    fclose(ofileHisx);

    fclose(ofile);
    /********************** END SIMULATION **********************/ 
  }

  gsl_rng_free(r);

  return EXIT_SUCCESS;
}
