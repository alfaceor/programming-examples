#include <iostream>

using namespace std;

int main(int argc, char **argv){
//int N =1000000; // GOOD NO SEGMENTATION FAULT
int N =2000000000; // BAD ==>  SEGMENTATION FAULT

//double Arr =new double[100000];
double* Arr = new double[N];
double* T_n = new double[N];
double* V_n = new double[N];
double* u_n = new double[N];
Arr[N-1]=5.0;
cout << Arr[N-1]<<endl;

delete [] Arr;
delete [] Arr;
delete [] T_n;
delete [] V_n;
delete [] u_n;

return 0;
}
