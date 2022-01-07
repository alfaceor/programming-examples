#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NPARTS 512

void printf_array(double *q, const int Np){
  for (int i=0; i<Np; i++){
    printf("%g ", q[i] );
  }
  printf("\n");
}

void init_equal_space(double *q, const int Np){
  double delta_q = M_PI/ Np ;
  for (int i=0; i<Np; i++){
    //printf("%g ", 2.0*M_PI/ i );
    q[i] = (i+0.5)*delta_q ;
  }
}

void cos_sin_q_array(double *q, const int Np, double *cosq, double *sinq){
  double sum = 0.0;
  for (int i=0; i<Np; i++){
    cosq[i] = cos(q[i]) ;
    sinq[i] = sin(q[i]) ;
  }
}

int main(){
  printf("Fast Fourier Transform\n");
  double q[NPARTS] = {0};
  double cosq[NPARTS] = {0};
  double sinq[NPARTS] = {0};
  cos_sin_q_array(q, NPARTS, cosq, sinq);
  printf_array(cosq, NPARTS);
  printf_array(sinq, NPARTS);
  //printf("sum_cos = %g\n", sum_cos_array(q, NPARTS));
  //printf("sum_sin = %g\n", sum_sin_array(q, NPARTS));

  return EXIT_SUCCESS;
}
