#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
int main ()
{
  int const FN=4;
  //FILE *ofileHis[FN]; // = fopen("rw.his_1e1", "w");
  FILE** ofileHis = malloc(closesizeof(FILE*) * (FN));
  // stringstream ssOfln;
  // for (int fn =0; fn < FN; fn++) {
  //   ssOfln.str("");
  //   ssOfln << "hist" << "__ts_" << fn << ".his";
  //   string flnHis;
  //   flnHis = ssOfln.str();
  //   ofileHis[fn] = fopen(flnHis.c_str(), "w");
  //   ofileHis[fn] << "fn = "<< fn <<endl;
  // }

  // // // free(ofileHis);
  /*
  for (int fn=0; fn < FN; fn++){
    fclose(ofileHis[fn]);
  }
  string strPartID_flux="3,5,7";
  int partID_flux[Mp] = {3,5,7,9};
  stringstream sstm;
  string basename="shit";
  string filename="";
//  cout << strPartID_flux <<endl;
//  cout << strPartID_flux.split(",")<<endl;

  for (int i=0; i<Mp ;i++)
  {
    sstm.str("");
    sstm << "__pi_";
    cout<<partID_flux[i]<<endl;
    sstm << setfill('0') << setw(5) << partID_flux[i];
    sstm << ".spd";
    filename = basename+sstm.str();
    outFile[i].open(filename.c_str());
  }


  for (int i=0; i<Mp ;i++){
    outFile[i]<<"Jesus ... "<<setfill('0') << setw(5) << i <<endl;
  }
 
//  for (int i=0;i<4;i++)
//      cout << std::boolalpha << outFile[i].good() << endl;

  for (int i=0;i<4;i++)
      outFile[i].close();
      */
  return 0;
}
