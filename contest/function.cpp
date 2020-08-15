#include "stdafx.h"
#include "function.h"

//string与unsigned short的转换函数
unsigned short STR2US(std::string str)
{
	unsigned short res = 0;
	std::istringstream invertor(str);
	invertor >> res;
	return res;
}

const short& min(const short&a, const short&b)
{
	if (a <= b)
		return a;
	return b;
}