/*
    copyprivate + single
*/
#include<stdio.h>
#include<omp.h>
void main(int argc, char *argv)
{
    #pragma omp parallel 
    {
        int a;
        #pragma omp single copyprivate(a)
        {
            a=50;
        }
        a++;
        printf("%d %d\n",omp_get_thread_num(),a);
    }
    #pragma omp parallel 
    {
        int a;
        #pragma omp single 
        {
            a=50;
        }
        a++;
        printf("%d %d\n",omp_get_thread_num(),a);
    }
        
}