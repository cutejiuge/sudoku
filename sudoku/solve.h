#pragma once
#ifndef _CHECK_H_
#define _CHECK_H_

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

#define MAX 1000005
using namespace std;

bool compare(char* a, const char* b);

class Check {
public:
	int argc;
	char** argv;
	int flag;
	Check(int argc, char** argv)
	{
		this->argc = argc;
		this->argv = argv;
		checkinput();
	}

	int checkinput()
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
	
}
#endif
#pragma once
