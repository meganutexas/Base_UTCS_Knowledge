#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void Signal(int signum, int* handler);
void segfault_handler(int sig, siginfo_t *sig_info, void* context);
void print_trump(void);

#define RED "\033[31m\0"
#define WHITE "\033[0m\0"
#define BACK_WHITE "\033[107m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define BACK_BLACK "\033[40m"
#define BLUE "\033[34m"

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

	if (faulting_addr == NULL)
		print_trump();

	//possibly some other printing that might be useful
	exit(-1);
}

void print_trump(void) {
printf("BUT I HAVE THE BEST POINTERS!\n");
printf("%s", BACK_BLACK);
printf("                                             %s',;;::::::;;::%sccclooooooodddd:'                     \n", YELLOW, RED);
printf("                                              %s',,;;:::;:::%sccclllloollllclool:'                   \n", YELLOW, RED);
printf("                                             %s',;;;::::::%sccclllllcllllloodxo:,                   \n", YELLOW, RED);
printf("                                              %s';:;;%scloooooodddooolllooddxkd;''                  \n", YELLOW, RED);
printf("                                              %s',;;:cc%sllodxxxxkxdoooodxxxxxo;';;'                \n", YELLOW, RED);
printf("                                             %s''.';%scllooooodxxoloodxdxxxddl:clc,                 \n", YELLOW, RED);
printf("                                             %s',;;%scolloxdlokxdolldkkkkxddolodc                   \n", YELLOW, RED);
printf("                                             %s;c:;%slddddxxddxkkkkkkkOOkxdddxxx;\n", YELLOW, RED);
printf("                                               %s:cc::%slddxxdodkkxxkOOkkxxddddkkl\n", YELLOW, RED);
printf("                                                 %s,,;;;;coddoloxxoodxkxdoooooll:\n", RED);
printf("                                                     %s,;:clooc:llodxxxddooool'\n", RED);
printf("                                                    %s.';;:cloooxxxxxxdddoool:. \n", RED);
printf("                                   %s......            %s',,:clcc%s;;;:%scoddddollc,.%s ..........\n", WHITE, RED, WHITE, RED, WHITE);
printf("                        %scc,%s.....                     %s.';;:cc:::ccclooolllcc;.         %s........\n", RED, WHITE, RED, WHITE);
printf("                       %s,dx:.%s                          %s.';::clccllooddollcckx.               %s...\n", RED, WHITE, RED, WHITE);
printf("                       %s'ox:.%s                           .:c;;:llooooolcc:ckXx.    .              ....\n", RED, WHITE);
printf("                   %s':lcldxc.%s                            ;ol;%s'''''''''%s;cxKNXl.                      .\n", RED, WHITE, BLUE, WHITE);
printf("             %s'',:oddoldkxxl.%s                            .d0kdl:%s'. .;%soOXWNN0,                        \n", RED, WHITE, BLUE, WHITE);
printf("           %s.;lollccdxl:coxl'',.%s                         .oXXXXk%s,. .;%sd0NWNNd.                       \n", RED, WHITE, BLUE, WHITE);
printf("          %s.:l::loc:cllldxoldo.%s                          ;KNX0kl,%s...%scx0NWK:...                      \n", RED, WHITE, BLUE, WHITE);
printf("          %s,dxxkkkxddxkkdoodl.%s                          .kXXNNKdcckNNNNNk' ....                   \n", RED, WHITE);
printf("          %s.lkkkkxxkkkxxdoodl.%s                   ....   .oNNNXd%s,..%sxWWWNNd. ... ...   ..            \n", RED, WHITE, BLUE, WHITE);
printf("          %s,dkkkkkOOkxxxxxxl.%s            .        ..    ;0NKo%s. ..%slXWWWXc....  .co,   ...          \n", RED, WHITE, BLUE, WHITE);
printf("          %s.okOkkkOkkxkkkxdc.%s       . .....             'kXk'%s .,%sl:o0xOO, ..  ...,.                \n", RED, WHITE, BLUE, WHITE);
printf("     ...  %s.cxkkkkOkkkkkxdl.%s         .......            .xXo%s..:%sOd.'c.lx. ..  . .       .          \n", RED, WHITE, BLUE, WHITE);

}

int main() {
	printf("If a segfault happens within this program it's faulting address will be printed\n");
	Signal(SIGSEGV, segfault_handler); //install the signal handler for segfaults

	int* i;
	*i = 6;
}
