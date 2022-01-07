#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Ring.h"
#include "SubSystem.h"
#include "SubSystem2.h"


#include <boost/program_options.hpp>
namespace po = boost::program_options;

using namespace std;


/******************** BEGIN MAIN ***********************/

int main(int argc, char **argv ){
  Ring r(10);
  SubSystem s1(5,0,4);
  r.p[0] = 1.00;
  r.p[4] =-1.00;
  r.p[8] = 2.00;
  cout<< r.strPhase(0)<<endl;
  s1.scaleP(&r, 7.0);
  cout<< r.strPhase(1)<<endl;

  SubSystem2 s2(r.N, &r, 5, 0, 4);
  s2.scaleP(2.0);
  cout<< r.strPhase(2)<<endl;
  SubSystem2 s3(r.N, &r, 5, 3, 7);
  s3.scaleP(3.0);
  cout<< r.strPhase(3)<<endl;

  return 0;
}

/******************* END MAIN ************************/
