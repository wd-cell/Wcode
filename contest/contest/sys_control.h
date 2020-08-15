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

	string filename;
	size_type time;
	size_type idea_time;
	size_type car_num_limit; //·���еĳ���������
	size_type cur_car_num;   //��ǰ·���еĳ�����
	size_type car_num;       //����·������������
	size_type gar_car_num;   //�����еĳ�����
	MAP map1;
	vec_contrl ctrls;
	vec_bool garage_blocked;
	cross_id_map map_num;    //�洢ÿ��·��id��Ӧ�Ľ��ճ�������Ŀ
	cross_id_map map_id;
	std::vector<size_type> lock_judge;

	void INIT_CONTRLS(); //��vec_contrl��ʱ���1
	void INIT_UPDATE_ARCS(); 
	void INIT_LOCK_JUDGE();
	void RELIEVE_LOCK_JUDGE();
	bool IS_MOVING_CAR_FINISHED();
	bool IS_ALL_CAR_TERMINATE();
	bool IS_ALL_GARAGE_BLOCKED();
	void REFRESH_GARAGE_BLOCK();
	//void HANDLE_BLOCKED_CAR();//����������
	std::vector<size_type> IS_LOCK_EXIST();//��������Ƿ���� �����ڷ��ؽ����ڵ�
	bool SEARCH_FOR_LOCK(size_type); 
	void HANDLE_LOCKED_ARC();//��������
	//void FIND_LONGEST_TIME();
	size_type TERMINATE_CAR_NUM();
public:
	SYS_CONTROL(string file) :time(0),car_num(0),cur_car_num(0),gar_car_num(0),car_num_limit(100),filename(file) {}
	void INIT_SYS_CONTROL(const vec_cross&,const vec_road&,const vec_car&);
	void NEW_TRAN();
	void TRAN();
};