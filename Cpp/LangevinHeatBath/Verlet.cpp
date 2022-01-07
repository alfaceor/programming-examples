#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>
#include <iostream>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <string>

#include <fstream>
#include "IOParams.h"

using namespace std;

double F(double x){
  return -sin(x);
}

int main(int argc, char **argv){
  IOParams io(argc, argv);
  io.printParams();
  const gsl_rng_type *T; T = gsl_rng_default;
  gsl_rng *r; r = gsl_rng_alloc(T);
  long unsigned int seed;
  ofstream ofilePQ;
  string flnmPQ = "PQ__T1_"+io.strT1+".dat";
  ofilePQ.open(flnmPQ.c_str());
  ofilePQ << "#t p q a dW"<<endl;
  seed = 100;
  gsl_rng_set(r,seed);
  
  double dW, p=sqrt(io.T1), q=0.0, a=0.0;
  double factor=sqrt(2*io.gamma1*io.T1*io.dt);
  a = F(q);
  double gammadt = io.gamma1*io.dt;
  double c0 = exp(-gammadt);
  double c1 = (1-c0)/gammadt;
  double c2 = (1-c1)/gammadt;
  cout <<"# gammadt=" << gammadt <<", c0="<< c0 
       <<", c1="<<c1<<", c2="<<c2<<endl;

 
  while (io.ttime<io.timeSteps){
    dW = factor*gsl_ran_gaussian(r,1);
    if (io.ttime % io.taux ==0)
      ofilePQ << io.ttime*io.dt << " " 
         << p << " " << q << " " 
         << a << " " << dW << endl; 
    // Velocity verlet
    q = q + io.dt*p + 0.5*io.dt2*a;
    p = p + 0.5*io.dt*a;
    a = F(q);
    p = p + 0.5*io.dt*a;
    io.ttime++;
  }

  ofilePQ << io.getParams();
  ofilePQ.close();
}
