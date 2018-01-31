#include <stdio.h>
#include <string.h>
#include <time.h>

int my_strlen(const char * str){
    int i=0;
    for(i=0;; i++){
        if (*(str+i) == '\0'){
            break;
        }
    }
    return i;

}

int main(int argc, char *argv[]){
    char * p = "hello";
    char * p2 = (char*)malloc(sizeof(100));
    strcpy(p2, "hello");
    printf("%d\n", my_strlen(p));
    printf("%d\n", my_strlen(p2));
    
    // my_strlen PK strlen
    clock_t start, stop;
    start = clock();
    for (int j=0; j < 1000000; j ++){
        my_strlen(p2);
    }
    stop = clock();
    printf("My strlen Cost %6.3f\n", (double)(stop - start));
    
    // test strlen
    start = clock();
    for (int j=0; j < 1000000; j ++){
        strlen(p2);
    }
    stop = clock();
    printf("Std strlen Cost %6.3f\n", (double)(stop - start));


    free(p2);
    return 0;
}
