#include <iostream>

using namespace std;

int main(int argc, char **argv){
  int N = 8192;
  int numberPointsRelax=100;

  double T_n[numberPointsRelax][N];
  double V_n[numberPointsRelax][N];
  double p[N];

  for (int n=0; n< N; n++){
    p[n] = 0.1*double(n);
  }

  // INITIATE TO ZERO
  for (int npr=0; npr< numberPointsRelax; npr++){
    for (int n=0; n< N; n++){
     T_n[npr][n] = 0;
    }
  }

  for (int npr=0; npr< numberPointsRelax; npr++){
    for (int n=0; n< N; n++){
     T_n[npr][n] = T_n[npr][n] + p[n]*p[n];
    }
  }

  //for (int npr=0; npr< numberPointsRelax; npr++){
  //  for (int n=0; n< N; n++){
  //   cout << T_n[npr][n] << " ";
  //  }
  //  cout << endl;
  //}

  return 0;
}

