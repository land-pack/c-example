#include <stdlib.h>
#include <string.h>



struct line{
    int length;
    char * contents[0];
};


int main(int argc, char **argv){
    int this_length = 10;
    struct line * the_line = (struct line*)malloc(sizeof(struct line) + this_length);
    the_line->length = this_length;
    memset(the_line->contents, 'a', this_length);
    return 0;
}
