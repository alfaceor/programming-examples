#include <iostream>
#include <gsl/gsl_math.h>
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
    void calForce001();
    void calForce002();
    void testOMP(double *qq, double Np, double delta);
    void printSomething();

};

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
  for (int i=0; i<N; i++){
    q[i] = q[i] + delta*i + 1.0*i/N;
  }
}

void Chain::calMag_i(){
 for (int i=0; i<N; i++){
   mx[i] = cos(q[i]);
   my[i] = sin(q[i]);
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
      fij = my[i]*mx[j] - mx[i]*my[j];
      force[i] +=  fij;
      force[j] += -fij;
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
    #pragma omp parallel for private(j, fij)
    for (j=0; j<i; j++){
      fij = my[i]*mx[j] - mx[i]*my[j];
      force[i] +=  fij;
      force[j] += -fij;
    }
  }
  
}
void Chain::testOMP(double *qq, double Np, double delta){
  for (int i=0; i<Np; i++){
    qq[i] = qq[i]+ delta*i;
  }
}

void Chain::printSomething(){
  cout << q[0]   << " " << mx[0]   << " " << my[0]   << " " << force[0]   <<endl;
  cout << q[N/2] << " " << mx[N/2] << " " << my[N/2] << " " << force[N/2] <<endl;
  cout << q[N-1] << " " << mx[N-1] << " " << my[N-1] << " " << force[N-1] <<endl;
}

int main(){
  int const N=50000;
  int timeSteps=100;
  double delta=0.0001;
  double qq[N];
  Chain ch(N);
  ch.initCond();
  ch.calMag_i();
  for (int t=0; t<timeSteps; t++){
    ch.changeQ(0.0003*t);
  }
  cout<<"-----force beging------"<<endl;
  ch.calForce001();
  cout<<"-----force end   ------"<<endl;
  ch.printSomething();
  //for (int t=0; t<timeSteps; t++){
  //  ch.testOMP(qq,N,delta*t);
  //}

//  int const N=1000000;
//  int const M=1000;
//  double q[N];
//  //q = new double[N];
//  #pragma omp parallel for
//  for (int i=0; i<N; i++){
//    q[i]=0.0;
//  }
//  #pragma omp parallel for
//  for (int i=0; i<N; i++){
//    for (int j=0; j<M; j++){
//      q[i] = q[i]+cos(0.01*i*j)+1.0*j;
//    }
//  }
//
//cout<< q[0]   <<endl;
//cout<< q[N/2] <<endl;
//cout<< q[N-1] <<endl;
////  for (int i=0; i<N; i++){
////    cout<<q[i]<<endl;
////  }

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
