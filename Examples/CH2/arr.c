#include <stdio.h>

void takearr(int buf[])
{
        printf("Size of buf in takearr = %zu\n", sizeof(buf));
        printf("Size of void* in takearr = %zu\n", sizeof(void*));
        printf("That's not a coincidence\n");
}

int main(void)
{
        int buf[100];
        printf("Size of buf in main = %zu\n", sizeof(buf));
        takearr(buf);
        return 0;
}
