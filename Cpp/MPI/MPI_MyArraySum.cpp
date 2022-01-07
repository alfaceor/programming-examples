#include<stdio.h>
#include<mpi.h>

int main(int argc, char **argv){
  int world_rank;
  MPI_Init(&argc,&argv);
  // Get the rank of the process
  MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
	int chain[5]={10,20,30,40,50};
  printf("Hello World from Node %d\n",chain[world_rank]);
  MPI_Finalize();
  return 0;
}
