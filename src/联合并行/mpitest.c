#include<mpi.h>
#include<omp.h>
#include<stdio.h>
int main(void){
    MPI_Init( NULL , NULL);
    int rank,size;
    MPI_Comm_rank( MPI_COMM_WORLD , &rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    #pragma omp parallel num_threads(2)
    {
        cudaGet(omp_get_thread_num,rank);
    }
    MPI_Finalize();
}
