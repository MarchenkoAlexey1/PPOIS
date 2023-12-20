#include "Room.h"

Room::Room(int room_number, const RoomType& type, int num_floor) : room_number(room_number), type(type)
{
	number_of_residents = 0;
	room_rate = 100 * num_floor;
	switch (type) {
	case RoomType::STANDART:
		room_rate += 20;
		break;
	case RoomType::DOUBLE:
		room_rate += 40;
		break;
	case RoomType::SUITE:
		room_rate += 90;
		break;
	}
}

int Room::GetRoomRate()
{
	return room_rate;
}

int Room::GetNumberOfResidents()
{
	return number_of_residents;
}

void Room::AddResidents()
{
	number_of_residents++;
}

void Room::ResidentsEvication()
{
	number_of_residents--;
}
