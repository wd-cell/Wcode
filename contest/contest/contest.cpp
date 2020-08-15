// contest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "road_read.h"
#include "cross_read.h"
#include "car_read.h"
#include "map.h"
#include "traffic_controller.h"
#include "sys_control.h"
#include <iostream>

int main()
{
	ROAD_READ reader;
	CROSS_READ reader1;
	CAR_READ reader2;
	std::vector<ROAD_PTR> roads = reader.READ_ROAD_ITEMS("road.txt");
	std::vector<CROSS_PTR> cross_s = reader1.READ_CROSS_ITEMS("cross.txt");
	std::cout << cross_s.size() << std::endl;
	std::vector<CAR_PTR> cars = reader2.READ_CAR_ITEMS("car.txt");
	//MAP map1;
	//map1.CREATE_MAP(cross_s, roads,cars);
	//map1.CHECK_MAP();
	/*
	map1.CHECK_MAP();
	for (size_t i = 0; i < cars.size(); i++)
	{
		map1.CHECK_FIND_METHOD(cars[i]->from_id, cars[i]->to_id);
		std::cout << map1.IS_CONNECTED(cars[i]->from_id, cars[i]->to_id) << std::endl;
	}*/
	//map1.CHECK_FIND_METHOD("31", "1");
	//map1.CHECK_FIND_METHOD("25", "5");
	//map1.CHECK_FIND_METHOD("19", "1");

	/*std::vector<TRAFFIC_CONTROLLER> controller;
	for (size_t i = 0; i < cross_s.size(); i++)
	{
		controller.push_back(TRAFFIC_CONTROLLER(cross_s[i]->cross_id, map1));
	}
	/*
	for (auto con : controller)
		con.TRAFFIC_CONTROLLER_CHECK();
		*/
	//map1.CHECK_MAP();
	//std::cout << std::endl;
	SYS_CONTROL contrls("answer.txt");
	contrls.INIT_SYS_CONTROL(cross_s, roads, cars);
	/*contrls.NEW_TRAN(map1, controller);
	std::cout << std::endl;
	map1.CHECK_MAP();
	contrls.NEW_TRAN(map1, controller);
	std::cout << std::endl;
	map1.CHECK_MAP();*/
	contrls.TRAN();

	return 0;
}

