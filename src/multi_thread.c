#include "../include/thread.h"

void Ta() { while (1) { printf("a"); } }
void Tb() { while (1) { printf("b"); } }

void Test1() {
	create(Ta);
	create(Tb);
}

int x = 0;
void Thello(int id) {
	printf("Thread id: %d\n", id);
	usleep(id * 10000);
	printf("Hello from thread #%c\n", "123456789ABCDE"[x++]);
}

void Test2() {
	for (int i = 0; i < 10; ++i)
		create(Thello);
}

void Test3() {
	const int kn = 1000000;
	long sum  = 0;
	void Tsum() { for (int i = 0; i < kn; ++i) { sum++; } }
	create(Tsum);
	create(Tsum);
	join();
	printf("sum = %ld\n", sum);
}

int main() {
	//Test2();
	Test3();
}
