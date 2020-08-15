#include "stdafx.h"
#include "class_def.h"
#include "function.h"
#include <iostream>

void ROAD_ARC_UPDATE::CREATE_ROAD_ARC(short len, short width, short ve)
{
	road_len = len;
	path_num = width;
	road_velocity = ve;
	car_stream = new MOVING_CAR_PTR*[path_num];
	for (short i = 0; i < path_num; i++)
	{
		car_stream[i] = new MOVING_CAR_PTR[road_len];
	}
	for (short i = 0; i < path_num; i++)
		for (short j = 0; j < road_len; j++)
			car_stream[i][j] = NULL;
	for (short i = 0; i < path_num; i++)
	{
		tail_index.push_back(-1);
		is_ready.push_back(true);
	}
	return;
}

void ROAD_ARC_UPDATE::UPDATE_PATH(short path)
{
	short pre_finished = -1;
	short pre_waiting = -1;
	for (short i = 0; i <road_len; i++)
	{
		if (car_stream[path][i] == NULL)
			continue;
		else if (car_stream[path][i]->carstate == TRAN_STATE::WAITING)
		{
			short step = min(road_velocity, car_stream[path][i]->carinfo->top_speed);
			if (pre_finished > -1)
			{
				short step1 = min(i - pre_finished - 1, step);
				MOVE_CAR(path, i, step1);
				pre_finished = i - step1;
			}
			else {
				if ((i - pre_waiting - 1) >= step)
				{
					MOVE_CAR(path, i, step);
					pre_finished = i - step;
				}
				else
					pre_waiting = i;
			}
		}
		else
		{
			pre_finished = i;
		}
	}
	tail_index[path] = (pre_finished > -1) ? pre_finished : pre_waiting;
	if (tail_index[path] > -1 && pre_finished == -1)
		is_ready[path] = false;
	else
		is_ready[path] = true;
}

void ROAD_ARC_UPDATE::INIT_ALL_PATH()
{
	for (short i = 0; i < path_num; i++)
	{
		is_ready[i] = true;
		for (short j = 0; j <= tail_index[i]; j++)
		{
			if (car_stream[i][j])
			{
				car_stream[i][j]->carstate = TRAN_STATE::WAITING;
				car_waiting_num++;
				is_ready[i] = false;
			}	
		}
	}
	for (short i = 0; i < path_num; i++)
	{
		UPDATE_PATH(i);
	}
	path_prior = -1;
	seq_prior = -1;
}

void ROAD_ARC_UPDATE::INSERT_CAR(MOVING_CAR_PTR newcar, short path, short step)
{
	short seq = road_len - step;
	car_stream[path][seq] = newcar;
	tail_index[path] = seq;
	car_num++;
	return;
}

void ROAD_ARC_UPDATE::MOVE_CAR(short path, short seq, short step_forward)
{
	MOVING_CAR_PTR temp = car_stream[path][seq];
	temp->carstate = TRAN_STATE::FINISHED;
	car_stream[path][seq - step_forward] = temp;
	car_stream[path][seq] = NULL;
	car_waiting_num--;
}

void ROAD_ARC_UPDATE::DELETE_CAR(short path, short seq)
{
	MOVING_CAR_PTR temp = car_stream[path][seq];
	temp->carstate = TRAN_STATE::FINISHED;
	car_stream[path][seq] = NULL;
	car_num--;
	car_waiting_num--;
	UPDATE_PATH(path);
}

void ROAD_ARC_UPDATE::DELETE_PRIOR_CAR()
{
	DELETE_CAR(path_prior, seq_prior);
	path_prior = -1;
	seq_prior = -1;
}

void ROAD_ARC_UPDATE::MOVE_PRIOR_TO_FRONT()
{
	MOVE_CAR(path_prior, seq_prior, seq_prior);
	UPDATE_PATH(path_prior);
	path_prior = -1;
	seq_prior = -1;
}

void ROAD_ARC_UPDATE::CUR_PRIOR(short& path, short& seq)
{
	path = path_prior;
	seq = seq_prior;
}

MOVING_CAR_PTR ROAD_ARC_UPDATE::FIND_PRIOR_CAR()
{
	if (IS_ALL_FINISHED())
		return NULL;
	for (short i = 0; i < road_len; i++)
	{
		for (short j = 0; j < path_num; j++)
		{
			if (car_stream[j][i] && car_stream[j][i]->carstate == TRAN_STATE::WAITING)
			{
				seq_prior = i;
				path_prior = j;
				return car_stream[j][i];
			}
		}
	}
	return NULL;
}

bool ROAD_ARC_UPDATE::IS_ALL_FINISHED()
{
	return car_waiting_num == 0;
}

void ROAD_ARC_UPDATE::FIND_AVAILABLE_SEAT(short& path, short& step, short& ve)
{
	short path_index = 0;
	while (path_index<path_num && is_ready[path_index])
	{
		if (tail_index[path_index] >= road_len-1)
			path_index++;
		else
		{
			path = path_index;
			step = road_len-1-tail_index[path_index];
			ve = road_velocity;
			return;
		}
	}
	path = -1;
	step = -1;
	ve = -1;
	return;
}

double ROAD_ARC_UPDATE::WEIGHTED_ROAD_LEN()
{
	return road_len - speed_fac*road_velocity + car_num_fac*(car_num / (road_len*path_num));
}

bool ROAD_ARC_UPDATE::IS_BLOCKED()
{
	for (size_type i = 0; i < path_num; i++)
	{
		if (!is_ready[i] || tail_index[i] < (road_len - 1))
			return false;
	}
	return true;
}

void ROAD_ARC_UPDATE::ROAD_ARC_UPDATE_CHECK()
{
	std::cout << "ROAD CHECKING..." << std::endl;
	for (short i = 0; i < path_num; i++)
	{
		std::cout << tail_index[i] << std::endl;
		for (short j = 0; j <= tail_index[i]; j++)
		{
			if (car_stream[i][j])
			{
				std::cout << "PATH: " << i << " SEQ:" << j << " CAR_SPEED:" << car_stream[i][j]->carinfo->top_speed << " CAR_ID:"
					<< car_stream[i][j]->carinfo->car_id << " CAR_START:" << car_stream[i][j]->carinfo->from_id
					<< " CAR_DES:" << car_stream[i][j]->carinfo->to_id 
					<< " CAR_DIR:" << car_stream[i][j]->cardir
					<< " CAR_STATE:" << car_stream[i][j]->carstate
					<< std::endl;
			}
		}
	}
}

ROAD_ARC_UPDATE::~ROAD_ARC_UPDATE()
{
	for (short i = 0; i < path_num; i++)
	{
		delete[] car_stream[i];
	}
	delete[] car_stream;
}