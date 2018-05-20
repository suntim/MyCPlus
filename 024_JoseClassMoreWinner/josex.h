#pragma once
class Jose
{
public:
	//Jose(int boys , int begin, int m, int win) :m_numOfBoys(6), m_beginPos(0), m_interval(3), m_winners(2)
	//{
	//	m_numOfBoys = boys;
	//	m_beginPos = begin;
	//	m_interval = m;
	//	m_winners = win;
	//};//不可以这样？

	Jose(int boys = 5, int begin = 1, int m = 3, int win=2)//防止出错
	{
		m_numOfBoys = boys;
		m_beginPos = begin;
		m_interval = m;
		m_winners = win;
	};
	void Initial();
	void GetWinner();
	~Jose();

protected:
	int m_numOfBoys;
	int m_beginPos;//开始位置数
	int m_interval;//数数
	int m_winners;//获胜者个数
};

