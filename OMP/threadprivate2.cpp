//
// Another way
//

/*
    threadprivate let vars can live self in different threads.
    "after sometime, I am not me"
*/
#include<stdio.h>
#include<omp.h>
int counte = 0;
#pragma omp threadprivate(counte)
int counter(){
    counte++;
    return 0;
}
int main(int argc, char **argv)
{
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            for(int i=0;i<2;i++)
                counter();
            printf("%d\n",counte);
        }

        #pragma omp section
        {
            for(int i=0;i<2;i++)
                counter();
            printf("%d\n",counte);
        }
        #pragma omp section
        {
            for(int i=0;i<2;i++)
                counter();
            printf("%d\n",counte);
        }
    }
}