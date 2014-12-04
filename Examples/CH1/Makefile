CC=gcc
COPTS=-Wall -Wextra -std=c11

SRC_DEREF=deref.c
EXEC1=deref.o

SRC_ARITH=arith.c
EXEC2=arith.o

all: deref arith

deref:
	$(CC) $(COPTS) -o $(EXEC1) $(SRC_DEREF)

arith:
	$(CC) $(COPTS) -o $(EXEC2) $(SRC_ARITH)
