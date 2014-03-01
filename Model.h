#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "View.h"


using namespace std;

class Model
{
	private:
		int time;
		Game_Object * object_ptrs[10];
		int num_objects;
		Person * person_ptrs[10];
		int num_persons;
		Gold_Mine * mine_ptrs[10];
		int num_mines;
		Town_Hall * hall_ptrs[10];
		int num_halls;
		//COPY CONSTRUCTOR Model(Model &);????
		
		public:
			friend class Game_Object;
			Model();
			virtual ~Model();
			Person * get_Person_ptr(int id);
			Gold_Mine * get_Gold_Mine_ptr(int id);
			Town_Hall * get_Town_Hall_ptr(int id);
			bool update();
			void display(View *view);
			void show_status();

};

#endif
