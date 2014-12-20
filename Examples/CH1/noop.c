#include <stdio.h>

/*
  Set the value of the input to five? Maybe?
 */
void noop(int x)
{
        x=5;
}

/*
  set the value pointed to by the input to five.
 */
void mutate_int(int *xptr)
{
        *xptr=5;
}

int main(void)
{
        int x=373;
        noop(x);
        printf("After noop call, x=%d\n", x);

        int *xptr=&x;
        mutate_int(xptr);
        printf("After mutate_int call, x=%d\n", x);

        return 0;
}
