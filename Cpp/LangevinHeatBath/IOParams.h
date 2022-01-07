#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <boost/program_options.hpp>
namespace po = boost::program_options;

using namespace std;

class IOParams{
  public:
    // input parameters
    int N;
    double U0;
    double T1;
    double T2;
    int timeSteps;
    double eps;
    double k;
    double kp;
    double gamma1;
    double gamma2;
    int job_id;
    double alpha;
    int partID_flux;
    int printTVR; // must be a bool type, 0 don't save
    long unsigned int seed;
    long unsigned int seed01_1;
    long unsigned int seed01_2;
    long unsigned int seed02_1;
    long unsigned int seed02_2;
    long unsigned int seedini;
    int ntrials;
    
    
    //var to name the file
    string strN;
    string strU0;
    string strT1;
    string strT2;
    string strEps;
    string strK;
    string strKp;
    string strJob_id; // job_id
    string strAlpha;    

//    string prmfilename; //Default parameters file
        
    string basename;        
    string inifilename;
    
    // output variables
    string outfilename;
    string outfilename2;
    string outfilename3;
    string outfilename4;
    //string outfilename5;
    
    // auxiliar variables
    int ttime;
    int timeDim;
    int taux;
    double dt;
    double dt2;  
    
    
    IOParams(int argc, char **argv);
    bool existInifile();
    ~IOParams();
    void printParams();
    string getParams();
    
};
