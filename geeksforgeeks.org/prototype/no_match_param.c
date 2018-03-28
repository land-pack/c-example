#include <stdio.h>

int main(){
    printf("return %d\n", func(1,2, 3));
    return 0;
}

int func(int a, int b, int c){
    return (a+b+c);
}
