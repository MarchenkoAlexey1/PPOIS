#pragma once
#include<iostream>

#include"Guest.h"

class CheckInVoucher
{
	std::string GuestName;
	int floor_address;
	int room_address;
	int number_live_days;
	int total_price;
public:

	CheckInVoucher(const std::string& GuestName, int floor_address, int room_address, int number_live_days, int total_price);

	std::string GetGuestName();
	int GetTotalPrice();
	int GetFloorAddress();
	int GetRoomAddress();

	int CalculatPricePerDay();
	void UseOfCheckInVoucher(Guest& guest);
};

