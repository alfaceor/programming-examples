#include "IOParams.h"

IOParams::IOParams(int argc, char **argv){
  
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
         po::value< string >(&strN)->default_value("00008"), 
         "Number of particles")
    ("U0,u", 
         po::value< string >(&strU0)->default_value("1.00"), 
         "Total Energy of the system without reservatories.")
    ("T1,1", 
         po::value< string >(&strT1)->default_value("0.00"), 
         "Temperature reservoir 1")     
    ("T2,2", 
         po::value< string >(&strT2)->default_value("0.00"), 
         "Temperature reservoir 2")     
    ("job_id,j", 
         po::value< string >(&strJob_id)->default_value("00000"), 
         "id of the job (trial)") 
    ("eps", 
         po::value< string >(&strEps)->default_value("1.00"), 
         "epsilon (interaction coefficient)")
    ("k", 
         po::value< string >(&strK)->default_value("1.00"), 
         "k (interaction coefficient)")
    ("kp", 
         po::value< string >(&strKp)->default_value("1.00"), 
         "kprime (interaction coefficient)")
    ("gamma1", 
         po::value< double >(&gamma1)->default_value(1.0), 
         "viscosity constant for the reservatory 1")
    ("gamma2", 
         po::value< double >(&gamma2)->default_value(1.0), 
         "viscosity constant for the reservatory 2")
    ("timeSteps", 
         po::value< int >(&timeSteps)->default_value(1000000), 
         "simulation time steps.")
    ("timeDim", 
         po::value< int >(&timeDim)->default_value(100000), 
         "save value every [timeDim] steps.")
    ("dt", 
         po::value< double >(&dt)->default_value(0.001), 
         "dt for the numerical integration.")
    ("alpha,A", 
         po::value< string >(&strAlpha)->default_value("0.00"), 
         "dt for the numerical integration.")
    ("printTVR", 
         po::value< int >(&printTVR)->default_value(0), 
         "save trajectories in .tvr file 0=false(don't print), 1=true (print).")
    ("ntrials,n", 
         po::value< int >(&ntrials)->default_value(1), 
         "Number of trials in the simulation.")
      ;
        
  
  po::options_description cmdline_options;
  cmdline_options.add(generic).add(config);

//  po::options_description config_file_options;
//  config_file_options.add(config);
      
  po::variables_map vm;
  po::store(po::command_line_parser(argc, argv).
              options(cmdline_options).run(), vm);
  po::notify(vm);
  
  this->basename="N_"+strN+"__U0_"+strU0+"__T1_"+strT1+"__T2_"+strT2+"__A_"+strAlpha+"__id_"+strJob_id;
  
  this->inifilename  = this->basename+".ini";
  this->outfilename  = this->basename+".dat";
  this->outfilename2 = this->basename+".tvr";
  this->outfilename3 = this->basename+".end";
  this->outfilename4 = this->basename+".Tpt";  
  
  // Convert to corresponding type.
  if (vm.count("Npart")) {
    N=atoi(vm["Npart"].as< string >().c_str());
  }
  if (vm.count("U0")) {
    U0=atof(vm["U0"].as< string >().c_str());
  }
  if (vm.count("T1")) {
    T1=atof(vm["T1"].as< string >().c_str());
  }
  if (vm.count("T2")) {
    T2=atof(vm["T2"].as< string >().c_str());
  }
  if (vm.count("eps")) {
    eps=atof(vm["eps"].as< string >().c_str());
  }
  if (vm.count("k")) {
    k  =atof(vm["k"].as< string >().c_str());
  }
  if (vm.count("kp")) {
    kp =atof(vm["kp"].as< string >().c_str());
  }
  if (vm.count("job_id")) {
    job_id=atoi(vm["job_id"].as< string >().c_str());
  }
  if (vm.count("alpha")) {
    alpha=atof(vm["alpha"].as< string >().c_str());
  }
  if (vm.count("partID_flux")) {
    partID_flux=atoi(vm["partID_flux"].as< string >().c_str());
  }
  

  this->ttime = 0;
//  cout<< "timeDim = " << this->timeDim <<endl;
  if (this->timeSteps > this->timeDim){
  	this->taux = (this->timeSteps)/this->timeDim;
  }else{
  	this->taux = 1;
  }

  this->dt2 = this->dt * this->dt;
//  cout<<"dt2 = "<<this->dt2<<endl;
  
  
  // Initialize seeds
  seed = time(NULL);
  srand (seed*job_id);
  seed01_1=rand();
  seed01_2=rand();
  seed02_1=rand();
  seed02_2=rand();
  seedini =rand();
}

void IOParams::printParams(){
  cout<<getParams();
}


string IOParams::getParams(){
  string parametros;
  stringstream sstm;
  sstm << "#***********************" <<endl;
  sstm << "# Npart = "       << N <<endl;
  sstm << "# U0 = "          << U0 <<endl;
  sstm << "# T1 = "          << T1 <<endl;
  sstm << "# T2 = "          << T2 <<endl;
  sstm << "# timeSteps = "   << timeSteps <<endl;
  sstm << "# timeDim = "     << timeDim <<endl;
  sstm << "# gamma1 = "      << gamma1 <<endl;
  sstm << "# gamma2 = "      << gamma2 <<endl;
  sstm << "# alpha = "       << alpha <<endl;
  sstm << "# job_id = "      << job_id <<endl;
  sstm << "# printTVR = "    << printTVR <<endl;
  sstm << "# basename = "    << basename <<endl;
  sstm << "# time seed = "   << seed <<endl;
  sstm << "# dt = "          << dt <<endl;
  sstm << "# dt2 = "         << dt2 <<endl;
  sstm << "# HB01 seed01_1 = " << seed01_1 <<endl;
  sstm << "# HB01 seed01_2 = " << seed01_2 <<endl;
  sstm << "# HB02 seed02_1 = " << seed02_1 <<endl;
  sstm << "# HB02 seed02_2 = " << seed02_2 <<endl;
  sstm << "#***********************" <<endl;
  parametros = ""+ sstm.str();
  return parametros;
}


IOParams::~IOParams(){

}
