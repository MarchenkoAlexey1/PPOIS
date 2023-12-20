#include "CheckInVoucher.h"

CheckInVoucher::CheckInVoucher(const std::string& guest_name, int floor_address, int room_address, int number_live_days, int total_price) : guest_name(guest_name), floor_address(floor_address), room_address(room_address), number_live_days(number_live_days), total_price(total_price)
{
}

std::string CheckInVoucher::GetGuestName()
{
	return guest_name;
}

int CheckInVoucher::GetTotalPrice()
{
	return total_price;
}

int CheckInVoucher::GetFloorAddress()
{
	return floor_address;
}

int CheckInVoucher::GetRoomAddress()
{
	return room_address;
}

int CheckInVoucher::CalculatPricePerDay()
{
	return total_price / number_live_days;
}

void CheckInVoucher::UseOfCheckInVoucher(Guest& guest)
{
	guest.PaymentForServices(total_price);
}
