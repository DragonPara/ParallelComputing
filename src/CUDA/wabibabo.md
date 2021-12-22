![1](photo/Store_Sign.png)

# CUDA

cuda program kernel function:

```__global__ void functionName(){}```

or

```void __global__ functionName(){}```

***

<h3>Hello World</h3>
<h4>Hello.cu</h4>

```c++
#include<stdio.h>
__global__ void GPU_print(){
    printf("Hello World\n");
}
int main(int argc,char **argv){
    GPU_print<<<2,2>>>();
    cudaDeviceSynchronize();
    return 0;
}
```

Compile:

```nvcc
nvcc Hello.cu -o Hello
```

Execute:

```c
./Hello
```

Result:

`Hello World`

`Hello World`

`Hello World`

`Hello World`

why?  <<<2,2>>>

***

CUDA kernel run in Device. We should realise the differences of Host datas with Device datas.

Let's see the CUDA functions !

cudaMalloc(

​						(void\*\*)&ptr,  int \*ptr -> (void\*\*)&ptr 

​						size, sizeof(ptr_type);

​					)

ptr will get some places from Device

cudaMemcpy(

​					dst, date to dst

​					src, date from src

​					size, how many bytes

​					kind,where to where(cudaMemcpyHostToDevice,cudaMemcpyDeviceToHost and ......)

​					)

cudaDeviceSynchronize()

Wait operate in Device finish

***

GPU has lot's of same things with CPU

different kinds of memory is one of the same things.

<h5>dynamic common Element</h5>

```c++
double *a;
int M=1000;
cudaMalloc((void**)&a,M);
cudaMemcpy(....);
kernel<<<gridSize,blockSize>>>(a);
```

<h5>static global Element</h5>
global and static

```c++
__device__ double a[5];
__device__ int b;
```

compiler should know the size of static global Element,and we need't be used by arg-way

needn't `kernel<<<1,1>>>(a);`

<h5>constant Element by arg-way</h5>
```c++
int a=1;
kernel<<<1,1>>>(a);
```

read-only and max size is 4KB

<h5>constant Element by __constant__</h5>

```
__constant__ int a=1;
```

read-only and max size is 64 in most NVIDIA GPU

How to copy datas from/to constant Element ?

cudaMemcpyFromSymbol(

​												dst, datas to dst

​												src, datas from src

​												copykind, cudaMemcpyDeviceToHost

​												)

cudaMemcpyToSymbol(

​											dst, datas to dst

​											src, datas from src

​											copykind, cudaMemcpyHostToDevice

​											)

<h5>dynamic shared memory</h5>
```
__global__ void kernel(){
	int n=10;
	__shared__ int a[n];
}
```

read and write, 64KB per block. same block with same shared memory value

<h5>static shared memory</h5>
outside:

`kernel<<<1,1,sharedMemorySize>>>()`

inside:

`extern __shared__  double a[]`

not *a, pointer isn't array

<h5>register memory</h5>
fast and small

```c++
__global__ void kernel(){
    int a=1;
    const int b=1;
}
```

<h5>dynamic unified memory</h5>
```c++
double *x,*y;
const int M=sizeof(double)*10000;
cudaMallocManaged((void**)&x,M);
cudaMallocManaged((void**)&y,M);
*x=1;
*y=2;
kernel<<<gridSize,blockSize>>>(x,y);
```
<h5>static unified memory</h5>
```c++
__device__ __managed__ int ret[1000];
__device__ __managed__ int a;
int main(){
    kernel<<<gridSize,blockSize>>>();
    cudaSynchronize();
    printf("%d\n",a);
}
```

<h5>Free Memory</h5>

`cudaFree(void* ptr)`

***

<h3>Atoi operate</h3>
look like synchronize, but really without synchronize

[Table](原子函数表.md)

<h3>CUDA Stream</h3>
Let's see the functions!

**type:** cudaStream_t  stream

cudaStreamCreate(&stream)

cudaStreamDestory(stream)

cudaStreamSynchronize(stream), wait stream finish

cudaStreamQuery(stream), check stream finish or not, **cudaSuccess** or **cudaErrorNotReady**

**run in stream :** `kernel<<<gridSize, blockSize,shared_size,stream>>>();`

cudaMemcpyAsync(

​									void *dst

​									const void *src

​									size_t count

​									enum cudaMemcpyKind kind

​									cudaStream_t stream, if you want to use default stream, by 0

​									)

which datas can be MemcpyAsync ? 

`cudaMallocHost(void**ptr, size_t size)`

`cudaHostAlloc(void**ptr, size_t size,size_t flag)`

if flag==cudaHostAllocDefault, cudaMallocHost equal to cudaHostAlloc

**Free:**`cudaFreeHost(void* ptr)`
