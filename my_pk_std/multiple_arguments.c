#include <stdio.h>

int v_print(int a, ...){
    
    int* p;
    int val, i=0;

    p = &a;
    for(i=0; i< a; i++){
        val = *p++;
        printf(" The %d ==> %d ==>%p\n", i, val, p);
    }
    p = NULL;
    return 0;
        
}


int main(int argc, char ** argv){
    v_print(2,3,4,5,5);
    return 0;
}
