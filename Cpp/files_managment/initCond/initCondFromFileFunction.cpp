#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>

using namespace std;

bool getInitCondFromFile(ifstream *iniCondFile, double *p, double *q, int Npart){
  string line;
  string key; 
  // TODO: Remove the first line
  getline(*iniCondFile,line);
  //cout<<line<<endl;
  for (int nn=0; nn<Npart; nn++){
    // TODO: Read from 2nd line to the Npart+1 and split by delim=" "
    getline(*iniCondFile,line);
    stringstream linestream(line);
    getline(linestream,key,' '); // i, p, q
    cout << key << " ";
    getline(linestream,key,' '); // p, q
    p[nn] = atof(key.c_str());
    getline(linestream,key,' '); // q
    q[nn] = atof(key.c_str());
    cout << p[nn] << " " << q[nn] << endl;
  } 
  //(*iniCondFile).close();
  return true;
}

int main(int argc, char** argv){
  cout << "Hello i am reading a file!" <<endl;
  int N=64;
  double *p, *q;
  p= new double[N];
  q= new double[N];
  
  string filename;
  filename="HistogramEvolutionS1S2__N_64__U0_0.5.ini";
  ifstream iniCondFile;
  iniCondFile.open(filename.c_str());
  
  for ( int nt=0; nt < 2; nt++){
    getInitCondFromFile(&iniCondFile, p, q, N);
    cout << nt <<endl;
  }
  iniCondFile.close();
}
