//Can Beyaznar 161044038

#ifndef rectangle_h
#define rectangle_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Rectangle
{
	public:
		Rectangle();
		Rectangle(double width_I, double height_I);
		Rectangle(const Rectangle &copyRectangle);
		
		void setWidth(double width_I );
		void setHeight(double height_I);
		
		double getWidth() const;
		double getHeight() const;
		
		void setLoc_X(double locX);
		void setLoc_Y(double locY);
		
		double getLoc_X() const;
		double getLoc_Y() const;
		
		void setColor(string color_name);
		string getColor() const;
		
		void draw(ofstream &File);

		
	private:
		string color;
		char type='R';
		double width;
		double height;
		double Location_X;
		double Location_Y;
		
};

#endif

