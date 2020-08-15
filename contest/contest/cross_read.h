#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "class_def.h"
class CROSS_READ {
protected:
	typedef std::string string;
	typedef std::vector<CROSS_PTR> vector;
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
	CROSS_PTR CROSS_PARSE(string);
public:
	vector READ_CROSS_ITEMS(string filename);
};