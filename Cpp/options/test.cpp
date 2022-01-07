
#include <iostream>
#include <fstream>
#include <stdlib.h>

#include <getopt.h>
#include <string>
#include <gsl/gsl_math.h>

using namespace std;

#define no_argument 0
#define required_argument 1 
#define optional_argument 2


class IOParams{
  public:
    double gasDensity;
    int N;
    int Ni;
    double xlen;
    double ylen;
    double T1;
    double T2;
    double dm;
    double otherDeltaR;
    
    string outfilename;
    string outfilename2;
    
    double sqrtT1;
    double sqrtT2;
    int ttime;
    int total_time;
    int timeDim;
    int taux;
    int other_time;
    double dt;
    double dt2;  
    
    
    IOParams(int argc, char **argv);
    ~IOParams();
    
};



IOParams::IOParams(int argc, char **argv){

  const struct option longopts[] =
  {
    {"help",      no_argument,        0, 'h'},
    {"stuff",     required_argument,  0, 's'},
    {"paramsfile", required_argument,        0, 'p'},
    {0,0,0,0},
  };

  int index;
  int iarg=0;

  //turn off getopt error message
  opterr=1; 

  while(iarg != -1)
  {
    iarg = getopt_long(argc, argv, "svh", longopts, &index);

    switch (iarg)
    {
      case 'h':
        cout << "You hit help" << endl;
        break;

      case 'v':
        cout << "You hit version" << endl;
        break;

      case 's':
        cout << "You hit stuff" << endl;
        break;
    }
  }



  this->gasDensity=3.0;
  this->N = atoi(argv[1]); //40
  this->Ni = 1./N;
  this->xlen=gasDensity*(N+1);
  this->ylen=4;
  this->T1=atof(argv[2]);//4.0;
  this->T2=atof(argv[3]);//10.0;
  this->dm=atof(argv[4]); // 0.2;
  this->otherDeltaR=atof(argv[5]);
  
  string strN(argv[1]);
  string strT1(argv[2]);
  string strT2(argv[3]);
  string strdm(argv[4]);
  string strODR(argv[5]);
  
  this->outfilename ="N_"+strN+"__T1_"+strT1+"__T2_"+strT2+"__dm_"+strdm+"__dr_"+strODR+".dat";
  this->outfilename2="N_"+strN+"__T1_"+strT1+"__T2_"+strT2+"__dm_"+strdm+"__dr_"+strODR+".trv";
  
  this->sqrtT1=sqrt(T1);
  this->sqrtT2=sqrt(T2);
  this->ttime = 0;
  this->total_time = 4000000; //4000000;
  this->timeDim    = 10000; //40000;
  this->taux = this->total_time/this->timeDim;
  this->other_time = 2000000;

  this->dt=0.001;
  this->dt2 = dt*dt;      
}

IOParams::~IOParams(){

}

/*****************************************************/
/*****************************************************/
/*****************************************************/

int main(int argc, char * argv[])
{

  IOParams io(argc, argv);

  cout << "Hello" << endl;

  const struct option longopts[] =
  {
    {"version",   no_argument,        0, 'v'},
    {"help",      no_argument,        0, 'h'},
    {"stuff",     required_argument,  0, 's'},
    {0,0,0,0},
  };

  int index;
  int iarg=0;

  //turn off getopt error message
  opterr=1; 

  while(iarg != -1)
  {
    iarg = getopt_long(argc, argv, "svh", longopts, &index);

    switch (iarg)
    {
      case 'h':
        cout << "You hit help" << endl;
        break;

      case 'v':
        cout << "You hit version" << endl;
        break;

      case 's':
        cout << "You hit stuff" << endl;
        break;
    }
  }

  cout << "GoodBye!" << endl;

  return 0; 
}
