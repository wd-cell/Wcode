#include "stdafx.h"
#include "stdafx.h"
#include "car_read.h"
CAR_PTR CAR_READ::CAR_PARSE(string line)
{
	int len = line.size() - 2;//字符串除去两端括号的长度
	int del_index = 0;        //记录当前是第几个逗号
	string temp_str;
	short temp_int = 0;
	CAR_PTR new_car = new CAR;
	if (!new_car)
		exit(1);
	for (int i = 1; i <= len; i++)
	{

		if (line[i] == ' ')
		{
			continue;
		}
		else if (line[i] >= '0'&&line[i] <= '9')
		{
			switch (del_index)
			{
			case 0:
			case 1:
			case 2:
				temp_str += line[i];
				break;
			case 3:
			case 4:
				temp_int = temp_int * 10 + (line[i] - '0');
			}
		}
		else {
			del_index++;
			switch (del_index)
			{
			case 1:
				new_car->car_id = temp_str;
				break;
			case 2:
				new_car->from_id = temp_str;
				break;
			case 3:
				new_car->to_id = temp_str;
				break;
			case 4:
				new_car->top_speed = temp_int;
			}
			temp_str.clear();
			temp_int = 0;
		}
	}
	new_car->time = temp_int;
	return new_car;
}

std::vector<CAR_PTR> CAR_READ::READ_CAR_ITEMS(string filename)
{
	vector cars;
	OPEN_FILE(filename);
	if (read_in) //若打开文件成功
	{
		string line;
		while (std::getline(read_in, line))
		{
			if (line.empty() || line[0] == '#')
				continue;
			cars.push_back(CAR_PARSE(line));
		}
	}
	CLOSE_FILE();
	return cars;
}