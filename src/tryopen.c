#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void tryOpen(char *fname) {
	int fd = open(fname, O_RDONLY);
	printf("open(\"%s\") returns %d\n", fname, fd);
	if (fd < 0) {
		perror(" FAIL");
	} else {
		printf(" SUCCESS!\n");
		close(fd);
	}
}

void testTryOpen() {
	tryOpen("/something/not/exist");
	tryOpen("/dev/sda");
	tryOpen("/etc/passwd");
}

int main() {
	testTryOpen();
}
