#include "stdafx.h"
#include "MyString.h"
#include <iostream>
#include <string.h>


int MyString::m_number = 0;

MyString::MyString()
{
	m_str = new char[1]; //开辟一个字符空间
	*m_str = '\0';//默认空字符串
	m_length = 0;
	m_number++;
}

MyString::MyString(const char *t_str)
{
	if (t_str == NULL)
	{
		m_str = new char[1]; //开辟一个字符空间
		*m_str = '\0'; //默认空字符
		m_length = 0; //默认长度为0
	}
	else
	{
		m_length = strlen(t_str);
		m_str = new char[m_length + 1];
		strcpy(m_str, t_str);
	}
	m_number++;
}

MyString::MyString(const MyString &t_str)//拷贝构造函数
{
	m_length = t_str.m_length;
	m_str = new char[m_length + 1];
	strcpy(m_str, t_str.m_str);
	m_number++;
}



MyString::~MyString()
{
	cout << "~MyString()" << endl;
	delete[] m_str;
	m_str = NULL;
	m_length = 0;
	m_number--;
}

MyString &MyString::operator = (const MyString &t_str)//
{
	//如果不是赋值给自己
	if (this != &t_str)
	{
		//如果左值的长度大于重载的长度，空间浪费？
		if (m_length > t_str.m_length)
		{
			m_length = t_str.m_length;
			strcpy(m_str, t_str.m_str);
		}
		else
		{
			delete[] m_str;
			m_length = t_str.m_length;
			m_str = new char[m_length + 1];
			strcpy(m_str, t_str.m_str);
		}
	}
	return *this;
}

MyString &MyString::operator = (const char *t_str)//
{
	if (t_str != NULL)
	{
		//如果左值的长度大于重载的长度
		if (m_length > strlen(t_str))
		{
			m_length = strlen(t_str);
			strcpy(m_str, t_str);
		}
		else
		{
			delete [] m_str;
			//m_str = NULL;
			m_length = strlen(t_str);
			m_str = new char[m_length + 1];
			strcpy(m_str, t_str);
		}
	}
	return *this;
}
MyString &MyString::operator += (const MyString &t_str)//重载+=操作符,在后面追加字符串
{
	char *tmp = m_str;
	int t_length = m_length;
	//重新开辟空间
	m_length += t_str.m_length;
	m_str = new char[m_length + 1];
	//将左值字符串复制过来
	strcpy(m_str, tmp);
	//如果不是追加给自己
	if (this != &t_str)
	{
		strcpy(m_str + t_length, t_str.m_str);//将右值字符串复制过来
	}
	else
	{
		strcpy(m_str + t_length, tmp);//因为本身已删除,//将右值字符串复制过来
	}
	delete[] tmp;
	tmp = NULL;
	return *this;
}
MyString &MyString::operator += (const char *t_str)//重载+=操作符，追加字符串
{
	if (t_str != NULL)
	{
		char *tmp = m_str;
		int t_length = m_length;
		//重新开辟空间
		m_length += strlen(t_str);
		m_str = new char[m_length + 1];
		//将左值字符串复制过来
		strcpy(m_str, tmp);
		//将右值字符串复制过来
		strcpy(m_str + t_length, t_str);
		//将临时的原字符串空间释放
		delete[] tmp;
		tmp = NULL;
	}
	return *this;
}
MyString &MyString::operator += (const char t_c)//+=一个字符
{
	//先将左值的字符串的首地址和长度保存下来
	char *tmp = m_str;
	int t_length = m_length;
	//重新开辟空间一个字符1的空间
	m_length += 1;
	m_str = new char[m_length + 1];
	//将左值的字符串复制过来
	strcpy(m_str, tmp);
	//将右值的字符串复制过来
	*(m_str + t_length) = t_c;//???
	*(m_str + m_length) = '\0';//???杜绝野指针
	//将临时的原字符串空间释放
	delete [] tmp;
	tmp = NULL;

	return *this;
}


bool operator == (const MyString &t_str1, const MyString &t_str2)
{
	return strcmp(t_str1.m_str, t_str2.m_str) == 0;
}
bool operator != (const MyString &t_str1, const MyString &t_str2)
{
	return strcmp(t_str1.m_str, t_str2.m_str) != 0;
}


MyString operator + (const MyString &t_str1, const MyString &t_str2)
{
	//用于保存字符串相加的结果
	MyString t_str;
	delete[] t_str.m_str;

	//开辟t_str的内存空间
	t_str.m_length = t_str1.m_length + t_str2.m_length;
	t_str.m_str = new char[t_str.m_length + 1];

	//将第一个字符串数据拷贝过来
	strcpy(t_str.m_str, t_str1.m_str);
	//将第二个字符串数据拷贝过来
	strcpy(t_str.m_str+t_str1.m_length, t_str2.m_str);
	return t_str;
}


MyString operator + (const MyString &t_str1, const char *t_str2)
{
	MyString t_str;
	delete[] t_str.m_str;
	if (t_str2 == NULL)//还要考虑为空的情况?
	{
		t_str.m_length = t_str1.m_length;
		t_str.m_str = new char[t_str.m_length + 1];
		strcpy(t_str.m_str, t_str1.m_str);
	}
	else
	{
		t_str.m_length = t_str1.m_length + strlen(t_str2);
		t_str.m_str = new char[t_str.m_length + 1];

		strcpy(t_str.m_str, t_str1.m_str);
		strcpy(t_str.m_str + t_str1.m_length, t_str2);
	}
		
	return t_str;
}

char MyString::operator [](int t_index) const
{
	if (t_index >= 0 && t_index < m_length)
	{
		return *(m_str + t_index);
	}
	else
	{
		cout << "index is wrong!" << endl;
		return '1';
	}
}


//使用友元函数重载输出
ostream &operator << (ostream &os, const MyString &t_str)
{
	os << t_str.m_str;
	return os;
}

//使用友元函数重载输入操作符
istream &operator >> (istream &is, MyString &t_str)
{
	//delet 原来的字符串内容
	delete [] t_str.m_str;

	//保存从键盘输入的字符
	char t_data[1024];

	is >> t_data;

	t_str.m_length = strlen(t_data);
	t_str.m_str = new char[t_str.m_length + 1];
	strcpy(t_str.m_str, t_data);
	return is;
}