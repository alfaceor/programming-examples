#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

// ----------------------- //
void init_theta(double *theta, const int N){
  for (int i=0; i<N; i++){
    theta[i] = (i+0.5) * M_PI / N; // * ((float) i)/N ;
  }
}

// ----------------------- //
void calc_Trigo(double *theta, double *cosq, double *sinq, const int N){
  for (int i=0; i<N; i++){
    cosq[i] = cos(theta[i]);
    sinq[i] = sin(theta[i]);
  }
}

// ----------------------- //
void printf_array(double *arr, const int N){
  for (int i = 0; i < N; i++)
    //printf("%g ", arr[i]);
    //printf("i = %d, %g\n", i, arr[i]);
    printf("%d %g\n", i, arr[i]);
  printf("\n");
}

// ----------------------- //
void printf_arrayComplex(fftw_complex *arr, const int N){
  for (int i = 0; i < N; i++){
    //printf("%g ", arr[i]);
    //printf("i = %d, %g\n", i, arr[i]);
    printf("%d %g\t", i, arr[i][0]);
    if (arr[i][1] < 0){
      printf("-i %g\n", i, abs(arr[i][1]));
    }else{
      printf("+i %g\n", i, abs(arr[i][1]));
    }
  }
  printf("\n");
}
// ----------------------- //
void calc_v(double *v_alpha, const int Npart, const double alpha){
  v_alpha[0] = 0.0;
  for (int i=1; i < Npart/2; i++){
    v_alpha[i] = pow(i, -alpha);
  }
  for (int i=Npart/2; i < Npart; i++){
    v_alpha[i] = pow(Npart-i, -alpha);
  }
}

// ----------------------- //
void force_brutal(double *theta, double *force, const int N, const double alpha){
  double sum_VijSinj = 0.0;
  double sum_VijCosj = 0.0;
  int aux = 0;
  printf("#VijSinj\tVijCosj\n");
  for (int i=0; i< N; i++){
    force[i]    = 0.0;
    sum_VijCosj = 0.0;
    sum_VijSinj = 0.0;
    for (int j=0; j< N; j++){
      if ( i != j){
        aux = abs(i-j);
        if (aux <= N/2){
          sum_VijSinj += pow(aux, -alpha)*sin(theta[j]);
          sum_VijCosj += pow(aux, -alpha)*cos(theta[j]);
        }else{
          aux = (N - aux);
          sum_VijSinj += pow(aux, -alpha)*sin(theta[j]);
          sum_VijCosj += pow(aux, -alpha)*cos(theta[j]);
        }
      }
    }
    printf("%g  \t  %g\n", sum_VijSinj, sum_VijCosj);
    force[i] = cos(theta[i])*sum_VijSinj - sin(theta[i])*sum_VijCosj;
  }
  printf("++++++++++++++++++++++++\n");
}

// ----------------------- //
void fft(fftw_complex *in, fftw_complex *out, const int N){
  // Define a DFT plan
  fftw_plan pf = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(pf);
  fftw_destroy_plan(pf);
  fftw_cleanup();
} 

// ----------------------- //
void ifft(fftw_complex *in, fftw_complex *out, const int N){
  // Define a DFT plan
  fftw_plan pf = fftw_plan_dft_1d(N, in, out, FFTW_BACKWARD, FFTW_ESTIMATE);
  fftw_execute(pf);
  fftw_destroy_plan(pf);
  fftw_cleanup();
  for (int i=0; i<N; i++){
    in[i][0] = in[i][0]/N;
    in[i][1] = in[i][1]/N;
  }
} 

// ----------------------- //
void calc_Lambda(fftw_complex *Lambda, double alpha, const int N){
  double v_alpha [N] = {0.0};
  // double *v_alpha;
  // v_alpha  = (double*) malloc(sizeof(double)*N);
  calc_v(v_alpha, N, alpha);
  printf("-------- v_alpha --------\n");
  printf_array(v_alpha, N);

  for (int j=0; j<N; j++){
    Lambda[j][0] = 0.0;
    Lambda[j][1] = 0.0;
    for (int k=0; k<N; k++){
      Lambda[j][0] += v_alpha[k]*cos(2.0*M_PI*j*k/ (double) N) ; // Real
      Lambda[j][1] += v_alpha[k]*sin(2.0*M_PI*j*k/ (double) N) ; // Imag
    }
    printf("Lambda_[%d]: %g\t+%g i\n",j, Lambda[j][0], Lambda[j][1]); 
  }
  //free(v_alpha);
}
// ----------------------- //
void calc_ForceFFTw(double *force, double *cosq, double *sinq, fftw_complex *Lambda, const int N){
  double cosISumJ = 0.0;
  double sinISumJ = 0.0;
  for (int i=0; i<N; i++) force[i] = 0.0;
  
  // Fourier Transform sinq and cosq
  fftw_complex  *inpSin, *outSin, *inpCos, *outCos;
  inpSin = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
  inpCos = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
  outSin = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
  outCos = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
  
  fftw_plan pfSin = fftw_plan_dft_1d(N, inpSin, outSin, FFTW_FORWARD,  FFTW_ESTIMATE);
  fftw_plan pfCos = fftw_plan_dft_1d(N, inpCos, outCos, FFTW_FORWARD,  FFTW_ESTIMATE);
   
  for (int i=0; i<N; i++){
    inpSin[i][0] = sinq[i];
    inpSin[i][1] = 0.0;
    inpCos[i][0] = cosq[i];
    inpCos[i][1] = 0.0;
  }
  printf("========== inpsin =========\n");
  printf_arrayComplex(inpCos, N);
  
  fftw_execute(pfSin);
  fftw_execute(pfCos);
  printf("==========  FOURIER TRANSFORM ======== \n");
  printf_arrayComplex(outCos, N);

  // You must create the plan before initializing the input, because FFTW_MEASURE overwrites the in/out arrays 
  fftw_plan pbSin = fftw_plan_dft_1d(N, inpSin, outSin, FFTW_BACKWARD, FFTW_ESTIMATE);
  fftw_plan pbCos = fftw_plan_dft_1d(N, inpCos, outCos, FFTW_BACKWARD, FFTW_ESTIMATE);

  for (int j=0; j<N; j++){
    inpSin[j][0] = ( Lambda[j][0]*outSin[j][0] - Lambda[j][1]*outSin[j][1]) / N;
    inpSin[j][1] = ( Lambda[j][0]*outSin[j][1] + Lambda[j][1]*outSin[j][0]) / N;
    inpCos[j][0] = ( Lambda[j][0]*outCos[j][0] - Lambda[j][1]*outCos[j][1]) / N;
    inpCos[j][1] = ( Lambda[j][0]*outCos[j][1] + Lambda[j][1]*outCos[j][0]) / N;
   // inpSin[j][0] = ( outSin[j][0]) / N;
   // inpSin[j][1] = ( outSin[j][1]) / N;
   // inpCos[j][0] = ( outCos[j][0]) / N;
   // inpCos[j][1] = ( outCos[j][1]) / N;
  }
  
  fftw_execute(pbSin);
  fftw_execute(pbCos);

  printf("==========  INVERSE FOURIER TRANSFORM ======== \n");
  printf_arrayComplex(outCos, N);
  
  printf("==========  VERIFY THIS SHITTRANSFORM ======== \n");
  for (int i=0; i<N; i++){
    printf("%g  \t  %g\n", outSin[i][0], outCos[i][0]);
    force[i] = cosq[i]*outSin[i][0] - sinq[i]*outCos[i][0] ;
  }

  fftw_free(inpSin);
  fftw_free(inpCos);
  fftw_free(outSin);
  fftw_free(outCos);
  fftw_destroy_plan(pfSin);
  fftw_destroy_plan(pfCos);
  fftw_destroy_plan(pbSin);
  fftw_destroy_plan(pbCos);
  // fftw_cleanup_threads();
  fftw_cleanup();
}
// ----------------------- //
int main()
{
   double alpha        = 1.0;
   const int Npart     = 8;
   double theta[Npart] = {0.0};
   double force[Npart] = {0.0};
   
   init_theta(theta, Npart);
   printf("-- theta --\n");
   printf_array(theta, Npart);

   double cosq    [Npart] = {0.0};
   double sinq    [Npart] = {0.0};
   //double Lambda  [Npart] = {0.0};
   calc_Trigo(theta, cosq, sinq, Npart);
   printf_array(cosq, Npart);
   printf_array(sinq, Npart);

   // calc to verify 
   force_brutal(theta, force, Npart, alpha); 
   printf("------ force_brutal ------\n");
   printf_array(force, Npart);

   // ======================================================================== //
   printf("====================================\n");
   fftw_complex *Lambda;
   Lambda  = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*Npart);
   calc_Lambda(Lambda, alpha, Npart);
   calc_ForceFFTw(force, cosq, sinq, Lambda, Npart);
   printf("------ ForceFFTw ------ \n");
   printf_array(force, Npart);

   fftw_free(Lambda);
   
   return EXIT_SUCCESS;
}
