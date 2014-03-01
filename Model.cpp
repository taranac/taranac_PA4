#include <iostream>
#include "Game_Object.h"
#include "Model.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "View.h"
#include "Soldier.h"

using namespace std;
//intialize given Cart_Points
//	Cart_Point gP1(1,20);
//	Cart_Point gP2(10,20);
//	Cart_Point mP3(5,1);
//	Cart_Point mP4(10,1);
//	Cart_Point sP1(5,15);
//	Cart_Point sP2(10,15);
//	Cart_Point tP5(0,0);

Model::Model()
{
	time=0;
	//Dynamically creates an object and a pointer to that object
	//put that pointer into respective arrays
	//one pointer to specific object the other to game object	
	 //intialize given Cart_Points
	 
	Cart_Point gP1(1,20);
	Cart_Point gP2(10,20);
	Cart_Point mP3(5,1);
	Cart_Point mP4(10,1);
	Cart_Point sP1(5,15);
	Cart_Point sP2(10,15);
	Cart_Point tP5(0,0);
	
	Miner * m1=new Miner(1,mP3);
	person_ptrs[0]=m1;
	object_ptrs[0]=person_ptrs[0];
	
	Miner *m2= new Miner(2, mP4);
	person_ptrs[1]=m2;
	object_ptrs[1]=person_ptrs[1];
	
	Soldier *s3=new Soldier(3, sP1);
	person_ptrs[2]=s3;
	object_ptrs[5]=person_ptrs[2];
	
	Soldier *s4=new Soldier(4,sP2);
	person_ptrs[3]=s4;
	object_ptrs[6]=person_ptrs[3];
	
	Gold_Mine *g1= new Gold_Mine(1,gP1);
	mine_ptrs[0]=g1;
	object_ptrs[2]= mine_ptrs[0];
	
	Gold_Mine *g2= new Gold_Mine(2,gP2);
	mine_ptrs[1]=g2;
	object_ptrs[3]= mine_ptrs[1];
	
	Town_Hall *t1=new Town_Hall(1,tP5);
	hall_ptrs[0]= t1;	
	object_ptrs[4]=hall_ptrs[0]; 
 
	num_objects=7;
	num_persons=4;
	num_mines=2;
	num_halls=1;
	
	cout<<"   Model default constructed."<<endl;
	
}

Model::~Model()
{
	for(int i=0; i<num_objects; i++)
	{
		delete object_ptrs[i];
	}
	for(int j=0; j<num_persons; j++)
	{
		delete person_ptrs[j];
	}
	for(int k=0; k<num_mines; k++)
	{
		delete mine_ptrs [k];
	}
	for(int n=0; n<num_halls; n++)
	{
		delete hall_ptrs [n];
	}
	cout<<"   Model destructed."<<endl;
}


Person * Model::get_Person_ptr(int id)//Only two ids
{ 
	if(id==1||id==2||id==3||id==4)
	{
		return person_ptrs[id-1];
	}
	else
	{
		return 0;
	}
}

Gold_Mine * Model::get_Gold_Mine_ptr(int id)//Only two ids
{
	if(id==1||id==2)
	{
		
		return mine_ptrs[id-1];
	}
	else
	{
		return 0;
	}
}
	


Town_Hall * Model::get_Town_Hall_ptr(int id)//Only 1 id
{
	if(id==1)
	{
		return hall_ptrs[id-1];
	}
	else
	{
		return 0;
	}
}

bool Model::update()
{
	bool noUpdate=1;
	bool myUpdate=0;
	
	while(noUpdate)//while there is no update will loop 
	{
		if (object_ptrs[0]->update())
		{
			noUpdate=0;
			myUpdate=1;
		}	
		 if (object_ptrs[1]->update())
		{
			noUpdate=0;	
			myUpdate=1;
		}	
		 if (object_ptrs[2]->update())
		{
			noUpdate=0;	
			myUpdate=1;
		}	
		 if (object_ptrs[3]->update())
		{
			noUpdate=0;	
			myUpdate=1;
		}	
		 if (object_ptrs[4]->update())
		{
			noUpdate=0;
			myUpdate=1;
	
		}
		if (object_ptrs[5]->update())
		{
			noUpdate=0;
			myUpdate=1;
	
		}		
		if (object_ptrs[6]->update())
		{
			noUpdate=0;
			myUpdate=1;
	
		}				
		
		Model::time=time+1;
		return myUpdate;	
}
}

void Model::display(View *view)
{
	//Will plot each object on the grid then use draw to cout everything
	
	view->clear();
	for(int i=0; i<num_persons;i++)
	{
		if(person_ptrs[i]->is_alive())
		{
			view->plot((person_ptrs[i]));		
		}
	}
	
//	view->plot((object_ptrs[0]));
//	view->plot((object_ptrs[1]));
	view->plot((object_ptrs[2]));
	view->plot((object_ptrs[3]));
	view->plot((object_ptrs[4]));
//	view->plot((object_ptrs[5]));
//	view->plot((object_ptrs[6]));
	view->draw();
}

void Model::show_status()
{
	cout<<"Time: "<<Model::time<<endl;
	object_ptrs[0]->show_status();
	object_ptrs[1]->show_status();
	object_ptrs[2]->show_status();
	object_ptrs[3]->show_status();
	object_ptrs[4]->show_status();
	object_ptrs[5]->show_status();
	object_ptrs[6]->show_status();

}
