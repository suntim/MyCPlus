// 009_ConstIsChanged.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;

enum SEANSON{ Spr, Sum, Aut, Winter };

int _tmain(int argc, _TCHAR* argv[])
{
	//const明修栈道暗度陈仓
	const int a = 10;
	//int *t_p1 = &a;
	//*t_p1 = 100;

	SEANSON season = Sum;
	//season = 2;
	cout << "season = " << season << endl;

	//安全输入
	char name[10];
	cout << "输入九个：" << endl;
	fgets(name, 10, stdin);
	cout << "取九个 = " << name << endl;

	//你有多大脚，我有多大鞋
	string nn;
	cout << "输入无限个：" <<"【"<<nn.max_size()<<"】"<< endl;
	cin >> nn;
	cout << "无限个 = " << nn << endl; 
	cout << "大小 = " << nn.size() << endl;

	
	return 0;
}

