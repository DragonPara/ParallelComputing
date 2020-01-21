#include <iostream>
#include <mpi.h>
#include <malloc.h>
int main(int argc, char **argv)
{
    int size;
    int rank;
    int send[5];
    int rec;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            send[i] = i;
        }
    }
    MPI_Scatter(send, 1, MPI_INT, &rec, 1, MPI_INT, 0, MPI_COMM_WORLD);
    std::cout << rec << " of " << rank << std::endl;
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}
//Scatter将send中的数据，按进程号依次分给rec