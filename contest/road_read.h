#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "class_def.h"
class ROAD_READ {
protected:
	typedef std::string string;
	typedef std::vector<ROAD_PTR> vector;
	typedef std::ifstream ifstream;
	ifstream read_in;
	void OPEN_FILE(string filename)
	{
		read_in.open(filename);
	}
	void CLOSE_FILE()
	{
		read_in.close();
	}
	ROAD_PTR ROAD_PARSE(string);
public:
	vector READ_ROAD_ITEMS(string filename);
};

