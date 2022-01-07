#include "Chain.h"


Chain::Chain(int const Np){
  this->N     = Np;
  this->q     = new double[Np];
  this->mx    = new double[Np];
  this->my    = new double[Np];
  this->force = new double[Np];  
}

void Chain::initCond(){
  for (int i=0; i<N; i++){
    q[i]     = 0.0;
    force[i] = 0.0;
  }
}


void Chain::changeQ(double delta){
  int i=0;
  #pragma omp parallel
  {
    #pragma omp for
    for (int i=0; i<N; i++){
      q[i] = q[i] + delta*i + 1.0*i/N;
    }
  }
}

void Chain::calMag_i(){
  int i =0;
  #pragma omp parallel
  {
    #pragma omp for
    for (i=0; i<N; i++){
      mx[i] = cos(q[i]);
      my[i] = sin(q[i]);
    }
  }
}

void Chain::calForce000(){
  int i;
  int j;
  double fij =0.0;
  for (i=0; i<N; i++){
    force[i] = 0.0;
    for (j=0; j<i; j++){
      fij = my[i]*mx[j] - mx[i]*my[j];
      force[i] +=  fij;
      force[j] += -fij;
    }
  }
}

void Chain::calForce000b(){
  int i;
  int j;
  double fij =0.0;
  for (i=0; i<N; i++){
    force[i] = 0.0;
    double sum =0.0;
    for (j=0; j<i; j++){
      fij = my[i]*mx[j] - mx[i]*my[j];
      sum +=  fij;
      force[j] += -fij;
    }
    force[i] +=sum;
  }
}
// This is not a real force just a test for calculation with openMP
void Chain::calForce001(){   // XXX: ESTE PARECE SER MAS RAPIDO QUE EL calForce002 !!!!!!!!!
  int i;
  int j;
  double fij =0.0;
  #pragma omp parallel
  {
    #pragma omp for private(j, fij)
    for (i=0; i<N; i++){
      force[i] = 0.0;
      for (j=0; j<i; j++){
        //cout << "  j = " << j << ", "<< i<<endl;
        fij = my[i]*mx[j] - mx[i]*my[j];
        #pragma omp critical
        {
          //cout << "i = " << i <<", j = "<< j <<endl;
          force[i] +=  fij;
          force[j] += -fij;
        }
      }
    }
  }
}


void Chain::calForce002(){
  int i;
  int j;
  double fij =0.0;
  for (i=0; i<N; i++){
    force[i] = 0.0;
    #pragma omp parallel for private(fij)
    for (j=0; j<i; j++){
      fij = my[i]*mx[j] - mx[i]*my[j];
      #pragma omp critical
      {
        //cout << "Force002: i = " << i << ", j = "<< j <<endl;
        force[i] +=  fij;
        force[j] += -fij;
      }
    }
  }
}

void Chain::calForce003(){
  int i;
  int j;
  double fij =0.0;
  for (i=0; i<N; i++){
    force[i] = 0.0;
    for (j=0; j<i; j++){
      fij = my[i]*mx[j] - mx[i]*my[j];
      force[i] +=  fij;
      force[j] += -fij;
    }
  }
}

void Chain::calForce004(){
  int i;
  int j;
  double fij =0.0;
  #pragma omp parallel
  {
    #pragma omp for private(j, fij)
    for (i=0; i<N; i++){
      force[i] = 0.0;
      double sum =0.0;
      for (j=0; j<i; j++){
        //cout << "  j = " << j << ", "<< i<<endl;
        fij = my[i]*mx[j] - mx[i]*my[j];
        sum +=fij;
        //#pragma omp atomic
        //force[i] +=  fij; 
        #pragma omp atomic
        force[j] += -fij;
      }
      #pragma omp atomic
      force[i]+=sum;
    }
  }
  //cout <<"time calcForce004 omp atomic = " << time <<endl;
}



void Chain::testOMP(double *qq, double Np, double delta){
  for (int i=0; i<Np; i++){
    qq[i] = qq[i]+ delta*i;
  }
}

void Chain::printSomething(){
  cout << q[0]   << ", mx[0]  = " << mx[0]   << " " << my[0]   << ", force[0] = " << force[0]   <<endl;
  cout << q[N/2] << ", mx[0]  = " << mx[N/2] << " " << my[N/2] << ", force[0] = " << force[N/2] <<endl;
  cout << q[N-1] << ", mx[0]  = " << mx[N-1] << " " << my[N-1] << ", force[0] = " << force[N-1] <<endl;
}


