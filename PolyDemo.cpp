#include "PolyDemo.h"

using namespace std;

void PolyDemo::DoDemo()
{
	cout << "Start of PolyDemo\n";

	Spell spell;
	FireSpell fireSpell;

	fireSpell.Setup("Flame Slash", "Fire", 8);
	fireSpell.Cast();
	fireSpell.CastUnique();
}
