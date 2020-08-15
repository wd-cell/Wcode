#include "stdafx.h"
#include "map.h"
#include "function.h"
#include <queue>
#include <iostream>

size_t MAP::LOCATE_CROSS_NODE(string cross_id)
{
	return map_id.at(cross_id);
}

bool MAP::BUILD_CROSS_NODE(const vec_cross& vec)
{
	cross_num = vec.size();
	cross_node_list = new CROSS_NODE[cross_num];
	if (!cross_node_list)
		exit(1);
	for (size_type i = 0; i < cross_num; i++)
	{
		CROSS_NODE_PTR temp_ptr = cross_node_list + i;
		temp_ptr->cross_id = vec[i]->cross_id;
		temp_ptr->flink = NULL;
		temp_ptr->tlink = NULL;
		temp_ptr->cross_garage = NULL;
		temp_ptr->crossinfo = vec[i];
		map_id.insert(std::pair<string, size_type>(temp_ptr->cross_id, i));
	}
	return true;
}

bool MAP::BUILD_ROAD_ARC_NET(const vec_road& vec)
{
	road_num = vec.size();
	for (size_type i = 0; i < road_num; i++)
	{
		ROAD_ARC_PTR arc = NULL;
		ROAD_ARC_PTR arc_re = NULL;
		size_type k = LOCATE_CROSS_NODE(vec[i]->from_id);
		size_type j = LOCATE_CROSS_NODE(vec[i]->to_id);
		arc = new ROAD_ARC;
		if (!arc)
			exit(1);
		arc->from_cross_id = vec[i]->from_id;
		arc->to_cross_id = vec[i]->to_id;
		arc->flink = cross_node_list[k].flink;
		cross_node_list[k].flink = arc;
		arc->tlink = cross_node_list[j].tlink;
		cross_node_list[j].tlink = arc;

		arc->roadinfo = vec[i];
		arc->cur_road = new ROAD_ARC_UPDATE;
		if (!arc->cur_road)
			exit(1);
		arc->cur_road->CREATE_ROAD_ARC(vec[i]->length, vec[i]->path_num, vec[i]->top_speed);
		arc_num += 1;
		if (vec[i]->is_duplex)
		{
			arc_re = new ROAD_ARC;
			if (!arc_re)
				exit(1);
			arc_re->from_cross_id = vec[i]->to_id;
			arc_re->to_cross_id = vec[i]->from_id;
			arc_re->flink = cross_node_list[j].flink;
			cross_node_list[j].flink = arc_re;
			arc_re->tlink = cross_node_list[k].tlink;
			cross_node_list[k].tlink = arc_re;

			arc_re->roadinfo = vec[i];
			arc_re->cur_road = new ROAD_ARC_UPDATE;
			if (!arc_re->cur_road)
				exit(1);
			arc_re->cur_road->CREATE_ROAD_ARC(vec[i]->length, vec[i]->path_num, vec[i]->top_speed);
			arc_num += 1;
		}
	}
	return true;
}

void MAP::INSERT_CAR_TO_GARAGE(size_type index, CAR_GARAGE_PTR new_car)
{
	GARAGE_PTR temp = cross_node_list[index].cross_garage;
	if (temp->first->next == NULL)
		temp->first->next = new_car;
	else {
		CAR_GARAGE_PTR insert_car = temp->first->next;
		CAR_GARAGE_PTR pre_car = temp->first;
		while (STR2US(insert_car->car->car_id) < STR2US(new_car->car->car_id) && insert_car->next)
		{
			pre_car = insert_car;
			insert_car = insert_car->next;
		}
		if (STR2US(insert_car->car->car_id) < STR2US(new_car->car->car_id))
		{
			insert_car->next = new_car;
			new_car->next = NULL;
		}
		else
		{
			pre_car->next = new_car;
			new_car->next = insert_car;
		}
	}
	temp->car_num++;
}

void MAP::INSERT_CAR_TO_GARAGE_SPEED_CONCERN(size_type index, CAR_GARAGE_PTR new_car)
{
	GARAGE_PTR temp = cross_node_list[index].cross_garage;
	if (temp->first->next == NULL)
		temp->first->next = new_car;
	else {
		CAR_GARAGE_PTR insert_car = temp->first->next;
		CAR_GARAGE_PTR pre_car = temp->first;
		while (insert_car->car->top_speed > new_car->car->top_speed && insert_car->next)
		{
			pre_car = insert_car;
			insert_car = insert_car->next;
		}
		if (insert_car->car->top_speed > new_car->car->top_speed)
		{
			insert_car->next = new_car;
			new_car->next = NULL;
		}
		else if (insert_car->car->top_speed < new_car->car->top_speed)
		{
			pre_car->next = new_car;
			new_car->next = insert_car;
		}
		else
		{
			CAR_GARAGE_PTR rear = insert_car;
			while (rear && insert_car->car->top_speed == rear->car->top_speed)
			{
				if (STR2US(rear->car->car_id) < STR2US(new_car->car->car_id))
				{
					pre_car = rear;
					rear = rear->next;
				}
				break;
			}
			pre_car->next = new_car;
			new_car->next = rear;
		}
	}
	temp->car_num++;
}

bool MAP::BUILD_CAR_GARAGE(const vec_car& vec)
{
	size_type car_num = vec.size();
	//为每个路口节点分配车库空间
	for (size_type i = 0; i < cross_num; i++)
	{
		GARAGE_PTR temp = new GARAGE;
		if (!temp)
			exit(1);
		temp->car_num = 0;
		//temp->is_blocked = false;
		CAR_GARAGE_PTR first = new CAR_GARAGE_NODE;
		if (!first)
			exit(1);
		first->car = NULL;
		first->next = NULL;
		temp->first = first;
		cross_node_list[i].cross_garage = temp;
	}
	//为路口的车库填充车辆
	for (size_type i = 0; i < car_num; i++)
    {
		CAR_GARAGE_PTR new_car = new CAR_GARAGE_NODE;
		if (!new_car)
			exit(1);
		new_car->car = vec[i];
		new_car->next = NULL;
		size_type index = map_id[vec[i]->from_id];
		INSERT_CAR_TO_GARAGE(index, new_car);
		//INSERT_CAR_TO_GARAGE_SPEED_CONCERN(index, new_car);
	}
	return true;
}

//按照上右下左的顺序返回进入路口的有向路段的指针
void MAP::FIND_TO_CROSS_ARCS(string crossid, vec_arc& vec1) 
{
	vec1.clear();
	size_type index = map_id[crossid];
	ROAD_ARC_PTR ptr1=NULL, ptr2=NULL, ptr3=NULL, ptr4=NULL;
	ROAD_ARC_PTR temp = cross_node_list[index].tlink;
	while (temp)
	{
		if (temp->roadinfo->road_id == cross_node_list[index].crossinfo->road_id_1)
			ptr1 = temp;
		else if (temp->roadinfo->road_id == cross_node_list[index].crossinfo->road_id_2)
			ptr2 = temp;
		else if (temp->roadinfo->road_id == cross_node_list[index].crossinfo->road_id_3)
			ptr3 = temp;
		else
			ptr4 = temp;
		temp = temp->tlink;
	}
	vec1.push_back(ptr1);
	vec1.push_back(ptr2);
	vec1.push_back(ptr3);
	vec1.push_back(ptr4);
	return;
}

//按照上右下左的顺序返回离开路口的有向路段的指针
void MAP::FIND_FROM_CROSS_ARCS(string crossid, vec_arc& vec1)
{
	vec1.clear();
	size_type index = map_id[crossid];
	ROAD_ARC_PTR ptr1 = NULL, ptr2 = NULL, ptr3 = NULL, ptr4 = NULL;
	ROAD_ARC_PTR temp = cross_node_list[index].flink;
	while (temp)
	{
		if (temp->roadinfo->road_id == cross_node_list[index].crossinfo->road_id_1)
			ptr1 = temp;
		else if (temp->roadinfo->road_id == cross_node_list[index].crossinfo->road_id_2)
			ptr2 = temp;
		else if (temp->roadinfo->road_id == cross_node_list[index].crossinfo->road_id_3)
			ptr3 = temp;
		else
			ptr4 = temp;
		temp = temp->flink;
	}
	vec1.push_back(ptr1);
	vec1.push_back(ptr2);
	vec1.push_back(ptr3);
	vec1.push_back(ptr4);
	return;
}

void MAP::FIND_GARAGE(string crossid, GARAGE_PTR& gar)
{
	gar = NULL;
	size_type index = map_id[crossid];
	gar = cross_node_list[index].cross_garage;
}

bool MAP::CREATE_MAP(const vec_cross& vec1, const vec_road& vec2, const vec_car& vec3)
{
	if (BUILD_CROSS_NODE(vec1) && BUILD_ROAD_ARC_NET(vec2) && BUILD_CAR_GARAGE(vec3))
		return true;
	return false;
}

void MAP::CHECK_MAP()
{
	for (size_type i = 0; i < cross_num; i++)
	{
		std::cout << cross_node_list[i].cross_id <<std::endl;
		ROAD_ARC_PTR temp = cross_node_list[i].flink;
		while (temp)
		{
			std::cout << temp->roadinfo->road_id << std::endl;
			temp->cur_road->ROAD_ARC_UPDATE_CHECK();
			//std::cout << "   ";
			temp = temp->flink;
		}
		std::cout << std::endl;
		std::cout << cross_node_list[i].cross_id << std::endl;
		temp = cross_node_list[i].tlink;
		while (temp)
		{
			std::cout << temp->roadinfo->road_id << std::endl;
			temp->cur_road->ROAD_ARC_UPDATE_CHECK();
			//std::cout << "   ";
			temp = temp->tlink;
		}
		std::cout << std::endl;
		std::cout << cross_node_list[i].cross_id << std::endl;
		GARAGE_PTR gar;
		gar = cross_node_list[i].cross_garage;
		std::cout << gar->car_num << "   ";
		CAR_GARAGE_PTR car_node = gar->first->next;
		while (car_node)
		{
			std::cout << car_node->car->car_id << " "<<car_node->car->top_speed<<"   ";
			car_node = car_node->next;
		}
		std::cout << std::endl;
	}
}

void MAP::DESTROY_ARC()
{
	for (size_type i = 0; i < cross_num; i++)
	{
		ROAD_ARC_PTR fptr = cross_node_list[i].flink;
		while (fptr) {
			ROAD_ARC_PTR temp = fptr->flink;
			delete fptr;
			fptr = temp;
		}
	}
}

void MAP::DESTROY_GARAGE()
{
	for (size_type i = 0; i < cross_num; i++)
	{
		GARAGE_PTR cur_garage = cross_node_list[i].cross_garage;
		CAR_GARAGE_PTR cur_car = cur_garage->first;
		while (cur_car)
		{
			CAR_GARAGE_PTR temp = cur_car->next;
			delete cur_car;
			cur_car = temp;
		}
		delete cur_garage;
	}
	return;
}

void MAP::DESTROY_MAP()
{
	DESTROY_ARC();
	DESTROY_GARAGE();
	delete[] cross_node_list;
}

MAP::~MAP()
{
	DESTROY_MAP();
}

DIRECTION MAP::UPDATE_DIR_FOR_MOVING_CAR(CAR_PTR car1, ROAD_ARC_PTR arc1)
{
	size_type cur_index = map_id[arc1->to_cross_id];
	size_type des_index = map_id[car1->to_id];
	if (cur_index == des_index)
		return DIRECTION::TERMINATE;
	else {
		size_type exclude_start = map_id[arc1->to_cross_id];
		size_type exclude_des = map_id[arc1->from_cross_id];
		ROAD_ARC_PTR exclude_arc = FIND_ARC_FOR_ADJ_CROSS(exclude_start, exclude_des);
		vec_arc path = FIND_PATH(cur_index, des_index, exclude_arc);
		if (path.empty())
		{
			std::cout << "start to des not passed" << std::endl;
			exit(1);
		}
		ROAD_ARC_PTR next_arc = path.back();
		string next_id = next_arc->roadinfo->road_id;
		string cur_id = arc1->roadinfo->road_id;
		short cur=-1,next=-1;
	    if (cur_id == cross_node_list[cur_index].crossinfo->road_id_1)
			cur = 0;
	    else if (cur_id == cross_node_list[cur_index].crossinfo->road_id_2)
			cur = 1;
		else if (cur_id == cross_node_list[cur_index].crossinfo->road_id_3)
			cur = 2;
		else
			cur = 3;
			
		if (next_id == cross_node_list[cur_index].crossinfo->road_id_1)
			next = 0;
		else if (next_id == cross_node_list[cur_index].crossinfo->road_id_2)
			next = 1;
		else if (next_id == cross_node_list[cur_index].crossinfo->road_id_3)
			next = 2;
		else
			next = 3;

		if ((cur + 2) % 4 == next % 4)
			return DIRECTION::FORWARD;
		else if ((cur + 1) % 4 == next % 4)
			return DIRECTION::LEFTWARD;
		else
			return DIRECTION::RIGHTWARD;
	}
}

ROAD_ARC_PTR MAP::FIND_ROAD_FOR_CAR(CAR_PTR car1)
{
	size_type cur_index = map_id[car1->from_id];
	size_type des_index = map_id[car1->to_id];
	vec_arc path=FIND_PATH(cur_index, des_index, NULL);
	if (path.empty())
		return NULL;
	else
		return path.back();
}

std::vector<ROAD_ARC_PTR> MAP::FIND_PATH(size_type start, size_type des, ROAD_ARC_PTR exclude_arc)
{
	vec_arc res;
	std::vector<size_type> short_path_seq;
	std::vector<short> pre_index;
	std::vector<double> distance;
	std::vector<bool> has_short;
	double min=-1; //-1为距离无限大
	size_type min_index = cross_num;
	for (size_type i = 0; i < cross_num; i++)
	{
		if (i == start)
			distance.push_back(0);
		else
		{
			double temp= FIND_CROSS_DISTANCE(start, i, exclude_arc);
			if (temp!=-1&&(min==-1||min > temp))
			{
				min = temp;
				min_index = i;
			}
			distance.push_back(temp);
		}
		has_short.push_back(false);
		pre_index.push_back(-1);
	}
	if (min == -1)
		return res;
	short_path_seq.push_back(min_index);
	has_short[min_index] = true;
	min = -1;
	while(!has_short[des])
	{
		size_type cur_index = short_path_seq.back();
		for (size_type i = 0; i < cross_num; i++)
		{
			if (i!=start&&!has_short[i])
			{
				double temp = FIND_CROSS_DISTANCE(cur_index, i, exclude_arc);
				if (temp!=-1 && (distance[i] == -1 || (temp + distance[cur_index]) < distance[i]))
				{
					distance[i] = temp + distance[cur_index];
					pre_index[i] = cur_index;
				}
				if (distance[i]!= -1 && (min == -1 || min > distance[i]))
				{
					min = distance[i];
					min_index = i;
				}
			}
		}
		if (min == -1) //两个路口不通
			return res;
		short_path_seq.push_back(min_index);
		has_short[min_index] = true;
		min = -1;
	}
	size_type indicator = min_index;
	while (pre_index[indicator]!=-1)
	{
		res.push_back(FIND_ARC_FOR_ADJ_CROSS(pre_index[indicator], indicator));
		indicator = pre_index[indicator];
	}
	res.push_back(FIND_ARC_FOR_ADJ_CROSS(start, indicator));
	return res;
}

std::vector<ROAD_ARC_PTR> MAP::FIND_PATH(string start_id, string des_id, string avoid_id)
{
	size_type start = map_id[start_id];
	size_type des = map_id[des_id];
	size_type avoid = map_id[avoid_id];
	ROAD_ARC_PTR avoid_arc = FIND_ARC_FOR_ADJ_CROSS(start, avoid);
	vec_arc path = FIND_PATH(start, des, avoid_arc);
	/*for (size_type i = 0; i < path.size(); i++)
	{
		std::cout << path[i]->roadinfo->road_id << " ";
	}
	std::cout << std::endl;*/
	return path;
}

double MAP::FIND_CROSS_DISTANCE(size_type start, size_type des, ROAD_ARC_PTR exclude_arc)
{
	if (exclude_arc)
	{
		size_type exclude_start = map_id[exclude_arc->from_cross_id];
		size_type exclude_des = map_id[exclude_arc->to_cross_id];
		if (start == exclude_start&&des == exclude_des)
			return -1;
	}
	ROAD_ARC_PTR arc1 = cross_node_list[start].flink;
	string des_id = cross_node_list[des].cross_id;
	while (arc1)
	{
		if (arc1->to_cross_id == des_id)
			return arc1->cur_road->WEIGHTED_ROAD_LEN();
		arc1 = arc1->flink;
	}
	return -1;
}

ROAD_ARC_PTR MAP::FIND_ARC_FOR_ADJ_CROSS(size_type start, size_type des)
{
	ROAD_ARC_PTR arc1 = cross_node_list[start].flink;
	string des_id = cross_node_list[des].cross_id;
	while (arc1)
	{
		if (arc1->to_cross_id == des_id)
			return arc1;
		arc1 = arc1->flink;
	}
	return NULL;
}

bool MAP::IS_CONNECTED(string start_id, string des_id)
{
	std::vector<bool> visited;
	std::queue<size_type> que;
	for (size_type i = 0; i < cross_num; i++)
	{
		visited.push_back(false);
	}
	size_type start = map_id[start_id];
	size_type des = map_id[des_id];
	que.push(start);
	visited[start] = true;
	while (!que.empty())
	{
		size_type temp = que.front();
		que.pop();
		ROAD_ARC_PTR adj = cross_node_list[temp].flink;
		while (adj)
		{
			size_type cur = map_id[adj->to_cross_id];
			if (!visited[cur])
			{
				visited[cur] = true;
				que.push(cur);
			}
			adj = adj->flink;
		}
	}
	return visited[des];
}

void MAP::INSERT_GARAGE_CAR(CAR_PTR car1)
{
	CAR_GARAGE_PTR new_car = new CAR_GARAGE_NODE;
	if (!new_car)
		exit(1);
	new_car->car = car1;
	new_car->next = NULL;
	size_type index = map_id[car1->from_id];
	INSERT_CAR_TO_GARAGE(index, new_car);
}

void MAP::UPDATE_ROAD_ARC()
{
	for (size_type i = 0; i < cross_num; i++)
	{
		ROAD_ARC_PTR temp = cross_node_list[i].flink;
		while (temp)
		{
			temp->cur_road->INIT_ALL_PATH();
			temp = temp->flink;
		}
	}
}

void MAP::CHECK_FIND_METHOD(string start_id, string des_id)
{
	size_type start = map_id[start_id];
	size_type des = map_id[des_id];
	vec_arc path = FIND_PATH(start, des);
	std::cout << "CROSS " << start_id << " TO " << des_id << ": ";
	for (auto arc : path)
		std::cout << arc->roadinfo->road_id << " ";
	std::cout << std::endl;
}