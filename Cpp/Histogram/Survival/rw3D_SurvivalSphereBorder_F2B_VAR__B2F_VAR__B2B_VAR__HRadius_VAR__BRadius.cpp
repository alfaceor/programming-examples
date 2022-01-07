#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string>
#include <sstream>

#include <gsl/gsl_math.h>
#include <gsl/gsl_randist.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_histogram.h>


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

  printf("pF2B = %s, pB2F = %s, pB2B = %s, Hrad = %s, Brad = %s \n", strF2B.c_str(), strB2F.c_str(), strB2B.c_str(), strHradius.c_str(), strBradius.c_str());
  
  // General strings for files
  // outputfile: rw3D_SurvivalSphereBorder_F2B_1.0__B2F_1.0__B2B_1.0__Hrad_20__Brad_21.his
  string flnPrefix = "rw3D_SurvivalSphereBorder_F2B_"+strF2B+"__B2F_"+strB2F+"__B2B_"+strB2B+"__Hrad_"+strHradius+"__Brad_"+strBradius;
  string strAux = "";
  stringstream sstrm;
  sstrm.str("");
  printf("#random walk 3D v 01 %s \n", flnPrefix.c_str());

  // Input parameter simulations
  const int Ntrials     = 1000000;
  const int Nsteps      =    1000;

  const int Radius      = Bradius+1; //10;
  const int UcellxSize  = (2*(Radius)+1); // + 1;      
  const int UcellySize  = (2*(Radius)+1); // + 1;      
  const int UcellzSize  = (2*(Radius)+1); // + 1;      

  gsl_histogram * hisTau = gsl_histogram_alloc (Nsteps+1);
  gsl_histogram_set_ranges_uniform (hisTau, -0.5, Nsteps+0.5); 



  printf("# UcellxSize = %d, UcellySize = %d, UcellzSize = %d\n", UcellxSize, UcellySize, UcellzSize);
  // outputfile: rw3D_SurvivalSphereBorder_F2B_1.0__B2F_1.0__B2B_1.0__Hrad_20__Brad_21.his
  
  // Open ofileTraje to save trajectories of one trial
  sstrm.str(""); sstrm << flnPrefix << ".his"; strAux = sstrm.str();
  FILE *ofileHis = fopen(strAux.c_str(), "w");
  fprintf(ofileHis, "#left right freq\n");
  
  // DEFINE THE NETWORK
  int currentPos = FREE;
  int nextPos    = FREE;
  int curr2next  = 10*currentPos + nextPos; // JUST TO GET A NOTATION USING MACROS
  int *net = new int[UcellxSize*UcellySize*UcellzSize]; // Three dimensional net
  for (int i =0; i<UcellxSize; i++) 
    for (int j =0; j<UcellySize; j++)
      for (int k =0; k<UcellzSize; k++)
        net[INDX(i,j,k)] = 0;   


  int r2  = Hradius*Hradius; 
  int r2b = Bradius*Bradius; 
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
  int tau = 0;
  bool fInBorder = true;
  for (int nt=0; nt < Ntrials; nt++){
    //In position i ==> net[i]
    ii  = 1;      // Begin at the border;
    jj  = Radius; // Begin at the border;
    kk  = Radius; // Begin at the border;
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
    
    //========= BEGIN TIME EVOLUTION =========// 
    currentPos = net[INDX(indx,indy,indz)];
    //for (int ns=0; ns < Nsteps; ns++){
    int ns    = 0;
    int nsave = 0;
    fInBorder = true;
    tau = 0;
    while( ns < Nsteps && fInBorder ){
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
        //  printf("currentPos = %d, nextPos = %d \n", currentPos, nextPos);
        
        curr2next = 10*currentPos + nextPos;
        //printf("%d curr2next = %d \n", ns, curr2next);
        // ------- Begin FROM TO conditions ------ // 
        if ( curr2next == B2F ) {  
          /***************************************/
          // THIS MUST END THE SIMULATION
          // Roll the dice 
          rndfloat = gsl_rng_uniform(r);
          if ( rndfloat < pB2F ) {
            // JUMP TO THE BORDER 
            x = ii; 
            y = jj; 
            z = kk; 
            currentPos = nextPos;
            tau++;
            fInBorder = false;
            gsl_histogram_increment (hisTau, tau);
            // printf("THIS MUST END THE TRIAL B2F tau = %d\n", tau);
            // TODO: FINISH THE TRIAL
          } else {
            // DO NOT JUMP TO BORDER
            ii = ii - dx[stpDir];
            jj = jj - dy[stpDir];
            kk = kk - dz[stpDir];
            tau++;
            fInBorder = true;
          }
          /***************************************/
        }else if ( curr2next == B2B ) {  
          /***************************************/
          // CONTINUE THE SIMULATION 
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
          tau++;
          fInBorder = true;
          /***************************************/
        } else if (curr2next == B2H ) {
          ii= ii - dx[stpDir];
          jj= jj - dy[stpDir];
          kk= kk - dz[stpDir];
          tau++;
          fInBorder = true;
        } else {
          ii= ii - dx[stpDir];
          jj= jj - dy[stpDir];
          kk= kk - dz[stpDir];
          tau++;
          fInBorder = false;
          printf("SOMETHING IS WRONG \n");
        }
        // ------- END FROM TO conditions ------ // 
        ns++;
      }
    }
    
  }
  //"#left right freq"
  double sum = gsl_histogram_sum(hisTau);
  if (sum > 0.0)  gsl_histogram_scale(hisTau, 1.0 / sum);
  gsl_histogram_fprintf (ofileHis, hisTau, "%g", "%g");

  // Before close
  fprintf(ofileHis, "##############\n");
  fprintf(ofileHis, "#Nsteps       = %d \n", Nsteps);
  fprintf(ofileHis, "#Ntrials      = %d \n", Ntrials);
  fprintf(ofileHis, "##############\n");
  fclose (ofileHis);
  
  return EXIT_SUCCESS;
  //return 0;
}
