#include <iostream>
#define indx(i,j,CDIM) ((i)*CDIM+j)

using namespace std;

void calcEk__T_n(double *p, double *T_n, int N){
  for (int i=0; i<N; i++){
    T_n[i] += p[i]*p[i];
  }
}

int main(int argc, char **argv){
  int N =10;
  int numberPointsRelax=4;
  
  double* p   = new double[N];
  double* T_n = new double[N*numberPointsRelax];
  double* V_n = new double[N*numberPointsRelax];
  double* u_n = new double[N*numberPointsRelax];
  
  // INITIATE TO ZERO
  for (int n=0; n< N; n++){
   p[n] = 0.1*double(n);
  }
  for (int npr=0; npr< numberPointsRelax; npr++){
    for (int n=0; n< N; n++){
     T_n[indx(npr, n, N)] = 0;
    }
  }

  // calculate T_n
  //for (int npr=0; npr< numberPointsRelax; npr++){
  //  for (int n=0; n< N; n++){
  //   T_n[indx(npr, n, N)] = T_n[indx(npr, n, N)] + p[n]*p[n];
  //  }
  //}
  
  for (int npr=0; npr< numberPointsRelax; npr++){
    calcEk__T_n(p, &T_n[indx(npr, 0, N)], N);
  }

  //
  // Print T_n
  for (int npr=0; npr< numberPointsRelax; npr++){
    for (int n=0; n< N; n++){
     cout << T_n[indx(npr, n, N)] << " ";
    }
    cout << endl;
  }

  delete [] T_n;
  delete [] V_n;
  delete [] u_n;
  
  return 0;
}
