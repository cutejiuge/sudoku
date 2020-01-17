/* 
 * solve.h
 * ������solve
 * ���ã�����ж������������������Ӧ���������ɶ�����������������
 * 
 */
#pragma once
#ifndef _solve_H_
#define _solve_H_

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
#include"base.h"
#include"answer.h"
#define MAX 1000005
using namespace std;

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

	int solveinput() //�жϲ�ִ������
	{
		if (argc != 3) //�����ʽ����ȷ
		{
			cout << "Illegal paramater number" << endl;
			cout << "Input like this: [sudoku.exe -c n] or [sudoku.exe -s path]" << endl;
			return 1;
		}

		if (strcmp(argv[1], "-c") && strcmp(argv[1], "-s"))   //��ĸ����
		{
			cout << "The first parameter should only be -c or -s" << endl;
			cout << "-c means to generate the sudoku to file." << endl;
			cout << "-s means to solve the sudoku from the file." << endl;
			return 2;
		}

		if (!strcmp(argv[1], "-c"))   //������������
		{
			int sum = 0;   //sudoku�ĸ���
			int len = strlen(argv[2]);
			for (int i = 0; i < len; i++)
			{
				if (!(argv[2][i] >= '0' && argv[2][i] <= '9'))   //������ַ����Ϸ����������֣�
				{
					cout << "The third paramater after -c should be number that indicate the sudoku you want." << endl;
					if (argv[2][i] == '+' || argv[2][i] == '-' || argv[2][i] == '/' || argv[2][i] == '*')
					{
						cout << "Please input the number!" << endl;
						return 8;
					}
					return 3;
				}
				sum = 10 * sum + argv[2][i] - '0';
			}

			if (sum > MAX || sum < 1)   //���ֹ���
			{
				cout << "The number is too large,the number should be 1-1000000" << endl;
				return 4;
			}
			/*----------------------------------*/
			/*�����������̶���*/
			/*...........*/

			FILE* file;
			file = freopen("sudoku.txt", "w", stdout);   //û���ļ�ʱ���Դ���
			Base base(sum, file);    //����Generator
			base.generate();
			/*----------------------------------*/

			return 5;
		}

		if (!strcmp(argv[1], "-s"))   //����
		{
			FILE* ans;
			FILE* question;   //������Ŀ
			question = freopen(argv[2], "r", stdin);
			if (!question)
			{
				cout << "The file path is not right,please check." << endl;
				return 6;
			}
			/*----------------------------------*/
			/*��������������*/
			/*...........*/
			ans = freopen("sudoku.txt", "w", stdout);
			Solver solver(question, ans);   //����Solver
			flag = solver.in();
			/*----------------------------------*/
			return 7;
		}
		
		return 8;   //����ִ�У���������
	}
};
#endif
