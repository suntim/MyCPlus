#include "stdafx.h"
#include "MyStringLen.h"



//���μ�����
//extern "C"
//{
//
//}
int mystringlen(char *t_c)
{
	int len = 0;
	while (*t_c)
	{
		len++;
		t_c++;
	}
	return len;
}
