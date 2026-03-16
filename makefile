TARGET = ./a.out
FILES = main.o vector.o process.o 
compile: *.c 
		gcc main.c matrix.c process.c -g -o main
.PHONY: all clean inctall uninstall
all: $(TARGET)
run: compile
	./main
main.o: main.c 
	gcc -c -o main.o main.c 
vector.o: vector.c 
	gcc -c -o vector.o vector.c 
process.o: process.c 
	gcc -c -o process.o process.c 