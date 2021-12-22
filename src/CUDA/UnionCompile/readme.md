# CUDA C Fortran union compile

An example for C->Fortran->C

After read, you can union cuda c fortran, in order to use fortran technology compute tools like gmres if you want use the data after compute in CUDA.

You need three file  to get it at least.

**compiler:** gfortran nvcc gcc, or we needn't gcc, it is replaced by nvcc.

**key:** If a function named Dragon in fortran, the function will named Dragon_ in c, add the line.

​	If a function named Dragon_ in c, the function will named Dragon in fortran, del the line.

​	compile all the codes one by one, and link them all finally.

## code

**main.c**

  ```c
  #include<stdio.h>
  void sub_fortran_(int*,float*,double*);
  double function_fortran_(double*);
  int main(){
      int num_int;
      float num_float;
      double num_double;
      double num;
      num_int=3;
      num_float=5.0;
      sub_fortran_(&num_int,&num_float,&num_double);
      num=function_fortran_(&num_double);
      printf("num_int=%d\nnum_float=%f\nnum_double=%f\nnum=%f\n",num_int,num_float,num_double,num);
      return 0;
  }
  ```

**sub.f90**

  ```fortran
  subroutine Sub_Fortran(NumInt,NumFloat,NumDouble)
      implicit none
      integer::NumInt
      real::NumFloat ! real==real(4)==real*4
      real(8)::NumDouble
      NumDouble=NumFloat**NumInt
  end subroutine
  
  real(8) function Function_Fortran(NumDouble)
      implicit none
      real(8)::NumDouble
      call cudafunction()
      Function_Fortran=sqrt(NumDouble)
  end function
  ```

**var.cu**

  ```c
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
  ```

**makefile**

  ```makefile
  main:main.o sub.o
  	gfortran -o main main.o sub.o var.o -L /usr/local/cuda/lib64 -lcudart 
  main.o:main.c
  	gcc -o main.o -c main.c
  sub.o:sub.f90
  	/usr/local/cuda/bin/nvcc -o var.o -c var.cu
  	gfortran -o sub.o -c sub.f90
  clean:
  	rm *.o main
  ```

  * If you use gfortran to compile main.o+sub.o, link to cuda lib, if you use nvcc to compile, link to fortran lib.
