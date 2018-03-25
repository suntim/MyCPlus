// 013_Reference.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void swap1(int *p_a, int *p_b)//开辟了两个临时空间
{
	*p_a ^= *p_b;
	*p_b ^= *p_a;
	*p_a ^= *p_b;
}

void swap2(int &r_a, int &r_b)//引用没有开辟空间
{
	r_a ^= r_b;
	r_b ^= r_a;
	r_a ^= r_b;
}

//指针的引用，平级解决问题，不开辟空间
void swap3(char* &r_a, char* &r_b)
{
	char *tmp = r_a;
	r_a = r_b;
	r_b = tmp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a = 10;
	int& r_a = a;
	r_a = 100;
	printf("a = %d, r_a = %d\n", a, r_a);
	printf("&a = %p  &r_a = %p\n", &a, &r_a);

	//交换
	int b = 20;
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
	swap1(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	swap2(a, b);
	printf("a = %d, b = %d\n", a, b);

	//指针的引用
	char *p_a = "china";
	char *p_b = "tea";
	cout << "交换前 p_a = " << p_a << " , p_b = " << p_b << endl;
	swap3(p_a, p_b);//char * &r_p = p指针的引用
	cout << "p_a = " << p_a << " , p_b = " << p_b << endl;


	return 0;
}

