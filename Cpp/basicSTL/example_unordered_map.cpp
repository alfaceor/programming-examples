// unordered_map::count
#include <iostream>
#include <string>
#include <unordered_map>
/**
 Count elements with a specific key
Searches the container for elements whose key is k and returns the number of elements found. Because unordered_map containers do not allow for duplicate keys, this means that the function actually returns 1 if an element with that key exists in the container, and zero otherwise.
 */
int main ()
{
  std::unordered_map<std::string,double> mymap = {
     {"Burger",2.99},
     {"Burger",10.00},
     {"Fries",1.99},
     {"Soda",1.50} };

  for (auto& x: {"Burger","Pizza","Salad","Soda"}) {
    if (mymap.count(x)>0)
      std::cout << "mymap has " << x << " value " << mymap[x] << std::endl;
    else
      std::cout << "mymap has no " << x << std::endl;
  }

  // This add carlos as a new member of the unordered_map.
  std::cout << "testo " << mymap["Carlos"] << std::endl;

  return 0;
}
