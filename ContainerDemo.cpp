#include "ContainerDemo.h"

using namespace std;

void ContainerDemo::DoDemo()
{
//std::cout << "This is the container demo\n";
//std::cin.get();
//ArrayDemo();

	Buddy myBuddy("Alex", 50, 20, 30, 40);
	std::list<Buddy> myBuddies;

	myBuddies.push_back(Buddy("Brendan", 50, 50, 20, 40));
	myBuddies.push_back(Buddy("lex", 75, 47, 30, 43));
	myBuddies.push_back(Buddy("Billy", 154, 200, 37, 35));
	myBuddies.push_back(Buddy("Alex", 67, 120, 47, 27));

	PrintControls(myBuddies);
}

void ContainerDemo::RenderBuddyList(SDL_Renderer* renderer)
{
	for (Buddy& currentBuddy : myBuddies) {
		currentBuddy.Render(renderer);
	}
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





#pragma region Buddy Stuff

void ContainerDemo::PrintBuddyData(Buddy& targetBuddy) {
	std::cout << targetBuddy.name << "Data: \n";
	std::cout << "	X = " << targetBuddy.rect.x << "\n";
	std::cout << "	Y = " << targetBuddy.rect.y << "\n";
	std::cout << "	Width = " << targetBuddy.rect.w << "\n";
	std::cout << "	Height = " << targetBuddy.rect.h << "\n";
	std::cout << "<================>\n\n";
}


//interface
void ContainerDemo::PrintControls(std::list<Buddy>& buddyList) {
	std::cout << "Controls: \n";
	std::cout << "	0 = Show Controls\n";
	std::cout << "	1 = View Buddies\n";
	std::cout << "	2 = Create New Buddy\n";
	std::cout << "	3 = Kill a Buddy\n";
	std::cout << "	4 = Clear Buddies\n";
	std::cout << "	5 = Sort Buddies\n";
	string str = "bbs";
	if (str.compare("aeb")) {
		std::cout << "true\n";
	}
	else {
		cout << "false \n";
	}
	InputControls(buddyList);
}

//input
void ContainerDemo::InputControls(std::list<Buddy>& buddyList)
{
	int input;
	std::cout << "\n What will you do? ";
	std::cin >> input;

	switch (input) {
	case 0:
		std::cout << "\n";
		PrintControls(buddyList);
		break;
	case 1:
		std::cout << "\n";
		PrintBuddies(buddyList);
		break;
	case 2:
		std::cout << "\n";
		CreateBuddy(buddyList);
		break;
	case 3:
		std::cout << "\n";
		KillBuddy(buddyList);
		break;
	case 4:
		std::cout << "\n";
		ClearBuddies(buddyList);
		break;
	case 5:
		std::cout << "\n";
		SortBuddies(buddyList);
		break;
	}
}

void ContainerDemo::PrintBuddies(std::list<Buddy>& buddyList) {

	std::cout << "---------<View Buddies>---------\n\n";

	if (buddyList.size() <= 0) {
		std::cout << "You have no buddies :(";
		std::cout << "\n\n--------------------------------\n\n";

		InputControls(buddyList);
		return;
	}
	
	std::cout << "| ";
	for (Buddy currentBuddy : buddyList) {
		std::cout << currentBuddy.name << " | ";
	}

	std::cout << "\n\n--------------------------------\n\n";

	InputControls(buddyList);
}

void ContainerDemo::CreateBuddy(std::list<Buddy>& buddyList)
{
	std::cout << "--------<Create Buddies>--------\n\n";

	std::string iName;
	std::cout << "Give your buddy a name: ";
	std::cin >> iName;

	float width;
	std::cout << "How wide is " << iName << "?";
	std::cin >> width;

	float height;
	std::cout << "How high is " << iName << "?";
	std::cin >> height;

	std::string confirm;
	std::cout << "Say 'Hi' to " << iName;
	std::cin >> confirm;

	if (confirm == "Hi") {

		std::cout << "\n" << iName << "Has been created :)\n";
		buddyList.push_back(Buddy(iName, 0, 0, width, height));

	}
	else {

		std::cout << "\n" << iName << " declined to exist :(\n";

	}

	std::cout << "\n--------------------------------\n\n";

	InputControls(buddyList);
}

void ContainerDemo::KillBuddy(std::list<Buddy>& buddyList)
{
	std::cout << "---------<Kill a Buddy>---------\n\n";

	std::cout << "Enter the name of the Buddy you want to kill. \n";

	std::cout << "Buddy Name: ";
	std::string searchName;
	std::cin >> searchName;
	std::cout << "\n";

	std::list<Buddy>::iterator itBud = buddyList.begin();
	bool buddyFound = false;

	for (std::list<Buddy>::iterator itBud = buddyList.begin(); (itBud != buddyList.end()); itBud++) {
		if (itBud->name == searchName) {
			buddyFound = true;
			std::cout << "Say 'Goodbye' to " << searchName << "\n";
			std::string goodbyeInput;
			std::cin >> goodbyeInput;

			if (goodbyeInput == "Goodbye") { //confirmation

				buddyList.erase(itBud);
				std::cout << searchName << " has been killed :(\n";

			}
			else { //cancelation

				std::cout << searchName << " will be staying for a bit longer\n";

			}
			break;
		}
	}

	if (!buddyFound) {
		std::cout << "You have no buddy named " << searchName << "\n";
	}

	std::cout << "\n--------------------------------\n\n";

	InputControls(buddyList);
}

void ContainerDemo::ClearBuddies(std::list<Buddy>& buddyList)
{
	std::cout << "---------<Clear all buddies>------\n\n";

	std::cout << "Say 'Goodbye' to all your buddies...\n";

	std::string textInput;
	std::cin >> textInput;

	if (textInput != "Goodbye") {
		std::cout << "It seems they will stay a little while longer.\n";
	}
	else {
		int i = 1;
		for (Buddy currentBuddy : buddyList) {
			if (i != buddyList.size()) {
				std::cout << currentBuddy.name << ", ";
			}
			else {
				std::cout << "and " << currentBuddy.name << " have left...\n";
			}
			i++;
		}
		buddyList.clear();
	}

	std::cout << "\n--------------------------------\n\n";

	InputControls(buddyList);
}

void ContainerDemo::SortBuddies(std::list<Buddy>& buddyList)
{
	
	std::cout << "-----------<Sort Buddies>---------\n\n";

	std::cout << "Buddies have been sorted alphabetically:\n";

	buddyList.sort();
	std::cout << "| ";
	for (Buddy currentBuddy : buddyList) {
		std::cout << currentBuddy.name << " | ";
	}


	std::cout << "\n--------------------------------\n\n";

	InputControls(buddyList);
}





#pragma endregion 