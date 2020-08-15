#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "class_def.h"
class CAR_READ {
protected:
	typedef std::string string;
	typedef std::vector<CAR_PTR> vector;
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
	CAR_PTR CAR_PARSE(string);
public:
	vector READ_CAR_ITEMS(string filename);
};
