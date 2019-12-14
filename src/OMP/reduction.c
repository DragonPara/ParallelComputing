#include<stdio.h>
#include<omp.h>

void main(int argc, char **argv)
{
    int sum=0;
    #pragma omp parallel sections reduction(+:sum)//sum=0 in this block
    {
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("一%d\n",sum);
        }
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("二%d\n",sum);
        }
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("三%d\n",sum);
        }
    }
    printf("If we use '+' : %d\n",sum);//sum(一)+sum(二)+sum(三)
    sum=0;
    #pragma omp parallel sections reduction(*:sum)//sum=1 in this block
    {
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("一%d\n",sum);
        }
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("二%d\n",sum);
        }
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("三%d\n",sum);
        }
    }
    printf("If we use '*' : %d\n",sum);//sum(一)*sum(二)*sum(三)
    sum=0;
    #pragma omp parallel sections reduction(&&:sum)//sum=1 in this block
    {
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("一%d\n",sum);
        }
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("二%d\n",sum);
        }
        #pragma omp section
        {
            for(int i=1;i<10;i++)
                sum=i;
            printf("三%d\n",sum);
        }
    }
    printf("If we use '&&' : %d\n",sum);//sum(一)&&sum(二)&&sum(三)
}