#pragma once
#include "map.h"
#include "traffic_controller.h"

class SYS_CONTROL {
protected:
	typedef size_t size_type;
	typedef std::string string;
 	typedef std::vector<TRAFFIC_CONTROLLER> vec_contrl;
	typedef std::vector<CAR_PTR> vec_car;
	typedef std::vector<ROAD_PTR> vec_road;
	typedef std::vector<CROSS_PTR> vec_cross;
	typedef std::vector<bool> vec_bool;
	typedef std::unordered_map<string, size_type> cross_id_map; 
	typedef cross_id_map::iterator iterator;

	size_type time;
	size_type idea_time;
	size_type car_num_limit; //路网中的车辆数上限
	size_type cur_car_num;   //当前路网中的车辆数
	size_type car_num;       //进入路网车辆的总数
	size_type gar_car_num;   //车库中的车辆数
	MAP map1;
	vec_contrl ctrls;
	vec_bool garage_blocked;
	cross_id_map map_num;    //存储每个路口id对应的接收车辆的数目
	cross_id_map map_id;
	std::vector<size_type> lock_judge;

	void INIT_CONTRLS(); //将vec_contrl的时间加1
	void INIT_UPDATE_ARCS(); 
	void INIT_LOCK_JUDGE();
	void RELIEVE_LOCK_JUDGE();
	bool IS_MOVING_CAR_FINISHED();
	bool IS_ALL_CAR_TERMINATE();
	bool IS_ALL_GARAGE_BLOCKED();
	void REFRESH_GARAGE_BLOCK();
	void HANDLE_BLOCKED_CAR();//处理车辆阻塞
	std::vector<size_type> IS_LOCK_EXIST();//检查死锁是否存在 若存在返回解锁节点
	bool SEARCH_FOR_LOCK(size_type); 
	void HANDLE_LOCKED_ARC();//处理死锁
	//void FIND_LONGEST_TIME();
	size_type TERMINATE_CAR_NUM();
public:
	SYS_CONTROL() :time(0),car_num(0),cur_car_num(0),gar_car_num(0),car_num_limit(400) {}
	void INIT_SYS_CONTROL(const vec_cross&,const vec_road&,const vec_car&);
	void NEW_TRAN();
	void TRAN();
};