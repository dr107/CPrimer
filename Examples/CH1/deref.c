#include <stdio.h>

void dereferencing(void)
{
        int x = 10;
        printf("The initial value of x is %d\n", x);

        /*
          The variable xptr, which has type pointer to int, is initialized
          with the memory address of the integer x.
         */
        int *xptr = &x;
        printf("The memory location of x is %p\n", xptr);

        /*
          Mutate the value of x
          Syntactically, this line means "set the four bytes of memory at xptr
          to the number 5"
        */
        (*xptr)=5;

        printf("When we dereference the memory location of x, we see %d\n",
               *xptr);
}

/*
  This function, which takes a pointer to int as its argument, simply prints the
  numerical value of its input, and the data stored at it.
 */
void deref_input(int *x)
{
        printf("The ptr we got as input was %p\n", x);
        printf("The value we extracted by dereferencing was %d\n", *x);
}

void mutate_int(int x)
{
        x=5;
}

int main(void)
{
        dereferencing();
        printf("\n\n");

        int var=373;
        deref_input(&var);

        int x=373;
        mutate_int(x);
        printf("\n\n");
        printf("After noop call x=%d != 5\n", x);
        return 0;
}
