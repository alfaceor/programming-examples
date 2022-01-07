#include <iostream>
#include <math.h>

using namespace std;
int main(int argc, char **argv){
  int timeSteps = 2048;
  int tt=0;
  for (int k=0; k< 5; k++){
    cout << "k = " << k << ", timeSteps = "<< timeSteps
         << ", tt = "<< tt  <<endl;
    timeSteps = pow(2,k);
    while(tt < timeSteps ){
      tt++;
    }
  }
  return 0;
}
