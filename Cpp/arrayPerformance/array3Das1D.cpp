#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define INDX(I,J,K) (I*UcellxSize*UcellySize + J*UcellySize + K)
using namespace std;
int main(const int argc, char** argv){
  int Nsize = atoi(argv[1]);
  const int UcellxSize = Nsize;
  const int UcellySize = Nsize;
  const int UcellzSize = Nsize;

  //cout << Nsize <<" "<< UcellzSize <<endl;

  const clock_t begin_time = clock();
  int *net = new int[UcellxSize*UcellySize*UcellzSize]; // Three dimensional net
  for (int i =0; i<UcellxSize; i++) 
    for (int j =0; j<UcellySize; j++)
      for (int k =0; k<UcellzSize; k++)
        net[INDX(i,j,k)] = i*UcellxSize*UcellySize + j*UcellySize + k;   
  cout<< Nsize << " "<< float(clock() - begin_time)/CLOCKS_PER_SEC<< " "<< net[1*UcellxSize*UcellySize+3*UcellySize+ 5] << endl;
  delete [] net;
  return 0;
}
