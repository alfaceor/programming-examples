#include<stdio.h>

void funcXXX(double *pointer){
  *pointer = *pointer+2.4;
}

void funcYYY(double *pointer){
  *pointer = 10.*(*pointer);
  funcXXX(pointer);
}

int main(){
  double *pointer;
  double a = 5.0;
  //int a = 5;
  *pointer = 6.0;
  //printf("memory: a =%d, pointer=%d",&a,pointer);
  printf("%f\n",*pointer);
  //funcXXX(pointer);
  funcYYY(pointer);
  printf("%f\n",*pointer);

}
