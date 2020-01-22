#include <stdio.h>
#include<mpi.h>
#include<malloc.h>
int main(int argc, char ** argv)
{
	int size;
	int rank;
	int send[5];
	int rec;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank!=0)
		rec = rank;
	MPI_Gather(&rec, 1, MPI_INT, send, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Barrier(MPI_COMM_WORLD);
	if (rank == 0)
		for (int i = 1; i < 5; i++)
			printf("%d", send[i]);
	MPI_Finalize();
}
//datas from other processor will into root