#include <stdio.h>
#include <stdlib.h>

//Formatting
#define NORMAL              "\033[0m\0"
#define BOLD 		    "\033[1m\0"
#define DIM                 "\033[2m\0"
#define UNDERLINED          "\033[4m\0"
#define INVERT              "\033[7m\0"
#define HIDDEN              "\033[8m\0"

//BACK Color
#define TEXT_DEFAULT        "\033[39m\0"
#define TEXT_BLACK          "\033[30m\0"
#define TEXT_RED            "\033[31m\0"
#define TEXT_GREEN          "\033[32m\0"
#define TEXT_YELLOW         "\033[33m\0"
#define TEXT_BLUE           "\033[34m\0"
#define TEXT_MAGENTA        "\033[35m\0"
#define TEXT_CYAN           "\033[36m\0"
#define TEXT_LIGHT_GREY     "\033[37m\0"
#define TEXT_DARK_GREY      "\033[90m\0"
#define TEXT_LIGHT_RED      "\033[91m\0"
#define TEXT_LIGHT_GREEN    "\033[92m\0"
#define TEXT_LIGHT_YELLOW   "\033[93m\0"
#define TEXT_LIGHT_BLUE     "\033[94m\0"
#define TEXT_LIGHT_MAGENTA  "\033[95m\0"
#define TEXT_LIGHT_CYAN     "\033[96m\0"
#define TEXT_WHITE          "\033[97m\0"

//Background Color
#define BACK_DEFAULT        "\033[49m\0"
#define BACK_BLACK          "\033[40m\0"
#define BACK_RED            "\033[41m\0"
#define BACK_GREEN          "\033[42m\0"
#define BACK_YELLOW         "\033[43m\0"
#define BACK_BLUE           "\033[44m\0"
#define BACK_MAGENTA        "\033[45m\0"
#define BACK_CYAN           "\033[46m\0"
#define BACK_LIGHT_GREY     "\033[47m\0"
#define BACK_DARK_GREY      "\033[100m\0"
#define BACK_LIGHT_RED      "\033[101m\0"
#define BACK_LIGHT_GREEN    "\033[102m\0"
#define BACK_LIGHT_YELLOW   "\033[103m\0"
#define BACK_LIGHT_BLUE     "\033[104m\0"
#define BACK_LIGHT_MAGENTA  "\033[105m\0"
#define BACK_LIGHT_CYAN     "\033[106m\0"
#define BACK_WHITE          "\033[107m\0"

int main() {
	printf("Formatting: \n");
	printf("   %s %s %s\n", NORMAL, "NORMAL", NORMAL);
	printf("   %s %s %s\n", BOLD, "BOLD", NORMAL);
	printf("   %s %s %s\n", DIM, "DIM", NORMAL);
	printf("   %s %s %s\n", UNDERLINED, "UNDERLINED", NORMAL);
	printf("   %s %s %s\n", INVERT, "INVERT", NORMAL);
	printf("   %s %s %s\n", HIDDEN, "HIDDEN", NORMAL);

	printf("Text Color: \n");
	printf("   %s %-20s %s %s %s\n", TEXT_DEFAULT, "TEXT_DEFAULT", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_BLACK, "TEXT_BLACK", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_RED, "TEXT_RED", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_GREEN, "TEXT_GREEN", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_YELLOW, "TEXT_YELLOW", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_BLUE, "TEXT_BLUE", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_MAGENTA, "TEXT_MAGENTA", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_CYAN, "TEXT_CYAN", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_LIGHT_GREY, "TEXT_LIGHT_GREY", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_LIGHT_RED, "TEXT_LIGHT_RED", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_LIGHT_GREEN, "TEXT_LIGHT_GREEN", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_LIGHT_YELLOW, "TEXT_LIGHT_YELLOW", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_LIGHT_BLUE, "TEXT_LIGHT_BLUE", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_LIGHT_MAGENTA, "TEXT_LIGHT_MAGENTA", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_LIGHT_CYAN, "TEXT_LIGHT_CYAN", BOLD, "BOLD", NORMAL);
	printf("   %s %-20s %s %s %s\n", TEXT_WHITE, "TEXT_WHITE", BOLD, "BOLD", NORMAL);

	printf("Background Color: \n");
	printf("   %s %s %s\n", BACK_DEFAULT, "BACK_DEFAULT", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_BLACK, "BACK_BLACK", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_RED, "BACK_RED", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_GREEN, "BACK_GREEN", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_YELLOW, "BACK_YELLOW", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_BLUE, "BACK_BLUE", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_MAGENTA, "BACK_MAGENTA", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_CYAN, "BACK_CYAN", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_LIGHT_GREY, "BACK_LIGHT_GREY", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_LIGHT_RED, "BACK_LIGHT_RED", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_LIGHT_GREEN, "BACK_LIGHT_GREEN", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_LIGHT_YELLOW, "BACK_LIGHT_YELLOW", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_LIGHT_BLUE, "BACK_LIGHT_BLUE", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_LIGHT_MAGENTA, "BACK_LIGHT_MAGENTA", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_LIGHT_CYAN, "BACK_LIGHT_CYAN", BACK_DEFAULT);
	printf("   %s %s %s\n", BACK_WHITE, "BACK_WHITE", BACK_DEFAULT);

	printf("You can mix and match formatting, text coloring and background coloring!\n");
}
