#pragma once
#include<vector>

#include"Hotel.h"

class PoliceOfficer : public Person
{

	int amount_of_money_confiscated;
	std::vector<Guest> list_of_criminals;

public:

	PoliceOfficer(std::string name);

	int GetAmountOfMoneyConfiscated();

	void WithdrawalOfFinances(Guest& guest);
	void CheckThePerson(Guest& guest);
	int CheckingTheHotelForCrime(Hotel& hotel);
};

