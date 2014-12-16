#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
  Here be declarations.

  Implement these functions. Feel free to use whatever helper functions you find
  appropriate.

*******************************************************************************/
typedef struct arraylist {
        // array of void*
        void **buffer;
        //number of elements in the array
        unsigned size;
        //arraylist's current capacity
        unsigned cap;
} arraylist;

/*
  Allocate a new arraylist with the specified capacity.

  Requires that the initial capacity be >0.
 */
arraylist *arraylist_new(unsigned init_cap);

/*
  Completely free an arraylist
 */
void arraylist_free(arraylist *a);

/*
  Get the ith element of the arraylist

  Does not mutate the arraylist. If i is out of bounds,
  print a message to stderr, and return NULL.
 */
void *arraylist_get(arraylist *a, unsigned i);


/*
  Put an element at the end of the arraylist.

  If the buffer is full, double its size
 */
void arraylist_push(arraylist *a, void *x);

/*
  Insert an elements at position i, moving the elements from
  i to the end down by one.

  BTW, when you implement this, don't move the elements down
  using a for/while loop. Use memcpy/memmove. But which one?
  Read the docs!
 */
void arraylist_insert(arraylist *a, void *x, unsigned i);

/*
  Get the ith element of the arraylist

  Does not mutate the arraylist
 */
void *arraylist_get(arraylist *a, unsigned i);

unsigned arraylist_find(arraylist *a, void *x);

/*
  The opposite of insert. Remove the ith element.
 */
void arraylist_remove(arraylist *a, unsigned i);

/*******************************************************************************
  End declarations. Put your implementations of the above functions,
  and whatever helper functions, below. I did the 'constructor' for you.
*******************************************************************************/

/*
  make sure each call to malloc is matched with a call to free in the
  free function.
 */
arraylist *arraylist_new(unsigned init_cap)
{
        if (init_cap==0) {
                fprintf(stderr,
                        "ERR: You can't have an arraylist with zero size\n");
                /*
                  NULL is just 0 cast to void*. When you dereference it, the
                  result is undefined, though on Linux, you'll get a segfault.
                  It lives in stdlib.h.
                */
                return NULL;
        }
        arraylist *a=malloc(sizeof(arraylist));
        a->size=0;
        a->cap=init_cap;
        a->buffer=malloc(init_cap*sizeof(void*));

        return a;
}


int main(void)
{
        printf("This is a stub implementation\n");
}
