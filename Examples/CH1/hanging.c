#include <stdio.h>

/*
  This returns a hanging pointer, and therefore produces a
  compiler warning.
 */
int *hanging(void)
{
        int x = 373;
        // return a pointer to a local variable.
        return (&x);
}

int main(void)
{
        int *ptr=hanging();
        printf("When you dereference ptr, you get %d ?= 373\n", *ptr);
        printf("Technically the value is unspecified, so it might be 373.\n");
        return 0;
}
