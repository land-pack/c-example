// From: https://www.geeksforgeeks.org/how-to-deallocate-memory-without-using-free-in-c/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){
    char * ptr = (char*)malloc(sizeof(char) * 10);


    // Simple free call to deallocate memory
    //free(ptr);


    // How to deallocate dynamically allocate memory without using “free()” function.
    char * tmp = realloc(ptr, 0);
    if (tmp == NULL) {
        // your realloc didn't work and strp->data still points to the
        // the original location
        return -1;
    }

    ptr = tmp;
    return 0;
}
