#include <stdio.h>
#define  TIMESINIT { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 26, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 117, 129, 142, 156, 172, 189, 208, 229, 252, 277, 304, 335, 368, 405, 446, 490, 539, 593, 653, 718, 790, 869, 956, 1051 }; 


void printf_array_int(int *arr, const int dim){
  for (int i=0; i < dim; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void printf_array_double(double *arr, const int dim){
  for (int i=0; i < dim; i++)
    printf("%g ", arr[i]);
  printf("\n");
}

int main(int argc, char *argv[]){

  const int Np2save = 59 ;
  int time2save[Np2save] = TIMESINIT; // { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 26, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 117, 129, 142, 156, 172, 189, 208, 229, 252, 277, 304, 335, 368, 405, 446, 490, 539, 593, 653, 718, 790, 869, 956, 1051 }; 
  const int N = 15;
  double arr01[N] = {0.0};
  printf_array_double(arr01, N);
  printf_array_int(time2save,Np2save);
  return 0;
}
