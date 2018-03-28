#include <stdio.h>

int x = 10;

int f(){
    return x;
}

int g(){
    int x = 1;

    return f();
}

int main(){

    printf("g return %d\n", g());
    return 0;
}
