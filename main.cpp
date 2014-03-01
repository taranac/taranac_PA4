#include <iostream>
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Game_Object.h"
#include "Person.h"
#include "View.h"
#include "Model.h"
#include "Game_Command.h"
#include <string>
using namespace std;

int main()
{
//Intializing objects with given values using Model and creating a view object
Model model;
View view;
model.show_status();
model.display(&view);


// quit=1 while user does not enter q.		
	bool quit=1;
	
	while(quit)
	{
		char command;//[100];
		cout<<endl<<"Enter command: ";
		cin>>command;
	//	cin.getline (command,100);
	
		//error checking!!!! will only enter if correct command
		if(!cin.fail() && (command=='m'|| command=='w'||command=='s'||command=='g'||command=='r'||command=='q'||command=='l'||command=='a'))
		{
			switch(command)
			{
				case 'm':
					int mID;
					double x ,y;
					cin>>mID>>x>>y;
					do_move_command(&model, mID, x,y, &view);
					break;
					
				case 'w':
					int ID1, ID2, ID3 ;
					cin>>ID1>>ID2>>ID3;
					//Pass all by reference to keep current state through Model
					do_work_command(&model, ID1, ID2, ID3, &view);
					break;
					
					case 'a'://new attack command
					int D1, D2;
					cin>>D1>>D2; 
					do_attack_command(&model, &view, D1, D2);
					break;
			
				case 's':
					int sID;
					cin>>sID;
					//Pass all by reference to keep current state by using model
					do_stop_command(&model, sID, &view);
					break;
				case 'g':
				//Pass all by reference to keep current state by using model
					do_go_command(&model, &view);
					break;
					
				case 'r':
				//Pass all by reference to keep current state using model
					do_run_command(&model,&view);
					break;
					
				case 'l':
					do_list_command(&model, &view); //list current status of game objects
					break;
					
				case 'q':
					cout<<"Terminating program"<<endl;
					model.~Model();
					quit=0;

			}		
		}
		while(cin.fail())
		{		
			cin.clear();
			cin.ignore();	
			cout<<endl<<"ERROR: Please enter a valid command!";
			break;
		}
	}
	
	return 0;
}




