#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string>
#include <sstream>

#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>


#define NPOSSIB 26 //  2x[ 6 (1stNeighr)] + 12 (2ndNeigh)

#define FREE 0
#define HARD 1
#define BORD 2

#define F2F 0
#define F2H 1
#define F2B 2

#define H2F 10
#define H2H 11
#define H2B 12

#define B2F 20
#define B2H 21
#define B2B 22

#define   MULTIPLIER  1664525
#define   INCREMENT   1013904223
#define   MODULUS     4294967296 


// MACRO INSTEAD A FUNCTION
#define   PRINTTRAJECTORY  fprintf(ofileTraje, "%d %d %d\n", ns, x, y);

#define INDX(I,J,K) (I*UcellxSize*UcellySize + J*UcellySize + K)



using namespace std;
int main(const int argc, char** argv){

  double pF2F = -1 ; // FREE to FREE
  double pF2B = -1 ; // FREE to BORD *
  double pF2H = -1 ; // FREE to HARD

  double pH2F = -1 ; // HARD to FREE
  double pH2B = -1 ; // HARD to BORD
  double pH2H = -1 ; // HARD to HARD

  double pB2F = -1 ; // BORD to FREE *
  double pB2B = -1 ; // BORD to BORD *
  double pB2H = -1 ; // BORD to HARD

  int   Hradius = -1;
  int   Bradius = -1;
  
  string strF2B ="";
  string strB2F ="";
  string strB2B ="";
  string strHradius = "";
  string strBradius = "";


  //--- Read options ---//
  int auxC;
  while (1)
    {
      static struct option long_options[] =
        {
          {"pF2B",  required_argument, 0, '1'},
          {"pB2F",  required_argument, 0, '6'},
          {"pB2B",  required_argument, 0, '7'},
          {"Hradius",  required_argument, 0, 'H'},
          {"Bradius",  required_argument, 0, 'B'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      auxC = getopt_long (argc, argv, "167HB",
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

        case '1':
          printf ("option --pF2B %s \n", optarg);
          pF2B   = atof(optarg);
          strF2B = optarg;
          break;

        case '6':
          printf ("option --pB2F %s \n", optarg);
          pB2F   = atof(optarg);
          strB2F = optarg;
          break;

        case '7':
          printf ("option --pB2B %s \n", optarg);
          pB2B   = atof(optarg);
          strB2B = optarg;
          break;

        case 'H':
          printf ("option --Hradius %s \n", optarg);
          Hradius    = atoi(optarg);
          strHradius = optarg;
          break;

        case 'B':
          printf ("option --Bradius %s \n", optarg);
          Bradius    = atoi(optarg);
          strBradius = optarg;
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

  if ( pB2F < 0 || pB2F > 1 ){
    printf("--pB2F is missing or not between 0 and 1 \n");
    exit (1);
  }

  if ( pB2B < 0 || pB2B > 1 ){
    printf("--pB2B is missing or not between 0 and 1 \n");
    exit (1);
  }

  if ( Hradius < 0 ){
    printf("--Hradius is missing \n");
    exit (1);
  }

  if ( Bradius < 0 ){
    printf("--Bradius is missing \n");
    exit (1);
  }

  printf("pF2B = %s, pB2F = %s, pB2B = %s \n", strF2B.c_str(), strB2F.c_str(), strB2B.c_str());
  
  // General strings for files
  // string flnPrefix = "rw2D_RegularPorousDepletionNet_2ndNeighMooreFabioProb";
  string flnPrefix = "rw3D_RegularPorousDepletion_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHradius+"__Brad_"+strBradius;
  string strAux = "";
  stringstream sstrm;
  sstrm.str("");
  printf("#random walk 3D v 01 %s \n", flnPrefix.c_str());
  int base10ton = 1;

  // Input parameter simulations
  const int Ntrials = 1000000;
  //const int Ntrials = 1000000;
  // const int Nsteps          = 1001;
  const int Nsteps          = 1000000;
  const int NstepsEvery     =     100;
  const int Nsteps2save     = Nsteps/NstepsEvery;

  const int Radius          = Hradius; //10;
  const int UcellxSize      = (2*(Radius)+1); // + 1;      
  const int UcellySize      = (2*(Radius)+1); // + 1;      
  const int UcellzSize      = (2*(Radius)+1); // + 1;      


  printf("# UcellxSize = %d, UcellySize = %d, UcellzSize = %d\n", UcellxSize, UcellySize, UcellzSize);
  
  // Initiate snapshots files
  int base10ton_snpshot = 1;
  for (int ns =0 ; ns <Nsteps; ns++){
    if ( (ns+1) % base10ton_snpshot == 0 ){
      base10ton_snpshot *= 10;
      // Snapshot file 
      stringstream ssOfln;
      string outfilename;
      ssOfln.str("");
      ssOfln << flnPrefix << "__ts_" << ns << ".snpsht";
      outfilename = ssOfln.str();
      FILE *ofile = fopen(outfilename.c_str(), "w");
      fprintf(ofile, "#x y z\n");
      fclose(ofile);
    }
  }
  
  // Open ofileTraje to save trajectories of one trial
  sstrm.str(""); sstrm << flnPrefix << ".trj"; strAux = sstrm.str();
  FILE *ofileTraje = fopen(strAux.c_str(), "w");
  fprintf(ofileTraje, "#t x y z\n");
  
  // DEFINE THE NETWORK
  int currentPos = FREE;
  int nextPos    = FREE;
  int curr2next  = 10*currentPos + nextPos; // JUST TO GET A NOTATION USING MACROS
  //int net[UcellxSize][UcellySize][UcellzSize]; // Three dimensional net
  //
  //
  //
  //
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

  // Save network in a file
  sstrm.str(""); sstrm << flnPrefix << ".net"; strAux = sstrm.str();
  FILE *ofileNet = fopen(strAux.c_str(), "w");
  fprintf(ofileNet, "#type i j k\n");
  for (int i=0; i<UcellxSize; i++){
    for (int j=0; j<UcellySize; j++){
      for (int k=0; k<UcellzSize; k++){
        fprintf(ofileNet, "%d %d %d %d \n", net[INDX(i,j,k)], i, j, k);
      }
    }
  }
  fclose(ofileNet);

  int ii   = 0;
  int jj   = 0;
  int kk   = 0;
  int x    = 0;
  int y    = 0;
  int z    = 0;
  int indx = 0; 
  int indy = 0; 
  int indz = 0; 

  // List of steps
  //            //----- 1st Neighbors    -----//  //-- 2nd Neighbors --//
  //  int dx[4] = {  1, -1,  0,  0 };
  //  int dy[4] = {  0,  0,  1, -1 };

  //  //    //-- 1st Neighbors  --//  //-- 2nd Neighbors --//
  //  int dx[8] = {  1, -1,  0,  0,   1, -1, -1,  1 };
  //  int dy[8] = {  0,  0,  1, -1,   1,  1, -1, -1 };
  //                //----- 1st Neighbors -----//   TWICE                     //-- 2nd Neighbors --//
  int dx[NPOSSIB] = {  1, -1,  0,  0,  0,  0,    1, -1,  0,  0,  0,  0,       1, -1, -1,  1,   0,  0,  0,  0,   1, -1, -1,  1    };
  int dy[NPOSSIB] = {  0,  0,  1, -1,  0,  0,    0,  0,  1, -1,  0,  0,       1,  1, -1, -1,   1, -1, -1,  1,   0,  0,  0,  0    };
  int dz[NPOSSIB] = {  0,  0,  0,  0,  1, -1,    0,  0,  0,  0,  1, -1,       0,  0,  0,  0,   1,  1, -1, -1,   1,  1, -1, -1    };

  int    *ttime  = new int    [Nsteps2save];
  double *x_mean = new double [Nsteps2save];
  double *y_mean = new double [Nsteps2save];
  double *z_mean = new double [Nsteps2save];
  
  double *x_var = new double [Nsteps2save];
  double *y_var = new double [Nsteps2save];
  double *z_var = new double [Nsteps2save];

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
