CC=gcc
COPTS=-Wall -Wextra -std=c11

SRC_STRING=stringstuff.c
EXEC1=str.o

SRC_ECHO=myecho.c
EXEC2=myecho.o

all: string echo

string:
	$(CC) $(COPTS) -o $(EXEC1) $(SRC_STRING)

echo:
	$(CC) $(COPTS) -o $(EXEC2) $(SRC_ECHO)
