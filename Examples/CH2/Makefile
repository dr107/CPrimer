CC=gcc
COPTS=-Wall -Wextra -std=c11

SRC_STRING=stringstuff.c
EXEC1=str.o

SRC_ECHO=myecho.c
EXEC2=myecho.o

SRC_ARR=arr.c
EXEC3=arr.o

all: string echo arr

string:
	$(CC) $(COPTS) -o $(EXEC1) $(SRC_STRING)

echo:
	$(CC) $(COPTS) -o $(EXEC2) $(SRC_ECHO)

arr:
	$(CC) $(COPTS) -o $(EXEC3) $(SRC_ARR)
