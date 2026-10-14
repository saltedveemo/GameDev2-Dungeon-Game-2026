#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <SDL3/SDL.h>
#include <Windows.h>



class PointerDemo
{
public:
	void DoDemo();
	void DemoIterate();

	class Buddy {

		public:

			float hsp;
			float vsp;
			SDL_FRect rect;
			std::string name;

			Buddy() {
				rect = { 0, 0, 0, 0 };
				name = "";
				hsp = 0;
				vsp = 0;

			}

			Buddy(std::string buddyName, float spawnX, float spawnY, float width, float height) {
				rect = { spawnX, spawnY, width, height };
				name = buddyName;
				hsp = 1;
				vsp = 1;
			}


			void Bounce() {
			//	this->hsp *= -1;
			}

			void FlipMovement() {
			//	this->hsp *= -1;
			}

		private:

	};
	Buddy myBuddy;
	std::list<Buddy> myBuddies;

	void PrintBuddyData(Buddy& targetBuddy);
	void PrintBuddies(std::list<Buddy>& buddyList);
	void PrintControls(std::list<Buddy>& buddyList);
	void InputControls(std::list<Buddy>& buddyList);
	void CreateBuddy(std::list<Buddy>& buddyList);
	void KillBuddy(std::list<Buddy>& buddyList);
	void CreateFillerBuddy(std::list<Buddy>& buddyList, std::string name);

private:

	void PassByValueDemo(float value);
	void PassByRefDemo(std::string& string);
	void UsePointerDemo(std::string* string);
	void MemLeakDemo();
};

