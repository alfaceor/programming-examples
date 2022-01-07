#include <cuda.h>
#include <cuda_runtime.h>
#include <curand.h>

#include <iostream>

__global__ void init_zero(double *d_x){
  d_x[blockIdx.x] = 0.0;
}

__global__ void randomWalk(double *d_x, double *d_GPU){
  d_x[blockIdx.x] = d_x[blockIdx.x] + 2.0*d_GPU[blockIdx.x]-1.0;
}

int main() {
  using namespace std;
  curandGenerator_t genGPU;

  curandCreateGenerator(&genGPU, CURAND_RNG_PSEUDO_MTGP32);
  curandSetPseudoRandomGeneratorSeed(genGPU, 1234ULL);

  const int n = 10000;
  double GPU[n];
  double x[n];

  // Allocated memory of the GPU
  double* d_GPU;
  double* d_x;
  cudaMalloc(&d_GPU, n*sizeof(double));
  cudaMalloc(&d_x,   n*sizeof(double));

  init_zero<<<n, 1>>>(d_x);

  for ( int i=0; i<100000; i++){
    // Generate an array of random numbers in the GPU
    curandGenerateUniformDouble(genGPU, d_GPU, n);
    randomWalk <<< n,1 >>> (d_x, d_GPU);
  }

  // Copy from GPU to CPU
  // cudaMemcpy(GPU, d_GPU, n*sizeof(double), cudaMemcpyDeviceToHost);
  // cudaMemcpy(x,   d_x,   n*sizeof(double), cudaMemcpyDeviceToHost);
  // for ( int i = 0; i < n; ++i ) {
  //   cout << GPU[i] << ' ' << x[i] << endl;
  // }

  curandDestroyGenerator(genGPU);
  cudaFree(d_GPU);
  cudaFree(d_x);

}
