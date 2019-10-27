all: main.o LinkedList.o
	gcc -o test_list main.o LinkedList.o

LinkedList.o: LinkedList.c LinkedList.h
	gcc -c LinkedList.c

main.o: main.c LinkedList.h
	gcc -c main.c

run:
	./test_list

clean:
	rm *.o
	rm test_list
