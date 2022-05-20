#include<stdio.h>
__global__ void kernel1(){
    printf("Hi Dragon\n");
}
extern "C" void cudaGet(int ompNumber,int mpiNumber){
    cudaSetDevice(ompNumber+mpiNumber);
    kernel1<<<2,2>>>();
    cudaDeviceSynchronize();
}