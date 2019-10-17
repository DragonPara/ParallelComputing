#include<stdio.h>
#include<omp.h>
long add()
{
    int i;
    for(i=0;i<100000000;i++)
    {

    }
    return i;
}
void main(int argc, char *argv)
{
    long i1,i2,i3,i4;
    long sum=0;
    double t1 = omp_get_wtime();
    #pragma omp parallel sections reduction(+:sum,i1,i2,i3,i4)  //let sections can use vars don't belong to them
    {
        #pragma omp section
        {
            printf("section 1 ThreadId = %d\n", omp_get_thread_num());
            i1=add();
        }
        #pragma omp section
        {
            i2=add();
            printf("section 2 ThreadId = %d\n", omp_get_thread_num());
        }
        #pragma omp section
        {
            i3=add();
            printf("section 3 ThreadId = %d\n", omp_get_thread_num());
        }
        #pragma omp section
        {
            i4=add();
            printf("section 4 ThreadId = %d\n", omp_get_thread_num());}
        }
    double t2= omp_get_wtime();
    printf("%ld\n",sum=i1+i2+i3+i4);
    printf("TotalTime : %lf\n",t2-t1);
}