#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void Signal(int signum, int* handler);
void segfault_handler(int sig, siginfo_t *sig_info, void* context);

#define RED "\033[31m\0"
#define WHITE "\033[0m\0"

//wrapper for sigaction function, just to make things easier
void Signal(int signum, int* handler) {
	struct sigaction action, old_action;

	action.sa_handler = handler;
	sigemptyset(&action.sa_mask); // block sigs of type being handled
	action.sa_flags = SA_RESTART | SA_SIGINFO; //restart syscalls if possible
	if(sigaction(signum, &action, &old_action) < 0) {
		printf("%sSignal Error!%s", RED, WHITE);
		exit(-1); 
	}

	return (old_action.sa_handler);
}

//handles segfault
void segfault_handler(int sig, siginfo_t *sig_info, void* context) {
	char* faulting_addr = sig_info->si_addr;
	
	printf("\n%s----------------------------\n", WHITE);
	printf("%sSegfault at address:%s %p\n", RED, WHITE, faulting_addr);
	printf("----------------------------\n");

	//possibly some other printing that might be useful
	exit(-1);
}

int main() {
	printf("If a segfault happens within this program it's faulting address will be printed\n");
	Signal(SIGSEGV, segfault_handler); //install the signal handler for segfaults

	int* i;
	*i = 6;
}
