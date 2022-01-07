#include <stdio.h>
#include <stdlib.h>

#define BULK 0


int main(const int argc, char** argv){
  printf("#random walk 2D v 01\n");
  //printf("hello\n");
  // Output file
  FILE *outfile = fopen("rw2Dv01.dat", "w");
  fprintf(outfile, "#nt x_mean_tmp y_mean_tmp x_var_tmp y_var_tmp r_var_tmp x y\n");

  const int Nsteps  = 100;
  //const int Ntrials = 10000000;
  const int Ntrials = 1;

  int x  = 0;
  int y  = 0;

  double x_mean = 0.0;
  double y_mean = 0.0;
  
  double x_var  = 0.0;
  double y_var  = 0.0;

  double x_mean_tmp = 0.0;
  double y_mean_tmp = 0.0;

  double x_var_tmp  = 0.0;
  double y_var_tmp  = 0.0;

  double r_var_tmp  = 0.0;

  const int dnetx=2*Nsteps+1;
  const int dnety=2*Nsteps+1;
  int net[dnetx][dnety]; // Two dimensional net
  //
  // DEFINE THE NETWORK
  for (int i=0; i<dnetx; i++)
    for (int j=0; j<dnety; j++)
      net[i][j] = 0;

  //printf("#x= %d, lx = %d\n", x, lx);
  double rnd = 0;
  for (int nt=0; nt < Ntrials; nt++){
    //In position i ==> net[i]
    x  = Nsteps;
    y  = Nsteps;
    for (int ns=0; ns < Nsteps; ns++){
      // Roll a dice and choose a direction between 1 to 4 first neighbors
      rnd = ((double) rand() / (RAND_MAX));
      // rnd = ( rand()%4); 

      if (rnd < 0.25){
        if ( net[x+1][y] == BULK) { x++; } else ns--;
      }else if ( rnd < 0.5){
        if ( net[x-1][y] == BULK) { x--; } else ns--;
      }else if ( rnd < 0.75){
        if ( net[x][y+1] == BULK) { y++; } else ns--;
      }else{
        if ( net[x][y-1] == BULK) { y--; } else ns--;
      }
    }
    //printf("x= %d, lx = %d\n", x, lx);
    x_mean += x;
    y_mean += y;

    x_var  += x*x;
    y_var  += y*y;

    x_mean_tmp = x_mean/float(nt+1);
    y_mean_tmp = y_mean/float(nt+1);

    x_var_tmp = (x_var /float(nt+1)- x_mean_tmp*x_mean_tmp);
    y_var_tmp = (y_var /float(nt+1)- y_mean_tmp*y_mean_tmp);

    //printf("%d %f %f %d\n", n, x_mean_tmp, x_var_tmp, x);
    if (nt%1000 == 0)
      fprintf(outfile, "%d %f %f %f %f %f %d %d\n", nt+1, x_mean_tmp, y_mean_tmp, x_var_tmp, y_var_tmp, x_var_tmp + y_var_tmp,  x, y);
  }
  
  fclose(outfile);
  return EXIT_SUCCESS;
  //return 0;
}
