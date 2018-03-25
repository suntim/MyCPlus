#pragma once
#include <iostream>

using namespace std;
class MyString
{
public:
	MyString();//无参的构造函数
	explicit MyString(const char *t_str);//有参的构造函数，抑制一个参数的构造函数隐式转换
	MyString(const MyString &t_str);//拷贝构造函数
	~MyString();//析构函数

	inline int Length() const { return m_length; }//返回字符串的长度

	MyString &operator = (const MyString &t_str);//重载赋值操作符
	MyString &operator = (const char *t_str);//
	MyString &operator += (const MyString &t_str);//重载+=操作符,在后面追加字符串
	MyString &operator += (const char *t_str);//重载+=操作符，追加字符串
	MyString &operator += (const char t_c);//重载+=操作符，追加一个字符


	friend bool operator == (const MyString &t_str1, const MyString &t_str2);//重载比较操作符
	friend bool operator != (const MyString &t_str1, const MyString &t_str2);//重载不等于操作符
	friend MyString operator + (const MyString &t_str1, const MyString &t_str2);
	friend MyString operator + (const MyString &t_str1, const char *t_str2);

	char operator [] (int t_index) const;//重载下标操作符
	static int getNumber(){ return m_number; }

	const char *getStr() const { return m_str; }

	friend ostream &operator << (ostream &os, const MyString &t_str);//使用友元函数重载输出
	friend istream &operator >> (istream &is, MyString &t_str);//使用友元函数重载输入操作符








private:
	char *m_str; //指向字符串的指针
	int m_length;//字符串的长度
	static int m_number;//记录字符串的数量
};

