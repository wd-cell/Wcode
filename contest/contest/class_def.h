#pragma once
#include <string>
#include <vector>
//道路
typedef struct ROAD {
	typedef std::string string;
	string road_id;
	string from_id;
	string to_id;
	short length;
	short top_speed;
	short  path_num;
	bool is_duplex;

	ROAD() {};
	ROAD(string id1,string id2,string id3,char len,char speed,char pathnum,bool duplex)
	:road_id(id1),from_id(id2),to_id(id3),length(len),top_speed(speed),path_num(pathnum),is_duplex(duplex){
	}
}*ROAD_PTR;

//路口
typedef struct CROSS {
	typedef std::string string;
	string cross_id;
	string road_id_1;
	string road_id_2;
	string road_id_3;
	string road_id_4;

	CROSS() {};
}*CROSS_PTR;

//汽车
typedef struct CAR {
	typedef std::string string;
	string car_id;
	string from_id;
	string to_id;
	short top_speed;
	short time;
    
	CAR() {};
}*CAR_PTR;

//行车方向
enum DIRECTION {
	FORWARD,     //直行
	LEFTWARD,    //左转
	RIGHTWARD,   //右转
	TERMINATE    //到达
};

//调度状态
enum TRAN_STATE {
	WAITING,     //等待调度
	FINISHED     //完成调度
};

//行驶中的汽车
typedef struct MOVING_CAR {
	typedef std::vector<std::string> vec_str;
    
	CAR_PTR carinfo;
	short start_time;
	DIRECTION cardir;
	TRAN_STATE carstate;
	vec_str passed_road;
}*MOVING_CAR_PTR;

class ROAD_ARC_UPDATE {
protected:
	typedef size_t size_type;
	typedef std::vector<short> vec_short;
	typedef std::vector<bool> vec_bool;

	MOVING_CAR_PTR **car_stream;
	short road_len;
	short path_num;
	short road_velocity;
	short seq_prior;
	short path_prior;
	short car_num;
	short car_waiting_num;
	const double speed_fac;
	const double car_num_fac;
	vec_short tail_index; //保存每条车道的最后被占车位
	vec_bool is_ready;    //当前道路是否能够插入汽车
	
	void UPDATE_PATH(short); //将某一车道的车辆状态更新
	void DELETE_CAR(short, short);      //将某一位置的车从此道路中删除
	void MOVE_CAR(short, short, short);           //将某车道的某辆车向前移动
public:
	double WEIGHTED_ROAD_LEN();
	ROAD_ARC_UPDATE() :car_stream(NULL), road_len(0), path_num(0), road_velocity(0), 
    seq_prior(0), path_prior(0), car_num(0), car_waiting_num(0),speed_fac(0.1), car_num_fac(1){};
	void CREATE_ROAD_ARC(short, short, short); //根据道路的长度和车道数分配车流空间
	void INIT_ALL_PATH();    //开始调度时初始化所以有车道里面的车的调度状态
	void INSERT_CAR(MOVING_CAR_PTR, short, short); //插入一辆车
	void DELETE_PRIOR_CAR();            //将当前最高优先级的车删除
	void MOVE_PRIOR_TO_FRONT();         //将当前最高优先级的车辆移到车道的最前端
	void STOP_PRIOR_CAR();              //将当前最高优先级车辆停止
	void CUR_PRIOR(short&,short&);      //返回当前最高优先级车辆的位置
	MOVING_CAR_PTR FIND_PRIOR_CAR();              //返回此道路优先级最高的车辆
	bool IS_ALL_FINISHED();                       //查询此道路车辆是否全部完成调度
	void FIND_AVAILABLE_SEAT(short&, short&, short&);       //查询此道路的空闲车位,并返回此道路的最高车速
	bool IS_BLOCKED();    //查询此道路是否没有空位
	void ROAD_ARC_UPDATE_CHECK();
	~ROAD_ARC_UPDATE();                           //释放空间
};

//有向路段
typedef struct ROAD_ARC {
	typedef std::string string;
	string from_cross_id;
	string to_cross_id;
	ROAD_ARC_UPDATE* cur_road;
	ROAD_ARC* flink, *tlink;
	ROAD* roadinfo;

	ROAD_ARC() :cur_road(NULL), flink(NULL), tlink(NULL), roadinfo(NULL) {}
	~ROAD_ARC()
	{
		if (cur_road)
			delete cur_road;
	}
}*ROAD_ARC_PTR;

//车库节点
typedef struct CAR_GARAGE_NODE {
	CAR_PTR car;
	CAR_GARAGE_NODE* next;
}*CAR_GARAGE_PTR;

//路口车库，存放以某一路口为出发点的车的链表
typedef struct GARAGE {
	typedef size_t size_type;
	size_type car_num;
	//bool is_blocked;
	CAR_GARAGE_PTR first;
}*GARAGE_PTR;

//路口节点
typedef struct CROSS_NODE {
	typedef std::string string;
	string cross_id;
	ROAD_ARC_PTR flink; //以此节点为初始点的弧
	ROAD_ARC_PTR tlink; //以此节点为终点的弧
	GARAGE_PTR cross_garage; //此路口的车库
	CROSS* crossinfo;
}*CROSS_NODE_PTR;