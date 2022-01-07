#include <iostream>

int main(){

  if (true  xor true  ) std::cout << "true  xor true  = false " << std::endl;
  if (true  xor false ) std::cout << "true  xor false = true  " << std::endl;
  if (false xor true  ) std::cout << "false xor true  = true  " << std::endl;
  if (false xor false ) std::cout << "false xor false = false " << std::endl;
  return 0;
}
