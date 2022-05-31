### generate debug and release procedure

+ main.f90
```fortran
program p
    integer::x
    x=1
    x=2
    x=3
end program p
```

***release***
```shell
$> gcc main.f90 -o main
```

***debug***
+  add flag `g`
```shell
$> gcc -g main.f90 -o main
```
```shell
$> gdb main 
Starting program: /home/dragon/code/main.exe
[New Thread 15816.0x2204]
[New Thread 15816.0x2ad0]
[New Thread 15816.0x5690]
[New Thread 15816.0x4be0]

Thread 1 "main" hit Temporary breakpoint 1, p () at main.f90:3
3           x=1
(gdb) x
Argument required (starting display address).
(gdb) print x
$1 = 0
(gdb) next
4           x=2
(gdb) print x
$2 = 1
(gdb) next
[New Thread 15816.0x52c]
5           x=3
(gdb) print x
$3 = 2
(gdb) next
6       end program p
```
