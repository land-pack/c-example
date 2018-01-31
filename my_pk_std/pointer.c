#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv){
    char a[32]="hello world";
    char *p = a;

    printf("The data is %s", a);
    printf("The data is %s", p);

    return 0;
}
