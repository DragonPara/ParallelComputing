#include<stdio.h>
__constant__ int c_a[3];
//int c_a[3] error
//__constant__ int c_a[] error
//__constant__ int c_a[3]={1,2,3} error
void __global__ print(){
    for(int i = 0;i<3;i++){
        printf("%d ",c_a[i]);
    }
}
int main(){
    int a[]={1,2,3};
    //cudaMemcpy(c_a,a,12,cudaMemcpyHostToDevice) error
    cudaMemcpyToSymbol(c_a,a,12,0,cudaMemcpyHostToDevice);
    print<<<1,1>>>();
}
/*cudaMemcpyToSymbol
cudaError_t cudaMemcpyToSymbol	(	
    const void * 	symbol, 常量内存地址
    const void * 	src,   数据来源地址
    size_t 	count,      拷贝的字节数
    size_t 	offset,     偏移量，如果是0，则从src起始位置开始
    enum cudaMemcpyKind 	kind	传递类型，填写cudaMemcpyHostToDevices 
    )	
*/