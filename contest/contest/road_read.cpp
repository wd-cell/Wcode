#include "stdafx.h"
#include "road_read.h"
ROAD_PTR ROAD_READ::ROAD_PARSE(string line)
{
	int len = line.size() - 2;//字符串除去两端括号的长度
	int del_index = 0;        //记录当前是第几个逗号
	string temp_str;
	short temp_int;
	ROAD_PTR new_road = new ROAD;
	if (!new_road)
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
			case 4:
			case 5:
				temp_str += line[i];
				break;
			case 1:
			case 2:
			case 3:
			case 6:
				temp_int = temp_int * 10 + (line[i] - '0');
			}
		}
		else {
			del_index++;
			switch (del_index)
			{
			case 1:
				new_road->road_id = temp_str;
				break;
			case 2:
				new_road->length = temp_int;
				break;
			case 3:
				new_road->top_speed = temp_int;
				break;
			case 4:
				new_road->path_num = temp_int;
				break;
			case 5:
				new_road->from_id = temp_str;
				break;
			case 6:
				new_road->to_id = temp_str;
			}
			temp_str.clear();
			temp_int = 0;
		}
	}
	new_road->is_duplex = temp_int;
	return new_road;
}

std::vector<ROAD_PTR> ROAD_READ::READ_ROAD_ITEMS(string filename)
{
	vector roads;
	OPEN_FILE(filename);
	if (read_in) //若打开文件成功
	{
		string line;
		while (std::getline(read_in, line))
		{
			if (line.empty()||line[0] == '#')
				continue;
			roads.push_back(ROAD_PARSE(line));
		}
	}
	CLOSE_FILE();
	return roads;
}