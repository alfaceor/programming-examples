#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967295


#define FREE 0
#define HARD 1
#define BORD 2

#define INDX(I,J,K) (I*UcellxSize*UcellySize + J*UcellySize + K)

int main(){
  const gsl_rng_type *T; T = gsl_rng_default;
  gsl_rng *r; r = gsl_rng_alloc(T);
  unsigned int seed = 210201208;
  gsl_rng_set(r, seed);

  const int Ntrials  = 100000;
  
  int   Hradius = 10;
  int   Bradius = 11;

  const int Radius          = Hradius; //10;
  const int UcellxSize      = (2*(Radius)+1); // + 1;      
  const int UcellySize      = (2*(Radius)+1); // + 1;      
  const int UcellzSize      = (2*(Radius)+1); // + 1;      


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

  int ii = 0;
  int jj = 0;
  int kk = 0;
  int i_rnd = 0;
  int j_rnd = 0;
  int k_rnd = 0;
  int indx = 0; 
  int indy = 0; 
  int indz = 0; 

  for (int i =0; i< Ntrials ; i++){
    do {
      // 1. Random integer value between -R and R
      i_rnd = (int)gsl_rng_uniform_int(r, 2*Radius+1) - Radius;
      j_rnd = (int)gsl_rng_uniform_int(r, 2*Radius+1) - Radius;
      k_rnd = (int)gsl_rng_uniform_int(r, 2*Radius+1) - Radius;
      ii = i_rnd;
      jj = j_rnd;
      kk = k_rnd;

      indx = ii % UcellxSize;
      if ( indx < 0 ) indx = indx + UcellxSize;
      indy = jj % UcellySize;
      if ( indy < 0 ) indy = indy + UcellySize;
      indz = kk % UcellzSize;
      if ( indz < 0 ) indz = indz + UcellzSize;
    } while ( net[INDX(indx, indy, indz)] == HARD  );
    // print number and should be odd
    printf("%d %d %d %d\n",i,  ii, jj, kk);
  }
  return 0;
}
