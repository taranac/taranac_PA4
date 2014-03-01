#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>
#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
using namespace std;

class Soldier: public Person
{
	//Private members
	private:
		int attack_strength;
		double range;
		Person *target;
		
	//Public members
	public:
		Soldier();
		Soldier(int, Cart_Point);
		void start_attack(Person * in_target);
		bool update();
		void show_status();
};

#endif
