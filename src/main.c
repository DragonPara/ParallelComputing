#include<time.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int time1=clock(),time2;
    int tmp=0;
#pragma omp parallel for
    for (int i = 0; i < 100000; i++)
    {
        tmp+=i;
        if(i%1000==0)
        printf("%d\n",i);
    }
    printf("i = %d\n", tmp);
    time2=clock();
    printf("%d",time2-time1);
    return 0;
}