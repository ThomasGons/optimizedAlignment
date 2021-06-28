INC = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJ = optAlign
CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -pedantic

EXE = optAlign

all: $(EXE)

local global:
ifeq ($(MAKECMDGOALS),local)
	@cd OptLocAlign
else
	@cd OptGlobAlign
endif
	$(shell pwd)
	make all

$(OBJ): $(SRC) $(INC)
	$(CC) -o $@ -c $< $(CFLAGS)
	@cd ..

$(EXE): $(OBJ)
	$(CC) -o $@ $<

.PHONY: clean

clean:
	rm -f $(EXE) *.o