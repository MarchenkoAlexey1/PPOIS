#pragma once
#include<string>

class Person
{
protected:

	int bucks_in_wallet;
	std::string name;
	
public:

	int GetBucksInWallet();
	std::string GetName();
};

