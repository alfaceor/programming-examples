#include <iostream>
#include <stdlib.h>
#include <gsl/gsl_math.h>

using namespace std;

int const N=1000;
double theta[N];
double alpha=0.50;
//theta= new double[100];
double inv_ijalpha[N];
double invNtildeI[N];


void calculateInvNtildeI(){  // depend of on the value of \alpha
  double auxNtildeI = 0.0;
  int delta_ij= 0;
  for (int i=0; i<N ; i++){
    auxNtildeI = 0.0;
    for (int j=0; j<N; j++){
      if (i != j){
        delta_ij = abs(i-j);
        // This is not the inverse of NtildeI
        auxNtildeI += inv_ijalpha[delta_ij]; 
      }
    // Now we invert the value to get the inverse
    invNtildeI[i] = 1.0/auxNtildeI;
    }
  }
  
} 

void calculateInvIJalpha(){  // r_{i,j}^\alpha = |i-j|^\alpha
//  cout<<" inv_ijalpha[delta_ij] "<<endl;
  inv_ijalpha[0] = 0.0;
  cout<<inv_ijalpha[0]<<endl;
  for (int delta_ij=1; delta_ij<N; delta_ij++){
    inv_ijalpha[delta_ij] = 1.0/pow(double(fabs(delta_ij)), alpha);
//    cout<<inv_ijalpha[delta_ij]<<" ";
  }
  cout<<endl;
//  cout<<"***************"<<endl;
}


double calculateEpotAlpha2(double eps){
  double auxEp = 0.0;
  double costhetaij = 0.0;
  double Ep = 0.0;
  for (int i=0; i<N; i++){
    auxEp = 0.0;
    for (int j=0; j<i; j++){
      costhetaij = cos(theta[i]-theta[j]); // vec_m[indx(i,0)]*vec_m[indx(j,0)] + vec_m[indx(i,1)]*vec_m[indx(j,1)] ;
      //cout<< costhetaij<<endl;
      auxEp += (1.0 - costhetaij)*inv_ijalpha[abs(i-j)];
//      cout<<auxEp<<endl;
    }
    Ep += invNtildeI[i]*auxEp;
  }
  Ep = eps*Ep;
  return Ep;
}

double calculateEpotAlpha3(double eps){
  double auxEp = 0.0;
  double costhetaij = 0.0;
  double Ep = 0.0;
  for (int i=0; i<N; i++){
    auxEp = 0.0;
    for (int j=0; j<i; j++){
      costhetaij = cos(theta[i]-theta[j]); // vec_m[indx(i,0)]*vec_m[indx(j,0)] + vec_m[indx(i,1)]*vec_m[indx(j,1)] ;
      //cout<< costhetaij<<endl;
      auxEp += (1.0 - costhetaij)*inv_ijalpha[abs(i-j)];
//      cout<<auxEp<<endl;
    }
    for (int j=i+1; j<N; j++){
      costhetaij = cos(theta[i]-theta[j]); // vec_m[indx(i,0)]*vec_m[indx(j,0)] + vec_m[indx(i,1)]*vec_m[indx(j,1)] ;
      auxEp += (1.0 - costhetaij)*inv_ijalpha[abs(i-j)];
    }
    Ep += invNtildeI[i]*auxEp;
  }
  Ep = 0.5*eps*Ep;
  return Ep;

}


int main(){
  
  for (int i=0; i<N; i++){
    theta[i]=0.01*i;
  }
  calculateInvIJalpha();
  calculateInvNtildeI();
  cout<<"EpotAlpha2="<<calculateEpotAlpha2(1)<<endl;
  cout<<"EpotAlpha3="<<calculateEpotAlpha3(1)<<endl;
}
