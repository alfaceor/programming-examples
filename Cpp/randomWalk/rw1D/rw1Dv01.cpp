#include <stdio.h>
#include <stdlib.h>

#define FREE 0


int main(const int argc, char** argv){
  printf("#random walk 1D\n");
  // Output file
  FILE *outfile = fopen("rw1Dv01.dat", "w");
  const int Nsteps  = 100;
  const int Ntrials = 1000000;
  int x  = 0;
  int lx = 0;
  double x_mean = 0.0;
  double x_var  = 0.0;
  double x_mean_tmp = 0.0;
  double x_var_tmp  = 0.0;
  int net[Nsteps];
  for (int i=0; i<Nsteps; i++)
    net[i] = 0;

  printf("#x= %d, lx = %d\n", x, lx);
  double rnd = 0;
  for (int n=0; n < Ntrials; n++){
    x  = 0;
    lx = 0;
    for (int i=0; i < Nsteps; i++){
      // Roll a dice
      // rnd = rand();
      rnd = ((double) rand() / (RAND_MAX)); // FIXME: BAD RANDOM NUMBER GENERATOR
      // printf("%e\n", rnd);

      if (rnd < 0.5){
        x++;
        lx ++;
      }else{
        x--;
        lx ++;
      }
    }
    //printf("x= %d, lx = %d\n", x, lx);
    x_mean += x;
    x_var  += x*x;
    x_mean_tmp = x_mean/float(n);
    x_var_tmp = (x_var - x_mean_tmp*x_mean_tmp) /float(n);
    //printf("%d %f %f %d\n", n, x_mean_tmp, x_var_tmp, x);
    fprintf(outfile, "%d %f %f %d\n", n, x_mean_tmp, x_var_tmp, x);
  }
  
  fclose(outfile);
  return EXIT_SUCCESS;
  //return 0;
}
