#include <iostream>

using namespace std;

int main (){
  int i = 15;
  constexpr const volatile int a = 1;
  auto&& a = 1;
  //auto&& b = i;
  //decltype(auto) c = i;
  //cout << b << " " << c <<endl;
  return 0;
}
