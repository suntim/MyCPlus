// 002_copy_construct.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Student.h"
#include <iostream>
using namespace std;

//���ÿ������캯���ĵڶ��������ֵ����,����Ķ���
void getStudentInfo(Student t_student)
{
	t_student.print();
}

void getStudentInfoCite(Student &t_student)//���ǿ������캯���ĵڶ������������
{
	t_student.print();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Student t_student1("My", 23,"woman");
	Student t_student2(t_student1);//�Զ����˿������캯�����Ͳ�����Ĭ�ϵ�,Ĭ�ϵĻ�������⣺��ָ���Ա
	//�����
	//		��new���������¿��ٿռ䣬��Ҫ�Զ��忽��������
	//ǳ������
	//		û���������뿪����Դ�����Ե���Ĭ�Ͽ���������
	//�������캯�����ã�
	//		���Ѵ��ڵ��϶���ȥ�����¶���
	cout << "t_student1.print();" << endl;
	t_student1.print();
	cout <<endl;
	cout << "t_student2.print();" << endl;
	t_student2.print();


	//���ÿ������캯���ĵڶ������
	cout << endl;
	cout << "INFO Print1();" << endl;
	getStudentInfoCite(t_student2);

	cout << endl;
	cout << "INFO Print2();" << endl;
	//getStudentInfo(t_student1);

}

