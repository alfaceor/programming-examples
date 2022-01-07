#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double d[4];
double c[4];

double xx = pow(2.0,1.0/3.0);                                                                                                        
double x1 = 1.0/(2.0-xx);
double x0 = -xx*x1;

int main(){
c[0] = x1/2.0;    
c[1] = (x0+x1)/2.0;    
c[2] = c[1];    
c[3] = c[0];    
    
d[0] = x1;    
d[1] = x0;    
d[2] = d[0];    
d[3] = 0.0;    
  return 0;
}
