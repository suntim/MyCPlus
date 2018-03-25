// 008_myString.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "MyString.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char *t_p1 = 0;
	MyString t_p(t_p1);//MyString::MyString(const char *t_str)
	cout << "t_p.str = " << t_p << endl;
	cout << "t_p.Length = " << t_p.Length() << endl;
	cout << "m_number = " << MyString::getNumber() << endl;

	//测试构造函数
	MyString t_str1;
	MyString t_str2("456");
	//测试拷贝构造函数
	MyString t_str3(t_str2);
	cout << "t_str1.str = " << t_str1 << endl;
	cout << "t_str1.Length = " << t_str1.Length() << endl;
	cout << "t_str2.str = " << t_str2 << endl;
	cout << "t_str2.Length = " << t_str2.Length() << endl;
	cout << "t_str3.str = " << t_str3 << endl;
	cout << "t_str3.Length = " << t_str3.Length() << endl;

	MyString mystr_1("a");
	cout << "mystr_1.str = " << mystr_1 << endl;
	cout << "mystr_1.Length = " << mystr_1.Length() << endl;
	MyString mystr_2("ab");
	cout << "mystr_2.str = " << mystr_2 << endl;
	cout << "mystr_2.Length = " << mystr_2.Length() << endl;



	//测试赋值操作符
	MyString t_str4("4444");
	
	cout << "t_str4.str = " << t_str4 << endl;

	//测试&operator = (const myString &t_str);
	t_str4 = t_str2;
	cout << "t_str4.str = " << t_str4 << endl;
	cout << "t_str4.Length = " << t_str4.Length() << endl;

	//测试&operator = (const char *t_str);
	MyString t_str5("5555");
	MyString t_str6("6666");
	t_str5 = t_p1;//等于NULL，不做事，之前多少就多少
	cout << "空t_str5.str = " << t_str5 << endl;
	cout << "m_number = " << MyString::getNumber() << endl;
	cout << "t_str5.Length = " << t_str5.Length() << endl;
	t_str5 = "123333";
	cout << "t_str5.str = " << t_str5 << endl;
	cout << "t_str5.Length = " << t_str5.Length() << endl;

	//测试&MyString::operator += (const MyString &t_str)//重载+=操作符,在后面追加字符串
	MyString t_str7("777");
	MyString t_str8("888");
	t_str7 += t_str8 += t_str8;
	cout << "t_str7.str = " << t_str7 << endl;
	cout << "t_str7.Length = " << t_str7.Length() << endl;
	t_str7 += t_str7;
	cout << "t_str7.str = " << t_str7 << endl;
	cout << "t_str7.Length = " << t_str7.Length() << endl;

	cout << "t_str8.str = " << t_str8 << endl;
	cout << "t_str8.Length = " << t_str8.Length() << endl;

	//测试 &MyString::operator += (const char *t_str)//重载+=操作符，追加字符串
	MyString t_str9("999");
	MyString t_str10("10");
	char *t_p2 = "abc";
	t_str10 += t_str9 += t_p2;
	cout << "t_str10.str = " << t_str10 << endl;
	cout << "t_str10.Length = " << t_str10.Length() << endl;
	cout << "t_str9.str = " << t_str9 << endl;
	cout << "t_str9.Length = " << t_str9.Length() << endl;
	t_str9 += t_p1;
	cout << "t_str9.str = " << t_str9 << endl;
	cout << "t_str9.Length = " << t_str9.Length() << endl;

	//测试 &MyString::operator += (const char t_c)//+=一个字符
	MyString t_str11("11");
	t_str11 += ' ';
	cout << "t_str11.str = " << t_str11 << endl;
	cout << "t_str11.Length = " << t_str11.Length() << endl; 
	t_str11 += 'a';
	cout << "t_str11.str = " << t_str11 << endl;
	cout << "t_str11.Length = " << t_str11.Length() << endl;

	//测试  operator == (const MyString &t_str1, const MyString &t_str2)

	if (t_str2 == t_str3)
	{
		cout << "相等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	//测试 operator + (const MyString &t_str1, const MyString &t_str2)
	MyString t_str12("123");
	t_str12 = t_str12 + t_str2;
	cout << "t_str12.str = " << t_str12 << endl;
	cout << "t_str12.Length = " << t_str12.Length() << endl;

	//测试operator + (const MyString &t_str1, const char *t_str2)
	MyString t_str13("13");
	t_str13 = t_str2 + t_p1 + "7";
	cout << "t_str13.str = " << t_str13 << endl;
	cout << "t_str13.Length = " << t_str13.Length() << endl;


	//测试 MyString::operator [](int t_index) const
	cout << "t_str13【Length】.str = " << t_str13[t_str13.Length()] << endl;
	cout << "t_str13【0】.str = " << t_str13[0] << endl;
	cout << "t_str13【1】.str = " << t_str13[1] << endl;
	cout << "t_str13【2】.str = " << t_str13[2] << endl;
	cout << "t_str13【3】.str = " << t_str13[3] << endl;
	cout << "t_str13.Length = " << t_str13.Length() << endl;

	//测试 ostream &operator << (ostream &os, const MyString &t_str)
	cout << "测试 ostream &operator << t_str13.str = " << t_str13 << endl;

	//测试 &operator >> (istream &is, MyString &t_str)
	MyString t_str14("14");
	MyString t_str15("15");
	cout << "t_str14.str = " << t_str14 << endl;
	cout << "重载输入操作符:\n";
	cin >> t_str14;
	cout << "t_str14.str = " << t_str14 << endl;

	cout << "重载输入两个操作符:\n";
	cin >> t_str14>>t_str15;
	cout << "t_str14.str = " << t_str14 << endl;
	cout << "t_str15.str = " << t_str15 << endl;

	cout << "m_number = " << MyString::getNumber() << endl;


	return 0;
}

