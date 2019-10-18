/*

*/
#include<stdio.h>
#include<omp.h>

void main(int argc, char *argv)
{
    int i=1,j=2;
    #pragma omp parallel sections shared(i,j)
    {
        #pragma omp section
        {
            i+=1;
            printf("%d\n",i);
        }
        //if i was changed in section1, section2 and section3 would be affected.
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