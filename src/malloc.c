#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *pi_heap = (int *) malloc(sizeof(int));

void testMalloc() {
	printf("size of pointer to int in heap: %p\n", pi_heap);
	printf("value pointerd by pi_heap: %d\n", *pi_heap);
	char *src = "hello";
	char *dst = (char *) malloc(strlen(src) + 1);
	/** char *dst; */
	strcpy(dst, src);
	printf("%s\n", dst);
}

void testStrlen() {
	char *s = "hello world";
	printf("size of s: %d\n", strlen(s));
	for (int i = 0; i < strlen(s); ++i) { printf("%c\n", s[i]); }
}

int main(int argc, char *argv[]) {
	int *pi = (int *) malloc(10 * sizeof(int));
	printf("size of pointer to int: %d\n", sizeof(pi));
	free(pi);
	int ia[10];
	printf("size of int array: %d\n", sizeof(ia));

	testStrlen();
	testMalloc();
	free(pi_heap);
	return 0;
}
