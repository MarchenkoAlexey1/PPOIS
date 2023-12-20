#include "CheckInVoucher.h"

CheckInVoucher::CheckInVoucher(const std::string& GuestName, int floor_address, int room_address, int number_live_days, int total_price) : GuestName(GuestName), floor_address(floor_address), room_address(room_address), number_live_days(number_live_days), total_price(total_price)
{
}

std::string CheckInVoucher::GetGuestName()
{
	return GuestName;
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
