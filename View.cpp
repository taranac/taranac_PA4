#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"
#include "View.h"
using namespace std;

//Constructor
	View::View()
	{
		size=11;
		scale=2;
		origin=Cart_Point();
			
	}
//PUBLIC member functions	
void View::clear()//clears board with '.'' '
{	
	for(int i=0; i<size ;i++)
	{ for (int j=0; j<size; j++)	
		{
			grid[i][j][0]='.';
			grid[i][j][1]=' ';
		}
	}
}
		void View::plot(Game_Object *ptr)
		{
			int ix=0;
			int iy=0;
			if(get_subscripts(ix, iy, (*ptr).get_location()))//get_subscripts will store the accurate x and y coordinates
			{	
				if (grid[iy][ix][0]=='.' && grid[iy][ix][1]==' ')
				{
					ptr->drawself(grid[iy][ix]);//ROW is the y index, COLUMN is the x-index will call drawself to actually plot
				}
				else
				{
					grid[iy][ix][0]='*';
					grid[iy][ix][1]=' ';
				}
			}
			
		}
		void View::draw()
		{	//int xAxis[]={0,2,4,6};
			int yAxis=int((size)*scale);	
			for(int i=size-1; i>=0; i--)
			{	yAxis=yAxis-int(scale);
					if(yAxis>=10 && yAxis==12 || yAxis==16 || yAxis==20)
					{
						cout<<yAxis;
					}
					if(yAxis<10&& yAxis==0|| yAxis==4|| yAxis==8)
					{
						cout<<yAxis<<" ";
					}
					if(yAxis==2||yAxis==6||yAxis==10||yAxis==14||yAxis==18)
					{
						cout<<"  ";
					}
				
				for (int j=0; j<size;j++)
				{
					cout<<grid[i][j][0];
					cout<<grid[i][j][1];
				}
				cout<<endl;		
			}
					cout<<"  0   4   8   12  16  20";
		}
	//Private member function
	
		bool View::get_subscripts(int &ix, int &iy, Cart_Point location)
		{
			ix=int((location.x-origin.x)/scale);
			iy=int((location.y-origin.y)/scale);
			if(ix<=(size*scale) && iy<=(size*scale))
			{
				return true;
			}
			else 
			{
				cout<<"An object is outside the display."<<endl;
				return false;
			}
		}
		




