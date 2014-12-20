#include <stdio.h>

/*
  This is a function found on the internet. Someone who
  clearly doesn't know anything about C was trying to make
  a function that swaps the values of two integers.

  This is what happened. What's wrong with this picture?
  http://ramblings.implicit.net/posts/2014/5/3/do-not-trust-random-websites-about-c

*/

void swapnum(int *i, int *j)
{
        int temp = i;
        i = j;
        j = temp;
}


int main(void) {
        // see how this compiles initially? That's why you need the
        // void in the arguments
        int i=0, j=1;
        printf("Before the swap, i=%d, j=%d", i, j);
        swapnum(&i, &j);
        printf("After, i=%d, j=%d\n", i, j);
        printf("Did the swap work?\n");
        return 0;
}
