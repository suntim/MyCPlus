#include "stdafx.h"
#include "ring.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Ring::Ring(int n)
//{
//	pBegin_ = new Boy[n];//动态分配小孩结构数组
//	pCurrent_ = pBegin_;
//	for (int i = 1; i <= n; i++, pCurrent_ = pCurrent_->next)//为什么放这里才行，理由如下1，2，3，4顺序
//	{
//		
//		pCurrent_->next = pBegin_ + i%n;
//		pCurrent_->code = i;
//		PrintBoy();
//		
//	}
//	cout << endl;
//	pCurrent_ = &pBegin_[n - 1];//当前位置处于最后一个，则下次从1开始
//}

Ring::Ring(int n)
{
	pBegin_ = new Boy[n];//动态分配小孩结构数组
	pCurrent_ = pBegin_;
	for (int i = 1; i <= n; i++)//为什么放这里才行
	{

		pCurrent_->next = pBegin_ + i%n;
		pCurrent_->code = i;
		PrintBoy();
		pCurrent_ = pCurrent_->next;//为什么放这里才行
	}
	cout << endl;
	pCurrent_ = &pBegin_[n - 1];//当前位置处于最后一个，则下次从1开始
}

void Ring::Count(int m)
{
	for (int i = 0; i < m; i++)
	{
		pivot_ = pCurrent_;//获取删除节点的前一个
		pCurrent_ = pCurrent_->next;
	}
}

void Ring::PrintBoy()
{
	static int numInline;
	if (numInline++ % 10 == 0)
	{
		cout << endl;
	}
	cout << setw(4) << pCurrent_->code;
}


void Ring::ClearBoy()
{
	pivot_->next = pCurrent_->next;
	pCurrent_ = pivot_;
}

Ring::~Ring()
{
	delete[] pBegin_;
}
