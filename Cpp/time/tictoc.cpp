#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]){
  time_t tstart, tend;
  tstart = time(0);
  int product=1;
  for (int i = 0; i<1000000000; i++){
    product = product*i;
  }
  tend = time(0);
  double deltat = difftime(tend,tstart);
  printf("deltaT = %lf\n",deltat);
}
