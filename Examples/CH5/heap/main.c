#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minheap.h"

void print_intarr(int *arr, int num_elems) {
        for(int i=0; i<num_elems; i++) {
                printf("%d ", arr[i]);
        }
        printf("\n");
}

/*
  Don't worry about this function. Generate a random number <max
 */
long random_at_most(long max)
{
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
int *genarr(unsigned siz)
{
        int *arr=malloc(siz*sizeof(int));
        for(unsigned i=0; i<siz; i++) {
                arr[i]=random_at_most(siz);
        }
        return arr;
}

void heapsort(int *arr, unsigned num_elems) {
        unsigned i;
        minheap h=heap_new(num_elems);
        for(i=0; i<num_elems; i++) {
                heap_push(h, arr[i]);
        }
        for(i=0; i<num_elems; i++) {
                arr[i]=heap_pop(h);
        }
        heap_free(h);
}


int main(void)
{
        clock_t t0, t1;
        float t;
        const unsigned num_elems=1000;
        int *arr=genarr(num_elems);
        printf("Initial array:\n");
        print_intarr(arr, num_elems);
        printf("\n");

        t0 = clock();
        heapsort(arr, num_elems);
        t1 = clock();

        printf("\nFinal array:\n");
        print_intarr(arr, num_elems);

        printf("\n\n");
        t = (((float) t1) - ((float) t0))/((float) CLOCKS_PER_SEC);
        printf("The sort operation took %f seconds\n", t);
        //don't forget to free!
        free(arr);
        return 0;
}
