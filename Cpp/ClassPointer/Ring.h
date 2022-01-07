/* 
 * File:   Ring.h
 * Author: alfaceor
 *
 * Created on September 23, 2016, 10:52 PM
 */


#include <iostream>
#include <sys/stat.h>

#include <string>
#include <sstream>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


#ifndef RING_H
#define RING_H

using namespace std;

class Ring {
public:
    int N;
    double *q;
    double *p;
    double *co;
    double *si;
    double Mx;
    double My;
    
    double Ek;
    double Ep;
    double Et;
    double U;
    double T;
    double M2;
    double M;
    
    
    Ring(int const Np);
    ~Ring();
    
    void initPzero();
    void initQzero();
    void initMzero();
    
    double getTotalP();
    void calcEk();
    void calcEp();
    
    void calcU();
    
//    void calcT();
    void calcMag_i();
    
    string strPhase(double t);
    string strMicrostate(double t);
    string strMag_i(double t);
    string strEnergy(double t);
    
//private:

};

#endif  /* RING_H */


