/* 
 * File:   Ring.cpp
 * Author: alfaceor
 * 
 * Created on September 23, 2016, 10:52 PM
 */

#include "Ring.h"


Ring::Ring(int const Np) {
    
  this->N  = Np;
  this->p  = new double[Np];
  this->q  = new double[Np];
  this->co = new double[Np];
  this->si = new double[Np];
  
  initPzero();
  initQzero();  
  initMzero();
}

//Ring::Ring(const Ring& orig) {
//}

Ring::~Ring() {
  
  delete[] p;
  delete[] q;
  
  delete[] co;
  delete[] si;
}

void Ring::initPzero(){
  for (int i=0; i<N; i++){
    p[i] = 0.0;
  }
}
void Ring::initQzero(){
  for (int i=0; i<N; i++){
    q[i] = 0.0;
  }
}
void Ring::initMzero(){
  for (int i=0; i<N; i++){
    co[i] = 0.0;
    si[i] = 0.0;
  }
}

double Ring::getTotalP(){
  double totalP=0.0;
  for (int i=0; i<N; i++){
    totalP += p[i];
  }
  return totalP;
}


void Ring::calcEk(){
  Ek = 0.0;
  for (int i=0; i<N; i++){
    Ek += p[i]*p[i];
  }
  T  = Ek/double(N);
  Ek = 0.5*Ek;
  
}

void Ring::calcEp(){
  calcMag_i();
  M2 = Mx*Mx+My*My;
  M  = sqrt(M2); 
  Ep = N*0.5*(1 - M2);
}


void Ring::calcU(){
  calcEk();
  calcEp();
//  calcMag_i();
//  U = Ek/double(N) + 0.5*(1 - (Mx*Mx+My*My));
  U = (Ek + Ep)/double(N);
}

void Ring::calcMag_i() {
  Mx=0.0;
  My=0.0;
  for (int i=0; i<N; i++){
    co[i] = cos(q[i]);
    si[i] = sin(q[i]);
    Mx   += co[i];
    My   += si[i];
  }
  Mx = Mx/double(N);
  My = My/double(N);
}



string Ring::strPhase(double t){
  string strReturn;
  stringstream sstm;
  sstm.precision(10);
  sstm << "# " << t << " " <<endl;
  for (int i = 0; i < N; i++) {
//    sstm<< i << " " << p[i] << " " << q[i] <<endl;
    sstm<< i << " " << p[i] << " " << q[i] <<endl;
  }
  strReturn = "" + sstm.str();
  return strReturn;
}

string Ring::strMicrostate(double t){
  string strReturn;
  stringstream sstm;
  sstm.precision(10);
  sstm << t ;
  for (int i = 0; i < N; i++) {
    sstm << " " << p[i] << " " << q[i];
  }
  strReturn = ""+sstm.str();
  return strReturn;
}


string Ring::strMag_i(double t){
  string strReturn;
  stringstream sstm;
  sstm.precision(17);
  sstm << "# " << t << " " <<endl;
  for (int i=0; i<N; i++){
    sstm << i << " " << co[i] << " " << si[i] << endl;
  }
  strReturn = ""+ sstm.str();
  return strReturn;
}

string Ring::strEnergy(double t){
  string strReturn;
  stringstream sstm;
  sstm.precision(17);
  sstm << t << " " << Ek << " " << Ep << " " << Ek+Ep << " ";
  strReturn = ""+ sstm.str();
  return strReturn;
}


