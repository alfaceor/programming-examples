#include <stdio.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_histogram.h>

#define FREE 0
#define HARD 1
#define BORD 2

#define INDX(I,J,K) (I*UcellxSize*UcellySize + J*UcellySize + K)

int main(int argc, char* argv[]){

  //============================================================//
  const int Ntrials = 1000;
  int       Hradius = 10;
  int       Bradius = 11;

  const int Radius          = Hradius; //10;
  const int UcellxSize      = (2*(Radius)+1); // + 1;      
  const int UcellySize      = (2*(Radius)+1); // + 1;      
  const int UcellzSize      = (2*(Radius)+1); // + 1;      

  printf("# UcellxSize = %d, UcellySize = %d, UcellzSize = %d\n", UcellxSize, UcellySize, UcellzSize);
  
  
  // DEFINE THE NETWORK
  int currentPos = FREE;
  int nextPos    = FREE;
  int curr2next  = 10*currentPos + nextPos; // JUST TO GET A NOTATION USING MACROS
  
  int *net = new int[UcellxSize*UcellySize*UcellzSize]; // Three dimensional net
  for (int i =0; i<UcellxSize; i++)
    for (int j =0; j<UcellySize; j++)
      for (int k =0; k<UcellzSize; k++)
        net[INDX(i,j,k)] = 0;   


  int border=1;
  //int r2  =  Radius*Radius;
  //int r2b = (Radius+border)*(Radius+border);
  int r2  = Hradius*Hradius; 
  int r2b = Bradius*Bradius; //  (Radius+border)*(Radius+border);
  int r2test = 0;

  // Circle 
  int cx = Radius;
  int cy = Radius;
  int cz = Radius;

  for (int i= 0 ; i < UcellxSize; i++){
    for (int j=0 ; j < UcellySize; j++){
      for (int k=0 ; k < UcellzSize; k++){
        // net[i][j] = FREE;
        r2test = (i - cx)*(i - cx) + (j - cy)*(j - cy) + (k-cz)*(k-cz);
        if       ( r2test <= r2  )    net[INDX(i,j,k)] = HARD;
        else  if ( r2test  > r2b )    net[INDX(i,j,k)] = FREE;
        else                          net[INDX(i,j,k)] = BORD;
      }
    }
  }

  //============================================================//

  int indx = 0; 
  int indy = 0; 
  int indz = 0; 

  unsigned int seed = 210201208;
  double       rndfloat = 0.0;
  unsigned int rndinteg = 0;
  const gsl_rng_type *T; T = gsl_rng_default;
  gsl_rng *r; r = gsl_rng_alloc(T);
  gsl_rng_set(r, seed);

  int i_rnd[Ntrials] = {0};
  int j_rnd[Ntrials] = {0};
  int k_rnd[Ntrials] = {0};
  
  for (int nt=0; nt < Ntrials; nt++){
    do {
      i_rnd[nt] = (int) gsl_rng_uniform_int(r, 2*Radius+1) - Radius;
      j_rnd[nt] = (int) gsl_rng_uniform_int(r, 2*Radius+1) - Radius;
      k_rnd[nt] = (int) gsl_rng_uniform_int(r, 2*Radius+1) - Radius;
    } while ( net[INDX(indx, indy, indz)] == HARD  ); 

    indx = i_rnd[nt] % UcellxSize;
    if ( indx < 0 ) indx = indx + UcellxSize;
  }

  for (int nt=0; nt < Ntrials; nt++){
    printf("%d %d %d %d\n", nt, i_rnd[nt], j_rnd[nt], k_rnd[nt]);
  }
  return 0;
}
