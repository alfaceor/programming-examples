// Objective: Save points every 1.1^power
#include <stdio.h>
#include <stdlib>

using namespace std;

int main(int argc, char *argv[]){
  int numberPointsTrans = 0;
  int numberPointsRelax = 0;
  double tau = 0;
  int    x = 0;
  for (int i = 0; i<=io.timeTransient; i++){
    if ( i< 100 )
      tau = 0.1*i;
    else{
      tau = 0.1*round(40*pow(1.01,x));
      }   
            
    if (i*io.dt==tau ){
      x++;
      numberPointsTrans++;
    }   
  }

  return EXIT_SUCCESS;
}

