#include <stdio.h>
#include <stdlib.h>

#define FREE 0


int main(const int argc, char** argv){
  printf("#random walk 1D v 02\n");
  // Output file
  FILE *outfile = fopen("rw1Dv02.dat", "w");
  const int Nsteps  = 10000;
  const int Ntrials = 1000;
  int x  = 0;
  int lx = 0;
  double x_mean = 0.0;
  double x_var  = 0.0;
  double x_mean_tmp = 0.0;
  double x_var_tmp  = 0.0;
  const int dnet=2*Nsteps+1;
  int net[dnet]; // One dimensional net
  for (int i=0; i<dnet; i++)
    net[i] = 0;

  printf("#x= %d, lx = %d\n", x, lx);
  double rnd = 0;
  for (int nt=0; nt < Ntrials; nt++){
    //In position i ==> net[i]
    x  = Nsteps;
    lx = 0;
    for (int ns=0; ns < Nsteps; ns++){
      // Roll a dice
      rnd = ((double) rand() / (RAND_MAX));
      if (rnd < 0.5){
        // Is possible
        if ( net[x+1] == 0) x++;
        else ns--;
      }else{
        if ( net[x-1] == 0) x--;
        else ns--;
      }
    }
    //printf("x= %d, lx = %d\n", x, lx);
    x_mean += x;
    x_var  += x*x;
    x_mean_tmp = x_mean/float(nt);
    x_var_tmp = (x_var - x_mean_tmp*x_mean_tmp) /float(nt);
    //printf("%d %f %f %d\n", n, x_mean_tmp, x_var_tmp, x);
    fprintf(outfile, "%d %f %f %d\n", nt, x_mean_tmp, x_var_tmp, x);
  }
  
  fclose(outfile);
  return EXIT_SUCCESS;
  //return 0;
}
