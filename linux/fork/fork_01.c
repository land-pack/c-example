#include <stdio.h>
#include <string.h>
#include <sys/types.h>


#define MAX_COUNT 200
#define BUF_SIZE 100

int main(int argc, char * argv[]){
    
    pid_t pid;
    int i;
    char buf[BUF_SIZE];
    
    fork();
    //pid = getpid();
    pid = getpid();
    for(i=0; i < MAX_COUNT; i++){
        sprintf(buf, "This line from pid %d , value %d\n", pid, i);
        write(1, buf, strlen(buf));
    }
    return 0;
}
