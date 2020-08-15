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

	CROSS_NODE_PTR cross_node_list;       //·�ڽڵ㶯̬����
	size_type road_num;                   //��·����
	size_type arc_num;                    //�����·����
	size_type cross_num;                  //·������
	cross_id_map map_id;                  //��·��idӳ�䵽��̬���������

	
	size_type LOCATE_CROSS_NODE(string); //����·��idȷ����·�ڽڵ��������е�λ��
	void INSERT_CAR_TO_GARAGE(size_type, CAR_GARAGE_PTR);
	void INSERT_CAR_TO_GARAGE_SPEED_CONCERN(size_type, CAR_GARAGE_PTR);
	bool BUILD_CROSS_NODE(const vec_cross&); //����·�ڽڵ�
	bool BUILD_ROAD_ARC_NET(const vec_road&); //��������·��
	bool BUILD_CAR_GARAGE(const vec_car&); //����·�ڳ���
	vec_arc FIND_PATH(size_type, size_type, ROAD_ARC_PTR = NULL); //�ҵ�����·��֮���·��(�ų�����·��)
	double FIND_CROSS_DISTANCE(size_type, size_type, ROAD_ARC_PTR = NULL); //������·�ڵľ��� ����ͨ����������ų�·����ͬ������-1
	ROAD_ARC_PTR FIND_ARC_FOR_ADJ_CROSS(size_type, size_type); //����������·��֮�������·��
	void DESTROY_ARC();                    //�ͷ�����·��������ڴ�
	void DESTROY_GARAGE();                 //�ͷų��������ڴ�
	void DESTROY_MAP();                    //�ͷ��ڴ�
public:
	MAP() :cross_node_list(NULL), road_num(0), arc_num(0), cross_num(0) {}
	bool CREATE_MAP(const vec_cross&, const vec_road&, const vec_car&);
	void FIND_TO_CROSS_ARCS(string, vec_arc&); //���ҽ���·�ڵ�����·��
	void FIND_FROM_CROSS_ARCS(string, vec_arc&); //�����뿪·�ڵ�����·��
	void FIND_GARAGE(string, GARAGE_PTR&); //���Ҵ�·�ڵĳ���
	DIRECTION UPDATE_DIR_FOR_MOVING_CAR(CAR_PTR, ROAD_ARC_PTR);
	ROAD_ARC_PTR FIND_ROAD_FOR_CAR(CAR_PTR);
	bool IS_CONNECTED(string, string);//�������·���Ƿ���ͨ
	void UPDATE_ROAD_ARC();           //�������е�·��
	void CHECK_MAP(); 
	void CHECK_FIND_METHOD(string, string);
	vec_arc FIND_PATH(string, string,string);
	void INSERT_GARAGE_CAR(CAR_PTR);
	~MAP();
};

