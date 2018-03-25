#include "stdafx.h"
#include "Student.h"
#include <iostream>
#include <string.h>
using namespace std;


Student::Student()
	:m_name("NoName"), m_age(0), m_sex(0)
{
	m_sex = new char[4];
	strcpy(m_sex, "man");
	cout<<"Student()"<<endl;


}
