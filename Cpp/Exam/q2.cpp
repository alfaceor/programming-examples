#include <iostream>

using namespace std;

int main (){
  int n1 = 1;
  const int& r1 = n1;
  const int  *r2 = &n1;
  cout << "sh" <<endl;
  n1 = 5;
  cout << n1 << " " <<r1 <<endl;
  return 0;
}
