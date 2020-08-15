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
	size_type terminate_num; //�����·�ڽ����ĳ���
	ROAD_ARC_PTR blocked;
	size_type block_time;    //��¼ĳ��������Ĵ���
	short gar_car_speed;     //��ǰʱ��Ƭ�ĳ��������ٶ�
	string filename;
	//vec_car blocked_car;      //���汻������·�ڵĳ���

	size_type TARC_MAP(ROAD_ARC_PTR); //ȷ������·�ڵ�����·����0 ��1 ��2 ��3λ��
	size_type TARC_SEQ_MAP(ROAD_ARC_PTR);
	void TARC_ID_ASCENDING(const vec_arc&, vec_arc&);//������·�ڵ�����·����id��������
	MOVING_CAR_PTR GET_MOVING_CAR(ROAD_ARC_PTR);  //��ȡ·�ε�������ȼ�����
	void DELETE_MOVING_CAR(ROAD_ARC_PTR);         //ɾ��·�ε�������ȼ�����
	void MOVE_MOVING_CAR(ROAD_ARC_PTR);           //�ƶ�·�ε�������ȼ���������ǰ��
	ROAD_ARC_PTR LOCATE_NEXT_ROAD_FOR_CAR(MOVING_CAR_PTR,ROAD_ARC_PTR); //ȷ����������һ��·
    ROAD_ARC_PTR LOCATE_NEXT_POSITION_FOR_CAR(MOVING_CAR_PTR,ROAD_ARC_PTR,short&,short&,short&);
	void VALIDATE_INSERT_STEP(MOVING_CAR_PTR,ROAD_ARC_PTR, short&, short&); //ȷ��������ʵ�ʲ���λ��
	bool FIND_CONFLICT(ROAD_ARC_PTR);
	void INSERT_MOVING_CAR(MOVING_CAR_PTR, ROAD_ARC_PTR, short, short);
	bool TRAN_MOVING_ONE_CAR(ROAD_ARC_PTR);//һ������ͨ��·��
	bool TRAN_ONE_GARAGE_CAR(CAR_GARAGE_PTR);            //����һ�γ����е�����
	void UPDATE_MOVING_CAR_DIR(MOVING_CAR_PTR, ROAD_ARC_PTR);//�����г�����
	bool CHANGE_BLOCKED_CAR_DIR(MOVING_CAR_PTR, ROAD_ARC_PTR);//Ϊ�������ĳ���������
	bool IS_DES_BLOCKED(ROAD_ARC_PTR);//Ŀ���·�Ƿ�ռ��
	//bool CHANGE_MOVING_CAR_DIR(MOVING_CAR_PTR, ROAD_ARC_PTR);
	ROAD_ARC_PTR SELECT_ROAD_FOR_GARAGE_CAR(CAR_GARAGE_PTR);
	void HANDLE_TERMINATE_CAR(MOVING_CAR_PTR); //�����Ѿ��ִ��յ�ĳ�
	void HANDLE_BLOCKED_CAR(MOVING_CAR_PTR,ROAD_ARC_PTR);//���������ĳ���
public: 
	CAR_PTR blocked_car;      //���汻������·�ڵĳ���
	ROAD_ARC_PTR lock_arc;
	void TRAN_GARAGE_CAR();              //���ȳ����е�����
	bool TRAN_ONE_GARAGE_CAR();          //����һ�����������
	bool TRAN_ONE_GARAGE_CAR_SPEED_CONCERNED();  //���ճ����ɴ�С�����ȼ�����һ�����������
	bool IS_GARAGE_BLOCKED();            //����Ŀǰ�Ƿ��г��ɵ�
	bool TRAN_MOVING_CAR(ROAD_ARC_PTR);  //����������ͨ��·��
	void TRAN_ONE_REV();              //Ϊ��·�ڽ���һ�ε���
	void NEW_TIME();                  //��ʼһ���µ�ʱ��Ƭ
	bool IS_TRAN_MOVING_FINISHED();          //��ѯ��ʱ��Ƭ��·����ʻ�����ĵ����Ƿ������
	void TRAFFIC_CONTROLLER_CHECK();
	string GET_TRAFFIC_CONTROLLER_ID();//����·��ID
	size_type GET_TERMINATE_CAR();     //���صִ����·�ڵĳ���
	bool BREAK_LOCK();                 //Ϊ��·�ڵĳ�����������������
	void HANDLE_BLOCKED_CAR();//���������ĳ���
	TRAFFIC_CONTROLLER(string, MAP&,string);
	TRAFFIC_CONTROLLER();             //Ĭ�Ϲ��캯��
};

