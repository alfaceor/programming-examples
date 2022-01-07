// string::rfind
#include <iostream>
#include <string>
#include <cstddef>

using namespace std;
int main ()
{
  string str ("The sixth sick sheik's sixth sheep's sick...");
  string key ("sixth");
  // string key ("j");

  cout << str << '\n';
  size_t found = str.rfind(key);
  cout << "str.length() = " << str.length() % 3 <<endl;
  cout << "found = " << found <<endl;
  cout << "string::npos = " << string::npos <<endl;
  if (found!=string::npos)
    str.replace (found,key.length(),"seventh");
  else
    cout << "JJOJOJO" << endl;

  cout << str << '\n';

  return 0;
}
