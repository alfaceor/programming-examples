#include <iostream>
#include <gsl/gsl_math.h>
using namespace std;

int main(){
  int const N=1000000;
  int const M=1000;
  double q[N];
  //q = new double[N];
  #pragma omp parallel for
  for (int i=0; i<N; i++){
    q[i] = 1.1*i;
    // q[i] =0.0;
    // for (int j=0; j<M; j++){
    //   q[i] = q[i]*cos(0.01*i*j);
    // }
  }
  for (int i=0; i<N; i++){
    cout<<q[i]<<endl;
  }
  return 0;
}
