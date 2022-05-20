src = main.f90 api.o func.o 

all: exe

exe: $(src)
	gfortran $(src) -o exe
	
%.o:%.f90
	gfortran -c $<
.c.o:
	gcc -c $<
clean:
	rm *.o exe *.mod