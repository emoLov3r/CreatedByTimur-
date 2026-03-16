CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -Iinclude
LDFLAGS = 
LDLIBS = -lm

SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

SRCS = $(SRCDIR)/main.c $(SRCDIR)/vector.c $(SRCDIR)/process.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)
HEADERS = $(INCDIR)/vector.h $(INCDIR)/process.h

TARGET = $(BINDIR)/vector

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m 

all: $(TARGET)
	@echo "$(GREEN)Build complete!$(NC)"

$(BINDIR) $(BUILDDIR):
	mkdir -p $@

$(TARGET): $(OBJS) | $(BINDIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@echo "$(GREEN)Linking complete!$(NC)"

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HEADERS) | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiled:$(NC) $<"

run: $(TARGET)
	@echo "$(GREEN)Running program:$(NC)"
	./$(TARGET)

valgrind: $(TARGET)
	@echo "$(GREEN)Running valgrind:$(NC)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

clean:
	rm -rf $(BUILDDIR) $(BINDIR)
	@echo "$(RED)Clean complete!$(NC)"

rebuild: clean all

init:
	mkdir -p $(SRCDIR) $(INCDIR) $(BUILDDIR) $(BINDIR)
	@echo "$(GREEN)Project structure created!$(NC)"

info:
	@echo "$(BLUE)Project Information:$(NC)"
	@echo "  Target: $(TARGET)"
	@echo "  Sources: $(SRCS)"
	@echo "  Objects: $(OBJS)"
	@echo "  Headers: $(HEADERS)"
	@echo "  Compiler: $(CC)"
	@echo "  CFLAGS: $(CFLAGS)"

.PHONY: all run clean rebuild init info valgrind

$(BUILDDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/vector.h $(INCDIR)/process.h
$(BUILDDIR)/vector.o: $(SRCDIR)/vector.c $(INCDIR)/vector.h
$(BUILDDIR)/process.o: $(SRCDIR)/process.c $(INCDIR)/process.h $(INCDIR)/vector.h