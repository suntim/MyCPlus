#pragma once
#include <string>
#include <string.h>
#include <iostream>
//#include <stdio.h> //printf
using namespace std;
class Student
{
public:
	Student();
	Student(const string &t_name, int t_age, const string &t_sex)
		:m_name(t_name), m_age(t_age), m_sex(0)
	{
		cout << "Student(...)" << endl;
		m_sex = new char[t_sex.length() + 1];
		strcpy(m_sex, t_sex.c_str()); //字符串转char？
	}

	//自定义拷贝构造函数
	Student(const Student &t_student)
	{
		cout << "Student(拷贝构造函数)" << endl;
		m_name = t_student.m_name;
		m_age = t_student.m_age;
		m_sex = new char[strlen(t_student.m_sex)+1];//先开辟内存
		strcpy(m_sex, t_student.m_sex);//再copy

	}
	~Student()
	{
		cout << "~Student()" << endl;
		cout << "sex = " << m_sex << endl;
		delete m_sex;
		m_sex = NULL;
		cout << "delete m_sex;" << endl;
	}
	void print()
	{
		cout << "Name: " << m_name << " Age: " << m_age << "  Sex: "<<m_sex<<endl;
		printf("sex address: %p\n", m_sex);
	}

private:
	string m_name;
	int m_age;
	char *m_sex;
};

