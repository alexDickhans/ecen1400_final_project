CC = clang
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g -Iinclude

SRCDIR = src
OBJDIR = obj

SOURCES = \
	main.c \
	factory/factory.c \
	factory/recipe.c \
	inventory/inventory.c \
	inventory/power.c \
	inventory/resources.c \
	misc/help.c \
	misc/utils.c \
	smelter/smelter.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

.PHONY: all clean

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) main
