CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -pedantic
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXE = optimizedAlignment

all: $(EXE)

%.c:%.o
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXE): $(OBJ)
	$(CC) -o $@ $<

.PHONY: clean

clean:
	rm -f $(EXE) *.o