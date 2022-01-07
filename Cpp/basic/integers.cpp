#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
  // int maxInteger = 4294967296; //2^32
  // int maxInteger = 4294967295; //2^32 -1 // printed maxInteger =  -1 
  // int maxInteger = 2147483648; //2^31 
  int maxInteger = 2147483647; //2^31 -1
  printf("maxInteger =  %d \n", maxInteger);

  unsigned int maxUnsignInteger = 4294967295; //2^32 -1 
  // unsigned int maxUnsignInteger = 4294967294; //2^32 -2 
  // unsigned int maxUnsignInteger = 2147483647; //2^31 -1 // GOOD
  // unsigned int maxUnsignInteger = 2147483648; //2^31 
  printf("maxUnsignInteger=  %u \n", maxUnsignInteger);
  return EXIT_SUCCESS;
}
