#pragma once
#include <iostream>

class ContainerDemo
{
	struct Game {
		std::string name;
		std::string developer;
		int timesPlayed;
		float price;
	};

public:
	void DoDemo();

private:
	void ArrayDemo();

};

