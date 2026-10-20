#include "PointerDemo.h"

using namespace std;


void PointerDemo::DemoIterate() {

}

void PointerDemo::DoDemo()
{

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

