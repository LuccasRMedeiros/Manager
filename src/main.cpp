// This program idea is to orquestrate C and C++ projects, keep
// dependencies updated and versioned to anyone maintaining said project

#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;

static void mngr_showhelp(void)
{
	cout << "Manager is a helper to build and control dependencies for C"
		<< " and C++ projects. You can call it with one or many of the"
		<< " following commands:"
		<< endl
		<< "\t--help: Show this help message" << endl
		<< "\t--start: Start a new project creating a toml file" << endl;
}

static void mngr_startproj(char *sargv)
{
	fstream cmakefile;
	fstream srcfile;
	fstream incfile;

	try 
	{
		filesystem::create_directory("src");
		filesystem::create_directory("inc");

		cmakefile.open("CmakeLists.txt");
		cmakefile 
			<< "cmake_minimum_required(VERSION 3.31.6)" << endl << endl
			<< "project(\"myproject\" VERSION 0.0.0)" << endl << endl
			<< "file(GLOB SRC \"src\\.*c\")" << endl
			<< "set(INC \"inc\")" << endl << endl
			<< "add_executable(${CMAKE_PROJECT_NAME} ${SRC})" << endl;
		cmakefile.close();
		
		srcfile.open("src/main.c");
		srcfile 
			<< "#include <stdio.h>" << endl << endl
			<< "int main(void)" << endl 
			<< "{" << endl 
			<< "// Make your code here" << endl
			<< "\tprintf(\"Hello World!\\n\");" << endl << endl 
			<< "}" << endl;
		srcfile.close();

		incfile.open("inc/main.h");
		incfile 
			<< "#ifndef __MAIN_H__" << endl 
			<< "#define __MAIN_H__" << endl << endl 
			<< "// Prototype your functions here" << endl << endl 
			<< "#endif // __MAIN_H__" << endl;
		incfile.close();
	}
	catch (fstream::failure err)
	{
		cerr << "Failed to start project, exception: " << err.code() << endl 
			<< err.what() << endl;
	}
}

int main(int argc, char **argv)
{
	string curr;

	if (argc == 1)
	{
		mngr_showhelp();
		return 0;
	}

	for (int argn = 1; argn < argc; ++argn)
	{
		curr = argv[argn];
		if (curr == "--help")
		{
			mngr_showhelp();
		}
		else if (curr == "--start")
		{
			mngr_startproj(NULL);
		}
	}

	return 0;
}
