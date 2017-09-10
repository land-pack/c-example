#include <stdlib.h>
#include <stdio.h>



struct b_struct {
	int a: 5;
	int b: 2;
	int c: 1;
};

int main(int argc, char *argv[])
{

	struct b_struct k;
	k.a = 12;
	k.b = 3;
	k.c = 1;
	printf("Hello I 3 Character ??! ??= \n");
	return 0;
}

