#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

int buffer;
int count = 0;

void put(int value) {
	/* assert(count == 0); */
	pthread_t p1;
	count = 1;
	buffer = value;
}

int get() {
	/* assert(count == 1); */
	count = 0;
	return buffer;
}

void *producer(void *arg) {
	int loops = (int) arg;
	for (int i = 0; i < loops; i++) {
		put(i);
	}
	return NULL;
}

void *consumer(void *arg) {
	int time = (int) arg;
	while (time--) {
		int tmp = get();
		printf("%d\n", tmp);
	}
	return NULL;
}

void testVersionLockFree() {
	int time = 100;
	producer(time);
	consumer(time);
}

int main() {
	testVersionLockFree();
}

