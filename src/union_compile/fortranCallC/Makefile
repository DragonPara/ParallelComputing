src = main.f90 api.o func.o 

all: exe

# exe:$(src)
# 	gfortran $(src) -o exe

exe: $(src)
	gfortran $(src) -o exe

api.o: api.f90
	gfortran -c api.f90
# func.o: func.c
# 	gcc -c func.c
.f90.o:
	gfortran -c $<
.c.o:
	gcc -c $<
clean:
	rm *.o exe *.mod