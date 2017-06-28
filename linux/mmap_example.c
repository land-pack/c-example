/* for args */
#include <stdarg.h>
/* For the size of the file. */
#include <sys/stat.h>
/* This contains the mmap calls. */
#include <sys/mman.h>
/* There are for error printing */
#include <errno.h>
#include <string.h>
#include <stdarg.h>
/* This is for open */
#include <fcntl.h>
#include <stdio.h>
/* For exit. */
#include <stdlib.h>
/* For the final part of the example */
#include <ctype.h>
#include <unistd.h>
/* "checks"  checks "test" and prints an error and exits
   if it is true. */

static void
check (int test, const char * message, ...)
{
    if(test){
        va_list args;
        va_start(args, message);
		printf("args, %s", args);
		fprintf(stderr, message, args);
        va_end(args);
        fprintf(stderr, "\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv){
    /* The file descriptor. */
    int fd;
    /* Information about the file */
    struct stat s;
    int status;
    size_t size;
    /* The file name to open. */
    const char * file_name = "me.txt";
    /* The memory-mapped thing itself */
    const char * mapped;
    int i;

    /* Open the file for reading. */
    fd = open(file_name, O_RDONLY);
    check(fd < 0, "open %s failed: %s", file_name, strerror(errno));

    /* Get the size of the file. */
    status = fstat(fd, &s);
    check(status < 0, "stat %s failed: %s", file_name, strerror(errno));
    size = s.st_size;
	printf("the file size is %i\n", size);
    /* Memory-map the file. */
    mapped = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
    check(mapped == MAP_FAILED, "mapped %s failed: %s",
            file_name, strerror(errno));

	printf("mapped=%s", mapped);
    /* Now do something with the information. */
    for(i = 0; i < size; i++){
        char c;
        c = mapped[i];
        if(isalpha(c) && ! isspace(c)){
            putchar(c);
        }
        if(i % 80 == 79){
            putchar('\n');
        }
    }
    return 0;
}
