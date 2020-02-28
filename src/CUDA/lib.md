# CUDA Lib

## Thrust

**namespace:** thrust

### <thrust/device_vector.h>

`thrust::device_vector<type>a(10,0);`

### <thrust/host_vector.h>

```thrust::host_vector<type>a(10,0);```

### <thrust/scan.h>

### <thrust/execution_policy.h>

```c++
thrust::inclusive_scan
```

eg:

```c++
thrust::device_vector<type>x(10,0);
thrust::device_vector<type>y(10,0);
thrust::inclusive_scan(x.begin(),x.end(),y.begin())
    
int *x,*y;
x=(int *)malloc(sizeof(int)*10);
y=(int *)malloc(sizeof(int)*10);
for(int i=0;i<10;i++){
    x[i]=i+1;
}
thrust::inclusize_scan(x,x+10,y);

int *x,*y;
cudaMalloc((void**)&x,sizeof(int)*10);
cudaMalloc((void**)&x,sizeof(int)*10);
thrust::inclusive_scan(thrust::device,x,x+10,y);
```

**But inclusive_scan can't include device elements and host elements at the same function**

## cuBLAS Basic Linear Algebra Subprograms

### head file

`cublas_v2.h`

### compiler option

`nvcc -arch=sm35 -lcublas cublas_gemm.cu`

### init

```c++
cublasStatus_t cublasSetVector
(
int n,   		//how many elements
int elemSize,	//size per element
const void *x,	//data from x
int incx,		//x[0],x[incx],x[2*incx],x[3*incx]...
void *y,		//data to y
int incy		//y[0],y[incy],y[2*incy],y[3*incy]...
);
```

## cuRand

### head file

`curand.h`

### compiler option

`nvcc -lcurand a.cu`

### Example

```c++
#include<stdio.h>
#include<curand.h>
__global__ void kernel(double *x){
	printf("%lf\n",*x);
}
int  main(){
	curandGenerator_t generator;
	curandCreateGenerator(&generator,CURAND_RNG_PSEUDO_DEFAULT);
	curandSetPseudoRandomGeneratorSeed(generator,1234);//1234: seed, time is a better choice
	double *g_x;
	cudaMalloc((void**)&g_x,8);
	curandGenerateUniformDouble(generator,g_x,1);//1: how many datas
	kernel<<<1,3>>>(g_x);
}
```

