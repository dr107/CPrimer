#include <stdio.h>

//type signature?
void mutate_int()
{
        //do things?
}

/*
  This is a function found on the internet. Someone who
  clearly doesn't know anything about C was trying to make
  a function that swaps the values of two integers.

  This is what happened. What's wrong with this picture?

  void swapnum_bad(int *i, int *j)
  {
    int temp = i;
    i = j;
    j = temp;
  }

*/

/*
  Here's how you actually do it. Does this make sense?
 */
void swapnum(int *i, int *j)
{
        int temp = *i;
        *i = *j;
        *j = temp;
}


int main(void) {
        //ever seen hexadecimal before?
        int x = 0xdeadbeef;
        // see how this compiles initially? That's why you need the
        // void in the arguments
        mutate_int(x);
        return 0;
}
