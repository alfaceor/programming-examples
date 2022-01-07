// test of Fast Fourier Transform package FFTW3.h
//#include </opt/intel/composer_xe_2013_sp1.3.174/mkl/include/fftw/fftw3.h>
#include <fftw3.h>
#include <stdio.h>
#include <math.h>

int main()
{
   double inforward[6][8]={{8.4155184, 5.6186607, 3.8737788, 2.6157615, 2.2563035, 0.9115739, 1.2059959, 6.4885629},{4.0620248, 5.8961773, 9.2228987, 4.9934938, 6.2740931, 8.3003166, 2.8553642, 9.9231909},{4.0948255, 6.8539797, 9.4881843, 2.6385784, 7.6084326, 5.8787202, 8.6075146, 0.5004198},{8.7841258, 8.9062247, 3.4353372, 5.2535631, 0.4855662, 4.8291793, 8.4941017, 7.4855066},{1.1383597, 5.0422128, 3.7601187, 5.3762298, 6.7239497, 2.232865, 5.2570608, 4.104059},{1.9983377, 3.4936154, 7.3409406, 1.1999255, 2.0171727, 8.4008857, 9.9312099, 6.0845263}};

   double outforward[6][8][2];
   double outbackward[6][8][2];

   const int N0 = 6;
   const int N1 = 8;
   int n0;
   int n1;

   // forward transform
   fftw_complex *in, *out;
   fftw_plan pf, pb;
   
   in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N0*N1);
   out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N0*N1);

   // plan for forward transform
   pf = fftw_plan_dft_2d(N0,N1,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
   // plan for backward transform
   pb = fftw_plan_dft_2d(N0,N1,in,out,FFTW_BACKWARD,FFTW_ESTIMATE);
  
   // initialize input vector in
   for(n0=0;n0<N0;n0++) {
      for(n1=0;n1<N1;n1++) {
         in[n0*N1+n1][0] = inforward[n0][n1];
         in[n0*N1+n1][1] = 0.0;
      }
   }
   
   fftw_execute(pf); // repeat as needed
   
   for(n0=0;n0<N0;n0++) {
      for(n1=0;n1<N1;n1++) {
         outforward[n0][n1][0] = out[n0*N1+n1][0];
         outforward[n0][n1][1] = out[n0*N1+n1][1];
      }
   }

   
   // backward transform

   // initialize input vector in

   for(n0=0;n0<N0;n0++) {
      for(n1=0;n1<N1;n1++) {
         in[n0*N1+n1][0] = outforward[n0][n1][0];
         in[n0*N1+n1][1] = outforward[n0][n1][1];
      }
   }
   
   fftw_execute(pb); // repeat as needed
   
   double normalize=1./(N0*N1);
   for(n0=0;n0<N0;n0++) {
      for(n1=0;n1<N1;n1++) {
         outbackward[n0][n1][0] = out[n0*N1+n1][0]*normalize;
         outbackward[n0][n1][1] = out[n0*N1+n1][1]*normalize;
      }
   }

   fftw_destroy_plan(pf);
   fftw_destroy_plan(pb);
   fftw_free(in);
   fftw_free(out);

   for(n0=0;n0<N0;n0++) {
      for(n1=0;n1<N1;n1++) {
         printf("%f",outbackward[n0][n1][0]);
         printf(" + ");
         printf("%f",outbackward[n0][n1][1]);
         printf("i");
         printf(", ");
      }
      printf("\n");
   }



   return 0;
}
