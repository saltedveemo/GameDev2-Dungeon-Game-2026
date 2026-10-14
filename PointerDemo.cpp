#include "PointerDemo.h"

using namespace std;


void PointerDemo::DemoIterate() {

}

void PointerDemo::DoDemo()
{
	Buddy myBuddy("Alex", 1, 2, 3, 4);
	std::list<Buddy> myBuddies;

	myBuddies.push_back(Buddy("Alex", 1, 2, 3, 4));
	myBuddies.push_back(Buddy("Brendan", 1, 2, 3, 4));
	myBuddies.push_back(Buddy("Billy", 1, 2, 3, 4));

	PrintControls(myBuddies);
}

void PointerDemo::PassByValueDemo(float value)
{
	string message = "Passed value = " + to_string(value);
	cout << message <<"\n";
	PassByRefDemo(message);
}

void PointerDemo::PassByRefDemo(std::string& string)
{
	cout << "Previous Message = '" << string << "'\n";
	UsePointerDemo(&string);
}

void PointerDemo::UsePointerDemo(std::string* string) {
	cout << "Pointer to previous message = " << string;
	MemLeakDemo();
}

void PointerDemo::MemLeakDemo()
{
	new SDL_FRect();
}




#pragma region Buddy Stuff

void PointerDemo::PrintBuddyData(Buddy &targetBuddy){
	std::cout << targetBuddy.name << "Data: \n";
	std::cout << "	X = " << targetBuddy.rect.x << "\n";
	std::cout << "	Y = " << targetBuddy.rect.y << "\n";
	std::cout << "	Width = " << targetBuddy.rect.w << "\n";
	std::cout << "	Height = " << targetBuddy.rect.h << "\n";
	std::cout << "<================>\n\n";
}


//interface
void PointerDemo::PrintControls(std::list<Buddy>& buddyList) {
	cout << "Controls: \n";
	cout << "	0 = Show Controls\n";
	cout << "	1 = View Buddies\n";
	cout << "	2 = Create New Buddy\n";
	cout << "	3 = Kill a Buddy\n";
	cout << "	9 = Perform Demo\n";

	InputControls(buddyList);
}

void PointerDemo::InputControls(std::list<Buddy>& buddyList)
{
	int input;
	cout << "\n What will you do? ";
	cin >> input;

	switch (input) {
	case 0:
		cout << "\n";
		PrintControls(buddyList);
		break;
	case 1:
		cout << "\n";
		PrintBuddies(buddyList);
		break;
	case 2:
		cout << "\n";
		CreateBuddy(buddyList);
		break;
	case 3:
		cout << "\n";
		KillBuddy(buddyList);
		break;
	case 9:
		cout << "\n";
		PassByValueDemo(67);
		break;
	}
}

void PointerDemo::PrintBuddies(std::list<Buddy> &buddyList){

	cout << "---------<View Buddies>---------\n\n";

	if (buddyList.size() <= 0) {
		cout << "You have no buddies :(";
		cout << "\n\n--------------------------------\n\n";

		InputControls(buddyList);
		return;
	}

	list<Buddy>::iterator itBud = buddyList.begin();
	cout << "You have " << buddyList.size() << " Buddies! \n";
	cout << "| ";
	for (int i = 0; i < buddyList.size(); i++)
	{
		cout << itBud->name << " | ";
		itBud++;
	}

//	for (Buddy currentBuddy : buddyList) {
//		cout << currentBuddy.name << " | ";
//	}

	cout << "\n\n--------------------------------\n\n";

	InputControls(buddyList);
}

void PointerDemo::CreateBuddy(std::list<Buddy>& buddyList)
{
	cout << "--------<Create Buddies>--------\n\n";

	string iName;
	cout << "Give your buddy a name: ";
	cin >> iName;

	float width;
	cout << "How wide is " << iName << "?";
	cin >> width;

	float height;
	cout << "How high is " << iName << "?";
	cin >> height;

	string confirm;
	cout << "Say 'Hi' to " << iName;
	cin >> confirm;

	if (confirm == "Hi") {

		cout << "\n" << iName << "Has been created :)\n";
		buddyList.push_back(Buddy(iName, 0, 0, width, height));

	}
	else {

		cout << "\n" << iName << " declined to exist :(\n";

	}

	cout << "\n--------------------------------\n\n";

	InputControls(buddyList);
}

void PointerDemo::KillBuddy(std::list<Buddy>& buddyList)
{

	cout << "---------<Kill a Buddy>---------\n\n";

	cout << "Enter the name of the Buddy you want to kill. \n";

	cout << "Buddy Name: ";
	string searchName;
	cin >> searchName;
	cout << "\n";

	list<Buddy>::iterator itBud = buddyList.begin();
	bool buddyFound = false;

	for (list<Buddy>::iterator itBud = buddyList.begin(); (itBud != buddyList.end()); itBud++) {
		if (itBud->name == searchName) {
			buddyFound = true;
			cout << "Say 'Goodbye' to " << searchName << "\n";
			string goodbyeInput;
			cin >> goodbyeInput;

			if (goodbyeInput == "Goodbye") { //confirmation

				buddyList.erase(itBud);
				cout << searchName << " has been killed :(\n";

			}
			else { //cancelation

				cout << searchName << " will be staying for a bit longer\n";

			}
			break;
		}
	}

	if (!buddyFound) {
		cout << "You have no buddy named " << searchName << "\n";
	}

	cout << "\n--------------------------------\n\n";

	InputControls(buddyList);
}

void PointerDemo::CreateFillerBuddy(std::list<Buddy>& buddyList, std::string name)
{
	cout << "\n Buddy was created but ran away to somewhere in memory\n";
	new Buddy(name, 0, 0, 0, 0);
	InputControls(buddyList);
}

#pragma endregion 