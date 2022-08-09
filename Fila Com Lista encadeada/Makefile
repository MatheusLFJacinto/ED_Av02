all: main.o module.o
	g++ main.o module.o -o main

main.o:	main.cpp
	g++ -c main.cpp

module.o:	module.h module.cpp
	g++ -c module.cpp

clean:
	rm -rf *.o

run:
	./main


