#include "ContainerDemo.h"

void ContainerDemo::DoDemo()
{
	std::cout << "This is the container demo\n";
	std::cin.get();
	ArrayDemo();
}

void ContainerDemo::ArrayDemo()
{
	std::cout << "<=====Array Demo====>\n\n";

	Game myGames[5];
	
	myGames[0].name = "coocoo papa";

	myGames[1].name = "coocoo papa 2: return of alex";

	myGames[2].name = "coocoo papa 3: tales from arncliffe";

	int i = 0;
	for (Game g : myGames) {
		std::cout << "Game at " << i << " = " << g.name << "\n";
			i++;
	}
}
