#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

void myInitFunc(int val) {
	printf("%d\n", val);
}

void (*pMyInitFunc) (int val);
void (*pMyInitFunc2) (int val);

void testMyInitFunc() {
	pMyInitFunc = myInitFunc;
	pMyInitFunc2 = &myInitFunc;
	printf("address of myInitFunc: %p\n", myInitFunc);
	printf("address of pMyInitFunc: %p\n", pMyInitFunc);
	printf("address of pMyInitFunc2: %p\n", pMyInitFunc2);
}
void testPfunction() {
	printf("testPfuntion = %p\n", testPfunction);
	printf("testPfuntion = %p\n", &testPfunction);
	printf("sizeof testPfuntion = %ld\n", sizeof(testPfunction));
	printf("sizeof testPfuntion = %ld\n", sizeof(&testPfunction));
}

int main(int argc, char *argv[]) {
	/** testPfunction(); */
	testMyInitFunc();
}
