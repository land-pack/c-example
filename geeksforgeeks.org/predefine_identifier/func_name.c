#include <stdio.h>


int main(){
    printf("In file:%s In function: %s In line: %d\n", __FILE__, __func__, __LINE__);
    return 0;
}
