#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

#include <gsl/gsl_math.h>

using namespace std;


double PhiLJ(double delta_r2, double sigma2, double eps){
  double ri6  = (sigma2/delta_r2)*(sigma2/delta_r2)*(sigma2/delta_r2);
  double ri12 = ri6*ri6;
  return 4*eps*(ri12 - ri6);
}

double PhiWall(double x, double sigma2, double eps,double halfXlen, double rmin){
  double delta_xw;
  double delta_xw2;
  if ( x< -halfXlen){
    delta_xw=(x+halfXlen+rmin);
    delta_xw2=delta_xw*delta_xw;
    return (PhiLJ(delta_xw2, sigma2, eps)+eps);
  }else if ((-halfXlen <= x) and (x<=halfXlen)){
    return 0;
  }else if (halfXlen<x){
    delta_xw=(-x+halfXlen+rmin);
    delta_xw2=delta_xw*delta_xw;
    return PhiLJ(delta_xw2, sigma2, eps)+eps;
  }else{
    cout<<"shit**!!!!!"<<endl;
    return 0;
  }
}

int main(int argc, char* argv[]) {
  double sigma=1.0;
  double sigma2=sigma*sigma;
  double eps=0.1;
  double halfXlen=10;
  double rmin=pow(2.0,1.0/6.0);
  double x =-10.5;
  while (x<10.5){
    cout<<x<<" "
    <<PhiWall(x,sigma2, 0.1, halfXlen, rmin)<< " "
    <<PhiWall(x,sigma2, 0.5, halfXlen, rmin)<< " "
    <<PhiWall(x,sigma2, 1.0, halfXlen, rmin)<< " "
    <<endl;
    x+=0.01;
  }

}
