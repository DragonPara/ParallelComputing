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