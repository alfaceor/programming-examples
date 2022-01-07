#include <stdio.h>

void functionReference(int *var){
  *var = 5;
}

int main(){
  int *a;
  *a = 3;
  printf("a = %d\n", *a);
  //int b;
  //b = 3;
  //functionReference(&b);
  //printf("b = %d\n", b);

  return 0;
}
