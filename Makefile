CC = clang
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g -Iinclude

SRCDIR = src
OBJDIR = obj

SOURCES = main.c factory.c resources.c utils.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

.PHONY: all clean

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) main
