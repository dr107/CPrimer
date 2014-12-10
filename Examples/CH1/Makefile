CC=gcc
COPTS=-Wall -Wextra -ggdb

EXEC1=deref.o
SRC_DEREF=deref.c

EXEC2=arith.o
SRC_ARITH=arith.c

EXEC3=hanging.o
SRC_HANGING=hanging.c

all: deref arith hanging

deref:
	$(CC) $(COPTS) -o $(EXEC1) $(SRC_DEREF)

arith:
	$(CC) $(COPTS) -o $(EXEC2) $(SRC_ARITH)

hanging:
	$(CC) $(COPTS) -o $(EXEC3) $(SRC_HANGING)
