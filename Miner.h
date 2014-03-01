#ifndef MINER_H
#define MINER_H
#include <iostream>
#include "Game_Object.h"
#include "Person.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

class Miner: public Person
{
	public:
		bool update();
		void start_mining(Gold_Mine *, Town_Hall*);
		void show_status();
		
	//Constructors	
		Miner();
		Miner(int, Cart_Point);
		
	//Deconstructor
		~Miner();		
	//Private member function	
	private: 
		double amount;		
		Gold_Mine * mine;
		Town_Hall * home;
};

#endif
