CC = clang
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g -Iinclude

SRCDIR = src
OBJDIR = obj

SOURCES = \
	main.c \
	factory/factory.c \
	factory/factory_shop.c \
	player.c \
	utils/help.c \
	utils/utils.c \

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

TEST_OBJS = $(OBJDIR)/factory/factory.o $(OBJDIR)/factory/factory_shop.o $(OBJDIR)/player.o

.PHONY: all clean test

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

test: test_runner
	./test_runner

test_runner: tests/run_tests.c $(TEST_OBJS)
	$(CC) $(CFLAGS) tests/run_tests.c $(TEST_OBJS) -lm -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) main test_runner
