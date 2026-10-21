#pragma once
#include <iostream>
#include <string>
#include <list>


class Spell
{
public:
	std::string name;
	std::string element;
	float potency;

	virtual void Cast();
	virtual void CastUnique();

	void Setup(std::string, std::string, float);
};

