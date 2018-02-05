#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#undef strlen

/* 
 * Return the length of the null-terminated string STR. Scan for
 * the null terminator quickly by testing four bytes at a time.
 */

  // size_t my_strlen (str) const char *str;
  size_t my_strlen(const char *str)
 {
    const char * char_ptr=str;
    const unsigned long int *longword_ptr;
    unsigned long int longword, magic_bits, himagic, lomagic;

    /*
     * Handle the first few characters by reading one character at a time.
     * Do this until CHAR_PTR is aligned on a longword boundary.
     */
    printf(" 'a' & 7 ==%lu\n", (unsigned long int) 'a' & 7);
    printf(" 'b' & 7 ==%lu\n", (unsigned long int) 'b' & 7);
    printf(" '0' & 7 ==%lu\n", (unsigned long int) '\0' & 7);

    for (char_ptr=str; ((unsigned long int) char_ptr & (sizeof(longword) -1)) !=0; ++char_ptr){
        printf("==>%c  = %lu\n", *char_ptr,(unsigned long int)(sizeof(longword) -1));
        if(*char_ptr == '\0'){
            return char_ptr - str;
        }
    }
    return 0;
 }

 int main(int argc, char * argv[]){
    char * s = "hello world!";
    size_t len =0;
    len = my_strlen(s);
    printf("The length of string ==%zu\n", len);
    return 0;
 }
    
