#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
  int size;
  int node;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&node);
  printf("Hello World from Node %d of %d processors\n",node, size);
  MPI_Finalize();
  return 0;
}
