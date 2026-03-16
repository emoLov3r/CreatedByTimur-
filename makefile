TARGET = ./a.out
FILES = main.o vector.o process.o 
CC = gcc
CFLAGS = -g

$(TARGET): $(FILES)
	$(CC) $(FILES) -o $(TARGET)

.PHONY: all clean run

all: $(TARGET)

run: $(TARGET)
	./$(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

vector.o: vector.c
	$(CC) $(CFLAGS) -c vector.c -o vector.o

process.o: process.c
	$(CC) $(CFLAGS) -c process.c -o process.o

clean:
	rm -f $(FILES) $(TARGET)