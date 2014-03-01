#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"

#include <string>

using namespace std;

//PUBLIC member functions
Cart_Point Game_Object::get_location()
{
	return location;
}

int Game_Object::get_id()
{
	return id_num;
}

void Game_Object::show_status()
{
	cout<<display_code<<get_id()<<" at "<<get_location();
}
void Game_Object::drawself(char* ptr)
{
	ptr[0]=display_code;
	ptr[1]=char(id_num+48);
	
}

//is alive is always true!
bool Game_Object::is_alive()
{
	return true;
}
//Constructors
Game_Object::Game_Object()
{
	display_code=' ';
	state='s';
	id_num=0;
	location=Cart_Point();
	cout<<"   Game_Object default constructed"<<endl;
}

Game_Object::Game_Object(char in_code)
{
	display_code=in_code;
	state='s';
	id_num=0;
	location=Cart_Point();
	cout<<"   Game_Object constructed"<<endl;
}

Game_Object::Game_Object(char in_code, int in_id , Cart_Point in_loc)
{
	display_code=in_code;
	id_num=in_id;
	location=in_loc;	
	state='s';
	cout<<"   Game_Object constructed"<<endl;
}

Game_Object::~Game_Object()
{
	cout<<"   Game_Object destructed"<<endl;
}

