#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <string>
using namespace std;



class Aligner{
  public:
    string i_filename;

    Aligner(string filename){
      cout << "input filename is: ";
      i_filename = filename;
      /*
      if (!infile){
        //cout << "ERROR: file " << filename << "doesn't exist" << endl;
        throw runtime_error("Fudeo!! se fudeo otario, " + filename + "ta n'ao rapaz");
      }else{
        cout << " ===> "<< i_filename << "<===" <<endl;
      }
      */
    };

    void readAlignFile(){
      ifstream infile(i_filename);
      if (infile){
        string line;
        getline(infile, line);
        cout << i_filename <<endl;
      }else{
        throw runtime_error("File "+ i_filename + " doesn't exist.");
      }
    }
    ~Aligner(){
    };
};



void FuncReadAlignFile(string i_filename){
  try{
    ifstream infile(i_filename);
    string line;
    getline(infile, line);
  }catch(exception &e){
    cout << "BICHA" << endl;
    throw e;
  }
  cout << i_filename <<endl;

}

int main(int argc, char** argv){
  cout << "====== Hi  bitch! ====== " << endl;
  try{
    Aligner v_align("v_align.csv");
    v_align.readAlignFile();
    Aligner d_align("d_align.csv");
    d_align.readAlignFile();

    FuncReadAlignFile("j_align.csv");
  }catch (exception& e){
    cout << "IN MAIN CATCH " << endl;
    cout << e.what() << endl;
  }
  cout << "..." <<endl;
  cout << "The program continues ..." << endl;
  cout << "====== Bye bitch! ====== " << endl;
  return EXIT_SUCCESS;
}
