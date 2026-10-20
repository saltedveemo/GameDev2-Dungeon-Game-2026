#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <SDL3/SDL.h>




class PointerDemo
{
public:
	void DoDemo();
	void DemoIterate();


private:

	void PassByValueDemo(float value);
	void PassByRefDemo(std::string& string);
	void UsePointerDemo(std::string* string);
	void MemLeakDemo();
};

