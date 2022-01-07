#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <sys/stat.h>


using namespace std;


bool initCondFromFile(string filename){
  struct stat buffer;   
  // Check if file exist
  if (stat (filename.c_str(), &buffer) != 0){  
//    cout<<filename+" doesn't Exist!"<<endl;
    return false;
  }else{
    ifstream iniCondFile;
    iniCondFile.open(filename.c_str()); //"xxxxxx.ini"
    
    string line;
    string key; 
    double p, q;
    int ntrials=2;
    int Npart=64;
    for (int nt=0; nt<ntrials; nt++){
      // TODO: Remove the first line
      getline(iniCondFile,line);
      //cout<<line<<endl;
      for (int nn=0; nn<Npart; nn++){
        // TODO: Read from 2nd line to the Npart+1 and split by delim=" "
        getline(iniCondFile,line);
        stringstream linestream(line);
        getline(linestream,key,' '); // i, p, q
        cout << key << " ";
        getline(linestream,key,' '); // p, q
        p=atof(key.c_str());
        getline(linestream,key,' '); // q
        q=atof(key.c_str());
        cout << p << " " << q << endl;
      } 
      // TODO: Plus one in trial counter.
    }
    
    iniCondFile.close();
    return true;
  }

}


int main(int argc, char** argv){
  cout << "Hello i am reading a file!" <<endl;
  if (initCondFromFile("HistogramEvolutionS1S2__N_64__U0_0.5.ini")){
    cout << "The file exist!" <<endl;
  }
}
