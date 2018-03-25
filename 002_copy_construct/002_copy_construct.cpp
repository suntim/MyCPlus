// 002_copy_construct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Student.h"
#include <iostream>
using namespace std;

//调用拷贝构造函数的第二种情况，值传递,该类的对象
void getStudentInfo(Student t_student)
{
	t_student.print();
}

void getStudentInfoCite(Student &t_student)//不是拷贝构造函数的第二种情况，引用
{
	t_student.print();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Student t_student1("My", 23,"woman");
	Student t_student2(t_student1);//自定义了拷贝构造函数，就不调用默认的,默认的会出现问题：如指针成员
	//深拷贝：
	//		有new操作，重新开辟空间，需要自定义拷贝函数；
	//浅拷贝：
	//		没有重新申请开辟资源，可以调用默认拷贝函数；
	//拷贝构造函数作用：
	//		用已存在的老对象！去构造新对象
	cout << "t_student1.print();" << endl;
	t_student1.print();
	cout <<endl;
	cout << "t_student2.print();" << endl;
	t_student2.print();


	//调用拷贝构造函数的第二种情况
	cout << endl;
	cout << "INFO Print1();" << endl;
	getStudentInfoCite(t_student2);

	cout << endl;
	cout << "INFO Print2();" << endl;
	//getStudentInfo(t_student1);

}

