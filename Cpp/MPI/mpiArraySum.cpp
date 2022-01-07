#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){
  MPI_Init(&argc,&argv);
  // Get the number of processes
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int chain[5]={10,20,30,40,50};
  printf("Hello World from rank %d, chain = %d\n", rank, chain[rank]);
  MPI_Finalize();
  return 0;
}
