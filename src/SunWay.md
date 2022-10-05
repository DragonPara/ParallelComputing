# C++ operator function in Sunway
#operator 

&emsp;athread对CPP的支持极差，但我们可以让athread的函数调用维持其C状态，在其他函数中使用C++的特性，比如运算符重载。
* main.cpp
```C++
include<athread.h>
extern "C" void SLAVE_FUN(test_slave)();
int main(void){
    int statu;
    statu = athread_init();
    if( statu==0 )
        printf("Init Success!\n");
    else
        printf("Init Fail!\n");
        athread_spawn((void *)SLAVE_FUN(test_slave),0);
    athread_join();
    return 0;
}
```
* slave.cpp
```C++
#include <slave.h>
#include <iostream>
using namespace std;
struct Block
{
    int data[2][2];
};
Block operator+(Block &a, Block &b)
{
    Block c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}
void P()
{
    Block a, b;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a.data[i][j] = 1;
            b.data[i][j] = 2;
        }
    }
    Block c;
    c = a + b;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<c.data[i][j]<<"\t";
        }
        cout<<endl;
    }
}
extern "C" void test_slave()
{
    if (_PEN == 0)
    {
        P();
    }
}
```
+ Makefile
```shell
main:main.o slave.o
	swg++ -mhybrid main.o slave.o -o main
main.o:main.c
	swgcc -mhost main.c -c
slave.o:slave.cpp
	swg++ -mslave slave.cpp -c
clean:
	rm *.o main
```
+ run.sh
```shell
bsub -I -b -o log -q <queue_name> -n 1 -cgsp <nums> -share_size <nums> ./main
```
+ log
```text
Init Success!
3	3	
3	3	
```
