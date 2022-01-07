// constructing vectors
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;
int main ()
{
  tuple <string, string, int, double > myTuple;
  myTuple = make_tuple ( "joder", "macho", 10, 3.14);
  // Printing initial tuple values using get()
  cout << "The initial values of tuple are : ";
  cout << get<0>(myTuple) << " " << get<1>(myTuple);
  cout << " " << get<2>(myTuple) << " " << get<3>(myTuple)<< endl;

  get<1>(myTuple) = "felino";
  get<2>(myTuple) = 999;

  cout << "The modified values of tuple are : ";
  cout << get<0>(myTuple) << " " << get<1>(myTuple);
  cout << " " << get<2>(myTuple) << " " << get<3>(myTuple)<< endl;
  // constructors used in the same order as described above:
  /*
  vector<int> first;                                // empty vector of ints
  vector<int> second (4,100);                       // four ints with value 100
  vector<int> third (second.begin(),second.end());  // iterating through second
  vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << "The contents of fifth are:";
  for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  */

  return 0;
}
