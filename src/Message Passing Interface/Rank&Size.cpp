#inclusede < iostream>
#include <mpi.h>
#include <malloc.h>
int main(int argc, char **argv)
{
	int size;
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	std::cout << rank << " of " << size << std::endl;
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Finalize();
}