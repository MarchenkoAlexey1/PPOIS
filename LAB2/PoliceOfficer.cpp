#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(std::string name)
{
	this->name = name;
	this->amount_of_money_confiscated = 0;
}

int PoliceOfficer::GetAmountOfMoneyConfiscated()
{
	return amount_of_money_confiscated;
}

void PoliceOfficer::WithdrawalOfFinances(Guest& guest)
{
	amount_of_money_confiscated += guest.GetBucksInWallet();
	guest.PaymentForServices(guest.GetBucksInWallet());
}

void PoliceOfficer::CheckThePerson(Guest& guest)
{
	switch (guest.GetSocialRole()) {
	case SocialRole::CIVILIAN:
		break;
	case SocialRole::MURDERER:
		list_of_criminals.push_back(guest);
		break;
	case SocialRole::THIEF:
		WithdrawalOfFinances(guest);
		list_of_criminals.push_back(guest);
		break;
	}
}

int PoliceOfficer::CheckingTheHotelForCrime(Hotel& hotel)
{
	int amount_of_crimes = 0;
	for (auto guests : hotel.reception.check_in_voucher) {
		for (auto crimes : list_of_criminals) {
			if (guests.GetGuestName() == crimes.GetName()) {
				amount_of_crimes++;
				hotel.HotelEviction(crimes);
			}
		}
	}
	return amount_of_crimes;
}
