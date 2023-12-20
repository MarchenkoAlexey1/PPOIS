#pragma once
#include<vector>

#include"Room.h"

class Floor
{
	int floor_number;

public:

	std::vector<Room> rooms;

	Floor(int floor_number);
};

