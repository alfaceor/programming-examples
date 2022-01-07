/**
Con este programa se pretende responde cual proceso es mas rapido
1. Calcular sin e cos de cada angulo, e luego hacer la diferencia, o
2. Calcular la diferencia 
*/

#include<iostream>
#include <stdlib.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>

#define DIM 2
#define indx(i,j) (i*DIM+j)
#define indx2(i,j,d) (i*d+j)

using namespace std;

/*
int indx2(int i, int j, int d){
  return (i*d+j);
};


int indx(int i, int j){
  return (i*DIM+j);
};

*/

int main(int argc, char* argv[]) {
	int const N=atoi(argv[1]);
	int const M=atoi(argv[2]);
  double *theta = new double[N];
  double *vec_m = new double[DIM*N];
  //double *arrayCos = new double[N*N];
  double *arraySin = new double[N*N];

  int k=0;
  while(k<M){
    for (int i=0; i<N; i++){
      theta[i]=2*M_PI*i/N;
      vec_m[indx(i,0)] = cos(theta[i]);
      vec_m[indx(i,1)] = sin(theta[i]);
      //cout<<theta[i]<<" "<< arrayCos[i] <<" "<<arraySin[i]<<endl;
    }
    for (int i=0; i<N; i++){
      for (int j=0; j<N; j++){
       //arrayCos[indx2(i,j,N)] = cos(theta[i]-theta[j]);
       arraySin[indx2(i,j,N)] = sin(theta[i]-theta[j]);
       
       //arrayCos[indx2(i,j,N)] = vec_m[indx(i,0)]*vec_m[indx(j,0)]+vec_m[indx(i,1)]*vec_m[indx(j,1)];
       //arraySin[indx2(i,j,N)] = vec_m[indx(i,1)]*vec_m[indx(j,0)]-vec_m[indx(i,0)]*vec_m[indx(j,1)]; // sin(x_i - x_j)

       //cout<< arrayCos[indx2(i,j,N)]<< " ";

      }
      //cout<<endl;
    }
    k++;
  }

}
