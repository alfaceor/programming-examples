#include <iostream>
using namespace std;

// A generic smart pointer class

template <class T>
class SmartPrt02{
  public:
    T *ptr; //actual pointer
    explicit SmartPrt02 (T *p = NULL) {ptr = p;};
    ~SmartPrt02() { delete(ptr); };
    
    // Overloading dereferencing operator
    T &operator *() { return *ptr; };
};

int main(){
  SmartPrt02<int> ptr( new int() );
  *ptr = 20;
  cout << *ptr;

  return 0;
}

