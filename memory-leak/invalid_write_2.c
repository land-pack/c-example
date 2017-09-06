#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]){

    char * t = malloc(strlen("Hello, World"));
    char * s = malloc(strlen("Good, morning"));

    strcpy(t, "Hello, World ,         Hello world!");
    //strcpy(s, "Good, morning");

    printf("t -->%s\n", t);
    printf("s -->%s\n", s);
    free(t);
    free(s);
}
