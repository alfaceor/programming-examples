#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

#define BULK 0

using namespace std;
int main(const int argc, char** argv){
  printf("#random walk 2D v 01\n");
  int base10ton = 10;


  const int Nsteps  = 100;
  //const int Ntrials = 10000000;
  const int Ntrials = 1000000;

  int x = 0;
  int y = 0;

  // List of steps
  //            //----- 1st Neighbors    -----//  //-- 2nd Neighbors --//
  int dx[12] = {  1, -1,  0,  0,  1, -1,  0,  0,      1, -1, -1,  1 };
  int dy[12] = {  0,  0,  1, -1,  0,  0,  1, -1,      1,  1, -1, -1 };

  double x_mean[Nsteps];
  double y_mean[Nsteps];
  
  double x_var[Nsteps];
  double y_var[Nsteps];

  double x_mean_tmp = 0.0;
  double y_mean_tmp = 0.0;

  double x_var_tmp  = 0.0;
  double y_var_tmp  = 0.0;

  double r_var_tmp  = 0.0;

  const int dnetx=2*Nsteps+1;
  const int dnety=2*Nsteps+1;
  int net[dnetx][dnety]; // Two dimensional net
  
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
        //printf("1 ");
        if ( net[x+1][y] == BULK) { x++; } else ns--;
      }else if ( rnd < 0.5){
        //printf("2 ");
        if ( net[x-1][y] == BULK) { x--; } else ns--;
      }else if ( rnd < 0.75){
        //printf("3 ");
        if ( net[x][y+1] == BULK) { y++; } else ns--;
      }else{
        //printf("4 ");
        if ( net[x][y-1] == BULK) { y--; } else ns--;
      }

      x_mean[ns] += x;
      y_mean[ns] += y;

      x_var[ns] += x*x;
      y_var[ns] += y*y;

      //if (true)
      //  fprintf(ofile, "%d %d %d\n", ns, x, y);
    }
    
    //if (true){
    if ( (nt+1) % base10ton == 0 ){
      base10ton *= 10;
      // Output file
      stringstream ssOfln;
      string outfilename;
      ssOfln << "rw2D__Trials_" << nt+1 << ".dat";
      outfilename = ssOfln.str();
      FILE *ofile = fopen(outfilename.c_str(), "w");
      fprintf(ofile, "#nt x y x_var y_var r_var\n");
      for (int ns=0; ns < Nsteps; ns++){
        x_mean_tmp = x_mean[ns]/float(nt+1);
        y_mean_tmp = y_mean[ns]/float(nt+1);
        x_var_tmp = (x_var [ns]/float(nt+1)- x_mean_tmp*x_mean_tmp);
        y_var_tmp = (y_var [ns]/float(nt+1)- y_mean_tmp*y_mean_tmp);
        fprintf(ofile, "%d %e %e %e %e %e\n", ns, x_mean_tmp, y_mean_tmp, x_var_tmp, y_var_tmp, x_var_tmp + y_var_tmp );
      }
      // Before close
      fprintf(ofile, "##############\n");
      fprintf(ofile, "#Nsteps  = %d \n", Nsteps);
      fprintf(ofile, "#Ntrials = %d \n", nt+1);
      fprintf(ofile, "##############\n");
      fclose(ofile);
    }
  }
  
  return EXIT_SUCCESS;
  //return 0;
}
