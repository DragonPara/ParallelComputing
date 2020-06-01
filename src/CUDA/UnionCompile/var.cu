#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
__global__ void kernel(int *a){
    int id=threadIdx.x;
    a[id]+=a[id];
}
extern "C" void cudafunction_(){
    cudaSetDevice(3);
    int *a,*b,r=0;
    a=(int*)malloc(sizeof(int)*1000);
    cudaMalloc((void **)&b,sizeof(int)*1000);
    for(int i=0;i<1000;i++){
        a[i]=1;
    }
    cudaMemcpy(b,a,sizeof(int)*1000,cudaMemcpyHostToDevice);
    kernel<<<1,1000>>>(b);
    cudaDeviceSynchronize();
    cudaMemcpy(a,b,sizeof(int)*1000,cudaMemcpyDeviceToHost);
    for(int i=0;i<1000;i++){
        r+=a[i];
    }
    printf("Final result is : %d\n",r);
}