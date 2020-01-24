#include <stdio.h>
#include<mpi.h>
#include<malloc.h>

int main(int argc, char** argv)
{
	MPI_Status status;
	int rank;
	char msg[20];
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if (rank == 0)
	{
		strcpy(msg, "hello");
		MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, 1, 99, MPI_COMM_WORLD);
	}
	if (rank == 1) {
		MPI_Recv(msg, 20, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &status);
		printf("%s\n", msg);
	}
	MPI_Finalize();
}