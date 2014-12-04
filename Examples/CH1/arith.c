#include <stdio.h>

void incrementing(void) {
        int *intptr=(int*) 0;

        char *charptr=(char*) 0;

        printf("Incrementing intptr gives you %p\n", ++intptr);
        printf("Incrementing charptr gives you %p\n", ++charptr);
}

void deadbeef(void) {
        int x=0xdeadbeef;
        int *ptr=&x;

        /*You can declare an integer is unsigned*/
        unsigned int i;
        unsigned char *chrptr=(unsigned char*) ptr;

        for(i=0; i<sizeof(int); i++) {
                printf("Byte %d=%x\n", i, *chrptr);
                chrptr++;
        }
        printf("\n");
}

int main(void) {
        //nothing to see here.....
        printf("Output of incrementing():\n");
        incrementing();
        printf("\n\nOutput of deadbeef()\n");
        deadbeef();

        return 0;
}
