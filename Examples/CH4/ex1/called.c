#include <stdio.h>

extern int buf[];

void printstuff(void)
{
        printf("We're in printstuff\n");
        printf("Main's buf = {%d %d %d}\n", buf[0], buf[1], buf[2]);
}
