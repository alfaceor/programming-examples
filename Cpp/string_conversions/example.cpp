#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
int main(int argc, char **argv){
  double E0 =0 ;
  string strE0;
  stringstream sstmE0;
  sstmE0.precision(4);
  while (E0 < 2){
    sstmE0.str("");
    //sstmE0 << setfill('0') << setw(4)  << E0;
    sstmE0 << E0;
    strE0 = ""+ sstmE0.str();
    cout << strE0<<endl;
    E0 += 0.1;
  }
  return 0;
}
