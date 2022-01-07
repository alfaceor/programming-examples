#include <iostream>
#include <gsl/gsl_math.h>


using namespace std;

double reduceAngle(double angle){
  double modAngle = 0.0;
  modAngle= fmod(angle, 2*M_PI);
  if (modAngle < 0)  return 2*M_PI+ modAngle;
  else return modAngle;
}

int main (){
  double N=8;
  double resi  =-0.6*(2*M_PI);
  double angle = N*M_PI+resi;
  double modAngle =0.0;
  cout << resi <<endl;
  modAngle= fmod(angle, 2*M_PI);
  if (modAngle < 0)  modAngle = 2*M_PI+ modAngle;
  cout << modAngle <<endl; 
  cout << reduceAngle(angle) <<endl;
}

