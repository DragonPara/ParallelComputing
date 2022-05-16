/*
mpi_Gather中的接受数量要比发送数量大，否则会报
write change was 1 (add): Bad file descriptor
接受数量会影响每个进程占用的字节数量，receive buf 多大，假定的数量就是多大
发送1，接收3，则会出现1 x x 2 x x，x为本次传输的无效位置

通信子内的进程必须全部参与，如果不参与，其他进程将一直等待未参与进程。
*/
#include <stdio.h>
#include <mpi.h>
#include<stdlib.h>
int main(void)
{
    MPI_Init(NULL,NULL);
    int rank, size;
    int m=1;
    int *x, *y;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if (rank == 0)
    {
        x = (int *)malloc(16);
        y = (int *)malloc(4);
        y[0]=1;
    }
    else
    {
        y = (int *)malloc(8);
        y[0]=2;
        y[1]=3;
    }
    if(rank<size-1)
        MPI_Gather(y, m, MPI_INT, x, m, MPI_INT, 0, MPI_COMM_WORLD);
    // if(rank==1) MPI_Send( y+1 , 1 , MPI_INT , 0 , 1 , MPI_COMM_WORLD);
    // else   MPI_Recv( x+2 , 1 , MPI_INT , 1 , 1 , MPI_COMM_WORLD , NULL);
    if (rank == 0)
    {
        for (int i = 0; i < 4; i++)
            printf("%d\t", x[i]);
        printf("\n");
        free(x);
    }
    free(y);
    MPI_Finalize();
    return 0;
}
