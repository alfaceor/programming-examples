#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;
class Aligner{
  public:
    string i_filename;

    Aligner(string filename){
      cout << "input filename is "<< filename <<endl;
      i_filename = filename;
      ifstream infile(filename);
      if (!infile){
        cout << "ERROR: file " << filename << "doesn't exist" << endl;
        throw runtime_error("Fudeo!! se fudeo otario, " + filename + "ta n'ao rapaz");
      }else{
        cout << " ===> "<< i_filename << "<===" <<endl;
      }
    };
    ~Aligner(){
    };
};

int main(int argc, char** argv){
  cout << "Hi bitch!" << endl;
  try{
    Aligner v_align("v_align.csv");
    cout << v_align.i_filename<< endl;
    Aligner d_align("d_align.csv");
  }catch (exception& e){
    cout << "N'ao foi, n'ao!" << endl;
  }
  cout << "Continuamos?"<< endl; 
  return EXIT_SUCCESS;
}
