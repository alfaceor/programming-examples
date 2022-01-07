#include <stdio.h>


int main(){
  int x=0;
  for (int i=0; i< 10; i++){
    if (x == 0) i--; 
    if (x == 9) i--; 
    x++;
    printf("%d %d\n", x, i);
  }
  return 0;
}
