#pragma once
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include <SDL3/SDL.h>


class ContainerDemo
{
	struct Game {
		std::string name;
		std::string developer;
	//	int timesPlayed;
	//	float price;
	};

	//Buddy Stuff
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
		
		Buddy(std::string buddyName, float spawnX, float spawnY, float width, float height) : name(buddyName), rect({spawnX, spawnY, width, height}) {
			hsp = 1;
			vsp = 1;
		}

		bool operator<(const Buddy& other) {
			return name < other.name;
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

	//Buddy Functions
	void PrintBuddyData(Buddy& targetBuddy);
	void PrintBuddies(std::list<Buddy>& buddyList);
	void PrintControls(std::list<Buddy>& buddyList);
	void InputControls(std::list<Buddy>& buddyList);
	void CreateBuddy(std::list<Buddy>& buddyList);
	void KillBuddy(std::list<Buddy>& buddyList);
	void ClearBuddies(std::list<Buddy>& buddyList);
	void SortBuddies(std::list<Buddy>& buddyList);
	bool compareBuddyNames(const Buddy& a, const Buddy& b);

public:
	void DoDemo();

private:
	void ArrayDemo();

};

