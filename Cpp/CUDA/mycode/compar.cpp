#include <cuda_runtime.h>
#include <curand.h>

#include <iostream>

int main() {
  using namespace std;
  curandGenerator_t genGPU;
  curandGenerator_t genCPU;

  curandCreateGenerator(&genGPU, CURAND_RNG_PSEUDO_MTGP32);
  curandSetPseudoRandomGeneratorSeed(genGPU, 1234ULL);
  curandCreateGeneratorHost(&genCPU, CURAND_RNG_PSEUDO_MTGP32);
  curandSetPseudoRandomGeneratorSeed(genCPU, 1234ULL);

  const int n = 10;
  double CPU[n];
  double GPU[n];

  double* d_GPU;
  cudaMalloc(&d_GPU, n*sizeof(double));

  curandGenerateUniformDouble(genCPU, CPU, n);
  curandGenerateUniformDouble(genGPU, d_GPU, n);
  cudaMemcpy(GPU, d_GPU, n*sizeof(double), cudaMemcpyDeviceToHost);

  for ( int i = 0; i < n; ++i ) {
    cout << CPU[i] << ' ' << GPU[i] << endl;
  }

  printf("---------------\n");
  // novo
  curandGenerateUniformDouble(genCPU, CPU, n);
  curandGenerateUniformDouble(genGPU, d_GPU, n);
  cudaMemcpy(GPU, d_GPU, n*sizeof(double), cudaMemcpyDeviceToHost);

  for ( int i = 0; i < n; ++i ) {
    cout << CPU[i] << ' ' << GPU[i] << endl;
  }
  curandDestroyGenerator(genGPU);
  curandDestroyGenerator(genCPU);
  cudaFree(d_GPU);

}
