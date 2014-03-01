#include <iostream>
#include "Soldier.h"
#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
using namespace std;

//Constructor

 Soldier::Soldier():Person('S')
{
	attack_strength=2;
	range=2;
	cout<<"   Soldier default constructed."<<endl;
}

Soldier::Soldier(int in_id, Cart_Point in_loc):Person('S', in_id, in_loc)
{
	attack_strength=2;
	range=2;
	cout<<"   Soldier constructed."<<endl;
}

void Soldier::start_attack(Person * in_target)
{
	//Will attack if Soldier is alive
	if(is_alive())
	{
		double dist=cart_distance(get_location(),(*in_target).get_location());		
		if(dist<=range)
		{
			
			cout<<display_code<<get_id()<<": Attacking."<<endl;
			target=in_target;
			state='a';
				
		} 
		else if(dist>range)
		{
			cout<<"Target is out of range!"<<endl;
		}
	}
	
	else if(is_alive()==0)
	{
		cout<<display_code<<get_id()<<": I am dead. You do not have the ability to summon the undead."<<endl;
	}
	
}

bool Soldier::update()
{
	switch(state){	
			case 'x':
				return false;
				break;	
			case 's'://stopped
				return false;
				break;
			case 'm'://moving
				if(update_location())
					{	
						state='s';
						return true;
						
					}
					else 
					{
						state='m';
						return false;
						
					}
				break;
			case 'a':
				double dist=cart_distance(get_location(),(*target).get_location());
				if(dist<=range)
				{
					if((*target).state=='x')//When target dead
					{
						cout<<display_code<<get_id()<<": I win."<<endl;
						state='s';
						return true;
					}
					if((*target).state!='x')//When target still alive
					{
						cout<<display_code<<get_id()<<": Take that!"<<endl;
						(*target).take_hit(attack_strength);// continue attacking target
						state='a';
						return false;
					}
				}
				else if(dist>range)
				{
					cout<<display_code<<get_id()<<": Target is out of range."<<endl;
					state='s';
					return true;
				}
	}
}

void Soldier::show_status()
{
		cout<<"Soldier status: ";
		Person::show_status();
		switch(state)
		{
			case 'a':
				cout<<display_code<<get_id()<<": Attacking."<<endl;
		}
}

