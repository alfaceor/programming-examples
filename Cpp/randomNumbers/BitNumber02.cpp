#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  unsigned int rnd = 4294967295;
  unsigned int stpDir = 0 ;

  for ( int i = 0; i< 10; i++){
    stpDir = rnd  >> i;
    printf("%u %u\n", rnd, stpDir);
  }
  
  return 0;
}
