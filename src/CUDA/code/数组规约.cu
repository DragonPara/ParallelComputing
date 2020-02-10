#include<stdio.h>
void __global__ add(const double *d_x,const double *d_y,double *d_z)
{
    const int n =blockDim.x*blockIdx.x+threadIdx.x;
    d_z[n]=d_x[n]+d_y[n];
}
int main(){
    double *d_x,*d_y,*d_z;
    double *h_x,*h_y,*h_z;
    cudaMalloc((void **)&d_x, 128*8);
    cudaMalloc((void **)&d_y, 128*8);
    cudaMalloc((void **)&d_z, 128*8);
    h_x=(double *)malloc(128*8);
    h_y=(double *)malloc(128*8);
    h_z=(double *)malloc(128*8);
    for(int i=0;i<128;i++)
    {
        h_x[i]=1.23;
        h_y[i]=2.34;
    }
    cudaMemcpy(d_x,h_x,128*8,cudaMemcpyHostToDevice);
    cudaMemcpy(d_y,h_y,128*8,cudaMemcpyHostToDevice);
    add<<<2,64>>>(d_x,d_y,d_z);
    cudaDeviceSynchronize();
    cudaMemcpy(h_z,d_z,128*8,cudaMemcpyDeviceToHost);
    cudaDeviceSynchronize();
    for(int i = 1 ; i<128;i++)
    {
        h_z[0]+=h_z[i];
    }
    printf("%lf\n",h_z[0]);
    return 0;
}
