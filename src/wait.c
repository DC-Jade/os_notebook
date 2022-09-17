#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

void *child(void *arg) {
	printf("child\n");
	return NULL;
}

void testChild() {
	printf("parent: begin\n");
	pthread_t p;
	int rc;
	rc = pthread_create(&p, NULL, child, NULL); assert(rc == 0);
	printf("parent: end\n");
	pthread_join(p, NULL);
}

int main(int argc, char *argv[]) {
	testChild();
	return 0;
}
