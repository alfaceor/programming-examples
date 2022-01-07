#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char **argv){
  int const Nfls = 4;
  string   flnBase  = "DataFile__";
  string   flnArray = new string[Nfls];
  string   hdrArray = "# ## # # # ### # #"; //new string[Nfls];
  ofstream ofileArray = new ofstream[Nfls]; 

  for (int i=0; i<Nfls; i++){
    flnArray[i] = "";
  }

  for (int i=0; i<Nfls; i++){
    for (int j=0; j<i; j++)
      flnArray[i] = flnArray[i]+"i";
  }



  for (int i=0; i<Nfls; i++){
    ofileArray[i].open(flnArray[i].c_str()); 
    ofileArray[i] << hdrArray <<endl;
  }
  
  for (int i=0; i<Nfls; i++)
    ofileArray[i].close();
  return 0;
}
