#pragma once
#include <iostream>
#include <string>
#include <list>
#include <map>

enum Element {
	None,
	Physical,
	Fire,
	Healing
};

const std::string ElementString[5]{
	"None",
	"Physical",
	"Fire",
	"Healing"
};

//enum Ailment {
//	None,
//	Poison,
//	Paralysis
//};
//
//enum Attribute {
//	Attack,
//	Defense,
//	Speed,
//};

//add Skill
//Spell
//Arts

//add attribute effect

//add ailment afliction

class Spell
{
public:
	std::string name;
	Element element;
	float potency;

	virtual void Cast();
	virtual void CastUnique();

	void PrintInfo();

	Spell(std::string _name, Element _element, float _potency) : name(_name), element(_element), potency(_potency) {};
};

