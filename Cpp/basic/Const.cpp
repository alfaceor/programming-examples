#include <stdio.h>

int main(int argc, char *argv[]){
  printf("const double array\n");
  size_t n;
  n = 20;
  const double range[n] ; //= {1, 2, 4, 8, 16, 32, 64, 128, 256, 521, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
  for (int i=0; i<n; i++){
    range[i] = 2.0;
  }
  for (int i=0; i<n; i++){
    printf(" range[%d] = %g \n",i , range[i]);
  }
  return 0;
}
