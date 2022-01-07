#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string>
#include <sstream>

#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


#define NPOSSIB 26 //  2x[ 6 (1stNeighr)] + 12 (2ndNeigh)

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967296 

#define INDX(I,J,K) (I*UcellxSize*UcellySize + J*UcellySize + K)



using namespace std;
int main(const int argc, char** argv){

  double pF2B = -1 ; // FREE to BORD *

  string strF2B ="";

  //--- Read options ---//
  int auxC;
  while (1)
    {
      static struct option long_options[] =
        {
          {"pF2B",  required_argument, 0, 'p'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      auxC = getopt_long (argc, argv, "p",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (auxC == -1)
        break;

      switch (auxC)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'p':
          printf ("option --pF2B %s \n", optarg);
          pF2B   = atof(optarg);
          strF2B = optarg;
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }
  if ( pF2B < 0 || pF2B > 1 ){
    printf("--pF2B is missing or not between 0 and 1 \n");
    exit (1);
  }


  printf("pF2B = %s\n", strF2B.c_str());
  
  // General strings for files
  // string flnPrefix = "rw2D_RegularPorousDepletionNet_2ndNeighMooreFabioProb";
  string flnPrefix = "Congruential_F2B_"+strF2B;
  string strAux = "";
  stringstream sstrm;
  sstrm.str("");
  printf("#random number generator %s \n", flnPrefix.c_str());
  int base10ton = 1;

  // Input parameter simulations
  const int Ntrials = 1000000;
  

  int    *ttime  = new int    [Nsteps2save];
  double *x_mean = new double [Nsteps2save];
  
  double *x_var = new double [Nsteps2save];

  for (int i=0; i< NstepsEvery; i++){
    ttime [i] = 0;
    x_mean[i] = 0.0;
    y_mean[i] = 0.0;
    z_mean[i] = 0.0;
    
    x_var[i]  = 0.0;
    y_var[i]  = 0.0;
    z_var[i]  = 0.0;
  }

  double x_mean_tmp = 0.0;
  double y_mean_tmp = 0.0;
  double z_mean_tmp = 0.0;

  double x_var_tmp  = 0.0;
  double y_var_tmp  = 0.0;
  double z_var_tmp  = 0.0;

  double r_var_tmp  = 0.0;

  // RANDOM NUMBER GENERATOR
  unsigned int rnd = 2969794267;
  unsigned int stpDir = 0;

  long unsigned int seed = 210201208;
  double rndfloat = 0.0;
  const gsl_rng_type *T; T = gsl_rng_default;
  gsl_rng *r; r = gsl_rng_alloc(T);
  gsl_rng_set(r,seed);



  /****** SIMULATION BEGIN ******/ 
  printf("#Comienza \n");
  for (int nt=0; nt < Ntrials; nt++){
    //In position i ==> net[i]
    ii  = 0; // Nsteps;
    jj  = 0; // Nsteps;
    kk  = 0; // Nsteps;
    x   = ii; //-Nsteps;
    y   = jj; //-Nsteps;
    z   = kk; //-Nsteps;
    indx = ii % UcellxSize;
    if ( indx < 0 ) indx = indx + UcellxSize;
    // indx = (indx < 0 )? indx + UcellxSize: indx;
    indy = jj % UcellySize;
    if ( indy < 0 ) indy = indy + UcellySize;
    indz = kk % UcellzSize;
    if ( indz < 0 ) indz = indz + UcellzSize;
    
    base10ton_snpshot = 1;
    
    //========= BEGIN TIME EVOLUTION =========// 
    currentPos = net[INDX(indx,indy,indz)];
    //for (int ns=0; ns < Nsteps; ns++){
    int ns    = 0;
    int nsave = 0;
    while( ns < Nsteps ){
      // Roll a dice and choose a direction 
      rnd = (MULTIPLIER *rnd + INCREMENT) % MODULUS;
      stpDir= rnd >> 27;
      if ( stpDir < NPOSSIB ){
        ii = ii + dx[stpDir];
        jj = jj + dy[stpDir];
        kk = kk + dz[stpDir];

        // Get the cell index
        indx = ii % UcellxSize;
        if ( indx < 0 ) indx = indx + UcellxSize;
        // indx = (indx < 0 )? indx + UcellxSize: indx;
        indy = jj % UcellySize;
        if ( indy < 0 ) indy = indy + UcellySize;
        //indy = (indy < 0 )? indy + UcellySize: indy;
        indz = kk % UcellzSize;
        if ( indz < 0 ) indz = indz + UcellzSize;
        //indz = (indz < 0 )? indz + UcellzSize: indz;
        nextPos = net[INDX(indx,indy,indz)]; 
        
        curr2next = 10*currentPos + nextPos;
        //printf("%d curr2next = %d \n", ns, curr2next);
        // ------- Begin FROM TO conditions ------ // 
        if ( curr2next == F2F ) {
          x = ii; 
          y = jj; 
          z = kk; 
          currentPos = nextPos;

        }else if ( curr2next == F2B ) {
          /***************************************/
          // Roll the dice 
          rndfloat = gsl_rng_uniform(r);
          if ( rndfloat < pF2B ) {
            // JUMP TO THE BORDER 
            x = ii; 
            y = jj; 
            z = kk; 
            currentPos = nextPos;

          } else {
            // DO NOT JUMP TO BORDER
            ii = ii - dx[stpDir];
            jj = jj - dy[stpDir];
            kk = kk - dz[stpDir];
          }
          /***************************************/
        
        }else if ( curr2next == B2F ) {  
          /***************************************/
          // Roll the dice 
          rndfloat = gsl_rng_uniform(r);
          if ( rndfloat < pB2F ) {
            // JUMP TO THE BORDER 
            x = ii; 
            y = jj; 
            z = kk; 
            currentPos = nextPos;

          } else {
            // DO NOT JUMP TO BORDER
            ii = ii - dx[stpDir];
            jj = jj - dy[stpDir];
            kk = kk - dz[stpDir];
          }
          /***************************************/
        
        }else if ( curr2next == B2B ) {  
          /***************************************/
          // Roll the dice 
          rndfloat = gsl_rng_uniform(r);
          if ( rndfloat < pB2B ) {
            // JUMP TO THE BORDER 
            x = ii; 
            y = jj; 
            z = kk; 
            currentPos = nextPos;

          } else {
            // DO NOT JUMP TO BORDER
            ii = ii - dx[stpDir];
            jj = jj - dy[stpDir];
            kk = kk - dz[stpDir];
          }
          /***************************************/
        } else {
          ii= ii - dx[stpDir];
          jj= jj - dy[stpDir];
          kk= kk - dz[stpDir];
        }
        // ------- END FROM TO conditions ------ // 

        // Save one trajectory
        if (!nt ) fprintf(ofileTraje, "%d %d %d %d\n", ns, x, y, z);

        // Save a snapshot in a file 
        if ( (ns+1) % base10ton_snpshot == 0 ){
          base10ton_snpshot *= 10;
          // Snapshot file 
          string outfilename;  stringstream ssOfln;  ssOfln.str("");
          ssOfln << flnPrefix <<  "__ts_" << ns << ".snpsht";
          outfilename = ssOfln.str();
          FILE *ofile = fopen(outfilename.c_str(), "a");
          fprintf(ofile, "%d %d %d\n", x, y, z);
          fclose(ofile);
        }

        // Mean values
        if ( ns % NstepsEvery == 0) {
          nsave = ns / NstepsEvery;
          ttime [nsave]  = ns;
          //printf("%d __ %d,     ",ns, ttime[nsave]);
          x_mean[nsave] += x;
          y_mean[nsave] += y;
          z_mean[nsave] += z;

          x_var[nsave]  += x*x;
          y_var[nsave]  += y*y;
          z_var[nsave]  += z*z;
        }
        ns++;
      }
    }
    
    //if (true){
    if ( (nt+1) % base10ton == 0 ){
      // printf("%u %u\n", stpDir, rnd);
      printf("ntrials = %d \n", nt+1);
      base10ton *= 10;

      // Output file
      stringstream ssOfln;
      string outfilename;
      ssOfln << flnPrefix << "__nt_" << nt+1 << ".dat";
      outfilename = ssOfln.str();
      FILE *ofile = fopen(outfilename.c_str(), "w");
      fprintf(ofile, "#nt x y x_var y_var r_var\n");
      for (int ns=0; ns < Nsteps2save; ns++){
        x_mean_tmp = x_mean[ns]/(float) (nt+1);
        y_mean_tmp = y_mean[ns]/(float) (nt+1);
        z_mean_tmp = z_mean[ns]/(float) (nt+1);
        x_var_tmp = (x_var [ns]/(float) (nt+1)- x_mean_tmp*x_mean_tmp);
        y_var_tmp = (y_var [ns]/(float) (nt+1)- y_mean_tmp*y_mean_tmp);
        z_var_tmp = (z_var [ns]/(float) (nt+1)- z_mean_tmp*z_mean_tmp);

        fprintf(ofile, "%d %e %e %e %e %e %e %e\n", ttime[ns], x_mean_tmp, y_mean_tmp, z_mean_tmp, x_var_tmp, y_var_tmp, z_var_tmp, x_var_tmp + y_var_tmp + z_var_tmp);
      }
      // Before close
      fprintf(ofile, "##############\n");
      fprintf(ofile, "##############\n");
      fprintf(ofile, "#Nsteps       = %d \n", Nsteps);
      fprintf(ofile, "#NstepsEvery  = %d \n", NstepsEvery);
      fprintf(ofile, "#Nsteps2save  = %d \n", Nsteps2save);
      fprintf(ofile, "#Ntrials      = %d \n", nt+1);
      fprintf(ofile, "##############\n");
      fclose(ofile);
    }
  }

  delete [] x_mean;
  delete [] y_mean;
  delete [] z_mean;
  delete [] x_var;
  delete [] y_var;
  delete [] z_var;
  // free(net);
  // free(dx);
  // free(dy);
  // free(x_mean);
  // free(y_mean);
  // free(x_var);
  // free(y_var);
  delete [] net;
  
  fclose(ofileTraje);
  return EXIT_SUCCESS;
  //return 0;
}
