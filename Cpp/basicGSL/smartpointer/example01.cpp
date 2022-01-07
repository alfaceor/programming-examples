#include <iostream>
using namespace std;


class SmartPrt02{
  public:
    int *ptr; //actual pointer
    explicit SmartPrt02 (int *p = NULL) {ptr = p;};
    ~SmartPrt02() { delete(ptr); };
    
    // Overloading dereferencing operator
    int &operator *() { return *ptr; };
};

int main(){
  SmartPrt02 ptr( new int() );
  *ptr = 20;
  cout << *ptr;

  return 0;
}

