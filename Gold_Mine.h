#ifndef GOLD_MINE_H
#define GOLD_MINE_H
#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Gold_Mine: public Game_Object
{
	public:
	//Member Functions
	
	bool is_empty();
	double dig_gold(double);
	bool update();
	void show_status();
	
	//Constructors
	
	Gold_Mine();//default constuctor
	Gold_Mine(int , Cart_Point);
	~Gold_Mine();
	
	
	//Private Member variables	
	private: 	
	double amount;
	
	
};

#endif
