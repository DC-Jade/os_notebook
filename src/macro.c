#include <stdio.h>

#define FOREACH(_) _(X) _(Y) 
#define PASTE(X) static char* X##1, X##2;
#define PRINT_TOKEN(X) printf(#X ": %s\n", X);

void testPASTE() {
	FOREACH(PASTE);
	PASTE(hello);
	hello1 = "hello1";
	hello2 = "hello2";
	PRINT_TOKEN(hello1);
	PRINT_TOKEN(hello2);
}

int main() {
	testPASTE();
}
