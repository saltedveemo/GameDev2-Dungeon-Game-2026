#include "PolyDemo.h"

using namespace std;

void PolyDemo::DoDemo()
{
	cout << "Start of PolyDemo\n";

	Spell spell("Flame Burst", Element::Fire, 10);
	spell.PrintInfo();
}
