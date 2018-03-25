// 012_defaultParam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include<string>
using namespace std;

void weatherCast(string w = "pm2.5")
{
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&t));
	cout << tmp << " weather is " << w << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	weatherCast("sun");
	return 0;
}

