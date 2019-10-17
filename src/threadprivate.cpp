/*
    threadprivate let vars can live self in different threads.
    "after sometime, I am not me"
*/
#include<stdio.h>
#include<omp.h>

int counter(){
    static int counter=0;
#pragma omp threadprivate(counter)
    counter++;
    printf("%d\n",counter);
    return counter;
}
void main(int argc, char *argv)
{
    int result;
#pragma omp parallel sections reduction(+:result)
    {
#pragma omp section
        {
            for(int i=0;i<2;i++)
                result=counter();
            printf("%d\n",result);
        }

#pragma omp section
        {for(int i=0;i<2;i++)
                result=counter();
            printf("%d\n",result);
        }
#pragma omp section
        {for(int i=0;i<2;i++)
                result=counter();
            printf("%d\n",result);
        }
    }
}