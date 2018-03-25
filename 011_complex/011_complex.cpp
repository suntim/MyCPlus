// 011_complex.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct Complex
{
	float real;
	float image;
};

Complex operator + (Complex a, Complex b)
{
	Complex c;
	c.real = a.real + b.real;
	c.image = a.image + b.image;

	return c;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Complex t_comp1 = { 1, 2 }, t_comp2 = { 2, 3 };
	Complex t_comp3 = t_comp1 + t_comp2;
	cout << "t_comp3 = (" << t_comp3.real << "," << t_comp3.image <<")"<< endl;
	return 0;
}

