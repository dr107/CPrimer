#include <stdio.h>
#include <stdlib.h>

/*
  Here be declarations
 */
typedef struct arraylist {
        // array of void*
        void **buffer;
        //number of elements in the array
        unsigned size;
        //arraylist's current capacity
        unsigned cap;
} arraylist;

/*
  Allocate a new arraylist with the specified capacity
 */
arraylist *arraylist_new(unsigned init_cap);

/*
  Completely free an arraylist
 */
void arraylist_free(arraylist *a);

/*
  Put an element at the end of the arraylist.

  If the buffer is full, double its size
 */
void arraylist_push(arraylist *a, void *x);

/*
  Get the ith element of the arraylist

  Does not mutate the arraylist
 */
void *arraylist_get(arraylist *a, int i);

/*
  End declarations. Put your implementations of the above functions,
  and whatever helper functions, below. I did the 'constructor'.
 */

/*
  make sure each call to malloc is matched with a call to free in the
  free function.
 */
arraylist *arraylist_new(unsigned init_cap) {
        arraylist *a=malloc(sizeof(arraylist));
        a->size=0;
        a->cap=init_cap;
        a->buffer=malloc(init_cap*sizeof(void*));

        return a;
}


int main(void) {
        printf("This is a stub implementation\n");
}
