CC=gcc
COPTS=-Wall -Wextra -std=c11
INCLUDE_PATH=-I.

SRC=main.c quad.c
EXEC=main.o

all: quad

quad:
	$(CC) $(COPTS) $(INCLUDE_PATH) -o $(EXEC) $(SRC) -lm
