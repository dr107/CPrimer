#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
  Here be declarations.....
 */

typedef struct heap {
        //the array that stores the ints
        int *buffer;
        //the number of elements
        //by the way, you can write unsigned as shorthand for unsigned int
        unsigned int size;
        //the number of elements the buffer can store
        unsigned int cap;
} heap;

/*
  Initialize a new heap of ten elements.

  Heap-allocates (lol) both the new heap itself and the buffer
 */
heap *heap_new(void);

/*
  Free a heap.
 */
void heap_free(heap *h);

/*
  Push an element onto the heap
 */
void heap_push(heap *h, int x);

/*
  Pop an element from the heap.

  if the heap doesn't have any more stuff, what is returned is
  unspecified because I'm a fucking asshole.
 */
int heap_pop(heap *h);

/*
  Print an array of integers. Requires that arr have at least num_elements
  elements
 */
void print_intarr(int *arr, int num_elems);

/*
  Heapsort. A guaranteed nlogn sort that works by putting a series
  of elements into a heap, and then pulls them out.

  Requires that arr have at least num_elems elements.

  This implementation sorts in-place, mutating arr, though it allocates
  and frees memory for its heap.
 */
void heapsort(int *arr, int num_elems);
/*
  End declarations, here be implementations...
 */


void arr_swap(int* arr, int i, int j) {
        int tmp=arr[i];
        arr[i]=arr[j];
        arr[j]=tmp;
}

heap *heap_new(void) {
        const int init_cap=5;

        heap *retval=malloc(sizeof(heap));
        retval->buffer=malloc(init_cap*sizeof(int));
        retval->size=0;
        retval->cap=init_cap;
        return retval;
}

void heap_free(heap *h)
{
        free(h->buffer);
        free(h);
}

void heap_dbl(heap *h)
{
        printf("Size=%d, Cap=%d, we have to call realloc to make room\n",
               h->size, h->cap);
        h->cap*=2;
        h->buffer=realloc(h->buffer, h->cap*sizeof(int));
}

unsigned parent(unsigned i)
{
        return i/2;
}

unsigned childl(unsigned i) {
        return 2*i+1;
}

unsigned childr(int i) {
        return 2*(i+1);
}

void bubble_up(heap *h, unsigned i)
{
        unsigned i_par=parent(i);
        while (h->buffer[i_par] > h->buffer[i]) {
                arr_swap(h->buffer, i, i_par);
                i=i_par;
                i_par=parent(i);
        }
}

void heap_push(heap *h, int x)
{
        if (h->size == h->cap) {
                heap_dbl(h);
        }
        h->buffer[h->size++]=x;
        bubble_up(h, h->size-1);
}

int is_valid_ind(heap *h, unsigned i) {
        return i<h->size;
}

int int_min(int x, int y) {
        return x<y ? x : y;
}

unsigned smallest_el(heap *h, unsigned i1, unsigned i2) {
        return h->buffer[i1] < h->buffer[i2] ? i1 : i2;
}

/*
  Return the array position of the smaller child of the element
  at the postion i, or i itself if it's the smallest. Return -1
  if i is a leaf. Checks if the children are valid, but not i
  itself.
 */
int smaller_child(heap *h, unsigned i)
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

void bubble_down(heap *h, unsigned i)
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

int heap_pop(heap *h) {
        int retval=h->buffer[0];
        arr_swap(h->buffer, 0, --h->size);
        bubble_down(h, 0);
        return retval;
}


/*
  Sort an array of numbers. Arr must be at least num_elems long
 */
void heapsort(int *arr, int num_elems) {
        int i;
        heap *h=heap_new();
        for(i=0; i<num_elems; i++) {
                heap_push(h, arr[i]);
        }
        for(i=0; i<num_elems; i++) {
                arr[i]=heap_pop(h);
        }
        heap_free(h);
}

void print_intarr(int *arr, int num_elems) {
        for(int i=0; i<num_elems; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

/*
  Don't worry about this function. Generate a random number <max
 */
long random_at_most(long max) {
  unsigned long
    // max <= RAND_MAX < ULONG_MAX, so this is okay.
    num_bins = (unsigned long) max + 1,
    num_rand = (unsigned long) RAND_MAX + 1,
    bin_size = num_rand / num_bins,
    defect   = num_rand % num_bins;

  long x;
  // This is carefully written not to overflow
  while (num_rand - defect <= (unsigned long)(x = rand()));

  // Truncated division is intentional
  return x/bin_size;
}

/*
  Generate an array of siz random numbers
 */
int *genarr(unsigned siz) {
        int *arr=malloc(siz*sizeof(int));
        for(unsigned i=0; i<siz; i++) {
                arr[i]=random_at_most(siz);
        }
        return arr;
}

int main(void) {
        int *arr=genarr(100);
        printf("Initial array:\n");
        print_intarr(arr, 100);
	printf("\n");

        heapsort(arr, 100);

        printf("\nFinal array:\n");
        print_intarr(arr, 100);

        //don't forget to free!
        free(arr);
        return 0;
}
