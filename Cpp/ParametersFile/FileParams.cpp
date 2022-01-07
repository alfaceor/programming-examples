// TODO:
// Read a formatted file for the parameters in the program.

#include <iostream>
#include <fstream>

#include <string>
#include <sstream>

//#include "IOParams.h"


using namespace std;
int main(int argc, char **argv){
  ifstream paramFile;
  paramFile.open("InputParams.prm");
  
  string line;

  while( getline(paramFile,line) ){
    stringstream linestream(line);
   
    string key;
    getline(linestream,key,'=');

    if (key=="N"){
      getline(linestream,key,'=');
      cout<<key<<endl;
    }
  }
  paramFile.close();
  return 0;
}