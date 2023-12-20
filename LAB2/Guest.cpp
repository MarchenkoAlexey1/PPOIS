#include "Guest.h"

Guest::Guest(int bucks_in_wallet, int required_days_of_stay, std::string name, const SocialRole& role) : required_days_of_stay(required_days_of_stay), role(role)
{
	this->bucks_in_wallet = bucks_in_wallet;
	this->name = name;
}

int Guest::GetRequiredDaysOfStay()
{
	return required_days_of_stay;
}

SocialRole Guest::GetSocialRole()
{
	return role;
}

void Guest::PaymentForServices(int price)
{
	bucks_in_wallet -= price;
}