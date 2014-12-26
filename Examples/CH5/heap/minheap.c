#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "minheap.h"

/*******************************************************************************
  Here be declarations.....

  these are the functions that an outside caller might wish to call
*******************************************************************************/
struct heap {
        //the array that stores the ints
        int *buffer;
        //the number of elements
        //by the way, you can write unsigned as shorthand for unsigned int
        unsigned int size;
        //the number of elements the buffer can store
        unsigned int cap;
};


/*******************************************************************************
  now the implementations...
*******************************************************************************/

static void arr_swap(int* arr, int i, int j)
{
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
}

minheap heap_new(unsigned cap)
{
        minheap retval=malloc(sizeof(struct heap));
        retval->buffer=malloc(cap*sizeof(int));
        retval->size=0;
        retval->cap=cap;
        return retval;
}

void heap_free(minheap h)
{
        free(h->buffer);
        free(h);
}

static void heap_dbl(minheap h)
{
        printf("Size=%d, Cap=%d, we have to call realloc to make room\n",
               h->size, h->cap);
        h->cap*=2;
        h->buffer=realloc(h->buffer, h->cap*sizeof(int));
}

static unsigned parent(unsigned i)
{
        return i/2;
}

static unsigned childl(unsigned i)
{
        return 2*i+1;
}

static unsigned childr(int i)
{
        return 2*(i+1);
}

static void bubble_up(minheap h, unsigned i)
{
        unsigned i_par=parent(i);
        while (h->buffer[i_par] > h->buffer[i]) {
                arr_swap(h->buffer, i, i_par);
                i=i_par;
                i_par=parent(i);
        }
}

void heap_push(minheap h, int x)
{
        if (h->size == h->cap) {
                heap_dbl(h);
        }
        h->buffer[h->size++]=x;
        bubble_up(h, h->size-1);
}

static int is_valid_ind(minheap h, unsigned i)
{
        return i<h->size;
}

static unsigned smallest_el(minheap h, unsigned i1, unsigned i2)
{
        return h->buffer[i1] < h->buffer[i2] ? i1 : i2;
}

/*
  Return the array position of the smaller child of the element
  at the postion i, or i itself if it's the smallest. Return -1
  if i is a leaf. Checks if the children are valid, but not i
  itself.
 */
static int smaller_child(minheap h, unsigned i)
{
        unsigned i_lc=childl(i);
        unsigned i_rc=childr(i);
        if (is_valid_ind(h, i_lc) && is_valid_ind(h, i_rc)) {
                return smallest_el(h, i, smallest_el(h, i_lc, i_rc));
        } else if (is_valid_ind(h, i_lc)) {
                return smallest_el(h, i, i_lc);
        } else if (is_valid_ind(h, i_rc)) {
                return smallest_el(h, i, i_rc);
        } else {
                return -1;
        }
}

static void bubble_down(minheap h, unsigned i)
{
        while (is_valid_ind(h, i)) {
                int smallest=smaller_child(h, i);
                if (smallest == -1 || smallest == ((int) i)) {
                        return;
                } else {
                        arr_swap(h->buffer, i, smallest);
                        i=smallest;
                }
        }

}

int heap_pop(minheap h) {
        int retval=h->buffer[0];
        arr_swap(h->buffer, 0, --h->size);
        bubble_down(h, 0);
        return retval;
}
