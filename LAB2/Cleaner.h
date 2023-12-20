#pragma once
#include"Person.h"
#include"Reception.h"

class Cleaner : public Person
{
	int number_of_rooms_cleaned;
	int cleaning_cost;

public:

	Cleaner(std::string name, int cleaning_cost);

	int GetCleaningCost();
	int GetNumberOfRoomsCleaned();

	void GetATipForCleaning(int tip);
	void RoomCleaning(int floor_address, int room_address);
	void ReceivingASalary(int number_of_cleanings_for_salary);
};

