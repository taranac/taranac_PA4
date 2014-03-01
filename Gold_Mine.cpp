#include <iostream>
#include "Gold_Mine.h"
#include "Game_Object.h"
#include "Cart_Point.h"
using namespace std;

	//Member Functions	
	bool Gold_Mine::is_empty()
	{
		if(amount==0)
			{return true;}
		else 
			{return false;}	
	}
	
	double Gold_Mine::dig_gold(double amount_to_dig=35.0)
	{
		if(amount>=amount_to_dig)
		{
			amount=amount-amount_to_dig;
			return amount_to_dig;
		}
		else
		{
			double temp=amount;
			amount=0;
			return temp;
			
		}
		
	}
		
	bool Gold_Mine::update()
	{
		if (is_empty() && state!='e' )
		{	
			state='e';
			display_code='g';
			cout<<"Gold_Mine "<<get_id()<<" has been depleted."<<endl;
			return true;
		}
		else
		{
			return false;
		}	
	}
	
	//This function displays status of gold mine
	void Gold_Mine::show_status()
	{
		cout<<"Gold_Mine status: ";
		Game_Object::show_status();
		cout<<" Contains "<<amount<<"."<<endl;	
	}

	//Constructors
	Gold_Mine::Gold_Mine(): Game_Object('G')//default constuctor
	{
		state='f';
		amount=100;
		cout<<"Gold_Mine default contructed."<<endl;
	}
	
	Gold_Mine::Gold_Mine(int in_id, Cart_Point in_loc): Game_Object('G', in_id, in_loc)
	{
		state='f';
		amount=100;
		cout<<"   Gold_Mine constructed."<<endl;
	}
//Destructor
Gold_Mine::~Gold_Mine()
{
	cout<<"   Gold_Mine destructed"<<endl;
}
