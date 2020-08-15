#include "stdafx.h"
#include "cross_read.h"
CROSS_PTR CROSS_READ::CROSS_PARSE(string line)
{
	int len = line.size() - 2;//字符串除去两端括号的长度
	int del_index = 0;        //记录当前是第几个逗号
	string temp_str;
	CROSS_PTR new_cross = new CROSS;
	if (!new_cross)
		exit(1);
	for (int i = 1; i <= len; i++)
	{

		if (line[i] == ' ')
		{
			continue;
		}
		else if (line[i]=='-'||line[i] >= '0'&&line[i] <= '9')
		{
			temp_str += line[i];
		}
		else {
			del_index++;
			switch (del_index)
			{
			case 1:
				new_cross->cross_id = temp_str;
				break;
			case 2:
				new_cross->road_id_1 = temp_str;
				break;
			case 3:
				new_cross->road_id_2 = temp_str;
				break;
			case 4:
				new_cross->road_id_3 = temp_str;
			}
			temp_str.clear();
		}
	}
	new_cross->road_id_4 = temp_str;
	return new_cross;
}

std::vector<CROSS_PTR> CROSS_READ::READ_CROSS_ITEMS(string filename)
{
	vector cross_s;
	OPEN_FILE(filename);
	if (read_in) //若打开文件成功
	{
		string line;
		while (std::getline(read_in, line))
		{
			if (line.empty() || line[0] == '#')
				continue;
			cross_s.push_back(CROSS_PARSE(line));
		}
	}
	CLOSE_FILE();
	return cross_s;
}