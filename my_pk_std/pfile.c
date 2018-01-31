#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
	
	char *p = "Hello, This is a text line";
	printf("The size of string:%d",sizeof p);
	puts("");
	printf("The length of string:%d",strlen(p));
	puts("");

	fwrite(p, sizeof p, 1, fd);
	
 	printf("The fd=%d -- size of fd=%d", fd, sizeof fd);
	/*
	After you finish the writing, you should
	alway close the file describer with fclose
	*/
	if (fclose(fd) == -1){
		perror("Close file failure");
		exit(EXIT_FAILURE);
	}
	printf("Hello Raspberr");
	puts("");
	
	/*
	Read a file from current path
	*/
	fd = NULL;
	fd = fopen("test.txt", "r+");
	if (fd == NULL){
		perror("Open file error");
		exit(EXIT_FAILURE);
	}
	char * buffer;
	buffer = (char*)malloc(sizeof(buffer) * 1024);
 	printf("The address of buffer=%x -- size=%d --  fd=%d -- typeof df=%d", buffer, sizeof buffer, fd, sizeof fd);
	puts("");
	/* Read the line to buffer
	*/
	size_t word_len;
	//word_len = read(fd, buffer, 10);
	word_len =fread(buffer, 10, 2, fd);
	if (word_len == -1){
		perror("Read Error:");
	}
	printf("Read words=%d ==> ", word_len);
	puts(buffer);
	puts("");

 	free(buffer);
	/*
	After you finish the writing, you should
	alway close the file describer with fclose
	*/
	if (fclose(fd) == -1){
		perror("Close file failure");
		exit(EXIT_FAILURE);
	}

	return 0;
}
