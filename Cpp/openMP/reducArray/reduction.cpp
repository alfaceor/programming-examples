#include <stdio.h>

int main(int argc, char *argv[]){
  const int N = 100;
  int a[N];
  for (int i=0; i < N; i++){
    a[i] = i + 1;
  }
  int sum = 0;
  #pragma omp parallel for reduction (+:sum)
  for (int i=0;i<N;i++)
    sum=sum+a[i];
  printf("sum = %d", sum);
  return 0;
}
