//Can Beyaznar 161044038

#ifndef circle_h
#define circle_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Circle
{
	public:
		Circle();
		Circle(double Radius_I);
		Circle(const Circle &copyCircle);		
		
		void setRadius(double Radius_I);
		double getRadius() const;
		
		void setLoc_X(double locX);
		void setLoc_Y(double locY);
		
		double getLoc_X() const;
		double getLoc_Y() const;
		
		void draw(ofstream &File);
		
		void setColor(string color_name);
		string getColor() const;
		
	private:
		string color;
		char type='C';
		double radius;
		double Location_X;
		double Location_Y;
};


#endif

