#include <stdio.h>

int main (){
  printf("Do While comparision\n");
  int a=0;
  while (a < 10){
    a++;
  }
  printf("While = %d\n", a);

  a=0;
  do {
    a++;
  }while (a < 10);
  printf("Do While = %d\n", a);
  return 0;
}
