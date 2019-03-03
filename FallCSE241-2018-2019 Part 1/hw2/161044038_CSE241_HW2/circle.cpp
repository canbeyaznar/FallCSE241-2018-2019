//Can Beyaznar 161044038

#include "circle.h"

using namespace std;

Circle::Circle(): radius(0){/* default contructor */}
Circle::Circle(double Radius_I): radius(Radius_I),Location_X(Radius_I),Location_Y(Radius_I) { }
Circle::Circle(const Circle &copyCircle)
{
	color=copyCircle.color;
	radius=copyCircle.radius;
	Location_X=copyCircle.Location_X;
	Location_Y=copyCircle.Location_Y;
	type=copyCircle.type;
}		
	
void Circle::setRadius(double Radius_I) {radius=Radius_I; }
double Circle::getRadius() const {return radius; }
		
void Circle::setLoc_X(double locX) {Location_X=locX; }
void Circle::setLoc_Y(double locY) {Location_Y=locY; }
		
double Circle::getLoc_X() const {return Location_X; }
double Circle::getLoc_Y() const {return Location_Y; }

void Circle::setColor(string color_name) {color=color_name;	}
string Circle::getColor() const {return color; }	
	
void Circle::draw(ofstream &File)
{
	if(getRadius()>0)
	{
		File<<"<circle cx=\""<<Location_X<<"\""<<" cy=\""<<Location_Y<<"\"";
		File<<" r=\""<<radius<<"\"";
		File<<" stroke=\"black\" stroke-width=\"0.5\"";	//this is for see the shapes clearly
		File<<" fill=\""<<color<<"\"/>"<<endl;
	}
}
		


