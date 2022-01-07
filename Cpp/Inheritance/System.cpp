#include "System.h"

System::System(int const Np){
  this->N = Np;
  this->p = new double[Np];
  this->q = new double[Np];
  initP();
  initQ();
}

void System::initP(){
  for (int i=0; i<N; i++){
    p[i] = 0.0;
  }
}

void System::initQ(){
  for (int i=0; i<N; i++){
    q[i] = 0.0;
  }
}

void System::strPhaseSpace(){
  for (int i =0; i< N; i++){
    cout << p[i] << " " << q[i] <<endl; 
  }
}

System::~System(){
  delete[] p;
  delete[] q;
}
