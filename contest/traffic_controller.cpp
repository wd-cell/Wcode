#include "stdafx.h"
#include "function.h"
#include "stdio.h"
#include "traffic_controller.h"

TRAFFIC_CONTROLLER::TRAFFIC_CONTROLLER()
{}

TRAFFIC_CONTROLLER::TRAFFIC_CONTROLLER(string crossid, MAP& map1)
{
	time = 0;
	start_index = 0;
	terminate_num = 0;
	cross_id = crossid;
	block_time = 0;
	blocked = NULL;
	gar_car_speed = 0;
	reference_map = &map1;
	blocked_car = NULL;
	lock_arc = NULL;
	map1.FIND_FROM_CROSS_ARCS(cross_id, farc);
	map1.FIND_TO_CROSS_ARCS(cross_id, tarc);
	map1.FIND_GARAGE(cross_id, cross_garage);
	TARC_ID_ASCENDING(tarc, tarc_id_sequence);
	/*for (size_type i = 0; i < 4; i++)
	{
		blocked[i] = NULL;
		blocked_time[i] = 0;
	}*/
}

void TRAFFIC_CONTROLLER::TARC_ID_ASCENDING(const vec_arc& vec1, vec_arc& vec2)
{
	for (size_type i = 0; i < vec1.size(); i++)
	{
		if (!vec1[i])
			continue;
		else {
			short temp = STR2US(vec1[i]->roadinfo->road_id);
			vec_arc::iterator ite;
			for (ite = vec2.begin(); ite != vec2.end(); ite++)
			{
				if (temp <= STR2US((*ite)->roadinfo->road_id))
					break;
			}
			vec2.insert(ite, vec1[i]);
		}
	}
	return;
}

size_t TRAFFIC_CONTROLLER::TARC_MAP(ROAD_ARC_PTR arc1)
{
	for (size_type i = 0; i < tarc.size(); i++)
		if (tarc[i] == arc1)
			return i;
	return -1;
}

size_t TRAFFIC_CONTROLLER::TARC_SEQ_MAP(ROAD_ARC_PTR arc1)
{
	for (size_type i = 0; i < tarc_id_sequence.size(); i++)
		if (tarc_id_sequence[i] == arc1)
			return i;
	return -1;
}


MOVING_CAR_PTR TRAFFIC_CONTROLLER::GET_MOVING_CAR(ROAD_ARC_PTR arc1)
{
	return arc1->cur_road->FIND_PRIOR_CAR();
}

ROAD_ARC_PTR TRAFFIC_CONTROLLER::LOCATE_NEXT_ROAD_FOR_CAR(MOVING_CAR_PTR car1, ROAD_ARC_PTR arc1)
{
	size_type i = TARC_MAP(arc1);
	size_type k = 0;
	switch (car1->cardir)
	{
	case DIRECTION::FORWARD:
		k = i + 2;
		break;
	case DIRECTION::LEFTWARD:
		k = i + 1;
		break;
	case DIRECTION::RIGHTWARD:
		k = i + 3;
		break;
	}
	return farc[k % 4];
}

ROAD_ARC_PTR TRAFFIC_CONTROLLER::LOCATE_NEXT_POSITION_FOR_CAR(MOVING_CAR_PTR car1 , ROAD_ARC_PTR arc1, short& path, short& step, short& ve)
{
	ROAD_ARC_PTR des = LOCATE_NEXT_ROAD_FOR_CAR(car1, arc1);
	des->cur_road->FIND_AVAILABLE_SEAT(path, step, ve);
	return des;
}

void TRAFFIC_CONTROLLER::VALIDATE_INSERT_STEP(MOVING_CAR_PTR car1, ROAD_ARC_PTR arc1, short& step, short& ve)
{
	short seq1 = -1;
	short path1 = -1;
	arc1->cur_road->CUR_PRIOR(path1, seq1);
	short v2 = min(car1->carinfo->top_speed,ve);
	short step_forward = v2 - seq1;
	step = min(step_forward, step);
}

bool TRAFFIC_CONTROLLER::FIND_CONFLICT(ROAD_ARC_PTR arc1)
{
	MOVING_CAR_PTR prior_car = GET_MOVING_CAR(arc1);
	size_type i = TARC_MAP(arc1);
	size_type rival1 = i;
	size_type rival2 = i;
	switch (prior_car->cardir)
	{
	case DIRECTION::TERMINATE:
		break;
	case DIRECTION::FORWARD:
		break;
	case DIRECTION::LEFTWARD:
		rival1 = (i + 3) % 4;
		break;
	case DIRECTION::RIGHTWARD:
		rival1 = (i + 1) % 4;
		rival2 = (i + 2) % 4;
		break;
	}
	if (rival1 != i&&rival2 == i)
	{
		if (tarc[rival1])
		{
			MOVING_CAR_PTR car1 = GET_MOVING_CAR(tarc[rival1]);
			if (car1&&car1->cardir == DIRECTION::FORWARD)
				return true;
		}
	}
	else if (rival1 != i&&rival2 != i)
	{
		if (tarc[rival1])
		{
			MOVING_CAR_PTR car1 = GET_MOVING_CAR(tarc[rival1]);
			if (car1&&car1->cardir == DIRECTION::FORWARD)
				return true;
		}
		if (tarc[rival2])
		{
			MOVING_CAR_PTR car2 = GET_MOVING_CAR(tarc[rival2]);
			if (car2&&car2->cardir == DIRECTION::LEFTWARD)
				return true;
		}
	}
	return false;
}

void TRAFFIC_CONTROLLER::INSERT_MOVING_CAR(MOVING_CAR_PTR car1, ROAD_ARC_PTR des1, short path, short step)
{
	des1->cur_road->INSERT_CAR(car1, path, step);
}

void TRAFFIC_CONTROLLER::DELETE_MOVING_CAR(ROAD_ARC_PTR arc1)
{
	arc1->cur_road->DELETE_PRIOR_CAR();
}

void TRAFFIC_CONTROLLER::MOVE_MOVING_CAR(ROAD_ARC_PTR arc1)
{
	arc1->cur_road->MOVE_PRIOR_TO_FRONT();
}

bool TRAFFIC_CONTROLLER::TRAN_MOVING_ONE_CAR(ROAD_ARC_PTR arc1)
{
	//size_type index = TARC_MAP(arc1);
	MOVING_CAR_PTR prior = GET_MOVING_CAR(arc1);
	if (prior->cardir == DIRECTION::TERMINATE)
	{
		DELETE_MOVING_CAR(arc1);
		prior->passed_road.push_back(arc1->roadinfo->road_id);
		HANDLE_TERMINATE_CAR(prior);
		terminate_num++;
		return true;
	}
	short path, step, des_ve;
	ROAD_ARC_PTR des = LOCATE_NEXT_POSITION_FOR_CAR(prior, arc1, path, step, des_ve);
	//std::cout << des << std::endl;
	//std::cout << path << " " << step << " " << des_ve << std::endl;
	if (path != -1 && step != -1 && des_ve != -1)
	{
		blocked = NULL;
		block_time = 0;
		VALIDATE_INSERT_STEP(prior, arc1, step, des_ve);
		if (step > 0)
		{
			UPDATE_MOVING_CAR_DIR(prior, des);
			INSERT_MOVING_CAR(prior, des, path, step);
			DELETE_MOVING_CAR(arc1);
			prior->passed_road.push_back(arc1->roadinfo->road_id);
		}
		else //step<=0 将prior移到最前端
		{
			MOVE_MOVING_CAR(arc1);
		}
		//std::cout << "success.. "<< std::endl;
		return true;
	}
	else {
		/*des->cur_road->ROAD_ARC_UPDATE_CHECK();
		std::cout << "CAR BLOCKED AT CROSS: " << cross_id << std::endl;
		std::cout << "CAR ID:" << prior->carinfo->car_id << " TO ROAD:" << des->roadinfo->road_id
			<< " START TIME:" << prior->start_time
			<< " CAR STATE:" << prior->carstate << " TIME:" << time << std::endl;
		/*block_time++;
		if (block_time >= 5)
		{
			if (CHANGE_BLOCKED_CAR_DIR(prior, arc1))
				block_time = 0;
			if (!blocked)
				blocked = des;
		}*/
		if (IS_DES_BLOCKED(des))
		{
			HANDLE_BLOCKED_CAR(prior, arc1);
			/*if (!CHANGE_BLOCKED_CAR_DIR(prior, arc1))
				HANDLE_BLOCKED_CAR(prior,arc1);
			else
			{
				std::cout << "changed" << std::endl;
			}*/
		}
		else {
			lock_arc = des;
			std::cout << cross_id <<" "<<des<< std::endl;
		}
		return false;
	}
}

bool TRAFFIC_CONTROLLER::TRAN_ONE_GARAGE_CAR(CAR_GARAGE_PTR gar_car)
{	
	//std::cout << gar_car->car->time << " " << time << std::endl;
	if (gar_car->car->time <= time)
    {
		ROAD_ARC_PTR des = SELECT_ROAD_FOR_GARAGE_CAR(gar_car);
		short path, step, ve;
		des->cur_road->FIND_AVAILABLE_SEAT(path, step, ve);
		if (path != -1 && step != -1 && ve != -1)
		{
			short vs = min(gar_car->car->top_speed, ve);
			step = min(vs, step);
			MOVING_CAR_PTR new_moving_car = new MOVING_CAR;
			if (!new_moving_car)
				exit(1);
			new_moving_car->carinfo = gar_car->car;
			new_moving_car->carstate = TRAN_STATE::FINISHED;
			new_moving_car->start_time = time;
			UPDATE_MOVING_CAR_DIR(new_moving_car, des);
			INSERT_MOVING_CAR(new_moving_car, des, path, step);
			//cross_garage->is_blocked = false;
			return true;
		}
	}
	//cross_garage->is_blocked = true;
	return false;
}

bool TRAFFIC_CONTROLLER::TRAN_ONE_GARAGE_CAR()
{
	CAR_GARAGE_PTR gar_car = cross_garage->first->next;
	CAR_GARAGE_PTR pre_car = cross_garage->first;
	while (gar_car)
	{
		CAR_GARAGE_PTR temp = gar_car->next;
		if (TRAN_ONE_GARAGE_CAR(gar_car))
		{
			delete gar_car;
			pre_car->next = temp;
			cross_garage->car_num--;
			return true;
		}
		else {
			pre_car = gar_car;
			gar_car = temp;
		}
	}
	return false;
}

bool TRAFFIC_CONTROLLER::TRAN_ONE_GARAGE_CAR_SPEED_CONCERNED()
{
	CAR_GARAGE_PTR gar_car = cross_garage->first->next;
	CAR_GARAGE_PTR pre_car = cross_garage->first;
	while (gar_car)
	{
		CAR_GARAGE_PTR temp = gar_car->next;
		if (gar_car_speed == 0 || gar_car->car->top_speed == gar_car_speed)
		{
			if (TRAN_ONE_GARAGE_CAR(gar_car))
			{
				if (gar_car_speed == 0)
					gar_car_speed = gar_car->car->top_speed;
				delete gar_car;
				pre_car->next = temp;
				cross_garage->car_num--;
				return true;
			}
		}
		pre_car = gar_car;
		gar_car = temp;
	}
	return false;
}

void TRAFFIC_CONTROLLER::TRAN_GARAGE_CAR()
{
	CAR_GARAGE_PTR gar_car = cross_garage->first->next;
	CAR_GARAGE_PTR pre_car = cross_garage->first;
	while (gar_car)
	{
		CAR_GARAGE_PTR temp = gar_car->next;
		if (TRAN_ONE_GARAGE_CAR(gar_car))
		{
			delete gar_car;
			pre_car->next = temp;
			gar_car = temp;
			cross_garage->car_num--;
		}
		else {
			pre_car = gar_car;
			gar_car = temp;
		}
	}
}

bool TRAFFIC_CONTROLLER::IS_GARAGE_BLOCKED()
{
	return true;
}

bool TRAFFIC_CONTROLLER::TRAN_MOVING_CAR(ROAD_ARC_PTR arc1)
{
	while (GET_MOVING_CAR(arc1) && !FIND_CONFLICT(arc1))
	{
		if (!TRAN_MOVING_ONE_CAR(arc1))
		{
			start_index = TARC_SEQ_MAP(arc1);
			return false;
		}
	}
	start_index = 0;
	return true;
}

void TRAFFIC_CONTROLLER::TRAN_ONE_REV()
{
	if (IS_TRAN_MOVING_FINISHED())
	{
		std::cout << "CROSS ID:" << cross_id << " FINISHED" << std::endl;
		return;
	}
	else
	{
		for (size_type i = start_index; i < tarc_id_sequence.size(); i++)
		{
			ROAD_ARC_PTR cur_arc = tarc_id_sequence[i];
			std::cout << "CROSS ID:" << cross_id << " ROAD" << cur_arc->roadinfo->road_id<<std::endl;
			if (!TRAN_MOVING_CAR(cur_arc))
				break;
		}
		return;
	}
}

bool TRAFFIC_CONTROLLER::IS_TRAN_MOVING_FINISHED()
{
	for (size_type i = 0; i < tarc_id_sequence.size(); i++)
	{
		if (!tarc_id_sequence[i]->cur_road->IS_ALL_FINISHED())
			return false;
	}
	return true;
}

void TRAFFIC_CONTROLLER::NEW_TIME()
{
	time++;
	gar_car_speed = 0;
}

void TRAFFIC_CONTROLLER::UPDATE_MOVING_CAR_DIR(MOVING_CAR_PTR car1, ROAD_ARC_PTR arc1)
{
	DIRECTION new_direction = reference_map->UPDATE_DIR_FOR_MOVING_CAR(car1->carinfo, arc1);
	car1->cardir = new_direction;
}

ROAD_ARC_PTR TRAFFIC_CONTROLLER::SELECT_ROAD_FOR_GARAGE_CAR(CAR_GARAGE_PTR gar_car1)
{
	return reference_map->FIND_ROAD_FOR_CAR(gar_car1->car);
}

void TRAFFIC_CONTROLLER::HANDLE_TERMINATE_CAR(MOVING_CAR_PTR terminate_car)
{
	std::cout << terminate_car->carinfo->car_id << std::endl;
	std::cout << "FROM CROSS: " << terminate_car->carinfo->from_id <<" TO CROSS: "<< terminate_car->carinfo->to_id<< std::endl;
	std::cout << "STARTING TIME: " << terminate_car->start_time << std::endl;
	std::cout << "PATH: ";
	for (size_type i = 0; i < terminate_car->passed_road.size(); i++)
	{
		std::cout << terminate_car->passed_road[i] << " ";
	}
	std::cout << std::endl;
	return;
}

void TRAFFIC_CONTROLLER::TRAFFIC_CONTROLLER_CHECK()
{
	std::cout << cross_id << std::endl;
	for (size_type i = 0; i < farc.size(); i++)
	{
		if(farc[i])
		 std::cout << "FARCS: " << farc[i]->roadinfo->road_id << " ";
	}
	std::cout << std::endl;
	for (size_type i = 0; i < tarc.size(); i++)
	{
		if(tarc[i])
		 std::cout << "TARCS: " << tarc[i]->roadinfo->road_id << " ";
	}
	std::cout << std::endl;
	CAR_GARAGE_PTR car = cross_garage->first->next;
	std::cout << "CAR: ";
	while (car)
	{
		std::cout << car->car->car_id << " ";
		car = car->next;
	}
	std::cout << std::endl;
}

std::string TRAFFIC_CONTROLLER::GET_TRAFFIC_CONTROLLER_ID()
{
	return cross_id;
}

size_t TRAFFIC_CONTROLLER::GET_TERMINATE_CAR()
{
	return terminate_num;
}

bool TRAFFIC_CONTROLLER::CHANGE_BLOCKED_CAR_DIR(MOVING_CAR_PTR car1, ROAD_ARC_PTR arc1)
{
	DIRECTION old_dir = car1->cardir;
	DIRECTION new_dir1, new_dir2;
	size_type cur_index = TARC_MAP(arc1);
	size_type new_index1, new_index2;
	ROAD_ARC_PTR new_arc1, new_arc2;
	switch (old_dir)
	{
	case DIRECTION::FORWARD:
		new_dir1 = DIRECTION::LEFTWARD;
		new_dir2 = DIRECTION::RIGHTWARD;
		new_index1 = (cur_index + 1) % 4;
		new_index2 = (cur_index + 3) % 4;
		break;
	case DIRECTION::LEFTWARD:
		new_dir1 = DIRECTION::FORWARD;
		new_dir2 = DIRECTION::RIGHTWARD;
		new_index1 = (cur_index + 2) % 4;
		new_index2 = (cur_index + 3) % 4;
		break;
	case DIRECTION::RIGHTWARD:
		new_dir1 = DIRECTION::FORWARD;
		new_dir2 = DIRECTION::LEFTWARD;
		new_index1 = (cur_index + 2) % 4;
		new_index2 = (cur_index + 1) % 4;
	}
	new_arc1 = farc[new_index1];
	new_arc2 = farc[new_index2];
	std::cout << "change..." << std::endl;
	if (new_arc1&& !IS_DES_BLOCKED(new_arc1))
	{
		std::cout << "changed..." << std::endl;
		vec_arc vec1 = reference_map->FIND_PATH(new_arc1->to_cross_id, car1->carinfo->to_id, new_arc1->from_cross_id);
		if (!vec1.empty())
		{
			car1->cardir = new_dir1;
			return true;
		}
	}
	std::cout << "change..." << std::endl;
	if (new_arc2&& !IS_DES_BLOCKED(new_arc2))
	{
		std::cout << "changed..." << std::endl;
		vec_arc vec2 = reference_map->FIND_PATH(new_arc2->to_cross_id, car1->carinfo->to_id, new_arc2->from_cross_id);
		if (!vec2.empty())
		{
			car1->cardir = new_dir2;
			return true;
		}
	}
	std::cout << "return..." << std::endl;
	return false;
}

bool TRAFFIC_CONTROLLER::IS_DES_BLOCKED(ROAD_ARC_PTR des)
{
	return des->cur_road->IS_BLOCKED();
}

void TRAFFIC_CONTROLLER::HANDLE_BLOCKED_CAR(MOVING_CAR_PTR car1,ROAD_ARC_PTR arc1)
{
	car1->carinfo->time = car1->start_time;
	blocked_car = car1->carinfo;
	DELETE_MOVING_CAR(arc1);
}

bool TRAFFIC_CONTROLLER::BREAK_LOCK()
{
	ROAD_ARC_PTR arc1 = tarc_id_sequence[start_index];
	MOVING_CAR_PTR prior = GET_MOVING_CAR(arc1);
	std::cout << "break lock.." <<prior<< std::endl;
	return CHANGE_BLOCKED_CAR_DIR(prior, arc1);
}

void TRAFFIC_CONTROLLER::HANDLE_BLOCKED_CAR()
{
	ROAD_ARC_PTR arc1 = tarc_id_sequence[start_index];
	MOVING_CAR_PTR prior = GET_MOVING_CAR(arc1);
	HANDLE_BLOCKED_CAR(prior, arc1);
}