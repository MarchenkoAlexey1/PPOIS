#pragma once

#include "RoomType.h"

class Room
{
	int room_number;
	int room_rate;
	RoomType type;
	int number_of_residents;

public:

	Room(int room_number, const RoomType& type, int num_floor);

	int GetRoomRate();
	int GetNumberOfResidents();

	void AddResidents();
	void ResidentsEvication();
};

