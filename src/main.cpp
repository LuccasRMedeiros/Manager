// This program idea is to be able to compile C and C++ projects, keep
// dependencies updated and versioned to anyone maintaining said project

#include <string.h>
#include <iostream>

void showhelp(void)
{
	std::cout << "Manager is a helper to build and control dependencies for C"
		<< " and C++ projects. You can call it with one or many of the"
		<< " following commands:"
		<< std::endl
		<< "\t--help: Show this help message" << std::endl;
}

int main(int argc, char **argv)
{
	for (int argn = 0; argn < argc; ++argn)
	{
		if (strcmp(argv[argn], "--help") == 0)
		{
			showhelp();
		}
	}
	return 0;
}
