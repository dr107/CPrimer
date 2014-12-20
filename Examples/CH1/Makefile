CC=gcc
COPTS=-Wall -Wextra -std=c11

EXEC5=global.o
SRC_GLOBAL=global.c

EXEC1=deref.o
SRC_DEREF=deref.c

EXEC2=arith.o
SRC_ARITH=arith.c

EXEC3=hanging.o
SRC_HANGING=hanging.c

SRC_EX1=ex1.c
EXEC4=ex1.o

all: global deref arith hanging ex1

global:
	$(CC) $(COPTS) -o $(EXEC5) $(SRC_GLOBAL)

deref:
	$(CC) $(COPTS) -o $(EXEC1) $(SRC_DEREF)

arith:
	$(CC) $(COPTS) -o $(EXEC2) $(SRC_ARITH)

hanging:
	$(CC) $(COPTS) -o $(EXEC3) $(SRC_HANGING)

ex1:
	$(CC) $(COPTS) -o $(EXEC4) $(SRC_EX1)
