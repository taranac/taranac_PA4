#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Person.h"
using namespace std;

const int view_maxsize=20;

class View
{
	//Public members
	public:
		View();
		void clear();
		void plot(Game_Object *);
		void draw();
		
	//Private members
	private:
		int size;
		double scale;
		Cart_Point origin;
		char grid[view_maxsize][view_maxsize][2];
		bool get_subscripts(int &ix, int &iy, Cart_Point );
		
};
#endif



