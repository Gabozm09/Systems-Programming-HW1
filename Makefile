all: BitRotations

BitRotations: BitRotations.o 
	gcc BitRotations.o -o BitRotations

BitRotations.o: BitRotations.c 
	gcc -c BitRotations.c -o BitRotations.o

clean:
	rm -f main *.o