#include <iostream>
#include <sstream>
#include <string>



using namespace std;

string printArray(double *array, int N){
  string strReturn;
  stringstream sstm;
  sstm << "--------------" <<endl;
  for (int i=0; i<N; i++){
    sstm << i <<" "<< array[i] <<endl;
  }
  strReturn = ""+sstm.str();
  return strReturn;
}

void add2Array(double *array, int N, double value){
  for (int i=0; i<N; i++){
    array[i] = array[i] + value;
  }
}

void funcFunc(double *array, int N){
  
  add2Array(array,N,7);
  cout << printArray(array, N) <<endl;
}

void funcFuncFunc(double *array, int N){
  cout<< "funcFuncFunc"  << endl;
  funcFunc(array, N);
  funcFunc(array, N);
}

int main(){
  int const N=10;
  double *pointer;
  pointer = new double[N];
  for (int i=0; i<N; i++){
    pointer[i] = 10.0*i;
  }

  //add2Array(pointer, N, 7);
  cout << printArray(pointer, N)<<endl;
  //funcFunc(pointer, N);
  funcFuncFunc(pointer, N);
}
