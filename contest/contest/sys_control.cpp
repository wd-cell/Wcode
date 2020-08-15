#include "stdafx.h"
#include "sys_control.h"
#include <fstream>

bool SYS_CONTROL::IS_MOVING_CAR_FINISHED()
{
	for (size_type i = 0; i<ctrls.size(); i++)
		if (!ctrls[i].IS_TRAN_MOVING_FINISHED())
			return false;
	return true;
}

void SYS_CONTROL::INIT_CONTRLS()
{
	for (size_type i=0;i<ctrls.size();i++)
		ctrls[i].NEW_TIME();
}

void SYS_CONTROL::INIT_UPDATE_ARCS()
{
	map1.UPDATE_ROAD_ARC();
}

void SYS_CONTROL::INIT_LOCK_JUDGE()
{
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		lock_judge.push_back(ctrls.size());
	}
}

void SYS_CONTROL::RELIEVE_LOCK_JUDGE()
{
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		lock_judge[i] = ctrls.size();
	}
}

void SYS_CONTROL::INIT_SYS_CONTROL(const vec_cross& cross,const vec_road& roads,const vec_car& cars)
{
	time = 0;
	gar_car_num = cars.size();
	map1.CREATE_MAP(cross, roads, cars);
	for (size_t i = 0; i < cross.size(); i++)
	{
		ctrls.push_back(TRAFFIC_CONTROLLER(cross[i]->cross_id, map1,filename));
		map_id.insert(std::pair<string, size_type>(cross[i]->cross_id, i));
		garage_blocked.push_back(false);
	}
	for (size_type i = 0; i < gar_car_num; i++)
	{
		iterator ite = map_num.find(cars[i]->to_id);
		if (ite == map_num.end())
			map_num.insert(std::pair<string, size_type>(cars[i]->to_id, 1));
		else
			(*ite).second++;
	}
	INIT_LOCK_JUDGE();
}

bool SYS_CONTROL::IS_ALL_CAR_TERMINATE()
{
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		size_type temp = ctrls[i].GET_TERMINATE_CAR();
		std::cout << temp << std::endl;
		if(temp != map_num[ctrls[i].GET_TRAFFIC_CONTROLLER_ID()])
		//if (ctrls[i].GET_TERMINATE_CAR() != map_num[ctrls[i].GET_TRAFFIC_CONTROLLER_ID()])
			return false;
	}
	return true;
}

size_t SYS_CONTROL::TERMINATE_CAR_NUM()
{
	size_type sum = 0;
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		sum += ctrls[i].GET_TERMINATE_CAR();
	}
	return sum;
}

bool SYS_CONTROL::IS_ALL_GARAGE_BLOCKED()
{
	for (size_type i = 0; i < garage_blocked.size(); i++)
		if (!garage_blocked[i])
			return false;
	return true;
}

void SYS_CONTROL::REFRESH_GARAGE_BLOCK()
{
	for (size_type i = 0; i < garage_blocked.size(); i++)
		garage_blocked[i] = false;
}

/*void SYS_CONTROL::HANDLE_BLOCKED_CAR()
{
	vec_car blocked_car;
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		if (!ctrls[i].blocked_car)
			continue;
		blocked_car.push_back(ctrls[i].blocked_car);
		ctrls[i].blocked_car = NULL;
	}
	if (blocked_car.empty())
		return;
	else {
		for (size_type i = 0; i < blocked_car.size(); i++)
		{
			//blocked_car[i]->time = idea_time + blocked_car[i]->time;
			blocked_car[i]->time = time + 5;
			map1.INSERT_GARAGE_CAR(blocked_car[i]);
		}
		car_num = car_num - blocked_car.size();
	}
	return;
}*/

bool SYS_CONTROL::SEARCH_FOR_LOCK(size_type index)
{
	if (lock_judge[index] == ctrls.size())
		return false;
	vec_bool check;
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		check.push_back(false);
	}
	check[index] = true;
	size_type index_temp = index;
	while (lock_judge[index_temp] != ctrls.size())
	{
		index_temp = lock_judge[index_temp];
		if (check[index_temp] && index_temp != index)
			return false;
		check[index_temp] = true;
		if (index_temp == index)
			return true;
	}
	return false;
}

std::vector<size_t> SYS_CONTROL::IS_LOCK_EXIST()
{
	std::vector<size_type> res;
	//size_type res=ctrls.size();
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		if (!ctrls[i].lock_arc)
			continue;
		else {
			size_type target = map_id[(ctrls[i].lock_arc)->to_cross_id];
			std::cout << i<<" "<<target<< std::endl;
			ctrls[i].lock_arc = NULL;
			lock_judge[i] = target;
			///if (lock_judge[target][i])
			//{
			//	res.push_back(i);
			//}
		}
	}
	for (size_type i = 0; i < ctrls.size(); i++)
	{
		if (SEARCH_FOR_LOCK(i))
			res.push_back(i);
	}

	RELIEVE_LOCK_JUDGE();
	/*if (res.empty())
		return ctrls.size();
	else {
		size_type index = rand() % (res.size());
		return res[index];
	}*/
	return res;
}

void SYS_CONTROL::HANDLE_LOCKED_ARC()
{
	std::vector<size_type> locked_node = IS_LOCK_EXIST();
	if (locked_node.empty())
		return;
	for (size_type i = 0; i < locked_node.size(); i++)
	{
		if (ctrls[locked_node[i]].BREAK_LOCK())
			return;
	}
	ctrls[locked_node[0]].HANDLE_BLOCKED_CAR();
}

void SYS_CONTROL::NEW_TRAN()
{
	time++;
	INIT_UPDATE_ARCS();
	INIT_CONTRLS();
	while (!IS_MOVING_CAR_FINISHED())
	{
		std::cout << "TRAN MOVING..." << std::endl;
		for (size_type i = 0; i<ctrls.size(); i++)
			ctrls[i].TRAN_ONE_REV();
		HANDLE_LOCKED_ARC();
		//HANDLE_BLOCKED_CAR();
	}
	cur_car_num = car_num - TERMINATE_CAR_NUM();
	std::cout << gar_car_num << " " << car_num << " " << cur_car_num << " " << TERMINATE_CAR_NUM() << std::endl;
	size_type i = 0;
	while (cur_car_num < car_num_limit && car_num<gar_car_num)
	{
		bool temp = ctrls[i % (ctrls.size())].TRAN_ONE_GARAGE_CAR();
		//std::cout <<"CROSS ID:"<< ctrls[i % (ctrls.size())].GET_TRAFFIC_CONTROLLER_ID()<<" "<< temp << std::endl;
		if(temp)
		{
			car_num++;
			cur_car_num++;
		}
		garage_blocked[i % (ctrls.size())] = !temp;
		if (IS_ALL_GARAGE_BLOCKED())
		{
			REFRESH_GARAGE_BLOCK();
			std::cout << "all blocked..." << std::endl;
			break;
		}
		i++;
	}
	/*for (size_type i = 0; i < ctrls.size(); i++)
	{
		ctrls[i].TRAN_GARAGE_CAR();
	}*/
}

void SYS_CONTROL::TRAN()
{
	std::ofstream writer(filename);
	if (!writer)
		exit(1);
	writer << "#(carId,StartTime,RoadId...)" << std::endl;
	writer.close();
	while (!IS_ALL_CAR_TERMINATE())
	{
		std::cout << "new_tran..." << std::endl;
		NEW_TRAN();
	}
}