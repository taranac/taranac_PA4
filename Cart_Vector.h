#ifndef CART_VEC_H
#define CART_VEC_H
#include <iostream>
using namespace std;

class Cart_Vector
{
	//Member variables
	public: 
		double x;
		double y;
		
	//Constructors	
		Cart_Vector();
		Cart_Vector(double, double);
};

// Nonmember Overloading operator functions

ostream &operator<<(ostream &, const Cart_Vector &);// overloads "<<"
Cart_Vector operator* (Cart_Vector , double );//overloads "*"
Cart_Vector operator/ (Cart_Vector , double );//overloads "/"

#endif
