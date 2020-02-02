#include<stdio.h>
__global__ void print(){
    printf("hello from the GPU");
}
int main(){
    print<<<1,1>>>();
    cudaDeviceSynchronize();
    return 0;
}