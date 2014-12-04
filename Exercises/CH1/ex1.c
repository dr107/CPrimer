#include <stdio.h>

//type signature?
void mutate_int() {
        //do things?
}

int main(void) {
        //ever seen hexadecimal before?
        int x = 0xdeadbeef;
        // see how this compiles initially? That's why you need the
        // void in the arguments
        mutate_int(x);
        return 0;
}
