+  main.c
```c
void hello();
int main(void){
        hello();
}
```
+  p1.c
```c
#include<stdio.h>
void hello(){
        printf("Hello\n");
}
```
## command line
***compile p1.c to p1.c***

  `gcc -c p1.c`
  
***create libp1.lib***

  `ar cr libp1.lib p1.o`
  
***convert libp1.lib to libp1.dll***

  `gcc --shared -fpic libp1.lib - libp1.dll`
  
***compile and link main procedure***

  `gcc main.c -L. -lp1 -o main`
  
run main
```shell
 $> ./main
 hello
```
