#pragma once
#include <string>
#include <vector>
//��·
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

//·��
typedef struct CROSS {
	typedef std::string string;
	string cross_id;
	string road_id_1;
	string road_id_2;
	string road_id_3;
	string road_id_4;

	CROSS() {};
}*CROSS_PTR;

//����
typedef struct CAR {
	typedef std::string string;
	string car_id;
	string from_id;
	string to_id;
	short top_speed;
	short time;
    
	CAR() {};
}*CAR_PTR;

//�г�����
enum DIRECTION {
	FORWARD,     //ֱ��
	LEFTWARD,    //��ת
	RIGHTWARD,   //��ת
	TERMINATE    //����
};

//����״̬
enum TRAN_STATE {
	WAITING,     //�ȴ�����
	FINISHED     //��ɵ���
};

//��ʻ�е�����
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
	vec_short tail_index; //����ÿ�����������ռ��λ
	vec_bool is_ready;    //��ǰ��·�Ƿ��ܹ���������
	
	void UPDATE_PATH(short); //��ĳһ�����ĳ���״̬����
	void DELETE_CAR(short, short);      //��ĳһλ�õĳ��Ӵ˵�·��ɾ��
	void MOVE_CAR(short, short, short);           //��ĳ������ĳ������ǰ�ƶ�
public:
	double WEIGHTED_ROAD_LEN();
	ROAD_ARC_UPDATE() :car_stream(NULL), road_len(0), path_num(0), road_velocity(0), 
    seq_prior(0), path_prior(0), car_num(0), car_waiting_num(0),speed_fac(0.1), car_num_fac(1){};
	void CREATE_ROAD_ARC(short, short, short); //���ݵ�·�ĳ��Ⱥͳ��������䳵���ռ�
	void INIT_ALL_PATH();    //��ʼ����ʱ��ʼ�������г�������ĳ��ĵ���״̬
	void INSERT_CAR(MOVING_CAR_PTR, short, short); //����һ����
	void DELETE_PRIOR_CAR();            //����ǰ������ȼ��ĳ�ɾ��
	void MOVE_PRIOR_TO_FRONT();         //����ǰ������ȼ��ĳ����Ƶ���������ǰ��
	void STOP_PRIOR_CAR();              //����ǰ������ȼ�����ֹͣ
	void CUR_PRIOR(short&,short&);      //���ص�ǰ������ȼ�������λ��
	MOVING_CAR_PTR FIND_PRIOR_CAR();              //���ش˵�·���ȼ���ߵĳ���
	bool IS_ALL_FINISHED();                       //��ѯ�˵�·�����Ƿ�ȫ����ɵ���
	void FIND_AVAILABLE_SEAT(short&, short&, short&);       //��ѯ�˵�·�Ŀ��г�λ,�����ش˵�·����߳���
	bool IS_BLOCKED();    //��ѯ�˵�·�Ƿ�û�п�λ
	void ROAD_ARC_UPDATE_CHECK();
	~ROAD_ARC_UPDATE();                           //�ͷſռ�
};

//����·��
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

//����ڵ�
typedef struct CAR_GARAGE_NODE {
	CAR_PTR car;
	CAR_GARAGE_NODE* next;
}*CAR_GARAGE_PTR;

//·�ڳ��⣬�����ĳһ·��Ϊ������ĳ�������
typedef struct GARAGE {
	typedef size_t size_type;
	size_type car_num;
	//bool is_blocked;
	CAR_GARAGE_PTR first;
}*GARAGE_PTR;

//·�ڽڵ�
typedef struct CROSS_NODE {
	typedef std::string string;
	string cross_id;
	ROAD_ARC_PTR flink; //�Դ˽ڵ�Ϊ��ʼ��Ļ�
	ROAD_ARC_PTR tlink; //�Դ˽ڵ�Ϊ�յ�Ļ�
	GARAGE_PTR cross_garage; //��·�ڵĳ���
	CROSS* crossinfo;
}*CROSS_NODE_PTR;