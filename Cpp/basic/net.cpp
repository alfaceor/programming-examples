#include <stdio.h>


int main(){
  int x=0;

  const int dnet = 10;
  int net[dnet] = { 1, 1, 1, 0, 0,  1, 0, 1, 0, 0 };
  int indx = 0;
  for (int i=-15; i< 20; i++){
    if (i ==  0 ) printf("-------\n");
    if (i == 10 ) printf("-------\n");
    indx = i%dnet;
    if ( indx < 0 ) indx = indx + dnet;
    printf("%d %d %d\n", net[indx], i, indx);
  }
  return 0;
}
