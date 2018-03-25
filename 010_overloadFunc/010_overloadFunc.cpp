// 010_overloadFunc.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "MyStringLen.h"
#include <string.h>
using namespace std;	

void print(int a)
{
	printf("In print(int a)\n");
}

void print(char a)
{
	printf("In print(char a)\n");
}

void print(long a)
{
	printf("In print(long a)\n");
}

void print(float a)
{
	printf("In print(float a)\n");
}

void print(double a)
{
	printf("In print(double a)\n");
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	int a = 1;
	print(a);

	//函数重载的二义性
	//double 到 int float
	//print(3.4);
	print(3.4f);
	//int 到 long double
	print(1);


	//测试 mystringlen
	int str_len = mystringlen("china");
	cout << "str_len = " << str_len << endl;

	char *str_1 = "chi";
	int str_len1 = mystringlen(str_1);
	cout << "str_len1 = " << str_len1 << endl;

	return 0;
}

