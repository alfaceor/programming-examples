 /**
 OBJECTIVE: Calculate the temporal evolution of the histogram of momentum and position
 * and see the diffusion process.
 * - Save the times in exponential times like 2, 4 , 8, 16, 32, 64, 128.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Ring.h"
#include "SubSystem.h"
#include <boost/program_options.hpp>

#define INDX(i,j,CDIM) ((i)*CDIM+j)


namespace po = boost::program_options;

using namespace std;

class IOParams {
  public:
    string strN;           int N;
    string strU0;          double U0;
    string strT0;          double T0;
    string strDemonFactor; double DemonFactor;
    string strBase;        int Base;

    int ntrials;
    int timeSteps;
    int timeTransient;    
    int ttime;
    double dt;
    int numberPoints;
   
    int initCondMethod;
    IOParams(int argc, char **argv);
    ~IOParams();
};


int main(int argc, char **argv ){
  cout << "# HMF Phase Space Evolution WB to equilibrium and Maxwell Demon S1 S2 " << endl;
  
  IOParams io(argc, argv);
  Ring r(io.N);  
  r.dt = io.dt;
  
  string parametros;
  stringstream sstm;
  sstm << "#****** PARAMETERS ******"                <<endl;
  sstm << "# demonFactor     = " << io.DemonFactor   <<endl;
  sstm << "# Mtrials         = " << io.ntrials       <<endl;
  sstm << "# Npart           = " << io.N              <<endl;
  sstm << "# U0              = " << io.U0            <<" " << r.U <<endl;
  sstm << "# Base            = " << io.Base          <<endl;
  sstm << "# stepsTransient  = " << io.timeTransient <<endl;
  sstm << "# timeSteps       = " << io.timeSteps     <<endl;
  sstm << "# dt              = " << io.dt            <<endl;
  sstm << "# initCond_WaterBag_U0 "  <<endl;
  sstm << "#***********************" <<endl;
  parametros = ""+ sstm.str();
  
  
  
  // NOW THE TRIALS.
  int numberPointsTimeProfile = io.numberPoints; //5000;
  int everySteps           = io.timeSteps/numberPointsTimeProfile;
  int every1percentTrials = io.ntrials/10;
  
  // Array to save the evolution of the energies profiles.
  double* tt_n = new double[numberPointsTimeProfile];
  double* T_n  = new double[r.N*numberPointsTimeProfile];
  double* V_n  = new double[r.N*numberPointsTimeProfile];
  double* u_n  = new double[r.N*numberPointsTimeProfile];
  
  for (int npr=0; npr< numberPointsTimeProfile; npr++){
    for (int n=0; n< r.N; n++){
      T_n[INDX(npr, n, r.N)] = 0.0;
      V_n[INDX(npr, n, r.N)] = 0.0;
      u_n[INDX(npr, n, r.N)] = 0.0;
    }   
  }

  int numberPointsTrans = 0;
  int numberPointsRelax = 0;
  double tau = 0;
  int    x = 0;
  for (int i = 0; i<=io.timeTransient; i++){
    if ( i< 100 )
      tau = 0.1*i;
    else{
      tau = 0.1*round(40*pow(1.01,x));
      }   
        
    if (i*io.dt==tau ){
      x++;
      numberPointsTrans++;
    }   
  }
  
  tau = 0;
  x = 0;
  for (int i = 0; i<=io.timeSteps; i++){
    if ( i< 100 )
      tau = 0.1*i;
    else{
      tau = 0.1*round(40*pow(1.01,x));
      }   
        
    if (i*io.dt==tau ){
      x++;
      numberPointsRelax++;
    }   
  }
  
  
  // Array to save the data for trials and initiate to zero.
  double timeTrans    [numberPointsTrans]; for (int i=0; i<numberPointsTrans; i++) timeTrans    [i] = 0.0;
  double trialsTransT [numberPointsTrans]; for (int i=0; i<numberPointsTrans; i++) trialsTransT [i] = 0.0;
  double timeRelax    [numberPointsRelax]; for (int i=0; i<numberPointsRelax; i++) timeRelax    [i] = 0.0;
  double trialsRelaxT [numberPointsRelax]; for (int i=0; i<numberPointsRelax; i++) trialsRelaxT [i] = 0.0;

  

  /** FILES INITIALIZATION **/
  // INI and END configurations after the perturbation
  string   hdrTimePhaseSpace = "#i p_i q_i";
  string flnIniFile;
  flnIniFile = "PhaseSpace_HMF__N_"+io.strN+"__U0_"+io.strU0+".ini";
  ofstream ofileIniFile;
  ofileIniFile.open(flnIniFile.c_str());
  ofileIniFile << hdrTimePhaseSpace <<endl;
  
  string flnEndFile;
  flnEndFile = "PhaseSpace_HMF__N_"+io.strN+"__U0_"+io.strU0+".end";
  ofstream ofileEndFile;
  ofileEndFile.open(flnEndFile.c_str());
  ofileEndFile << hdrTimePhaseSpace <<endl;
  
  
  int powerStep= 0 ;
  // ====== TRANSIENT ====== 
  int KtransFiles=0;
  powerStep = pow(io.Base, KtransFiles);
  io.ttime = 0;
  while (io.ttime < io.timeTransient){
    if (io.ttime == powerStep){
      KtransFiles++;
      powerStep = pow(io.Base, KtransFiles);
    }
    io.ttime++;
  }
  
  long unsigned int seed;
  for (int nt=0; nt<io.ntrials; nt++){

    seed = (long unsigned int) time(NULL); 
    r.initCond_WaterBag_U0(seed*nt,io.U0);
    
    io.ttime = 0;
    // ----------------> BEGIN TRANSIENT <---------------- //
    int Ktrans=0;
    powerStep = pow(io.Base, Ktrans);
    tau = 0;
    x = 0;
    while (io.ttime < io.timeTransient){
      // PRINT IN FILES.
      if ( io.ttime< 100 )
        tau = 0.1*io.ttime;
      else{
        tau = 0.1*round(40*pow(1.01,x));
        }   
          
      if (io.ttime*io.dt==tau ){
        r.calcEk();
        timeTrans[x] = tau;
        trialsTransT[x] += r.T;
        x++;
      }   
      
      r.Dynamics();
      io.ttime++;
    }
    // ----------------> END TRANSIENT <---------------- //
    
    // SAVE THE TEMPERATURE OF THE WHOLE SYSTEM.
    string flnThermoQuantTrialsBeforeDemon;
    flnThermoQuantTrialsBeforeDemon = "ThermoQuanTrialsBD_HMF__N_"+io.strN+"__U0_"+io.strU0+".dat";
    ofstream ofileThermoQuantTrialsBeforeDemon;
    ofileThermoQuantTrialsBeforeDemon.open(flnThermoQuantTrialsBeforeDemon.c_str());
    ofileThermoQuantTrialsBeforeDemon << "#t T " <<endl;
    
    for (int i=0; i< numberPointsTrans; i++){
      ofileThermoQuantTrialsBeforeDemon << timeTrans[i] << " " << trialsTransT[i]/double(nt+1) << endl;
    }
    ofileThermoQuantTrialsBeforeDemon << "# ntrials = " << nt+1 <<endl;
    ofileThermoQuantTrialsBeforeDemon.close();
    
    // Save ini state before separation
    ofileIniFile << r.strPhaseNoModAngle(io.ttime) <<endl;

    // ************ Begin Maxwell daemon ************
    io.ttime = 0;
    r.calcU();
    if (nt+1 % every1percentTrials == 0)
      cout <<"N "<< io.N << " "<< nt<< "/" << io.ntrials<<" After protocol " << r.U << ", " <<r.Ek;
    
//    double Ekaux = r.Ek - 0.5*(r.p[r.N/2]*r.p[r.N/2] + r.p[r.N/2 -1]*r.p[r.N/2 -1]);
    double T0  = r.T;
    
    // Initial energy in the middle of the chain
    r.p[r.N/2 -1] = -sqrt(2.0*T0);
    r.p[r.N/2]    =  sqrt(2.0*T0);
    
    //Make momentum zero first
    double deltaP0    = (r.calcPFromItoJ(0       , r.N/2 -2) 
                      +  r.calcPFromItoJ(r.N/2 +1, r.N -1  ) )/double(r.N);
    
    r.addDeltaPFromItoJ(0       , r.N/2 -2, deltaP0);
    r.addDeltaPFromItoJ(r.N/2 +1, r.N -1  , deltaP0);
    
    double Ekaux = r.calcEkFromItoJ(0       , r.N/2 -2) 
                 + r.calcEkFromItoJ(r.N/2 +1, r.N -1  );
    
    double pScaleFactor = sqrt((r.N - 2*2)*T0/(2.0*Ekaux));
    
    r.scalePfromItoJ(0       , r.N/2 -2, pScaleFactor);
    r.scalePfromItoJ(r.N/2 +1, r.N -1  , pScaleFactor);
    
    r.calcU();
    if (nt+1 % every1percentTrials == 0)
      cout << ", Before protocol " << r.U << ", " << r.Ek <<endl;
//    cout << r.strPhaseNoModAngle(0.0)<< endl;
    
    
    // ************ End Maxwell daemon ************
    
    
    
    // ----------------> BEGIN DEMON RELAXATION DYNAMICS <---------------- //
    int Ksteps=0;
    powerStep = pow(io.Base, Ksteps);
    tau = 0;
    x = 0;
    int npr=0;
    while (io.ttime < io.timeSteps){
      if (io.ttime % everySteps == 0){
        npr=io.ttime / everySteps;
        tt_n[npr] = io.ttime*r.dt;
        r.calcEk__T_n   ( &T_n[INDX(npr, 0, r.N)] ); // 0 to take the first element
        r.calcEpHMF__V_n( &V_n[INDX(npr, 0, r.N)] );
        // Note: Before print calculate the Total energy per particle.
      }
      
      if ( io.ttime< 100 )
        tau = 0.1*io.ttime;
      else{
        tau = 0.1*round(40*pow(1.01,x));
        }   
          
      if (io.ttime*io.dt==tau ){
        r.calcEk();
        r.calcEp();
        
        timeRelax[x] = tau;
        trialsRelaxT[x] += r.T;
        x++;
      }   

      r.Dynamics();
      io.ttime++;
    }
    /************    WRITE  TRIAL   FILES ******************/
    if ( (nt+1) %  (every1percentTrials) == 0){
        // ----------------> END DEMON RELAXATION DYNAMICS <---------------- //
        // Save in files every trial is complete.
        string flnThermoQuantTrials;
        flnThermoQuantTrials = "ThermoQuanTrialsAD_HMF__N_"+io.strN+"__U0_"+io.strU0+".dat";
        ofstream ofileThermoQuantTrials;
        ofileThermoQuantTrials.open(flnThermoQuantTrials.c_str());
        ofileThermoQuantTrials << "#t T" <<endl;

        for (int i=0; i< numberPointsRelax; i++){
          ofileThermoQuantTrials << timeRelax[i] << " " 
                  << trialsRelaxT[i]/double(nt+1)  << endl; 
        }
        ofileThermoQuantTrials << parametros <<endl;
        ofileThermoQuantTrials << "# ntrials = " << nt+1 <<endl;
        ofileThermoQuantTrials.close();


        //-------------------SAVE FILES FOR ENERGY PROFILE IN TIME--------------------------------
        string flnTimeProfileAD;
        ofstream ofileTimeProfileAD;

        // -- TEMPERATURE PROFILE
        flnTimeProfileAD = "Time_Tn_ProfileAD_HMF__U0_"+io.strU0+"__N_"+io.strN+".dat";    
        ofileTimeProfileAD.open(flnTimeProfileAD.c_str()); // OPEN FILE
        ofileTimeProfileAD << "#t" ;
        for (int n=0; n< r.N; n++){
          ofileTimeProfileAD << " T_"<< n;
        }
        ofileTimeProfileAD <<endl;

        for (int i=0; i< numberPointsTimeProfile; i++){
          ofileTimeProfileAD << tt_n[i];
          for (int n=0; n< r.N; n++){
            ofileTimeProfileAD << " " << T_n[INDX(i, n, r.N)]/double(nt+1); 
          }
          ofileTimeProfileAD << endl;
        }
        ofileTimeProfileAD << parametros <<endl;
        ofileTimeProfileAD << "# ntrials = " << nt+1 <<endl;
        ofileTimeProfileAD.close();                       // CLOSE FILE

        // -- POTENTIAL ENERGY PROFILE
        flnTimeProfileAD = "Time_Vn_ProfileAD_HMF__U0_"+io.strU0+"__N_"+io.strN+".dat";    
        ofileTimeProfileAD.open(flnTimeProfileAD.c_str()); // OPEN FILE
        ofileTimeProfileAD << "#t";
        for (int n=0; n< r.N; n++){
          ofileTimeProfileAD << " V_"<< n;
        }
        ofileTimeProfileAD <<endl;

        for (int i=0; i< numberPointsTimeProfile; i++){
          ofileTimeProfileAD << tt_n[i];
          for (int n=0; n< r.N; n++){
            ofileTimeProfileAD << " " << V_n[INDX(i, n, r.N)]/double(nt+1); 
          }
          ofileTimeProfileAD << endl;
        }
        ofileTimeProfileAD << parametros <<endl;
        ofileTimeProfileAD << "# ntrials = " << nt+1 <<endl;
        ofileTimeProfileAD.close();                       // CLOSE FILE

        // -- TOTAL ENERGY PROFILE
        flnTimeProfileAD = "Time_Un_ProfileAD_HMF__U0_"+io.strU0+"__N_"+io.strN+".dat";    
        ofileTimeProfileAD.open(flnTimeProfileAD.c_str()); // OPEN FILE
        ofileTimeProfileAD << "#t";
        for (int n=0; n< r.N; n++){
          ofileTimeProfileAD << " U_"<< n;
        }
        ofileTimeProfileAD <<endl;

        for (int i=0; i< numberPointsTimeProfile; i++){
          ofileTimeProfileAD << tt_n[i];
          for (int n=0; n< r.N; n++){
            ofileTimeProfileAD << " " << (0.5*T_n[INDX(i, n, r.N)]+V_n[INDX(i, n, r.N)])/double(nt+1); 
          }
          ofileTimeProfileAD << endl;
        }
        ofileTimeProfileAD << parametros <<endl;
        ofileTimeProfileAD << "# ntrials = " << nt+1 <<endl;
        ofileTimeProfileAD.close();                       // CLOSE FILE

        //---------------------------------------------------
    }
    
    // Save end state after separation
    ofileEndFile << r.strPhaseNoModAngle(io.ttime) <<endl;
  }
  
  // Close files.
  ofileIniFile.close();
  ofileEndFile.close();
  
  return 0;
}



/******************* END MAIN ************************/

IOParams::IOParams(int argc, char **argv) {
  // 0. Boost options initialize.

  // Declare a group of options that will be 
  // allowed only on command line
  po::options_description generic("Generic options");
  generic.add_options()
      ("version,v", "print version string")
      ("help", "produce help message")
//      ("config,c", po::value<string>(&prmfilename)->default_value("InputParams.prm"),
//            "name of a file of a configuration.")
      ;
      
  // Declare a group of options that will be 
  // allowed both on command line and in
  // config file
  po::options_description config("Configuration");
  config.add_options()
    ("Npart,N", 
         po::value< string >(&strN)->default_value("16"), 
         "Number of particles")
    ("DemonFactor,P", 
         po::value< string >(&strDemonFactor)->default_value("1.0"), 
         "percentage of kinetic energy for the part 1 of the system")
    ("U0,u", 
         po::value< string >(&strU0)->default_value("1.0"), 
         "Total Energy of the system without reservatories.")
    ("T0", 
         po::value< string >(&strT0)->default_value("1.00"), 
         "The will have a initial temperature T0.")
    ("ntrials", 
         po::value< int >(&ntrials)->default_value(1), 
         "Number of trials (realizations) for the simulation.")
    ("Base,B", 
         po::value< string >(&strBase)->default_value("10"), 
         "Number of base^Kmax steps")
    ("timeSteps", 
         po::value< int >(&timeSteps)->default_value(1000000), 
         "simulation time steps.")
    ("timeTransient", 
         po::value< int >(&timeTransient)->default_value(100000), // How to make the same value of timeSteps?
         "simulation time steps.")
    ("dt", 
         po::value< double >(&dt)->default_value(0.1), 
         "dt for the numerical integration.")
    ("numberPoints", 
         po::value< int >(&numberPoints)->default_value(1000), 
         "number of points to save data.")
    ("initCondMethod", 
         po::value< int >(&initCondMethod)->default_value(5), 
         "Initial condition method")
      ;
        
  
  po::options_description cmdline_options;
  cmdline_options.add(generic).add(config);

//  po::options_description config_file_options;
//  config_file_options.add(config);
      
  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).
              options(cmdline_options).run(), vm);
  po::notify(vm);
  
  // Convert to corresponding type.
  if (vm.count("Npart")) {
    N=atoi(vm["Npart"].as< string >().c_str());
  }  
  if (vm.count("U0")) {
    U0=atof(vm["U0"].as< string >().c_str());
  }  
  if (vm.count("T0")) {
    T0=atof(vm["T0"].as< string >().c_str());
  }
  if (vm.count("Base")) {
    Base=atoi(vm["Base"].as< string >().c_str());
  }
  if (vm.count("DemonFactor")) {
    DemonFactor=atof(vm["DemonFactor"].as< string >().c_str());
  }
  
  this->ttime = 0;
}

//IOParams::IOParams(const IOParams& orig) {
//}

IOParams::~IOParams() {
  
}
