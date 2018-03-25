#include "stdafx.h"
#include "MyString.h"
#include <iostream>
#include <string.h>


int MyString::m_number = 0;

MyString::MyString()
{
	m_str = new char[1]; //����һ���ַ��ռ�
	*m_str = '\0';//Ĭ�Ͽ��ַ���
	m_length = 0;
	m_number++;
}

MyString::MyString(const char *t_str)
{
	if (t_str == NULL)
	{
		m_str = new char[1]; //����һ���ַ��ռ�
		*m_str = '\0'; //Ĭ�Ͽ��ַ�
		m_length = 0; //Ĭ�ϳ���Ϊ0
	}
	else
	{
		m_length = strlen(t_str);
		m_str = new char[m_length + 1];
		strcpy(m_str, t_str);
	}
	m_number++;
}

MyString::MyString(const MyString &t_str)//�������캯��
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
	//������Ǹ�ֵ���Լ�
	if (this != &t_str)
	{
		//�����ֵ�ĳ��ȴ������صĳ��ȣ��ռ��˷ѣ�
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
		//�����ֵ�ĳ��ȴ������صĳ���
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
MyString &MyString::operator += (const MyString &t_str)//����+=������,�ں���׷���ַ���
{
	char *tmp = m_str;
	int t_length = m_length;
	//���¿��ٿռ�
	m_length += t_str.m_length;
	m_str = new char[m_length + 1];
	//����ֵ�ַ������ƹ���
	strcpy(m_str, tmp);
	//�������׷�Ӹ��Լ�
	if (this != &t_str)
	{
		strcpy(m_str + t_length, t_str.m_str);//����ֵ�ַ������ƹ���
	}
	else
	{
		strcpy(m_str + t_length, tmp);//��Ϊ������ɾ��,//����ֵ�ַ������ƹ���
	}
	delete[] tmp;
	tmp = NULL;
	return *this;
}
MyString &MyString::operator += (const char *t_str)//����+=��������׷���ַ���
{
	if (t_str != NULL)
	{
		char *tmp = m_str;
		int t_length = m_length;
		//���¿��ٿռ�
		m_length += strlen(t_str);
		m_str = new char[m_length + 1];
		//����ֵ�ַ������ƹ���
		strcpy(m_str, tmp);
		//����ֵ�ַ������ƹ���
		strcpy(m_str + t_length, t_str);
		//����ʱ��ԭ�ַ����ռ��ͷ�
		delete[] tmp;
		tmp = NULL;
	}
	return *this;
}
MyString &MyString::operator += (const char t_c)//+=һ���ַ�
{
	//�Ƚ���ֵ���ַ������׵�ַ�ͳ��ȱ�������
	char *tmp = m_str;
	int t_length = m_length;
	//���¿��ٿռ�һ���ַ�1�Ŀռ�
	m_length += 1;
	m_str = new char[m_length + 1];
	//����ֵ���ַ������ƹ���
	strcpy(m_str, tmp);
	//����ֵ���ַ������ƹ���
	*(m_str + t_length) = t_c;//???
	*(m_str + m_length) = '\0';//???�ž�Ұָ��
	//����ʱ��ԭ�ַ����ռ��ͷ�
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
	//���ڱ����ַ�����ӵĽ��
	MyString t_str;
	delete[] t_str.m_str;

	//����t_str���ڴ�ռ�
	t_str.m_length = t_str1.m_length + t_str2.m_length;
	t_str.m_str = new char[t_str.m_length + 1];

	//����һ���ַ������ݿ�������
	strcpy(t_str.m_str, t_str1.m_str);
	//���ڶ����ַ������ݿ�������
	strcpy(t_str.m_str+t_str1.m_length, t_str2.m_str);
	return t_str;
}


MyString operator + (const MyString &t_str1, const char *t_str2)
{
	MyString t_str;
	delete[] t_str.m_str;
	if (t_str2 == NULL)//��Ҫ����Ϊ�յ����?
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


//ʹ����Ԫ�����������
ostream &operator << (ostream &os, const MyString &t_str)
{
	os << t_str.m_str;
	return os;
}

//ʹ����Ԫ�����������������
istream &operator >> (istream &is, MyString &t_str)
{
	//delet ԭ�����ַ�������
	delete [] t_str.m_str;

	//����Ӽ���������ַ�
	char t_data[1024];

	is >> t_data;

	t_str.m_length = strlen(t_data);
	t_str.m_str = new char[t_str.m_length + 1];
	strcpy(t_str.m_str, t_data);
	return is;
}