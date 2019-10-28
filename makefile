all: node.o main.o
	gcc -o nodetest node.o main.o

structs.o: node.c node.h
	gcc -c node.c

main.o: main.c node.h
	gcc -c main.c

run:
	./nodetest

clean:
	rm *.o
	rm *~
