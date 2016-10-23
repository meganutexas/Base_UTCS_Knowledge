#include <stdio.h>
#include <stdlib.h>

void debug_backtrace(void);
void foo(void);
void bar(void);
void one(void);

#define RED "\033[31m\0"
#define WHITE "\033[0m\0"

//print the call stack
//code taken from the PintOS project
void debug_backtrace(void) {
	void** frame;

	printf("%sCALL STACK:%s %x", RED, WHITE, __builtin_return_address(0));
	for(frame = __builtin_frame_address(1);
		  frame > 0x1000 && frame[0] != NULL;
		  frame = frame[0])
		printf(" %x", frame[1]);
	printf("\n");
}

void foo(void) {
	debug_backtrace();
}

void bar(void) {
	foo();
}

void one(void) {
	bar();
}

int main() {
	debug_backtrace();
	one();

	return 0;
}
