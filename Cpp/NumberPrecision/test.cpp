#include <iostream>

using namespace std;

int main(){
  double x=0;
  int N=1000000000+2; // 10^9
  for (int i=0; i<N; i++){
    x = x+0.03*i;
  }
  cout<<x<<endl;
}
