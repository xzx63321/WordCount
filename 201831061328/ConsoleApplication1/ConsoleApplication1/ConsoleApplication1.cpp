// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include"pch.h"
#include <stdio.h> 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void  wordnumber(ifstream &ch) //字符统计
{
	
	string d;
	int num = 0;
	while (getline(ch, d)) //以行为单位读入文件
		if(d > "a"&&d<"z" || d>"A"&&d < "Z" || d>"0"&& d <"9"||d==" ")
		num += d.size(); //累计字符数

	cout << "字符数： "<< num << endl;

}
void linesnumber(ifstream &ch)//行数统计
{
	ch.clear();
	ch.seekg(0, ios::beg);
	char d ;
	int num=1;
	while (!ch.eof())
	{
		ch.read(&d, 1);
		if (d == '\n')
			num++;
	}
	cout << "有效行数为：" << num << endl;
}
void wordsnumber(ifstream &ch)
{
	ch.clear();
	ch.seekg(0, ios::beg);
	char word[30] = {0},st;
	int i = 0,num=0,j=0,flag=0;
	while (!ch.eof())      /*统计文件中有多少个单词*/
	{
		ch.read(&st, 1);
			word[i] = st;
			i++;
			if(st==' '||st=='\t'||st=='\n')
			{
				if (word[i - 1] != ' ' || word[i - 1] != '\t' || word[i - 1] != '\n')
				{
					if (i >= 3)
					{
						for (j = 0; j < 4; j++)
						{
							if (word[j] > 'a'&&word[j]<'z' || word[j]>'A'&&word[j] < 'Z')

								flag++;
							if (flag >= 4)
							{
								num++;
								for (j = 0; j < i; j++)
									word[j] = 0;
								i = 0;
							}

						}
						for (j = 0; j < i; j++)
							word[j] = 0;
						i = 0;
					
					}

				}
				
			}
			
	}
	
	cout << "单词数目: " << num << endl;
}
int main()
{
	ifstream in;
	string filename;                   //声明变量 存储文件名 
	cout << "Please input filename to Open:" << endl;    //提示输入文件名 
	getline(cin, filename, '\n');                              //接收输入文件名 
	in.open(filename);
	if (!in)
	{
		cout << "error" << endl;
		exit(0);
	}
		wordnumber(in);
		linesnumber(in);
		wordsnumber(in);
		in.close();
	return  0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
