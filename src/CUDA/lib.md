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
