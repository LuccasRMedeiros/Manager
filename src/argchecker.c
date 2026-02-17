#include "main.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static const char *classify(char *str)
{
	size_t strlength = strlen(str);
	size_t ch = 0;
	int isnegative = 0;

	if (str[0] == '-')
	{
		isnegative = 1;
		ch = 1;
	}

	while (ch < strlength)
	{
		if (!isdigit(str[ch]))
			return "String";

		++ch;
	}

	if (isnegative)
		return "Negative Number";
	return "Positive Number";
}

void check(int argc, char **argv)
{
	if (argc <= 0)
	{
		printf("No arguments were given.\n");
		return;
	}
	
	for (int arg = 0; arg < argc; ++arg)
	{
		printf("%s (%s)\n", argv[arg], classify(argv[arg]));
	}
}
