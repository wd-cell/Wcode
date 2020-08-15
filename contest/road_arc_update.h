#pragma once
#include "class_def.h"
#include <vector>

//实时更新每条有向路的路况(车流)
class ROAD_ARC_UPDATE {
protected:
	typedef size_t size_type;
	typedef std::vector<short> vec_short;

	MOVING_CAR_PTR **car_stream;
	short road_len;
	short path_num;
	vec_short tail_index; //保存每条车道的起始空闲车位
	size_type car_num;
	size_type car_num_waiting; //此道路中处于等待状态的车辆个数
	bool is_finished;          
	void UPDATE_PATH(short); //将某一车道的车辆状态更新
public:
	ROAD_ARC_UPDATE() :car_stream(NULL), road_len(0), path_num(0),car_num(0),car_num_waiting(0),is_finished(true) {};
	void CREATE_ROAD_ARC(short, short); //根据道路的长度和车道数分配车流空间
	void INSERT_CAR(MOVING_CAR_PTR,short, short); //插入一辆车
	void MOVE_CAR(short, short, short);           //将某车道的某辆车向前移动
	void DELETE_CAR(short, short);      //将某一位置的车从此道路中删除
	void DELETE_PRIOR_CAR();            //将当前最高优先级的车删除
	MOVING_CAR_PTR FIND_PRIOR_CAR();              //返回此道路优先级最高的车辆
	bool IS_ALL_FINISHED();                       //查询此道路车辆是否全部完成调度
	void FIND_AVAILABLE_SEAT(short, short);       //查询此道路的空闲车位
	~ROAD_ARC_UPDATE();                           //释放空间
};