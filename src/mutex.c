#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
static int counter = 0;

typedef struct myarg_t {
	char *name;
	int *counter;
} myarg_t;

void *mythread(void *arg) {
	printf("%s begin\n", arg);
	for (int i = 0; i < 1e7; i++) {
		pthread_mutex_lock(&lock);
		counter = counter + 1; pthread_mutex_unlock(&lock);
	}
	printf("%s end\n", arg);
}

void *mythread1(myarg_t *arg) {
	pthread_mutex_lock(&lock);
	printf("%s begin: counter = %d\n", arg->name, *(arg->counter));
	for (int i = 0; i < 1e7; i++) {
		counter = counter + 1;
	}
	printf("%s end: counter = %d\n", arg->name, *(arg->counter));
	pthread_mutex_unlock(&lock);
}

void testMutex1(void) {
	pthread_t p1, p2;
	int rc;
	printf("begin main: counter = %d\n", counter);
	rc = pthread_create(&p1, NULL, mythread, "A"); assert(rc == 0);
	rc = pthread_create(&p2, NULL, mythread, "B"); assert(rc == 0);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("end main: counter = %d\n", counter);
}

void testMutex2(void) {
	pthread_t p1, p2;
	myarg_t p1_arg = { "C", &counter };
	myarg_t p2_arg = { "D", &counter };
	int rc;
	printf("main begin: counter = %d\n", counter);
	rc = pthread_create(&p1, NULL, mythread1, (void *) &p1_arg); assert(rc == 0);
	rc = pthread_create(&p2, NULL, mythread1, (void *) &p2_arg); assert(rc == 0);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	printf("end main: counter = %d\n", counter);
}

int main() {
	/** testMutex1(); */
	testMutex2();
}
