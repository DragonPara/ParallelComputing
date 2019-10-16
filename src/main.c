#include<time.h>
#include <stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
    int time1=clock(),time2;
    int tmp=0;
    #pragma omp parallel for
    for (int i = 0; i < 10000; i++)
    {
//        tmp+=i;
//        if(i%10==0)
        int count=2;
        for(;count<=pow(i,0.5);count++)
            if(i%count==0)
                break;
        if(count>pow(i,0.5))
        printf("%d\n",i);
    }
//    printf("i = %d\n", tmp);
    time2=clock();
    printf("%d",time2-time1);
    return 0;
}
