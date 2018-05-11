// 021_JoseStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<iomanip>

using namespace std;

struct Jose//小孩结构
{
	int code;   //小孩编号
	Jose * next;//用于指向下一个小孩节点
};

//全局变量
int number;		 //小孩总数
int begin_number;//开始位置
int m;			 //数小孩间隔
Jose* pivot;	 //链表哨兵，剔除结点的前一个
Jose* pCur;		 //当前结点指针

//函数声明
int assign();			  //赋初值，成功1；失败0；
void initial(Jose* pJose);//初始化环形链表
void count(int m);		  //数m个小孩的位置
void process();			  //删除当前结点指针，处理m位置的链表


int _tmain(int argc, _TCHAR* argv[])
{
	if (!assign())
	{
		cout << "The program failed!" << endl;
		return 0;
	}

	Jose* pJose = new Jose[number];//分配结构数组
	initial(pJose);				   //初始化结构数组
	count(begin_number);
	process();

	cout << "\n\n the winner is :" << pCur->code << endl;
	delete[] pJose;
	return 0;
}


//赋初值，成功1；失败0；
int assign()			  
{
	int num, start_num, m_num;
	cout << "please input the Number:\n";
	cin >> num; 
	cout << "please input the Star at:\n";
	cin >> start_num;
	cout << "please input the Count Number:\n";
	cin >> m_num;

	if (num < 2)
	{
		cerr << "bad number of children\n";
		return 0;
	}

	if (start_num < 0)
	{
		cerr << "bad begin position\n";
		return 0;
	}

	if (m_num<1 || m_num>num)
	{
		cerr << "bad interval number\n";
		return 0;
	}

	number = num; begin_number = start_num; m = m_num;//赋值全局变量
	return 1;
}

//链表初始化
void initial(Jose* pJose)
{
	int lineCount = 0;
	Jose* px = pJose;
	for (int i = 1; i <= number; i++)
	{
		px->next = pJose + i%number;
		px->code = i;
		px = px->next;

		if ((lineCount++ % 10) == 0)//打印一行输出个数控制
		{
			cout << endl;
		}

		cout << setw(4) << i;
	}
	pCur = pJose + number - 1;//下一个便是第一个
}

//数m个小孩的位置
void count(int m)
{
	for (int i = 0; i < m; i++)
	{
		pivot = pCur;
		pCur = pivot->next;
	}
}


//删除当前结点指针，处理m位置的链表
void process()
{
	cout << "\n\nDelete children are: " << endl;
	int lineCout = 0;
	for (int i = 1; i < number - 1; i++)
	{
		count(m);//数m个小孩
		if ((lineCout++ % 10) == 0)//输出剔除的小孩
		{
			cout << endl;
		}
		cout << setw(4) << pCur->code;

		pivot->next = pCur->next;//小孩脱链
		pCur = pivot;
	}

	
}
