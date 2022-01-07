
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <getopt.h>
#include <string>
#include <gsl/gsl_math.h>

using namespace std;

//#define no_argument 0
//#define required_argument 1 
//#define optional_argument 2


class IOParams{
  public:
    int N;
    double xlen;
    double ylen;
    double zlen;
    double T1;
    double T2;
    double dm;
    
    IOParams(int argc, char **argv);
    ~IOParams();
};

IOParams::IOParams(int argc, char **argv){

  this->N=100;
  this->xlen=10.0; this->ylen=10.0; this->zlen=10.0;
  this->T1=2.0; this->T2=2.0;
  this->dm=1.0;

  static struct option longopts[] =
  {
    {"inifile",     required_argument,  0, 'i'},
    {"version",   no_argument,        0, 'v'},
    {"help",      no_argument,        0, 'h'},
    {"Npart",     required_argument,  0, 'N'},
    {"xlen",     required_argument,  0, 'x'},
    {"ylen",     required_argument,  0, 'y'},
    {"zlen",     required_argument,  0, 'z'},
    {"T1",     required_argument,  0, '1'},
    {"T2",     required_argument,  0, '2'},
    {0,0,0,0}
  };

  int index=0;
  int opt=0;
  //turn off getopt error message
  opterr=1; 

  ifstream ifile;
  string line;


  while ((opt = getopt_long(argc, argv, "Nvhs", longopts, &index))!=-1){

    switch (opt)
    {
      case 'h':
        cout << "You hit help " << endl;
        break;

      case 'v':
//        cout << "You hit version " <<index<< endl;
        break;

      case 'i':
        cout << "Inifilename = "<< optarg <<endl;
        //ifile.open("jojo.txt");
        ifile.open(optarg);
        if (ifile.is_open()){
          while (getline(ifile,line) ){
          cout <<line<<endl;
          }
        }
        break;

      case 'N':
        this->N=atoi(optarg);
        cout << "Number of particles = "<< this->N <<endl;
        break;

      case 'x':
        this->xlen=atof(optarg);
        cout << "xlen= "  << this->xlen << endl;
        break;

      case 'y':
        this->ylen=atof(optarg);
        cout << "ylen= " << this->ylen << endl;
        break;

      case 'z':
        this->zlen=atof(optarg);
        cout << "zlen= "  << this->zlen << endl;
        break;

      case '1':
        this->T1=atof(optarg);
        cout << "T1= "  << this->T1 << endl;
        break;

      case '2':
        this->T2=atof(optarg);
        cout << "T2 = "  << this->T2 << endl;
        break;

      default:
        cout << "You hit default " << endl;
        break;
    }
  }
  
  ifile.close();

};

IOParams::~IOParams(){

};
/***********************************************/

int main(int argc, char *argv[])
{
  IOParams io(argc,argv);
  return 0; 
}
