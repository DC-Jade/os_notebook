#include <stdio.h>
#include <assert.h>
#include <pthread.h>

static volatile int counter = 0;

void *mythread1(void *arg) {
	printf("%s\n", (char *) arg);
	return NULL;
}

void testMythread1(void) {
	pthread_t p1, p2;
	/** br int rc; */
	int rc;
	printf("main: begin\n");
	rc = pthread_create(&p1, NULL, mythread1, "A"); assert(rc == 0);
	rc = pthread_create(&p2, NULL, mythread1, "B"); assert(rc == 0);
	// join waits for the threads to finish
	rc = pthread_join(p1, NULL); assert(rc == 0);
	rc = pthread_join(p2, NULL); assert(rc == 0);
	printf("main: end\n");
	return NULL;
}

void *mythread2(void *arg) {
	printf("%s: begin\n", (char *) arg);
	for (int i = 0; i < 1e7; i++) {
		counter = counter + 1;
	}
	printf("%s: end\n", (char *) arg);
	return NULL;
}

void testMythread2(void) {
	pthread_t p1, p2;
	printf("main: begin (counter = %d)\n", counter);
	pthread_create(&p1, NULL, mythread2, "A");
	pthread_create(&p2, NULL, mythread2, "B");

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("main: done with both (counter = %d)\n", counter);
	return NULL;
}

int main(int argc, char *argv[]) {
	/** testMythread1(); */
	testMythread2();
	return 0;
}
