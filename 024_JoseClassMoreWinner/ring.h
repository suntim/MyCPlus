#pragma once
struct	Boy
{
	int code;
	Boy* net;
};
class Ring
{
public:
	Ring(int n);//构造环
	void Count(int m);//数m个小孩
	void PrintCurrent();//输出当前小孩编号
	void ClearBoy();//小孩脱钩
	void DisplayAll();//显示环中小孩
	~Ring();
protected:
	Boy* m_pBegin;
	Boy* m_pCurrent;
	Boy* m_pGuard;
};

