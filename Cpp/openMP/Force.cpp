#include <iostream>
#include <gsl/gsl_math.h>
using namespace std;

void initCond(double *q, int N){
  #pragma omp parallel for
  for (int i=0; i<N; i++){
    q[i] = 1.0;
  }
}

void calcForce(double *q, int N, int M){
  #pragma omp parallel for
  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      q[i] = q[i]+cos(0.01*i*j)+1.0*j;
    }
  }
}

void printQ(double *q, int N){
  cout<< q[0]   <<endl;
  cout<< q[N/2] <<endl;
  cout<< q[N-1] <<endl;
}

int main(){


  int const N=1000000;
  int const M=1000;
  double q[N];
  //q = new double[N];
  //#pragma omp parallel for
  //for (int i=0; i<N; i++){
  //  q[i]=0.0;
  //}



  //#pragma omp parallel for
  //for (int i=0; i<N; i++){
  //  for (int j=0; j<M; j++){
  //    q[i] = q[i]+cos(0.01*i*j)+1.0*j;
  //  }
  //}

  initCond(q,N);
  calcForce(q,N,M);
  printQ(q,N);


}



//void calcForcesAlpha03(double *force){
////  double forzaij[6][6];
//  initForceZero();
//  calcMag_i();
//  double fij=0.0;
//  // Fixed BC
//  force[0] += kpL*sin(-q[0]);
//  for (int i=0; i<N; i++){
//    for (int j=0; j<i; j++){
//      fij = k*(my[j]*mx[i] - mx[j]*my[i])*invIJalpha[abs(i-j)];   //sin(q[j] - q[i]);
//      force[i] +=  fij;
//      force[j] += -fij;
//    }
//  }
//  force[N-1] += kpR*sin(-q[N-1]);
//}
