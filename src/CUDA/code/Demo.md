### Demo
+ demo.cu
```cuda
#include <iostream>
#include <cstdlib>
#define ElemType int
#define N 1'000'000
__global__ void kernel(const ElemType *a, const ElemType *b, ElemType *c)
{
    uint id = blockIdx.x * blockDim.x + threadIdx.x;
    c[id] = b[id] + a[id];
}
using namespace std;
int main(void)
{
    ElemType *device_variables[3];
    ElemType *host_variable = NULL;
    cudaError_t status;
    int c = 2;
    host_variable = new int[N];
    if (host_variable == NULL)
    {
        fprintf(stderr, "malloc fail in host var\n");
        exit(1);
    }
    do
    {
        status = cudaMalloc((void **)&device_variables[c], sizeof(ElemType) * N);
        if (status != cudaSuccess)
        {
            fprintf(stderr,"%s\n",cudaGetErrorString(status));
            fprintf(stderr, "malloc fail in device var\n");
            exit(2);
        }
        c--;
    } while (c >= 0);
    for(int i=0;i<N;i++){
        host_variable[i] = 1;
    }
    cudaMemcpy(device_variables[0], host_variable, sizeof(ElemType) * N, cudaMemcpyHostToDevice);
    cudaMemcpy(device_variables[1], host_variable, sizeof(ElemType) * N, cudaMemcpyHostToDevice);
    kernel<<<1000,1000>>>(device_variables[0],device_variables[1],device_variables[2]);
    cudaMemcpy(host_variable, device_variables[2], sizeof(ElemType) * N, cudaMemcpyDeviceToHost);
    for(int i=0;i<10;i++){
        cout<<host_variable[i]<<endl;
    }
    cudaFree(device_variables[0]);
    cudaFree(device_variables[1]);
    cudaFree(device_variables[2]);
    delete[] host_variable;
    return 0;
}
```
execute
```shell
[bash cuda]$ nvcc demo.cu -o demo
[bash cuda]$ cuda-memcheck ./demo 
========= CUDA-MEMCHECK
========= This tool is deprecated and will be removed in a future release of the CUDA toolkit
========= Please use the compute-sanitizer tool as a drop-in replacement
2
2
2
2
2
2
2
2
2
2
========= ERROR SUMMARY: 0 errors
```
