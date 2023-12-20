#pragma once
#include"Person.h"
#include"SocialRole.h"

class Guest : public Person
{
	int required_days_of_stay;
	SocialRole role;

public:

	Guest(int bucks_in_wallet, int required_days_of_stay, std::string name, const SocialRole& role);

	int GetRequiredDaysOfStay();
	SocialRole GetSocialRole();

	void PaymentForServices(int price);
};

