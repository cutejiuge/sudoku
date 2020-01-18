#include "CppUnitTest.h"
#include "../sudoku/base.h"
#include "../sudoku/solve.h"
#include "../sudoku/main.cpp"
#include <windows.h>
#include <cassert>
#include <cstring>
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*��Ԫ����*/
namespace UnitTest_Sudoku
{
	TEST_CLASS(UnitTest1)
	{
	public:
		int argc;
		char **argv;

		UnitTest1()
		{
			/*�������� "sudoku.exe -c 100" */
			argv = new char*[3];

			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");

			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-c");

			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "100");
		}

		TEST_METHOD(TestMethod1)   //�����ʽ����ȷ��ʱ��
		{
			/*�������� ��sudoku.exe��*/
			argc = 1;
			solve solve1(argc, argv);
			int result = solve1.solveinput();
			assert(result == 1);
		}

		TEST_METHOD(TestMethod2)   //����Ĳ���-c����-s��ʱ��
		{

			/*�������� "sudoku.exe -k 100" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-k");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "100");

			solve solve2(argc, argv);
			int result = solve2.solveinput();
			assert(result == 2);
		}

		TEST_METHOD(TestMethod3)   //���벻�����ֵ�ʱ��
		{
			/*�������� "sudoku.exe -c abc" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-c");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "abc");

			solve solve3(argc, argv);
			int result = solve3.solveinput();
			assert(result == 3);
		}

		TEST_METHOD(TestMethod4)   //��������ֹ���
		{
			/*�������� "sudoku.exe -c 1000009" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-c");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "1000009");

			solve solve4(argc, argv);
			int result = solve4.solveinput();
			assert(result == 4);
		}

		TEST_METHOD(TestMethod5)   //����������������������ȷ
		{
			/*�������� "sudoku.exe -c 10000" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-c");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "10000");

			solve solve5(argc, argv);
			int result = solve5.solveinput();
			assert(result == 5);
		}

		TEST_METHOD(TestMethod6)   //���������·������
		{
			/*�������� "sudoku.exe -s 100" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-s");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "100");

			solve solve6(argc, argv);
			int result = solve6.solveinput();
			assert(result == 6);
		}

		TEST_METHOD(TestMethod7)   //���������·����ȷ
		{
			/*�������� "sudoku.exe -s solver.txt" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-s");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "solver.txt");

			solve solve7(argc, argv);
			int result = solve7.solveinput();
			assert(result == 7);
		}

		TEST_METHOD(TestMethod8)   //������ʽ
		{
			/*�������� "sudoku.exe -c 10/5" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-c");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "10/5");

			solve solve8(argc, argv);
			int result = solve8.solveinput();
			assert(result == 8);
		}

		TEST_METHOD(TestMethod9) //�����Ƿ�ɹ�
		{
			/*�������� "sudoku.exe -s solver.txt" */
			argc = 3;

			argv = new char*[3];
			argv[0] = new char[100];
			strcpy_s(argv[0], 100, "sudoku.exe");
			argv[1] = new char[100];
			strcpy_s(argv[1], 100, "-s");
			argv[2] = new char[100];
			strcpy_s(argv[2], 100, "solver.txt");

			solve solve7(argc, argv);
			assert(solve7.flag == 0);
		}

		TEST_METHOD(TestMethod10)   //֤��û�������ظ��ľ���
		{
			int sudoku_number = 1000000;
			FILE* file;
			freopen_s(&file, "sudoku_temp.txt", "w", stdout);//д�ļ�
			assert(file != NULL);
			//��������
			Base sudoku_generator(sudoku_number, file);
			sudoku_generator.generate();
			fclose(stdout);

			freopen_s(&file, "sudoku_temp.txt", "r", stdin);//���ļ�
			assert(file != NULL);
			string s1;
			bool end = false;
			//���������뼯�ϣ��������������ĸ�����sudoku_number��ȣ������ظ�
			set<string> container;

			while (true)
			{
				int temp;
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (fscanf_s(file, "%d", &temp) == EOF)
						{
							end = true;
							break;
						}
						s1.push_back(temp + '0');
					}
					if (end) break;
				}
				if (end) break;
				container.insert(s1);
				s1.clear();
			}
			fclose(stdin);

			assert(container.size() != sudoku_number);
		}
	};
}