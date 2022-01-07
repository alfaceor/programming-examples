#include <iostream>
#include <string>

int main ()
{
  std::string str ("Test string");
  std::cout << "The size of str is " << str.length() << " bytes.\n";
  std::cout << str.length()/3 << std::endl;
  std::cout << str.length() % 3 << std::endl;
  return 0;
}

