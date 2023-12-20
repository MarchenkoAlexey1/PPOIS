#include "pch.h"
#include "CppUnitTest.h"
#include "..\Laba_Hotel\Hotel.h"
#include "..\Laba_Hotel\PoliceOfficer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HotelTests
{
	TEST_CLASS(HotelTests)
	{
	public:
		
		TEST_METHOD(Hotel_Check_In_Test)
		{
			Hotel Continental(1);
			Assert::AreEqual(Continental.GetRoomPrice(0, 0), 20);
			Assert::AreEqual(Continental.CalculateCheckInFloor(440), 4);
			Assert::AreEqual(Continental.CalculateCheckInRoom(440), 1);
			Assert::AreEqual(Continental.GetRoomPrice(4, 1), 440);
			Assert::AreEqual(Continental.GetRoomPrice(6, 2), 690);
			Guest Gustavo(452, 2, "Gustavo", SocialRole::CIVILIAN);
			Assert::AreEqual(Gustavo.GetBucksInWallet(), 452);
			Assert::IsTrue(Gustavo.GetName() == "Gustavo");
			Assert::AreEqual(Continental.reception.CalculateTotalPrice(Gustavo), 220);
			Assert::AreEqual(Continental.floors[2].rooms[0].GetNumberOfResidents(), 0);
			Continental.CheckInHotel(Gustavo);
			Assert::AreEqual(Continental.floors[2].rooms[0].GetNumberOfResidents(), 1);
			Assert::AreEqual(Continental.floors[2].rooms[0].GetRoomRate(), 220);
			Assert::AreEqual(Gustavo.GetBucksInWallet(), 12);
		}

		TEST_METHOD(Reception_Forming_Check_In_Voucher_Test)
		{
			Hotel Continental(3);
			Guest  Bob(895, 3, "Bob", SocialRole::CIVILIAN);
			Continental.CheckInHotel(Bob);
			Assert::AreEqual(Continental.floors[2].rooms[2].GetNumberOfResidents(), 1);
			Assert::AreEqual(Continental.floors[2].rooms[2].GetRoomRate(), 290);
			Assert::AreEqual(Continental.reception.check_in_voucher[0].GetFloorAddress(), 2);
			Assert::AreEqual(Continental.reception.check_in_voucher[0].GetRoomAddress(), 2);
			Assert::IsTrue(Continental.reception.check_in_voucher[0].GetGuestName() == "Bob");
			Assert::AreEqual(Continental.reception.check_in_voucher[0].GetTotalPrice(), 870);
		}

		TEST_METHOD(Cleaner_Test)
		{
			Hotel Continental(1);
			Guest Charlz(286, 1, "Charlz", SocialRole::MURDERER);
			Continental.CheckInHotel(Charlz);
			Cleaner Bob("Bob", 12);
			Assert::AreEqual(Bob.GetBucksInWallet(), 0);
			Assert::AreEqual(Bob.GetNumberOfRoomsCleaned(), 0);
			Assert::IsTrue(Continental.HousekeepingOrder(Charlz, Bob));
			Assert::AreEqual(Bob.GetBucksInWallet(), 62);
		}

		TEST_METHOD(PoliceOfficer_Test)
		{
			Hotel Continental(1);
			Guest Gustavo(80, 2, "Gustavo", SocialRole::CIVILIAN);

			Guest Vyacheslav(9999, 3, "Vyacheslav", SocialRole::THIEF);
			Continental.CheckInHotel(Gustavo);
			Continental.CheckInHotel(Vyacheslav);
			PoliceOfficer Steve("Steve");
			Assert::AreEqual(Steve.GetAmountOfMoneyConfiscated(), 0);
			Steve.CheckThePerson(Gustavo);
			Steve.CheckThePerson(Vyacheslav);
			Assert::AreEqual(Steve.CheckingTheHotelForCrime(Continental), 1);
			Assert::AreEqual(Steve.GetAmountOfMoneyConfiscated(), 7029);
			Guest Charlz(245, 1, "Charlz", SocialRole::MURDERER);
			Steve.CheckThePerson(Charlz);
			Assert::AreEqual(Steve.GetAmountOfMoneyConfiscated(), 7029);
		}

		TEST_METHOD(Hotel_Evacation_Test)
		{
			Hotel Continental(1);
			Guest Gustavo(80, 2, "Gustavo", SocialRole::CIVILIAN);
			Continental.CheckInHotel(Gustavo);
			Assert::AreEqual(Continental.floors[0].rooms[1].GetNumberOfResidents(), 1);
			Continental.HotelEviction(Gustavo);
			Assert::AreEqual(Continental.floors[0].rooms[1].GetNumberOfResidents(), 0);
		}
	};
}
