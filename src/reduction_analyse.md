choose a sign (eg:+ - & && | *) ,  and run it when these code return.
for example, if you choose +, and the code is

```c++
int i=2;
#pragma omp parallel section reduction(+:i)
{
  #pragma omp section{
      i+=1;
  }
  #pragma omp section{
      i+=1;
  }
}
printf("%d",i);
```

***different signs have differentt initalize,for example:***
-|sin|value|
-| - |-
1| + | 1 |
2| * | 0 |
3| - | 0 |
4| | | 0 |
5| && | 1 |
