#pragma once
#include "class_def.h"
#include <vector>
#include <unordered_map>
class MAP {
protected:
	typedef std::string string;
	typedef std::vector<CROSS_PTR> vec_cross;
	typedef std::vector<ROAD_PTR> vec_road;
	typedef std::vector<CAR_PTR> vec_car;
	typedef std::vector<ROAD_ARC_PTR> vec_arc;
	typedef size_t size_type;
	typedef std::unordered_map<string, size_type> cross_id_map;

	CROSS_NODE_PTR cross_node_list;       //路口节点动态数组
	size_type road_num;                   //道路数量
	size_type arc_num;                    //单向道路数量
	size_type cross_num;                  //路口数量
	cross_id_map map_id;                  //将路口id映射到动态数组的索引

	
	size_type LOCATE_CROSS_NODE(string); //根据路口id确定该路口节点在数组中的位置
	void INSERT_CAR_TO_GARAGE(size_type, CAR_GARAGE_PTR);
	void INSERT_CAR_TO_GARAGE_SPEED_CONCERN(size_type, CAR_GARAGE_PTR);
	bool BUILD_CROSS_NODE(const vec_cross&); //建立路口节点
	bool BUILD_ROAD_ARC_NET(const vec_road&); //建立有向路网
	bool BUILD_CAR_GARAGE(const vec_car&); //建立路口车库
	vec_arc FIND_PATH(size_type, size_type, ROAD_ARC_PTR = NULL); //找到两个路口之间的路径(排除给定路段)
	double FIND_CROSS_DISTANCE(size_type, size_type, ROAD_ARC_PTR = NULL); //返回两路口的距离 若不通或者与给定排除路段相同，返回-1
	ROAD_ARC_PTR FIND_ARC_FOR_ADJ_CROSS(size_type, size_type); //返回两相邻路口之间的有向路段
	void DESTROY_ARC();                    //释放有向路网分配的内存
	void DESTROY_GARAGE();                 //释放车库分配的内存
	void DESTROY_MAP();                    //释放内存
public:
	MAP() :cross_node_list(NULL), road_num(0), arc_num(0), cross_num(0) {}
	bool CREATE_MAP(const vec_cross&, const vec_road&, const vec_car&);
	void FIND_TO_CROSS_ARCS(string, vec_arc&); //查找进入路口的有向路段
	void FIND_FROM_CROSS_ARCS(string, vec_arc&); //查找离开路口的有向路段
	void FIND_GARAGE(string, GARAGE_PTR&); //查找此路口的车库
	DIRECTION UPDATE_DIR_FOR_MOVING_CAR(CAR_PTR, ROAD_ARC_PTR);
	ROAD_ARC_PTR FIND_ROAD_FOR_CAR(CAR_PTR);
	bool IS_CONNECTED(string, string);//检查两个路口是否连通
	void UPDATE_ROAD_ARC();           //更新所有的路况
	void CHECK_MAP(); 
	void CHECK_FIND_METHOD(string, string);
	vec_arc FIND_PATH(string, string,string);
	void INSERT_GARAGE_CAR(CAR_PTR);
	~MAP();
};

