#include "Cleaner.h"

Cleaner::Cleaner(std::string name, int cleaning_cost) : cleaning_cost(cleaning_cost)
{
	this->bucks_in_wallet = 0;
	this->name = name;
	this->number_of_rooms_cleaned = 0;
}

int Cleaner::GetCleaningCost()
{
	return cleaning_cost;
}

int Cleaner::GetNumberOfRoomsCleaned()
{
	return number_of_rooms_cleaned;
}

void Cleaner::GetATipForCleaning(int tip)
{
	bucks_in_wallet += tip;
}

void Cleaner::RoomCleaning(int floor_address, int room_address)
{
	number_of_rooms_cleaned++;
}

void Cleaner::ReceivingASalary(int number_of_cleanings_for_salary)
{
	this->number_of_rooms_cleaned -= number_of_cleanings_for_salary;
	bucks_in_wallet += 50;
}
