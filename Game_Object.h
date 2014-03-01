#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <iostream>
#include "Cart_Point.h"

using namespace std;
class Game_Object
{	
	public:
	//Constuctors
	Game_Object();
	Game_Object(char in_code);
	Game_Object(char in_code, int in_id, Cart_Point in_loc);
	
	//Destructor
	virtual ~Game_Object();
	
	//friend View to get_id and get_location
	friend class View;
	friend class Model;
	
	//Public member functions
	virtual	Cart_Point get_location();
	virtual	int get_id();
	void drawself(char* ptr);
	virtual void show_status();
	virtual bool update()=0;
	virtual bool is_alive();
	
	//Protected member variables
	protected:	
	Cart_Point location;
	char display_code;
	char state;
	
	//Private member variable
	private:
	int id_num;
};
#endif
