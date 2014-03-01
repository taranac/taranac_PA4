#ifndef TOWN_HALL_H
#define TOWN_HALL_H
#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Town_Hall: public Game_Object
{
	public:
	//Member Functions	
	void deposit_gold(double);		
	bool update();
	void show_status();
	
	//Constructors	
	Town_Hall();//default constuctor
	Town_Hall(int , Cart_Point);//user define constructor
	~Town_Hall();//destructor
	
	//Member variables
	private:
	char state;
	double amount;

};

#endif
