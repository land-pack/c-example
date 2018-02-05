#include <stdio.h>

int main(){

    // infinite loop
    int j=20;
	for (unsigned int i = 10; i >= 0; i--){
    	printf("%u\n", i);
        j--;
        if (j==0) break;
	}

    unsigned int k = 4294967295;
    printf("k == %u\n", k);
    k++;
    printf("k == %u\n", k);

    int h = 4294967295/2;
    int v = -4294967295/2 -1;
    printf("h is ==>%d\n",h);
    printf("v is ==>%d\n",v);
    v--;
    h++;
    printf("h is ==>%d\n",h);
    printf("v is ==>%d\n",v);

	return 0;
}
