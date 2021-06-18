CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -pedantic
SRC = $(wildcard *.c)
INC = $(wildcard *.h)
OBJ = $(SRC:.c=.o)
EXE = optAlign

all: $(EXE)

$(OBJ): $(SRC) $(INC) 
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $<

.PHONY: clean

clean:
	rm -f $(EXE) *.o