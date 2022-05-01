#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/ostep-code/include/common.h"

int main(int argc, char *argv[]) {
	int *p = malloc(sizeof(int));
	assert(p != NULL);
	printf("(%d) adress of p: %p\n",
				 getpid(), (unsigned) p);
	*p = 0;
	while (1) {
		Spin(1);
		*p = *p + 1;
		printf("(%d) p: %d\n", getpid(), *p);
	}
	return 0;
}
