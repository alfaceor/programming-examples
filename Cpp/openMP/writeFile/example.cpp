// g++ -std=c++11 -Wall -Wextra -pedantic -fopenmp critical.cpp
#include <iostream>

int main()
{
  #pragma omp parallel for
  for (int i = 0; i < 20; ++i)
    std::cout << "unsynchronized(" << i << ") ";
  std::cout << std::endl;
  #pragma omp parallel for
  for (int i = 0; i < 20; ++i)
    #pragma omp critical
    std::cout << "critical(" << i << ") ";
  std::cout << std::endl;
  #pragma omp parallel for ordered
  for (int i = 0; i < 20; ++i)
    #pragma omp ordered
    std::cout << "ordered(" << i << ") ";
  std::cout << std::endl;
  return 0;
}
