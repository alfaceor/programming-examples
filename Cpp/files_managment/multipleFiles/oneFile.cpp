#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(int argc, char **argv){
  string   flnBase="BaseName__";
  string   flnArray = "Prefix__"+flnBase+".dat";
  string   hdrArray = "#i T_i JL_i JR_i";
  ofstream ofileArray; 
  ofileArray.open(flnArray.c_str()); 
  ofileArray << hdrArray<<endl;
  
  ofileArray.close();
 return 0;
}
