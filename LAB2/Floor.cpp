#include "Floor.h"

Floor::Floor(int floor_number) : floor_number(floor_number)
{
	Room room1(0, RoomType::STANDART, floor_number);
	rooms.push_back(room1);
	Room room2(1, RoomType::DOUBLE, floor_number);
	rooms.push_back(room2);
	Room room3(2, RoomType::SUITE, floor_number);
	rooms.push_back(room3);
}
