//
// Created by Dragon on 2019/10/16.
//

#include<stdio.h>
#include <omp.h>
int main(){
#pragma omp parallel for
    for(int i=0;i<5;i++){
        printf("Thread num = : %d\n",omp_get_thread_num());
    }
}