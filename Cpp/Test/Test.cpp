
#include <stdio.h>
#include <iostream>
#include <gsl/gsl_math.h>
#include <stdlib.h>

#define N 1000000
using namespace std;

//const int N = 5;
double alpha = 0.5;

//double *inv_ijalpha;
//double inv_ijalpha = new double[N];
double inv_ijalpha[N];
//double *NtildeI;
//double NtildeI = new double[N];
double NtildeI[N];

void calculateNtildeI(){  // depend of on the value of \alpha
//  calculateInvIJalpha();
  int delta_ij= 0;
  for (int i=0; i<N ; i++){
    NtildeI[i] = 0.0;
    for (int j=0; j<N; j++){
      if (i != j){
        delta_ij = abs(i-j);
        NtildeI[i] += inv_ijalpha[delta_ij];
      }
    }
    cout<<NtildeI[i]<< " ";
  }
  cout<<endl;
}  

void calculateInvIJalpha(){  // r_{i,j}^\alpha = |i-j|^\alpha
  cout<<" inv_ijalpha[delta_ij] "<<endl;
  inv_ijalpha[0] = 0.0;
  cout<<inv_ijalpha[0]<<endl;
  for (int delta_ij=1; delta_ij<N; delta_ij++){
    inv_ijalpha[delta_ij] = 1.0/pow(fabs(delta_ij), alpha);
    cout<<inv_ijalpha[delta_ij]<<" ";
  }
  cout<<endl;
  cout<<"***************"<<endl;
}

int main(){
  calculateInvIJalpha();
  calculateNtildeI();
/*
  for (int i =0; i<N; i++){
   inv_ijalpha[i] = 0.0;
   NtildeI[i] = 0.0;
  }
  icout<<"HELLO Bitch!"<<endl;
  */
}
