#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("location of code : %p\n", main);
	printf("location of heap : %p\n", malloc(1));
	int c = 3;
	printf("location of stack : %p\n", &c);
	int *x = &c;
	printf("location of old x : %p\n", &x);
	int *x1 = (int *) malloc(sizeof(int));
	printf("location of new x : %p\n", &x1);
	return 0;
}


