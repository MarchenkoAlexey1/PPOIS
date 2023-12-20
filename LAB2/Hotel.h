#pragma once
#include<vector>
#include<string>

#include"Floor.h"
#include"Reception.h"

class Hotel
{
	int number_of_stars;

public:

	Reception reception;
	std::vector<Floor> floors;

	Hotel(int number_of_stars);

	int GetRoomPrice(int num_floor, int num_room);

	int CalculateCheckInFloor(int total);
	int CalculateCheckInRoom(int total);
	void CheckInHotel(Guest& guest);
	void HotelEviction(Guest& guest);
	bool HousekeepingOrder(Guest& guest, Cleaner& cleaner);
};

