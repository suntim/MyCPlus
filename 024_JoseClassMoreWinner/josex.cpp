#include "stdafx.h"
#include "josex.h"
#include<iostream>
#include "ring.h"
using namespace std;


void Jose::Initial()
{
	int num, begin, m, winner;
	cout << "Please input the number of boys: \n";
	cin >> num;
	cout << "Please input the beginning position: \n";
	cin >> begin;
	cout << "Please input the interval per count: \n";
	cin >> m;
	cout << "Please input the number of winners: \n";
	cin >> winner;


	if (num < 2)
	{
		cerr << "bad number of boys." << endl;
		return;
	}

	if (begin < 0)
	{
		cerr << "bad begining position." << endl;
		return;
	}

	if (m<1 || m>num)
	{
		cerr << "bad interval number." << endl;
		return;
	}

	if (winner < 1 || winner >= num)
	{
		cerr << "bad number of winners." << endl;
		return;
	}

	m_numOfBoys = num;
	m_beginPos = begin;
	m_interval = m;
	m_winners = winner;
}


void Jose::GetWinner()
{
	Ring r(m_numOfBoys);
	r.Count(m_beginPos);
	cout << "淘汰成员：" << endl;
	for (int i = 1; i < m_numOfBoys - m_winners + 1; i++)
	{
		r.Count(m_interval);
		r.PrintCurrent();
		r.ClearBoy();
	}

	cout << "\n最终获胜者名单：" << endl;
	r.DisplayAll();
}
Jose::~Jose()
{
	cout << "~Jose()" << endl;
}
