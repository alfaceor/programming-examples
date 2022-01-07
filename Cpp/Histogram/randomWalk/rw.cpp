#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_histogram.h>
#define NSTEPS 107196579
#define NP2SAVE 180 
#define TIME2SAVE { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 26, 28, 31, 34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 117, 129, 142, 156, 172, 189, 208, 229, 252, 277, 304, 335, 368, 405, 446, 490, 539, 593, 653, 718, 790, 869, 956, 1051, 1156, 1272, 1399, 1539, 1693, 1862, 2048, 2253, 2479, 2726, 2999, 3299, 3629, 3992, 4391, 4830, 5313, 5844, 6429, 7072, 7779, 8557, 9412, 10354, 11389, 12528, 13781, 15159, 16675, 18342, 20176, 22194, 24413, 26855, 29540, 32494, 35743, 39318, 43249, 47574, 52332, 57565, 63322, 69654, 76619, 84281, 92709, 101980, 112178, 123396, 135735, 149309, 164240, 180664, 198730, 218603, 240463, 264510, 290961, 320057, 352063, 387269, 425996, 468595, 515455, 567000, 623700, 686070, 754677, 830145, 913160, 1004475, 1104923, 1215415, 1336957, 1470653, 1617718, 1779490, 1957439, 2153182, 2368501, 2605351, 2865886, 3152474, 3467722, 3814494, 4195943, 4615538, 5077092, 5584801, 6143281, 6757609, 7433370, 8176707, 8994377, 9893815, 10883197, 11971516, 13168668, 14485535, 15934088, 17527497, 19280247, 21208271, 23329099, 25662008, 28228209, 31051030, 34156133, 37571747, 41328921, 45461813, 50007995, 55008794, 60509674, 66560641, 73216705, 80538375, 88592213, 97451434, 107196578 }; 


#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967295 //4294967296 


int
main (int argc, char **argv)
{
  // const int Nsteps       = NSTEPS;
  const int Nsteps  =  10000;
  const int Ntrials = 100000;

  FILE *ofileHis = fopen("rw.his", "w");
  unsigned int rnd = 0;
  int x   = 0;
  int binrnd = 0;
  gsl_histogram * h = gsl_histogram_alloc (2*Nsteps+1);
  gsl_histogram_set_ranges_uniform (h, -Nsteps-0.5, Nsteps+0.5);
  gsl_histogram_fprintf (stdout , h, "%g", "%g");

  for (int nt=0; nt<Ntrials; nt++ ){
    x = 0;
    printf("nt = %d\n",nt);
    for (int ns=0; ns<Nsteps; ns++ ){
      rnd    = (MULTIPLIER *rnd + INCREMENT) % MODULUS;
      binrnd = rnd >> 31;
      ( binrnd == 0 )? x-- : x++; 
      // printf("rnd = %10u, binrnd = %4d, x = %10d \n", rnd, binrnd, x);
      if (ns == 1000)
        // printf("x = %d", x);
        gsl_histogram_increment (h, x);
    }
  }

  // fprintf(ofileHis, "------------------\n");
  double sum = gsl_histogram_sum(h);
  printf("sum = %g\n", sum);
  if (sum > 0.0)  gsl_histogram_scale(h, 1.0 / sum);
  gsl_histogram_fprintf (ofileHis, h, "%g", "%g");

  gsl_histogram_free (h);
  fclose(ofileHis);

  return 0;
}

