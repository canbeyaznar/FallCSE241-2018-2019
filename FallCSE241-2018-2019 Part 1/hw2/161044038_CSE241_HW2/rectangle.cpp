//Can Beyaznar 161044038

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(): width(0), height(0){/* default contructor */}
Rectangle::Rectangle(double width_I, double height_I): width(width_I), height(height_I),Location_X(0),Location_Y(0){ }

Rectangle::Rectangle(const Rectangle &copyRectangle)//copy constructor
{
	color=copyRectangle.color;
	width=copyRectangle.width;
	height=copyRectangle.height;
	Location_X=copyRectangle.Location_X;
	Location_Y=copyRectangle.Location_Y;
	type=copyRectangle.type;
}

void Rectangle::setWidth(double width_I ) {width=width_I;	}
void Rectangle::setHeight(double height_I) {height=height_I;	}
	
double Rectangle::getWidth() const {return width; }
double Rectangle::getHeight() const {return height; }
	
void Rectangle::setLoc_X(double locX) {Location_X=locX; }
void Rectangle::setLoc_Y(double locY) {Location_Y=locY; }
	
double Rectangle::getLoc_X() const {return Location_X; }
double Rectangle::getLoc_Y() const {return Location_Y; }

void Rectangle::setColor(string color_name) {color=color_name;	}
string Rectangle::getColor() const {return color; }
	
void Rectangle::draw(ofstream &File)
{
	if(getWidth()>0 || getHeight()>0)
	{
		File<<"<rect x=\""<<Location_X<<"\" "<<"y=\""<<Location_Y<<"\"";
		File<<" width=\""<<width<<"\"";	
		File<<" height=\""<<height<<"\"";
		File<<" stroke=\"black\" stroke-width=\"0.5\"";
		File<<" fill=\""<<color<<"\"/>"<<endl<<endl;
	}
		
}


