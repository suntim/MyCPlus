#include "stdafx.h"
#include<iostream>
#include <stdio.h>
#include <iomanip>
#include"josex.h"
#include"ring.h"

using namespace std;


//Jose::Jose(int boys=10,int begin=1,int m=3)
//{
//	
//}

void Jose::Initial()
{
	int num, begin, m;
	cout << "please input number of boys: " << endl;
	cin >> num;
	cout << "please input beginning position: " << endl;
	cin >> begin;
	cout << "please input count interval number: " << endl;
	cin >> m;
	cout << "总共成员：" << endl;

	if (num < 2)
	{
		cerr << "bad number of boys!!!" << endl;
		return;
	}

	if (begin < 0)
	{
		cerr << "bad beginning position!!!" << endl;
		return;
	}

	if (m<1 || m>num)
	{
		cerr << "bad interval number!!!" << endl;
		return;
	}

	//输入合法
	numOfBoys_ = num;
	beginPos_ = begin;
	interval_ = m;


}
void Jose::GetWinner()
{
	Ring r(numOfBoys_);//围成一圈
	r.Count(beginPos_);//转到开始位置起点
	cout << "结束：" << endl;
	for (int i = 1; i < numOfBoys_; i++)
	{
		r.Count(interval_);//数interval_个小孩
		r.PrintBoy();//打印输出当前环中小孩编号
		r.ClearBoy();//清理脱节小孩
	}

	cout << "\n获胜者：";
	r.PrintBoy();
	cout << endl;
}

Jose::~Jose()
{
	cout << "~Jose()" << endl;
}
