#include <stdio.h>
/*This is where malloc and free live*/
#include <stdlib.h>

/*
  Many of these functions are already implemented in the C standard libraries,
  but it's good to implement them for practice.
 */

/*
  String equality. Returns 1 if s1 and s2 are the same string, otherwise
  returns 0.

  Requires that s1 and s2 are properly allocated, null-terminated
  C strings.
 */
int streq(char* s1, char* s2) {
        char c1=*s1;
        char c2=*s2;
        /*
          The loop exits when either string
          ends (indicated by the null character), or any
          character is different between the
          strings. This could have been done more elegantly
          with a for loop, but incrementing multiple variables
          in a for loop is confusing when you've never seen it
          before.
        */
        while(c1!=0 || c2!=0) {
                c1=*s1;
                c2=*s2;
                if (c1 != c2) {
                        //return false
                        return 0;
                }
                s1++;
                s2++;
        }
        /*
          The loop exiting means we're at the end of one string, we return
          whether they both ended at the same time.
         */
        return c1==0 && c2==0;
}


/*
  You can heap allocate strings just like normal arrays.

  Since they are just normal arrays. Return "abcd".
 */
char *mkabcd(void) {
        //note the extra space for the null character
        char *str=malloc(5*sizeof(char));
        str[0]='a';
        str[1]='b';
        str[2]='c';
        str[3]='d';
        //null-terminated......
        str[4]=0;
        // Look, I'm returning a pointer to heap memory
        return str;
}

void test_streq(void)
{
        char *s1="abcd";
        char *s2="abcd";
        char *s3="abcde";
        char *s4="abce";
        char *s5=mkabcd();

        printf("%s is equivalent to %s is %s\n", s1, s2,
               streq(s1, s2) ? "true" : "false");
        printf("%s is equivalent to %s is %s\n", s1, s3,
               streq(s1, s3) ? "true" : "false");
        printf("%s is equivalent to %s is %s\n", s1, s4,
               streq(s1, s4) ? "true" : "false");
        printf("%s is equivalent to %s is %s\n", s1, s5,
               streq(s1, s5) ? "true" : "false");

        free(s5);

}

/*
  TODO:

  Get the character at position i of string s1.

  Requires that the string is properly-allocated, and null-terminated.

  If the string is less than i+1 characters long, return the null character.
 */
char string_getchar(char *s, unsigned int i)
{

        return 0;
}

/*
  TODO:

  Find the position of a character in a string

  Requires that the string is properly-allocated, and null-terminated.

  If the string does not contain the character, return -1.
 */
int string_findchar(char *s, char c)
{
        return -1;
}

/*
  TODO

  Get length of a string

  Requires that the string is properly-allocated, and null-terminated.
 */
int string_len(char *s)
{
        return 0;
}

int main(void)
{
        test_streq();
        return 0;
}
