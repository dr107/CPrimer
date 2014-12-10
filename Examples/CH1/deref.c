#include <stdio.h>

void dereferencing(void)
{
        int x = 10;
        printf("The initial value of x is %d\n", x);

        int *xptr = &x;
        printf("The memory location of x is %p\n", xptr);

        /*
          Mutate the value of x
          This line means "set the four bytes of memory at xptr to
          the number 10"
        */
        (*xptr)=5;

        printf("When we dereference the memory location of x, we see %d\n",
               *xptr);
}

void deref_input(int* x) {
        printf("The ptr we got as input was %p\n", x);
        printf("The value we extracted by dereferencing was %d\n", *x);
}

void mutate_int(int x) {
        x=5;
}

int main(void) {
        int var=373;
        dereferencing();
        printf("\n\n");
        deref_input(&var);
        int x=373;
        mutate_int(x);
        printf("\n\n");
        printf("After noop call x=%d != 5\n", x);
	return 0;
}
