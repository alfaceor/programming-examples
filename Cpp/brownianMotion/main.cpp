#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <time.h>

double force_cc_r(double epsilon, double q, double r2){
  double force;
  double r6 = 1.0/(r2*r2*r2);
  double r8 = r6*(1.0/(r2));

  if(r2 <=1){
    force = ( 12*epsilon*r8*(r6-1) );
  }else{
    double r   = sqrt(r2);
    if(r < 1+q){
      double aux = (r-1)/q;
      double denominador = r*q*(1.0/aux - aux);
      force =  -2*epsilon/denominador;
    }else{
      force = 0;
    }

  }
  return force;
}


void addPosition3DNoise(double dt, double KT, gsl_rng *r){
  // Position noise for 3D dimensions.
  double etha=sqrt(2*KT*dt)*gsl_ran_gaussian(r,1);
  double teta=gsl_rng_uniform_pos(r);
  double phi =gsl_rng_uniform_pos(r);
  vec_r[0] += etha*sin(teta)*cos(phi);
  vec_r[1] += etha*sin(teta)*sin(phi);
  vec_r[2] += etha*cos(teta);
}


int main(){
  printf("FUCK YOU\n");
  double force;
  double epsi=1.0;
  double q = 0.13;
  double r2=1.0;
  double temp=0.07;
  int N=10;

  const gsl_rng_type *T; T = gsl_rng_default;
  gsl_rng *r; r = gsl_rng_alloc(T);
  long unsigned int seed;
  seed = time(NULL); // Get the time of the system as seed
  gsl_rng_set(r,seed);
  //printf("%ju\n");
  for (int i=0;i<N;i++){
    force = force_cc_r(epsi,q,r2);
    printf("%lf\t%lf\n",r2,epsi);
  }
  
}
