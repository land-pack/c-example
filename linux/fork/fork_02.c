#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 200

void processParent(void);
void processChild(void);


int main(int argc, char * argv[]){
    
    pid_t pid;
    int i;
    pid = fork();
    if( pid ==0){
        // In child process
        processChild();
    }else if (pid > 0){

        // In parent process
        processParent();
    }
    return 0;
}


void processParent(void){
    int i;
    for(i=0; i < MAX_COUNT; i++){
        printf("I am from child process i:%d\n", i);
    }
}

void processChild(void){
    int i;
    for(i=0; i < MAX_COUNT; i++){
        printf("I am from parent process i:%d\n", i);
    }
}
