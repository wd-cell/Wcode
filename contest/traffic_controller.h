#pragma once
#include "class_def.h"
#include "map.h"
#include <vector>
#include <iostream>

class TRAFFIC_CONTROLLER {
	typedef size_t size_type;
	typedef std::string string;
	typedef std::vector<ROAD_ARC_PTR> vec_arc;
	typedef std::vector<CAR_PTR> vec_car;
	typedef std::vector<size_type> vec_size;
protected:
	short time;
	MAP* reference_map;
	string cross_id;
	vec_arc farc;
	vec_arc tarc;
	vec_arc tarc_id_sequence;
	//ROAD_ARC_PTR blocked[4];
	//size_type blocked_time[4];
	size_type start_index;
	GARAGE_PTR cross_garage;
	size_type terminate_num; //在这个路口结束的车辆
	ROAD_ARC_PTR blocked;
	size_type block_time;    //记录某车被阻隔的次数
	short gar_car_speed;     //当前时间片的车库汽车速度
	//vec_car blocked_car;      //保存被堵塞在路口的车辆

	size_type TARC_MAP(ROAD_ARC_PTR); //确定进入路口的有向路的上0 右1 下2 左3位置
	size_type TARC_SEQ_MAP(ROAD_ARC_PTR);
	void TARC_ID_ASCENDING(const vec_arc&, vec_arc&);//将进入路口的有向路按照id升序排列
	MOVING_CAR_PTR GET_MOVING_CAR(ROAD_ARC_PTR);  //获取路段的最高优先级车辆
	void DELETE_MOVING_CAR(ROAD_ARC_PTR);         //删除路段的最高优先级车辆
	void MOVE_MOVING_CAR(ROAD_ARC_PTR);           //移动路段的最高优先级车辆至最前方
	ROAD_ARC_PTR LOCATE_NEXT_ROAD_FOR_CAR(MOVING_CAR_PTR,ROAD_ARC_PTR); //确定汽车的下一条路
    ROAD_ARC_PTR LOCATE_NEXT_POSITION_FOR_CAR(MOVING_CAR_PTR,ROAD_ARC_PTR,short&,short&,short&);
	void VALIDATE_INSERT_STEP(MOVING_CAR_PTR,ROAD_ARC_PTR, short&, short&); //确定汽车的实际插入位置
	bool FIND_CONFLICT(ROAD_ARC_PTR);
	void INSERT_MOVING_CAR(MOVING_CAR_PTR, ROAD_ARC_PTR, short, short);
	bool TRAN_MOVING_ONE_CAR(ROAD_ARC_PTR);//一辆汽车通过路口
	bool TRAN_ONE_GARAGE_CAR(CAR_GARAGE_PTR);            //调度一次车库中的汽车
	void UPDATE_MOVING_CAR_DIR(MOVING_CAR_PTR, ROAD_ARC_PTR);//更新行车方向
	bool CHANGE_BLOCKED_CAR_DIR(MOVING_CAR_PTR, ROAD_ARC_PTR);//为被阻塞的车更换方向
	bool IS_DES_BLOCKED(ROAD_ARC_PTR);//目标道路是否被占满
	//bool CHANGE_MOVING_CAR_DIR(MOVING_CAR_PTR, ROAD_ARC_PTR);
	ROAD_ARC_PTR SELECT_ROAD_FOR_GARAGE_CAR(CAR_GARAGE_PTR);
	void HANDLE_TERMINATE_CAR(MOVING_CAR_PTR); //处理已经抵达终点的车
	void HANDLE_BLOCKED_CAR(MOVING_CAR_PTR,ROAD_ARC_PTR);//处理被堵塞的车辆
public: 
	CAR_PTR blocked_car;      //保存被堵塞在路口的车辆
	ROAD_ARC_PTR lock_arc;
	void TRAN_GARAGE_CAR();              //调度车库中的汽车
	bool TRAN_ONE_GARAGE_CAR();          //调度一辆车库的汽车
	bool TRAN_ONE_GARAGE_CAR_SPEED_CONCERNED();  //按照车速由大到小的优先级调度一辆车库的汽车
	bool IS_GARAGE_BLOCKED();            //车库目前是否有车可调
	bool TRAN_MOVING_CAR(ROAD_ARC_PTR);  //若干辆汽车通过路口
	void TRAN_ONE_REV();              //为该路口进行一次调度
	void NEW_TIME();                  //开始一段新的时间片
	bool IS_TRAN_MOVING_FINISHED();          //查询该时间片对路上行驶车辆的调度是否已完成
	void TRAFFIC_CONTROLLER_CHECK();
	string GET_TRAFFIC_CONTROLLER_ID();//返回路口ID
	size_type GET_TERMINATE_CAR();     //返回抵达这个路口的车辆
	bool BREAK_LOCK();                 //为该路口的车辆调整方向解除死锁
	void HANDLE_BLOCKED_CAR();//处理被堵塞的车辆
	TRAFFIC_CONTROLLER(string, MAP&);
	TRAFFIC_CONTROLLER();             //默认构造函数
};

