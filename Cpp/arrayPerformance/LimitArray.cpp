#include <iostream>

using namespace std;

int main(int argc, char **argv){
//int N =1000000; // GOOD NO SEGMENTATION FAULT
int N =10000000; // BAD ==>  SEGMENTATION FAULT

//double Arr =new double[100000];
double Arr[N];
Arr[N-1]=5.0;
cout << Arr[N-1]<<endl;
return 0;
}
