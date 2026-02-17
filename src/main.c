#include "main.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	printf("Hello, this is the test program.\n");
	printf("It tests what arguments where given to the program.\n");
	printf("Let's start!\n");

	check(argc - 1, argv + 1);

	return 0;
}
