#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv){
  int N=100;
  int transiente;
  double dt = 0.01;
  cout << "pow(N,1.7)/dt             = " << pow(N,1.7)/dt <<endl;
  cout << "round(pow(N,1.7)/dt)      = " << round(pow(N,1.7)/dt)  <<endl;
  cout << "int(round(pow(N,1.7)/dt)) = " << int(round(pow(N,1.7)/dt)) <<endl;
  cout << pow(N,1.7) <<endl;
  cout << "fasdf" <<endl;
}

