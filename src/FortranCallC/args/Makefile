all: intTest floatTest charTest
intTest:intTest.f90 intTest.c
	gcc -c intTest.c
	ifort intTest.o intTest.f90 -o intTest
floatTest:floatTest.f90 floatTest.c
	gcc -c floatTest.c
	ifort floatTest.o floatTest.f90 -o floatTest
charTest:charTest.f90 charTest.c
	gcc -c charTest.c
	ifort charTest.o charTest.f90 -o charTest
test:
	./intTest
	./floatTest
	./charTest
clean:
	rm *.o intTest floatTest charTest