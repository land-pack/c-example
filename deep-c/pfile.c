#include <stdio.h>
#include <stdlib.h>



int main(int argc, char * argv[]){

	/*
	File describer declare by FILE type!
	*/
	FILE * fd;
	fd = fopen("hello.txt", "w+a");
	
	/*
	If the return of fopen with NULL,
	That's because file no exists!
	*/
	if (fd == NULL){
		perror("Open file failure");
		exit(EXIT_FAILURE);
	}
	/*
	If you can open a file succesful, you
	can keep work with it. like writing.
	*/

	fwrite("Hello, This is a text line", 26, 1, fd);
	
	/*
	After you finish the writing, you should
	alway close the file describer with fclose
	*/
	if (fclose(fd) == -1){
		perror("Close file failure");
		exit(EXIT_FAILURE);
	}
	printf("Hello Raspberr");
	return 0;
}
