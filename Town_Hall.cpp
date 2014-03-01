#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Town_Hall.h"
using namespace std;


	//Member Functions	
	void Town_Hall::deposit_gold(double deposit_amount)//deposits gold to Town Hall
	{
		amount=amount+deposit_amount;
	}
		
	bool Town_Hall::update()
	{
		if (amount>=50 && state!='u')
		{	
			state='u';
			display_code='T';
			cout<<display_code<<get_id()<<" has been upgraded."<<endl; 
			return true;
		}
		else
		{
			return false;
		}
	
	}
	void Town_Hall::show_status()//prints status of Town_Hall shows whether upgraded or not
	{
		cout<<"Town_Hall status: ";
		Game_Object::show_status();
		cout<<"   contains "<<amount<<" of gold.";
		if(state=='u')
		cout<<"   Upgraded."<<endl;
		else
		{cout<<"   Not yet upgraded."<<endl;}
	}
	
	//Constructors
	Town_Hall::Town_Hall(): Game_Object('t')//default constuctor
	{
		state='o';
		amount=0;
		cout<<"Town_Hall default constructed."<<endl;
	}
	
	Town_Hall::Town_Hall(int in_id, Cart_Point in_loc): Game_Object('t', in_id, in_loc)
	{
		state='o';
		amount=0;
		cout<<"   Town_Hall constructed."<<endl;
	}
	Town_Hall::~Town_Hall()
	{
		cout<<"   Town_Hall destructed."<<endl;
	}


