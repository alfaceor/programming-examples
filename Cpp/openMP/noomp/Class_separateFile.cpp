#include <iostream>
#include <gsl/gsl_math.h>
#include <omp.h>
#include "Chain.h"
using namespace std;

int main(){
  int const N=1000;
  int timeSteps=5;
  double delta=0.0001;
  double qq[N];
  Chain ch(N);
  ch.initCond();
  for (int t=0; t<timeSteps; t++){
    ch.changeQ(delta*t);
    ch.calMag_i();
    //ch.calForce000b();
    ch.calForce006();
  }
  ch.printSomething();
}

