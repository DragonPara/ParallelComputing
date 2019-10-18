/*

*/
#include<stdio.h>
#include<omp.h>

void main(int argc, char *argv)
{
    int i=1,j=2;
    #pragma omp parallel sections private(i,j)
    {
        #pragma omp section
        {
            i+=1;
            printf("一%d\n",i);
        }

        #pragma omp section
        {
            printf("二%d\n",i);
        }
        #pragma omp section
        {
            printf("三%d\n",j);
        }
    }
    printf("After first compute, I=:%d,J=%d\n",i,j);
    #pragma omp parallel sections firstprivate(i,j)
    {
        #pragma omp section
        {
            i+=1;
            printf("一%d\n",i);
        }

        #pragma omp section
        {
            printf("二%d\n",i);
        }
        #pragma omp section
        {
            printf("三%d\n",j);
        }
    }
    printf("After second compute, I=:%d,J=%d\n",i,j);
    #pragma omp parallel sections lastprivate(i,j)
    {
        #pragma omp section
        {
            i=0;
            i+=1;
            printf("一i=%d\n",i);
        }

        #pragma omp section
        {
            i=3;
            j=2;
            printf("二i=%d\n",i);
        }
        #pragma omp section
        {
            j=0;
            i=0;
            printf("三j=%d\n",j);
        }
    }
    printf("After third compute, I=:%d,J=%d\n",i,j);
    #pragma omp parallel sections firstprivate(i,j),lastprivate(i,j)
    {
        #pragma omp section
        {
            i=0;
            i+=1;
            printf("一i=%d\n",i);
        }

        #pragma omp section
        {
            i=3;
            j=2;
            printf("二i=%d\n",i);
        }
        #pragma omp section
        {
            j=0;
            i=0;
            printf("三j=%d\n",j);
        }
    }
    printf("After last compute, I=:%d,J=%d\n",i,j);
}