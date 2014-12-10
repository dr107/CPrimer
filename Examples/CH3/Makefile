CC=gcc
COPTS=-Wall -Wextra -std=c11

SRC_VEC=vec3d.c
EXEC1=vec.o

SRC_HEAP=minheap.c
EXEC2=heap.o

all: vec heap 

vec:
	$(CC) $(COPTS) -o $(EXEC1) $(SRC_VEC)

heap:
	$(CC) $(COPTS) -o $(EXEC2) $(SRC_HEAP)
