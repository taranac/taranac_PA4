#include "Game_Object.h"
#include "Person.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Miner.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include <iostream>
//#include <math.h>

using namespace std;


	//Public Member Functions
	bool Miner::update()
	{
		switch(state){		
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
				
			case 'o'://outbound
				if (update_location())
				{
					state='g';
					return true;
					
				}
				else
				{
					state='o';
					return false;
					
				}
				break;
				
			case 'g'://getting gold
				amount=(*mine).dig_gold(35.0);//where to dig
				cout<<display_code<<get_id()<<": Got "<<amount<<" gold."<<endl; 
				setup_destination((*home).get_location());//where to deposit
				state='i';
				return true;
				break;
			
			case 'i'://inbound mining
				if(update_location())
				{
					state='d';
					return true;
						
				}
				else
				{ 
					state='i';
					return false;
				}				
				break;
			
			case 'd':
				cout<<display_code<<get_id()<<": Deposit "<<amount<<" of gold."<<endl; 
				(*home).deposit_gold(amount);//depositing
				amount=0;
				if((*mine).is_empty())
				{
					state='s';
					cout<<display_code<<get_id()<<": More work?"<<endl;
					return true;
				}
				else
				{
					setup_destination((*mine).get_location());
					state='o';
					cout<<display_code<<get_id()<<": Going back for more."<<endl; 
					return true;
				}
				break;
				case 'x':
					state='x';
					return false;
					break;
		}	
	}

	void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
	{
		if(state!='x')
		{
			home=inputHome;
			mine=inputMine;
			setup_destination((*mine).get_location());//starts toward mine
			state='o';
			cout<<"Miner "<<get_id()<<" mining at Gold_Mine "<<(*mine).get_id()<<" and depositing at Town_Hall "<<(*home).get_id()<<"."<<endl; 
			cout<<display_code<<get_id()<<": Yes, my lord."<<endl;
		}
		
		else if(state=='x')
		{
			cout<<display_code<<get_id()<<": I am dead. Are you kidding me? Ask a zombie to work!?!?"<<endl;
		}
	}
	

	void Miner::show_status()
	{
		cout<<"Miner status: ";
		Person::show_status();
		switch(state)
		{
			case 'o'://outbound mining
				cout<<"   Outbound to a mine."<<endl;
				break;
			case 'g'://getting gold
				cout<<"   Getting gold from mine."<<endl;
				break;
			case 'i'://inbound mining
				cout<<"   Inbound to home with load: "<<amount<<endl;
				break;
			case 'd'://depositing gold
				cout<<"   Depositing gold."<<endl;		
				break;
		}
	}
	
	//Constructors
	
	Miner::Miner():Person('M')//default constuctor
	{
		amount=0;
		home=NULL;
		mine=NULL;
		cout<<"   Miner default constructed."<<endl;
		
	}
	
	Miner::Miner(int in_id, Cart_Point in_loc):Person('M', in_id, in_loc) 
	{
		amount=0;
		home=0;
		mine=0;
		cout<<"   Miner constructed."<<endl;
	}
	
	//Destructor
	Miner::~Miner()
	{
		cout<<"   Miner destructed."<<endl;
	}
