#ifndef CART_POINT_H
#define CART_POINT_H
#include <iostream>
#include "Cart_Vector.h"
using namespace std;

class Cart_Point 
{
	//Member variables
	public:
		double x;
		double y;

//Constructors	
	Cart_Point();	
	Cart_Point(double, double);
	


};

//Nonmember Overloading Operator Functions
ostream &operator<<(ostream &, const Cart_Point &);//overloads "<<"
double cart_distance(Cart_Point , Cart_Point );//calculates distance between two points
Cart_Point operator+(Cart_Point, Cart_Vector);//overloads "+"
Cart_Vector operator-(Cart_Point, Cart_Point);//overloads"-"

#endif
