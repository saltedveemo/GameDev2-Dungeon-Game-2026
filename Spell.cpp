#include "Spell.h"

void Spell::Cast() {
	std::cout << "You cast " << name << " of potency " << potency << std::endl;
}

void Spell::CastUnique()
{
	std::cout << "Unset CastUnique";
}

void Spell::Setup(std::string _name, std::string _element, float _potency)
{
	name = _name;
	element = _element;
	potency = _potency;
}
