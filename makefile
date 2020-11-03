all: main.o structs.o
	gcc -o main main.o structs.o

main.o: main.c structs.h
	gcc -c main.c structs.h

structs.o:
	gcc -c structs.c structs.h

run:
	./main

clean:
	rm *.o
	rm *.gch