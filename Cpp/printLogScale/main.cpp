#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv){
  int time = 0;
  int timeStps = 10000000;
  double tau;
  double dt=0.1;
  double x = 0;
  for (int i = 0; i<=timeStps; i++){
    if ( i< 100 )
      tau = 0.1*i;
    else{
      tau = 0.1*round(40*pow(1.01,x));
      //cout <<tau <<endl;
      }
    
    if (i*dt==tau ){
      cout << tau << " " << 2 <<endl;
      x++;
    }
  }
  cout << x <<endl;

}
