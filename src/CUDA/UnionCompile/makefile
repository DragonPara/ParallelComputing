main:main.o sub.o
	gfortran -o main main.o sub.o var.o -L /usr/local/cuda/lib64 -lcudart 
main.o:main.c
	gcc -o main.o -c main.c
sub.o:sub.f90
	/usr/local/cuda/bin/nvcc -o var.o -c var.cu
	gfortran -o sub.o -c sub.f90
clean:
	rm *.o main