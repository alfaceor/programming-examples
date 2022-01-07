#include <iostream>
#include <string>
#include <iomanip>

#include <stdlib.h>

#include <sstream>


using namespace std;

void Params(int N, double U0, double T1, double T2){
  cout << "#***********************" <<endl;
  cout << "# Npart = "       << N <<endl;
  cout << "# U0 = "          << U0 <<endl;
  cout << "# T1 = "          << T1 <<endl;
  cout << "# T2 = "          << T2 <<endl;
  cout << "#***********************" <<endl;
}


string Params2(int N, double U0, double T1, double T2){
  string parametros;
  stringstream sstm;
  sstm.str("");
  sstm << "#***********************"   <<endl;
  sstm << "# Npart  = "          << N  <<endl;
  sstm << "# U0     = "          << U0 <<endl;
  sstm << "# T1     = "          << T1 <<endl;
  sstm << "# T2     = "          << T2 <<endl;
  sstm << "#***********************"   <<endl;
  parametros=""+sstm.str();
  return parametros;
}


int main(){

  int Mp=3;
  /*
  stringstream sstm;
  string tmpfilename="";
  string basename="hj";
  for (int i=0;i<Mp ;i++)
  {
    sstm.str("");
    sstm << "__pi_";
    //sstm << setfill('0') << setw(5) << partID_flux[i];
    sstm << setfill('0') << setw(5);
    sstm << ".spd";
    tmpfilename = basename+sstm.str();
    //outFile[i].open(tmpfilename.c_str());
    cout<< tmpfilename<<endl;
  }
  */

  cout<< Params2(100, 0.5, 0.45, 0.35) <<endl;
//  string joder;
//  joder = ""+Params2(100, 0.5, 0.45, 0.35);
//  cout<<joder<<endl;
  cout<<"Hello"<<endl;
}
