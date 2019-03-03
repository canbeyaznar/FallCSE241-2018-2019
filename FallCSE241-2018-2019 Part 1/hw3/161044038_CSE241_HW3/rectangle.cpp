//Can Beyaznar 161044038

#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(double width_I, double height_I): width(width_I), height(height_I),Location_X(0),Location_Y(0), color("black"){
	
	//width or height can not be negative...
	if(width_I<0 || height_I<0)
	{
		width=0;
		height=0;
	}
	
	perimeterOfShape=2*(width+height);
	areaOfShape=width*height;
}

Rectangle::Rectangle(const Rectangle &copyRectangle)//copy constructor
{
	width=copyRectangle.width;
	height=copyRectangle.height;
	perimeterOfShape=copyRectangle.perimeterOfShape;
	areaOfShape=copyRectangle.areaOfShape;
	color=copyRectangle.color;
	Location_X=copyRectangle.Location_X;
	Location_Y=copyRectangle.Location_Y;
	type=copyRectangle.type;
}

//Operator overload functions

Rectangle Rectangle::operator ++(int IgnoreMe) //Postfix version
{
	++(*this);
	return *this;
	
}
Rectangle Rectangle::operator ++() //Prefix version
{
	this->Location_X++;
	this->Location_Y++;	
	return *this;
}

Rectangle Rectangle::operator --(int IgnoreMe) //Postfix version
{
	//The coordinates must not be negative numbers so we should do like that to avoid mistakes...
	if(!(this->Location_X-1<0))
		this->Location_X--;
	else
		this->Location_X=0;
		
	if(!(this->Location_Y-1<0))
		this->Location_Y--;
	else
		this->Location_Y=0;
		
		
	return *this;
}

Rectangle Rectangle::operator --() //Prefix version
{	
	//The coordinates must not be negative numbers so we should do like that to avoid mistakes...	
	if(!(this->Location_X-1<0))
		this->Location_X--;
	else
		this->Location_X=0;
		
	if(!(this->Location_Y-1<0))
		this->Location_Y--;
	else
		this->Location_Y=0;
	
	return *this;
}

const Rectangle operator +(const Rectangle& Rectangle_I, double Value)
{
	Rectangle newRectangle=Rectangle_I;
	
	newRectangle.height=Rectangle_I.height+Value;
	newRectangle.width=Rectangle_I.width+Value;
	newRectangle.perimeterOfShape=2*(newRectangle.height+newRectangle.width);
	newRectangle.areaOfShape=newRectangle.height*newRectangle.width;
	
	return newRectangle;
}

const Rectangle operator -(const Rectangle& Rectangle_I, double Value)
{
	Rectangle newRectangle=Rectangle_I;
	//width and height can not be negative...
	//** If the user gives the value bigger than width or height, set both of them as 0 (zero)... 
	if(!(Rectangle_I.height-Value<0 || Rectangle_I.width-Value<0))
	{
		newRectangle.height=Rectangle_I.height-Value;
		newRectangle.width=Rectangle_I.width-Value;
	}
	else
	{
		newRectangle.height=0;
		newRectangle.width=0;
	}
	newRectangle.perimeterOfShape=2*(newRectangle.height+newRectangle.width);
	newRectangle.areaOfShape=newRectangle.height*newRectangle.width;
	
	return newRectangle;
}

ostream& operator <<(ostream& outputStream, const Rectangle& Rectangle_I)
{
	if(Rectangle_I.width>0 || Rectangle_I.height>0)
	{
		outputStream<<"<rect x=\""<<Rectangle_I.Location_X<<"\" "<<"y=\""<<Rectangle_I.Location_Y<<"\"";
		outputStream<<" width=\""<<Rectangle_I.width<<"\"";	
		outputStream<<" height=\""<<Rectangle_I.height<<"\"";
		outputStream<<" stroke=\"black\" stroke-width=\"0.5\"";
		outputStream<<" fill=\""<<Rectangle_I.color<<"\"/>"<<endl<<endl;
	}
	else
		cout<<endl<<"You can not draw this shape!!"<<endl;
	
	return outputStream;
}
/*double Rectangle::getNewPerimeter()
{
	//static double temp1=width, temp2=height;
	//perimeterOfShape=2*(width+height);
	return perimeterOfShape;
}
double Rectangle::getNewArea()
{
	//areaOfShape=(width*height);
	return areaOfShape;
}*/


