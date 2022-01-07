#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
 
int main(int argc, char *argv[])
{
    const int Np = 100;
    // construction uses aggregate initialization
    std::array<int, Np> arr; ;  // never required after =
    for (int i=0; i< Np; i++){
      arr[i] = i*i;
    }
    //  for(const auto& s: arr)
    //    s += 100;
 
    // ranged for loop is supported
    for(const auto& s: arr)
        std::cout << s << ", ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
