#include<stdio.h>
void __global__ init(){
    if(blockIdx.x==0){
        printf("Alright\n");
    }else{
        printf("Yes\n");
    }
}
int main(){
    cudaSetDevice(1);
    init<<<2,4>>>();
}