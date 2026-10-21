#include "Spell.h"


using namespace std;



void Spell::Cast() {
	std::cout << "You cast " << name << " of potency " << potency << std::endl;
}

void Spell::CastUnique()
{
	std::cout << "Unset CastUnique";
}


void Spell::PrintInfo()
{
	cout << "<" << name << ">\n";
	cout << "	Element: " << ElementString[Element::Fire] << endl;
	cout << "	Potency: " << potency << endl;
}
