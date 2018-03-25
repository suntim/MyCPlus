#pragma once
#include <iostream>

using namespace std;
class MyString
{
public:
	MyString();//�޲εĹ��캯��
	explicit MyString(const char *t_str);//�вεĹ��캯��������һ�������Ĺ��캯����ʽת��
	MyString(const MyString &t_str);//�������캯��
	~MyString();//��������

	inline int Length() const { return m_length; }//�����ַ����ĳ���

	MyString &operator = (const MyString &t_str);//���ظ�ֵ������
	MyString &operator = (const char *t_str);//
	MyString &operator += (const MyString &t_str);//����+=������,�ں���׷���ַ���
	MyString &operator += (const char *t_str);//����+=��������׷���ַ���
	MyString &operator += (const char t_c);//����+=��������׷��һ���ַ�


	friend bool operator == (const MyString &t_str1, const MyString &t_str2);//���رȽϲ�����
	friend bool operator != (const MyString &t_str1, const MyString &t_str2);//���ز����ڲ�����
	friend MyString operator + (const MyString &t_str1, const MyString &t_str2);
	friend MyString operator + (const MyString &t_str1, const char *t_str2);

	char operator [] (int t_index) const;//�����±������
	static int getNumber(){ return m_number; }

	const char *getStr() const { return m_str; }

	friend ostream &operator << (ostream &os, const MyString &t_str);//ʹ����Ԫ�����������
	friend istream &operator >> (istream &is, MyString &t_str);//ʹ����Ԫ�����������������








private:
	char *m_str; //ָ���ַ�����ָ��
	int m_length;//�ַ����ĳ���
	static int m_number;//��¼�ַ���������
};

