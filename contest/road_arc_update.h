#pragma once
#include "class_def.h"
#include <vector>

//ʵʱ����ÿ������·��·��(����)
class ROAD_ARC_UPDATE {
protected:
	typedef size_t size_type;
	typedef std::vector<short> vec_short;

	MOVING_CAR_PTR **car_stream;
	short road_len;
	short path_num;
	vec_short tail_index; //����ÿ����������ʼ���г�λ
	size_type car_num;
	size_type car_num_waiting; //�˵�·�д��ڵȴ�״̬�ĳ�������
	bool is_finished;          
	void UPDATE_PATH(short); //��ĳһ�����ĳ���״̬����
public:
	ROAD_ARC_UPDATE() :car_stream(NULL), road_len(0), path_num(0),car_num(0),car_num_waiting(0),is_finished(true) {};
	void CREATE_ROAD_ARC(short, short); //���ݵ�·�ĳ��Ⱥͳ��������䳵���ռ�
	void INSERT_CAR(MOVING_CAR_PTR,short, short); //����һ����
	void MOVE_CAR(short, short, short);           //��ĳ������ĳ������ǰ�ƶ�
	void DELETE_CAR(short, short);      //��ĳһλ�õĳ��Ӵ˵�·��ɾ��
	void DELETE_PRIOR_CAR();            //����ǰ������ȼ��ĳ�ɾ��
	MOVING_CAR_PTR FIND_PRIOR_CAR();              //���ش˵�·���ȼ���ߵĳ���
	bool IS_ALL_FINISHED();                       //��ѯ�˵�·�����Ƿ�ȫ����ɵ���
	void FIND_AVAILABLE_SEAT(short, short);       //��ѯ�˵�·�Ŀ��г�λ
	~ROAD_ARC_UPDATE();                           //�ͷſռ�
};