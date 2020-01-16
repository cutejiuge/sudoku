#pragma once
#ifndef _solve_H_
#define _solve_H_

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

#define MAX 1000005
using namespace std;

bool compare(char* a, const char* b);

class solve {
public:
	int argc;
	char** argv;
	int flag;
	solve(int argc, char** argv)
	{
		this->argc = argc;
		this->argv = argv;
		solveinput();
	}

	int solveinput()
	{
		if (argc != 3)   //�����ʽ����ȷ
		{
			cout << "Illegal paramater number" << endl;
			cout << "Input like this: [sudoku.exe -c n] or [sudoku.exe -s path]" << endl;
			return 1;
		}

		if (!(compare(argv[1], "-c") || compare(argv[1], "-s")))   //��ĸ����
		{
			cout << "The first parameter should only be -c or -s" << endl;
			cout << "-c means to generate the sudoku to file." << endl;
			cout << "-s means to solve the sudoku from the file." << endl;
			return 2;
		}

		if (compare(argv[1], "-c"))   //������������
		{
			
		}

		if (compare(argv[1], "-s"))   //����
		{
			
		}
		else 
		{

		}
			
	}
};

bool compare(char* a, const char* b)  //�����ж��ַ����ĺ���
{
	if (strlen(a) != strlen(b))
		return false;
	for (int i = 0; i < (int)strlen(a); i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
#endif
#pragma once
