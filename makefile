.PHONY: all docs clean memcheck

SHELL	= /bin/bash

SRCDIR	= src/
INCDIR	= inc
OBJDIR	= obj/
BINDIR	= bin/
DOCDIR	= doc/

_BIN	= test
BIN		= $(addprefix $(BINDIR), $(_BIN))

SRC		= $(wildcard src/*.c)
_OBJS	= $(patsubst src/%.c, %.o, $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(_OBJS))

CC		= gcc
CFALGS	= -Wall -Wextra -std=c99 -Wpedantic -Wstrict-prototypes -Wunreachable-code -Wconversion -Wshadow -Werror
OFLAGS	=

all: $(BIN)

$(BIN): $(OBJS) | $(BINDIR)
	$(CC) $(OFLAGS) $^ -o $@

$(BINDIR):
	mkdir -p $@

$(OBJS): $(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@ 

$(OBJDIR):
	mkdir -p $(OBJDIR)

docs:
	doxygen docs

memcheck: all
	valgrind -v --show-leak-kinds=all --leak-check=full --track-origins=yes ./$(BIN)

clean:
	rm -rf $(BINDIR) $(OBJDIR) $(DOCDIR)

print-%:
	@echo $* = $($*)
