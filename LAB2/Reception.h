#pragma once
#include <vector>

#include "Cleaner.h"
#include "CheckInVoucher.h"

class Cleaner;
class Reception
{
	int money_in_the_cash_register;
	int number_of_cleanings_for_salary;

public:
	std::vector<CheckInVoucher> check_in_voucher;

	void SetMoneyInTheCashRegister(int money);
	void SetNumberOfCleaningsForSalary(int number);
	int GetMoneyInTheCashRegister();

	int CalculatePricePerDay(Guest& guest);
	int CalculateTotalPrice(Guest& guest);
	void ReceivingAProfit(int profit);
	void FormingCheckinVoucher(Guest& guest, int floor_address, int room_address);
	void CleanersSalaries(Cleaner& cleaner);
	
};

