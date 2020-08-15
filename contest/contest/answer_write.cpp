#include "stdafx.h"
#include "answer_write.h"
#include "sstream"

ANSWER_WRITE::ANSWER_WRITE(string file)
{
	filename = file;
}

void ANSWER_WRITE::WRITE_MOVING_CAR_ITEMS(MOVING_CAR_PTR car1)
{
	OPEN_FILE();
	if (writer) //若打开文件成功
	{
		std::ostringstream ostr;
		string line;
		line += '(';
		line += car1->carinfo->car_id;
		line += ',';
		ostr << car1->start_time;
		line += ostr.str();
		//line.push_back(car1->start_time + '0');
		for (size_type i = 0; i < car1->passed_road.size(); i++)
		{
			line += ',';
			line += car1->passed_road[i];
		}
		line += ')';
		writer << line << std::endl;
	}
	CLOSE_FILE();
}