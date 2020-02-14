#pragma once//表示当前代码只编译一次
#include<stdio.h>
#define CHECK(call){\ // '\'为续行符，宏定义必须在一行
do{\
    const cudaError_t error_code = call;\//call为cuda函数的返回值
    if(error_code!=cudaSuccess){\ //如果出现错误，将返回错误的代码
        printf("CUDA Error:\n");\
        printf("File:       %s\n",__FILE__);\
        printf("Line:       %d\n",__LINE__);\
        printf("Error code:   %d\n",error_code);\
        printf("Error text:   %s\n",\
            cudaGetErrorString(error_code));\
        exit(1);\
    }\
}while(0)}//如果不用do while，将可能导致一些错误