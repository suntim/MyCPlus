#include "stdafx.h"
#include "ring.h"
#include<iostream>
#include<iomanip>
using namespace std;


Ring::Ring(int n)
{
	m_pBegin = new Boy[n];
	m_pCurrent = m_pBegin;

	for (int i = 1; i <= n; i++, m_pCurrent = m_pCurrent->net)
	{
		m_pCurrent->net = m_pBegin + i%n;
		m_pCurrent->code = i;
	}
	DisplayAll();//在这里打印所有，而不是当前

	m_pCurrent = &m_pBegin[n - 1];//初始化为最后一个
}

void Ring::Count(int m)
{
	for (int i = 0; i < m; i++)
	{
		m_pGuard = m_pCurrent;
		//m_pCurrent = m_pCurrent->net;//可以这样吗？
		m_pCurrent = m_pGuard->net;

	}
}

void Ring::PrintCurrent()
{
	static int InLineNum = 0;
	if (InLineNum++ % 10 == 0)
	{
		cout << endl;
	}

	cout << setw(4) << m_pCurrent->code;
}

void Ring::ClearBoy()
{
	m_pGuard->net = m_pCurrent->net;
	m_pCurrent = m_pGuard;
}

void Ring::DisplayAll()
{
	cout << "打印所有成员：" << endl;
	Boy* pTmp = m_pCurrent;
	do
	{
		//cout << setw(4) << pTmp->code;//可以这样吗？
		//pTmp = pTmp->net;//可以这样吗？
		PrintCurrent();
		m_pCurrent = m_pCurrent->net;
	} while (pTmp!=m_pCurrent);

	cout << endl;
}
Ring::~Ring()
{
	delete[] m_pBegin;
}
