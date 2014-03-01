#include <iostream>
#include "Game_Object.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <math.h>
using namespace std;


//Person constructors
Person::Person()
{
	speed=5;
	destination=Cart_Point();
	delta=Cart_Vector();
	health=5;
	cout<<"Person default constructed."<<endl;
	
}

Person::Person(char in_code):Game_Object(in_code)
{
	speed=5;
	health=5;
	destination=Cart_Point();
	delta=Cart_Vector();
	cout<<"   Person constructed."<<endl;
}

Person::Person(char in_code,int in_id, Cart_Point in_loc): Game_Object(in_code, in_id, in_loc)
{
	speed=5;
	health=5;
	destination=Cart_Point();
	delta=Cart_Vector();
	cout<<"   Person constructed."<<endl;
}
//DESTRUCTOR
Person::~Person()
{
	cout<<"   Person destructed."<<endl;
}

//PUBLIC member functions

void Person::start_moving(Cart_Point dest)
{	
	if(is_alive())
	{
	
		setup_destination(dest);
		state='m';//moving
		cout<<"Moving "<<get_id()<<" to "<<destination<<" ."<<endl; 
		cout<<display_code<<get_id()<<": On my way."<<endl; 
	
	}
	
	else if(!is_alive())
	{
//		setup_destination(dest);
//		state='m';//moving
//		cout<<"Moving "<<get_id()<<" to "<<destination<<" ."<<endl; 
//		cout<<display_code<<get_id()<<": On my way."<<endl; 
		cout<<display_code<<get_id()<<": I am dead. I may move but you just cannot see me."<<endl;
	}
}

void Person::stop()
{
	state='s'; 
	cout<<"     Stopping "<<get_id()<<"."<<endl;
	cout<<display_code<<get_id()<<": All right."<<endl;
}	

void Person::show_status()
{
		Game_Object::show_status();
		switch(state)
		{
			case 's'://stopped
				if(is_alive())
				{
					cout<<" moving at speed of "<<speed<<" towards "<<destination<<" at each step of "<<delta<<"."<<endl;
					cout<<"   Stopped."<<endl;
				}
				
				break;
			case 'm'://moving to a destination
				if(is_alive())
				{
					cout<<"   moving at speed "<<speed<<" to "<<destination<<" at each step of  "<<delta<<"."<<endl;
				}
				else if(is_alive()==0)
				{
				cout<<"   moving at speed "<<speed<<" to "<<destination<<endl<<" at each step of "<<delta<<" is dead."<<endl;
					
				}
			case 'x':
				cout<<"   moving at speed "<<speed<<" to "<<destination<<endl<<" at each step of "<<delta<<" is dead."<<endl;	
				break;
		}
}
//PROTECTED member functions	
bool Person::update_location()
	{	
		if(fabs((destination-location).x)<=fabs(delta.x) && fabs((destination-location).y)<=fabs(delta.y))
		{
			location=destination;
			cout<<display_code<<get_id()<<": I'm there!"<<endl; 
			return true;
		}
		else
		{
			location=location+delta;
			cout<<display_code<<get_id()<<": step..."<<endl; 
			return false;		
		}
	}

void Person::setup_destination(Cart_Point dest)
	{
		destination=dest; 
		delta=(destination-location)*(speed/(cart_distance(destination,location)));	
	}
	
//Public member functions	
void Person::start_mining()
{
	if(is_alive())
	{
		cout<<display_code<<get_id()<<": Sorry I can't work a mine."<<endl;
	}
	if(is_alive()==0)
	{
		cout<<display_code<<get_id()<<": Sorry I can't work a mine. I'm also dead."<<endl;
	}
}

bool Person::is_alive()
{
	if (state=='x')
	{
		return false;
	}
	if (state!='x')
	{
		return true;
	}
}	

void Person::take_hit(int attack_strength)
{
	health=health-attack_strength;
	if(health<=0)
	{
		cout<<display_code<<get_id()<<": Ahhhhh, I am dying!"<<endl;
		state='x';
	}
	else if(health>0)
	{
		cout<<display_code<<get_id()<<": Ouch!"<<endl;
	}
}	

void Person::start_attack(Person *target)
{
	if(is_alive())
	{
		cout<<display_code<<get_id()<<": I can't attack."<<endl;
	}
	if(is_alive()==0)
	{
		cout<<display_code<<get_id()<< ": I can't attack. I'm also dead."<<endl;
	}
}
