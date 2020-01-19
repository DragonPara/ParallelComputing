/*

*/
#include<stdio.h>
#include<omp.h>

int main(int argc, char **argv)
{
    int i=1,j=2;
    #pragma omp parallel sections shared(i,j)
    {
        #pragma omp section
        {
            i+=1;
            printf("%d\n",i);
        }
        #pragma omp section
        {
            printf("%d\n",i);
        }
        #pragma omp section
        {
            printf("%d\n",j);
        }
    }
}