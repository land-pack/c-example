#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char * argv[])
{   
    // make space for a string on the heap
    char *s = malloc(strlen("cs50 rocks!"));

    // uh-oh... we didn't add space for the '\0'!
    strcpy(s, "cs50 rocks!");

    // but everything prints out just fine ..
    printf("%s\n", s);

    // clean up
    free(s);

    return 0;
}
