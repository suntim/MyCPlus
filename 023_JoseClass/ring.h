#include <iostream>

using namespace std;
struct  Boy
{
	int code;
	Boy * next;
};

class Ring
{
public:
	Ring(int n);//构造函数，初始化
	void PrintBoy();//输出打印当前小孩编号
	void Count(int m);//数小孩
	void ClearBoy();//将小孩剔除
~Ring();
protected:
	Boy* pBegin_;
	Boy* pivot_;
	Boy* pCurrent_;
};

