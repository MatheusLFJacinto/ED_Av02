all: module.o
	gcc module.o main.c -o main

module.o:	module.h
	gcc -c module.c

clean:
	rm -rf *.o

run:
	./main


