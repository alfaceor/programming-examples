#include <stdio.h>
#include <stdlib.h>
#include <gsl/gsl_histogram.h>

int
main (int argc, char **argv)
{
  double a, b;
  a =  -0.5;// atof (argv[1]);
  b =   10.5;// atof (argv[2]);
  size_t n;
  n =   11;// atoi (argv[3]);
  const int Nrmn = 20;

  FILE *ofileHis = fopen("IntegerHistogram.his", "w");
  double x;
  gsl_histogram * h = gsl_histogram_alloc (n);
  gsl_histogram_set_ranges_uniform (h, a, b);

  for (int i=0; i<Nrmn; i++ ){
    x = (rand() % 10) + 1 - 10 ; 
    if (x < 0) printf ("%g", x );
    gsl_histogram_increment (h, x);
  }
  bool flag = false;
  if ( flag ){
    gsl_histogram_fprintf (ofileHis, h, "%g", "%g");
  }else{
    // fprintf(ofileHis, "------------------\n");
    double sum = gsl_histogram_sum(h);
    printf("sum = %g\n", sum);
    if (sum > 0.0)  gsl_histogram_scale(h, 1.0 / sum);
    gsl_histogram_fprintf (ofileHis, h, "%g", "%g");
  }

  gsl_histogram_free (h);
  fclose(ofileHis);

  return 0;
}

