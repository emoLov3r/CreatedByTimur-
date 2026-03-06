# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude
LDFLAGS = 
LDLIBS = -lm

# Директории
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

# Исходные файлы
SRCS = $(SRCDIR)/main.c $(SRCDIR)/vector.c $(SRCDIR)/process.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
HEADERS = $(INCDIR)/vector.h $(INCDIR)/process.h

# Имя исполняемого файла
TARGET = $(BINDIR)/vector

# Цвета для вывода
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m # No Color

# Правило по умолчанию
all: $(TARGET)
	@echo "$(GREEN)Build complete!$(NC)"

# Создание директорий
$(BINDIR) $(BUILDDIR):
	mkdir -p $@

# Линковка объектных файлов в исполняемый файл
$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@echo "$(GREEN)Linking complete!$(NC)"

# Компиляция .c файлов в .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiled:$(NC) $<"

# Запуск программы
run: $(TARGET)
	@echo "$(GREEN)Running program:$(NC)"
	./$(TARGET)

# Запуск с valgrind (проверка утечек памяти)
valgrind: $(TARGET)
	@echo "$(GREEN)Running valgrind:$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Очистка
clean:
	rm -rf $(BUILDDIR) $(BINDIR)
	@echo "$(RED)Clean complete!$(NC)"

# Полная пересборка
rebuild: clean all

# Создание директорий для нового проекта
init:
	mkdir -p $(SRCDIR) $(INCDIR) $(BUILDDIR) $(BINDIR)
	@echo "$(GREEN)Project structure created!$(NC)"

# Информация о проекте
info:
	@echo "$(BLUE)Project Information:$(NC)"
	@echo "  Target: $(TARGET)"
	@echo "  Sources: $(SRCS)"
	@echo "  Objects: $(OBJS)"
	@echo "  Headers: $(HEADERS)"
	@echo "  Compiler: $(CC)"
	@echo "  CFLAGS: $(CFLAGS)"

# Псевдоцели
.PHONY: all run clean rebuild init info valgrind

# Зависимости
$(BUILDDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/vector.h $(INCDIR)/process.h
$(BUILDDIR)/vector.o: $(SRCDIR)/vector.c $(INCDIR)/vector.h
$(BUILDDIR)/process.o: $(SRCDIR)/process.c $(INCDIR)/process.h $(INCDIR)/vector.h