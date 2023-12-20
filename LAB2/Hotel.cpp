#include "Hotel.h"

Hotel::Hotel(int number_of_stars) : number_of_stars(number_of_stars)
{
	reception.SetNumberOfCleaningsForSalary(number_of_stars);
	reception.SetMoneyInTheCashRegister(0);
	for (int i = 0; i < 10; i++) {
		Floor floor(i);
		floors.push_back(floor);
	}
}

int Hotel::GetRoomPrice(int num_floor, int num_room)
{
	return floors[num_floor].rooms[num_room].GetRoomRate();
}

int Hotel::CalculateCheckInFloor(int price_per_day)
{
	int floor_num = 0;
		for (int i = 0; i < 10; i++) {
			if (price_per_day >= i * 100 + 20) floor_num = i;
		}
		return floor_num;
}

int Hotel::CalculateCheckInRoom(int price_per_day)
{
	int floor_num = CalculateCheckInFloor(price_per_day);
	int room_num = 0;
	if (price_per_day >= floor_num * 100 + 40) room_num = 1;
	if (price_per_day >= floor_num * 100 + 90) room_num = 2;
	return room_num;
}

void Hotel::CheckInHotel(Guest& guest)
{
	int price_per_day = reception.CalculatePricePerDay(guest);
	int floor_num = CalculateCheckInFloor(price_per_day);
	int room_num = CalculateCheckInRoom(price_per_day);
	floors[floor_num].rooms[room_num].AddResidents();
	reception.FormingCheckinVoucher(guest, floor_num, room_num);
}

void Hotel::HotelEviction(Guest& guest)
{
	int price_per_day = 0;
	for (auto n : reception.check_in_voucher) {
		if (n.GetGuestName() == guest.GetName()) price_per_day = n.CalculatPricePerDay();
	}
	int floor_num = CalculateCheckInFloor(price_per_day);
	int room_num = CalculateCheckInRoom(price_per_day);
	floors[floor_num].rooms[room_num].ResidentsEvication();
	reception.check_in_voucher.pop_back();
}

bool Hotel::HousekeepingOrder(Guest& guest, Cleaner& cleaner)
{
	int floor_address = 0;
	int room_address = 0;
	if (guest.GetBucksInWallet() < cleaner.GetCleaningCost()) return false;
	else guest.PaymentForServices(cleaner.GetCleaningCost());
	for (auto n : reception.check_in_voucher) {
		if (n.GetGuestName() == guest.GetName()) {
			floor_address = n.GetFloorAddress();
			room_address = n.GetRoomAddress();
		}
	}
	cleaner.RoomCleaning(floor_address, room_address);
	cleaner.GetATipForCleaning(cleaner.GetCleaningCost());
	reception.CleanersSalaries(cleaner);
}