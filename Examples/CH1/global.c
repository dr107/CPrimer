#include <stdio.h>

void incr_local(void)
{
        int count=0;
        printf("Local count=%d\n", count++);
}

int count=0;
void incr_global(void)
{
        printf("y=%d\n", y);
        printf("Global count=%d\n", count++);
}

void incr_static(void)
{
        static int count_static=0;
        printf("Static count=%d\n", count_static++);
}


int main(void)
{
        // will these ever print anything different?
        incr_local();
        incr_local();
        incr_local();

        // what about these?
        incr_global();
        incr_global();
        incr_global();

        incr_static();
        incr_static();
        incr_static();
}
