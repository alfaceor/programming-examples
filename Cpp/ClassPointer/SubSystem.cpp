/* 
 * File:   SubSystem.cpp
 * Author: alfaceor
 * 
 * Created on October 19, 2016, 1:47 AM
 */

#include "SubSystem.h"

SubSystem::SubSystem(int N, int i, int j) {
  this->N     = N;
  this->fromI = i;
  this->toJ   = j;
  
  this->T     = 0.0;
  this->Ep    = 0.0;
  this->Ek    = 0.0;
  this->U     = 0.0;
  this->Mx    = 0.0;
  this->My    = 0.0;
  this->M2    = 0.0;
  // N == j-i+1;
}

void SubSystem::scaleP(Ring* r, double scaleFactor){
  for (int i=fromI; i<=toJ; i++){
    r->p[i] = scaleFactor*r->p[i];
  }
}


void SubSystem::calcEk(Ring* r){
  Ek = 0.0;
  for (int i=fromI; i<=toJ; i++){
    Ek += r->p[i]*r->p[i];
  }
  T  = Ek/double(N);
  Ek = 0.5*Ek;
}

void SubSystem::calcEp(Ring* r){
  // call the calcM(Ring* r) function first
  M2 = Mx*Mx+My*My;
//  M  = sqrt(M2); 
  Ep = N*0.5*(1 - M2);
}

void SubSystem::calcM(Ring* r){
  Mx=0.0;
  My=0.0;
  for (int i=fromI; i<toJ; i++){
    Mx   += r->co[i];
    My   += r->si[i];
  }
  Mx = Mx/double(N);
  My = My/double(N);
}

SubSystem::SubSystem(const SubSystem& orig) {
}

SubSystem::~SubSystem() {

}

