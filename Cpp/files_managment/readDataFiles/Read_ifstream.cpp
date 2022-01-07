#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void initCond_ReadNextTrial(ifstream *ifileIniFile, int N){
  int k;
  double p_i, q_i;
  cout.precision(16);
  string line="";
  istringstream iss(line);
  getline(*ifileIniFile, line); // The header line
  for (int i =0 ; i< N; i++){
    // Read the first values.
    getline(*ifileIniFile, line);
    iss.str(line);
    cout << line <<endl;
    iss >> k ;
    iss >> p_i >> q_i;
    cout << i << "  " << p_i << " " << q_i <<endl;
    iss.clear();
  }
}


int main(int argc, char** argv){
  int N = 64;
  int ntrials=10;

  string flnIniFile="HistogramEvolutionXYS1S2__N_64__U0_0.2.ini";
  ifstream ifileIniFile(flnIniFile.c_str());
  string line="";
  //istringstream iss(line);
  istringstream iss(line);
  cout << line <<endl;
  for (int nt=0; nt<ntrials; nt++ )
    initCond_ReadNextTrial(&ifileIniFile, N);
  
//  cout.precision(16);
//  for (int nt=0 ; nt< ntrials; nt++){
//    getline(ifileIniFile, line); // The header line
//    cout << line <<endl;
//    for (int i =0 ; i< N; i++){
//      // Read the first values.
//      getline(ifileIniFile, line);
//      iss.str(line);
//      //cout << line <<endl;
//      iss >> k ;
//      iss >> p_i >> q_i;
//      //cout << i << "  " << p_i << " " << q_i <<endl;
//      iss.clear();
//    }
//  }
  ifileIniFile.close();

}

