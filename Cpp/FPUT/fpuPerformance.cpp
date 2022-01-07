#include <iostream>

using namespace std;


void printArr(double *q, int N){
  for (int i=0; i<N; i++){
    cout << q[i] << " ";
  }
  cout << endl;
}

void zerosArr(double *q, int N){
  for (int i=0; i<N; i++){
    q[i] = 0.0;
  }
}

void initArr(double *q, int N){
  int M = N/2;
  double factor= 1/double(N);
  for (int i=0; i<N; i++){
    q[i] = q[i] + factor*double(i % M);
  }
}

void calcForce(double *force, double *deltaQ3, double *deltaQ2, double *deltaQ, double *q, int N){
  double fij =0.0;
  int l =0;
  zerosArr(force,N);
  printArr(force,N);
  for (int i=0; i<N-1; i++){
    l = i+1;
    deltaQ[i]   = q[l] - q[i];
    deltaQ2[i]  = deltaQ[i]*deltaQ[i];
    deltaQ3[i]  = deltaQ2[i]*deltaQ[i];
    fij =  0.5*( deltaQ[i] + 0.1*deltaQ3[i]);
    force[i] +=  fij;
    force[l] += -fij;
  }
  int i = N-1;
  l = 0;
  deltaQ[i] = q[l] - q[i];
  deltaQ2[i]  = deltaQ[i]*deltaQ[i];
  deltaQ3[i]  = deltaQ2[i]*deltaQ[i];
  fij =  0.5*( deltaQ[i] + 0.1*deltaQ3[i]);
  force[i] +=  fij;
  force[l] += -fij;
  printArr(force,N);
}



int main(int argc, char **argv){
  int N =128;
  double q[N];
  double deltaQ[N];
  double deltaQ2[N];
  double deltaQ3[N];
  double force[N];

  zerosArr(q, N);
  zerosArr(deltaQ, N);
  zerosArr(deltaQ2, N);
  zerosArr(deltaQ3, N);
  zerosArr(force, N);
  initArr(q, N);
  printArr(q, N);
  calcForce(force, deltaQ3, deltaQ2, deltaQ, q, N);
  printArr(force, N);
}
