all: main.o random_number.o
	gcc -o program main.o random_number.o

main.o: main.c random_number.h
	gcc -c main.c

random_number.o: random_number.c random_number.h
	gcc -c random_number.c

run:
	./program

clean:
	rm program
	rm rand
	rm *.o
