#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
  //printf("hello wolrd\n");
	//while (1) {}
	syscall(SYS_exit, 42);
}
