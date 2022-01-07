#include <iostream>

#include "Ring.h"
using namespace std;

int main(int argc, char **argv ){
  cout << "HMF Relax" << endl;
  int N=16;
  Ring r(N);
  cout<< r.getParams()<<endl;
  return 0;
}
