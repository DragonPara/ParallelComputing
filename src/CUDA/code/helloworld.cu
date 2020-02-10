#include<stdio.h>
__global__ void print(){
    printf("hello from the GPU");
}
int main(){
    print<<<1,1>>>();
    cudaDeviceSynchronize();
    return 0;
}
//在就算能力达到3.0之前，CUDA并未实现通过GPU直接printf打印的功能