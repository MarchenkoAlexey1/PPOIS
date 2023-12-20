#include "Reception.h"

void Reception::SetMoneyInTheCashRegister(int money)
{
	money_in_the_cash_register = money;
}

void Reception::SetNumberOfCleaningsForSalary(int number)
{
	number_of_cleanings_for_salary = number;
}

int Reception::GetMoneyInTheCashRegister()
{
	return money_in_the_cash_register;
}

int Reception::CalculatePricePerDay(Guest& guest)
{
	int price = guest.GetBucksInWallet() / guest.GetRequiredDaysOfStay();
	return price;
}

int Reception::CalculateTotalPrice(Guest& guest)
{
	int price_per_day = CalculatePricePerDay(guest);
	int floor_num = 0, total = 0;
	for (int i = 0; i < 10; i++) {
		if (price_per_day >= i * 100 + 20) {
			floor_num = i;
			total = i * 100 + 20;
		}
	}
	if (price_per_day >= floor_num * 100 + 40) total = floor_num * 100 + 40;
	if (price_per_day >= floor_num * 100 + 90) total = floor_num * 100 + 90;
	return total;
}

void Reception::ReceivingAProfit(int profit)
{
	money_in_the_cash_register += profit;
}

void Reception::FormingCheckinVoucher(Guest& guest, int floor_address, int room_address)
{
	int total = CalculateTotalPrice(guest) * guest.GetRequiredDaysOfStay();
	CheckInVoucher check_in_voucher(guest.GetName(), floor_address, room_address, guest.GetRequiredDaysOfStay(), total);
	check_in_voucher.UseOfCheckInVoucher(guest);
	this->check_in_voucher.push_back(check_in_voucher);
	ReceivingAProfit(total);
}

void Reception::CleanersSalaries(Cleaner& cleaner)
{
	if (number_of_cleanings_for_salary <= cleaner.GetNumberOfRoomsCleaned()) {
		money_in_the_cash_register -= 50;
		cleaner.ReceivingASalary(number_of_cleanings_for_salary);
	}
}
