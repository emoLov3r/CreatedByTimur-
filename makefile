# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

# Имя исполняемого файла
TARGET = vector

# Исходные файлы
SRCS = main.c vector.c
OBJS = $(SRCS:.c=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Компиляция .c файлов в .o
%.o: %.c vector.h
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(OBJS) $(TARGET)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Псевдоцели
.PHONY: all clean run