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
#include "Soldier.h"

using namespace std;

//move command handle
void do_move_command(Model *model, int mID, double x, double y, View *view)
{	
	if(x<=view_maxsize && y<=view_maxsize)
	{
		Cart_Point input(x,y);//will call start_moving to input destination	
	
		if(mID==1||mID==2||mID==3||mID==4)//use get pointer to object then call start_moving only is mID is 1 or 2
		{
			(model->get_Person_ptr(mID)->start_moving(input));
			model->display(view);
		}
		else 
		{
			cout<<"ERROR:Incorrect object ID Please try again: "<<endl;
		}
		
	}
	else 
	{
		cout<<"An object is outside the display.";
	}
}

//	work command handle to mine
void do_work_command(Model *model, int ID1, int ID2, int ID3,View *view) //Check ids of objects accordingly then calls start mining
{			
	if(ID1==1 ||ID1==2 && ID2==1 || ID2==2 && ID3==1)
		{
			//Need to cast a Person to a miner to call the start_mining fucntion of the minor
			Person * m=model->get_Person_ptr(ID1);
			
			static_cast<Miner*>(m)->start_mining((model->get_Gold_Mine_ptr(ID2)),(model->get_Town_Hall_ptr(ID3)));
			model->display(view);
		}
	else if(ID1==3||ID1==4 && ID2==1 || ID2==2  && ID3==1)	
		{
			model->get_Person_ptr(ID1)->start_mining();
			model->display(view);
		}
	else if(ID1!=1||ID1!=2||ID1!=3|| ID1!=4 || ID2!=1||ID2!=2 && ID3!=1)
		{
			cout<<"ERROR:Incorrect object ID Please try again: "<<endl;
		}
			
}
	

void do_stop_command(Model *model, int sID, View *view)//stops miner of choice
{
	if(sID==1||sID==2||sID==3||sID==4)
	{
		(model->get_Person_ptr(sID)->stop());
		model->display(view);
	}
	else if(sID!=1||sID!=2||sID!=3|| sID!=4)
		{
			cout<<"ERROR:Incorrect object ID Please try again: "<<endl;
		}
	
}

void do_go_command(Model *model, View *view)//updates and shows status of every object once
{	
	cout<<"Advancing one tick."<<endl;
	model->update();
	model->show_status();
	model->display(view);
}

void do_run_command(Model *model, View *view)//updates until an update returns true or 5 updates depending on which is first
{		
	int i=0;
	cout<<"Advancing to next event."<<endl;

	while(!model->update() && i<5)
	{
		i=i+1;
	}
	model->show_status();
	model->display(view);
}

void do_attack_command(Model *model, View *view, int ID1, int ID2)
{
	if(ID1==3 ||ID1==4 && ID2==1 || ID2==2|| ID2==3 ||ID2==4)
		{
			
			//Need to cast a Person to a soldier to call the start_attack function of the soldier
			Person * s=model->get_Person_ptr(ID1);
			
			//calling start attack changes state to a which will make target take hit.
			static_cast<Soldier*>(s)->start_attack((model->get_Person_ptr(ID2)));
			model->display(view);
		}
		
	else if(ID1==1|| ID1==2 && ID2==3 ||ID2==4|| ID2==2 ||ID2==1 )	
		{
			model->get_Person_ptr(ID1)->start_attack(model->get_Person_ptr(ID2));
			model->display(view);
		}
	else if (ID1!=1||ID1!=2||ID1!=3 ||ID2!=4 && ID2!=1||ID2!=2||ID2!=3 ||ID2!=4  )
		{
			cout<<"ERROR:Incorrect object ID Please try again: "<<endl;
		}
}
void do_list_command(Model *model, View *view)
{
	model->show_status();
	model->display(view);
}

