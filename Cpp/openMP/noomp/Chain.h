#include <gsl/gsl_math.h>
#include <iostream>

#ifndef CHAIN_H
#define CHAIN_H
using namespace std;

class Chain{
  public:
    int N;
    double *q;
    double *mx;
    double *my;
    double *force;

    Chain(int const Np);
    void initCond();
    void changeQ(double delta);
    void calMag_i();
    void calForce000();
    void calForce000b();
    void calForce001();
    void calForce002();
    void calForce003();
    void calForce004();
    void testOMP(double *qq, double Np, double delta);
    void printSomething();

};

#endif  /* CHAIN_H */
