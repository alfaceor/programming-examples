// constructing vectors
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MyVector : public vector<T>{
  using vector<T>::vector;
  public:
    void print(){
      cout << "foda-se! s'il vous plait" <<endl;
      // FIXME: How to solve this problem?
      //for (::iterator it = this->begin(); it != this->end(); ++it)
      //  cout << ' ' << *it;
      //cout << '\n';
    };
};

int main ()
{
  // constructors used in the same order as described above:
  MyVector<int> first;                                // empty vector of ints
  MyVector<int> second (4,100);                       // four ints with value 100
  MyVector<int> third (second.begin(),second.end());  // iterating through second
  MyVector<int> fourth (third);                       // a copy of third
  fourth.print();

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  MyVector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << "The contents of fifth are:";
  for (MyVector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
