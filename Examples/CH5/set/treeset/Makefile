CC=gcc
COPTS=-Wall -Wextra -std=c11

INCLUDE_PATH=-I.. -I.
SRC=btree.c treeset.c main.c
EXEC=main.o

all: hashset

hashset:
	$(CC) $(INCLUDE_PATH) $(COPTS) -o $(EXEC) $(SRC)
