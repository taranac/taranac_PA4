#include <iostream>
#include "Cart_Vector.h"
using namespace std;

//Constructors	
Cart_Vector::Cart_Vector()
{
	x=0;
	y=0;
}	
Cart_Vector::Cart_Vector(double inputx, double inputy)
{
	x=inputx;
	y=inputy;
}

//NonMember Functions Overloading Operator Functions
Cart_Vector operator* (Cart_Vector v1, double d)//overloads "*"
{	Cart_Vector v3(v1.x*d, v1.y*d);
	return v3;
}

Cart_Vector operator/ (Cart_Vector v1, double d)//overloads "/"
{	Cart_Vector v3(v1.x/d, v1.y/d);
	return v3;
}

ostream &operator<<(ostream &out, const Cart_Vector &v1)//overloads"<<"
{
	out<<"<"<<v1.x<<", "<<v1.y<<">";
}

