#include <iostream>
#include <math.h>

using namespace std;

inline bool print(int tt, double dt, int x){
  if ( tt< 100 )
    return tt*dt == 0.1*tt;
  else
    return tt*dt == 0.1*round(40*pow(1.01,x));
}

int main(int argc, char **argv){
  int totalSteps = 1000;
  int tt = 0;
  int x  = 0;
  double dt = 0.1;
  while (tt < totalSteps){
    if (print(tt, dt, x) ){
      cout << ""<< tt << " " << x << " " << tt*dt <<endl;
      x++;
    }
    tt++;
  }
}
