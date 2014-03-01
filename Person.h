#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include <math.h>
#include "Cart_Vector.h"

using namespace std;
class Person: public Game_Object
{
	friend class Miner;
	friend class Soldier;
	public:
		//Constructors
		Person();
		Person(char);
		Person(char , int , Cart_Point );
		
		//Destructor
		virtual ~Person();
		
		//Public member functions
		void start_moving(Cart_Point );
		void stop();
		void show_status();
		virtual void start_mining();
		
		virtual bool is_alive();
		void take_hit(int attack_strength);
		virtual void start_attack(Person *target);
		
	protected:
		bool update_location();
		void setup_destination(Cart_Point );		
	
	private:
		double speed;
		Cart_Point destination;
		Cart_Vector delta;
		int health;
};
#endif
