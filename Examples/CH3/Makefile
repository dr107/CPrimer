CC=gcc
COPTS=-Wall -Wextra -std=c11

SRC_VEC=vec3d.c
EXEC1=vec.o

SRC_HEAP=minheap.c
EXEC2=heap.o

SRC_AL=arraylist.c
EXEC3=arraylist.o

all: vec heap al

vec:
	$(CC) $(COPTS) -o $(EXEC1) $(SRC_VEC)

heap:
	$(CC) $(COPTS) -o $(EXEC2) $(SRC_HEAP)

al:
	$(CC) $(COPTS) -o $(EXEC3) $(SRC_AL)
