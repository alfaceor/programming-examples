// constructing vectors
#include <iostream>
#include <vector>
using namespace std;

class IOParams {
public:
  // Params
  bool align    = false;
  vector<int> first; 
  // THIS DOESNT WORK!!!
  //vector<int> second (4,100); 

  // To initialize a vector
  vector<string> name = vector<string>(5);
  vector<int> val{vector<int>(5,0)};
  vector<pair<string,string>> v_genomic;

  // std::unordered_map<string,size_t> v_CDR3_anchors;
  bool align_data_is_CDR3 = false;

  // Methods
  IOParams(int argc, char **argv);
  ~IOParams();
};

IOParams::IOParams(int argc, char **argv){
  cout << argc << endl;
}

IOParams::~IOParams(){

}


string IOParams::strIOParams(){
  string parametros;
  stringstream sstm;
  sstm << "#****** PARAMETERS ******"  <<endl;
  parametros = ""+sstm.str();
  return parametros;
}

/*
 * Main 
 * */

int main (int argc, char**argv)
{
  
  IOParams io(argc, argv);
  for (vector<string>::const_iterator i = io.name.begin(); i !=io.name.end(); ++i){
    cout << *i << endl;
  }
  cout << "---------------" << endl;
  vector<int> second (4,100); 
  for (vector<int>::const_iterator i = second.begin(); i != second.end(); ++i ){
    cout << *i <<endl;
  }

  /*
  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  */

  return 0;
}
