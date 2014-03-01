#include <iostream>
#include <cmath>
#include "Cart_Point.h"
#include "Cart_Vector.h"
using namespace std;

//Constructors creates Cartisian points
Cart_Point::Cart_Point()
{
	x=0.0;
	y=0.0;
}	

Cart_Point::Cart_Point(double inputx, double inputy)
{
	x=inputx;
	y=inputy;
}
//Nonmember overloading operator functions

Cart_Point operator+ (Cart_Point p1, Cart_Vector v1)//overloads "+"
{	Cart_Point p3(p1.x+v1.x, p1.y+v1.y);
	return p3;
}

Cart_Vector operator- (Cart_Point p1, Cart_Point p2)//overloads"-"
{	Cart_Vector v3(p1.x-p2.x, p1.y-p2.y);
	return v3;
}
 ostream &operator<<(ostream &out, const Cart_Point &p1)//overloads "<<"
{
	out<<"("<<p1.x<<", "<<p1.y<<")";
}

double cart_distance(Cart_Point p1, Cart_Point p2)//this function calculates distance between two points
{
	double distance=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
	return distance;
}
