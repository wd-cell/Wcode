#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "class_def.h"
class ANSWER_WRITE {
protected:
	typedef size_t size_type;
	typedef std::string string;
	typedef std::ofstream ofstream;
	ofstream writer;
	string filename;
	void OPEN_FILE()
	{
		writer.open(filename,ofstream::app);
	}
	void CLOSE_FILE()
	{
		writer.close();
	}
public:
	ANSWER_WRITE(string);
    void WRITE_MOVING_CAR_ITEMS(MOVING_CAR_PTR);
};