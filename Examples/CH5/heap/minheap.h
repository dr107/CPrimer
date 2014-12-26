#ifndef __MINHEAP_H_INCLUDED
#define __MINHEAP_H_INCLUDED

/*
  Define the heap type.
 */

typedef struct heap *minheap;

/*
  Initialize a new heap with initial capacity cap.

  Needs to be freed.
 */
minheap heap_new(unsigned cap);

/*
  Free a heap.
 */
void heap_free(minheap h);

/*
  Push an element onto the heap
 */
void heap_push(minheap h, int x);

/*
  Pop an element from the heap.

  if the heap doesn't have any more stuff, what is returned is
  unspecified because I'm a fucking asshole.
 */
int heap_pop(minheap h);

#endif
