//Can Beyaznar 161044038

#include "circle.h"

namespace Shapes_namespace
{
	Circle::Circle(double radius_I): radius(radius_I),Location_X(radius_I),Location_Y(radius_I), color("grey")
	{
		
		//radius can not be negative...
		if(radius_I<0 )
			radius=0;
		
		perimeterOfShape=2*3.14*radius;
		areaOfShape=3.14*radius*radius;
	}
	
	Circle::Circle(const Circle &copyCircle)
	{
		color=copyCircle.color;
		radius=copyCircle.radius;
		perimeterOfShape=copyCircle.perimeterOfShape;
		areaOfShape=copyCircle.areaOfShape;
		Location_X=copyCircle.Location_X;
		Location_Y=copyCircle.Location_Y;
		type=copyCircle.type;
	}			
	
	//Operator overload functions
	
	Circle Circle::operator ++(int IgnoreMe) //Postfix version
	{
		double temp1=this->Location_X;
		double temp2=this->Location_Y;
		
		this->Location_X++;
		this->Location_Y++;	
		
		return Circle(*this,temp1,temp2);
		
	}
	Circle Circle::operator ++() //Prefix version
	{
		this->Location_X++;
		this->Location_Y++;	
		return *this;
	}
	
	Circle Circle::operator --(int IgnoreMe) //Postfix version
	{	
		//The coordinates must not be negative numbers so we should do like that to avoid mistakes...
		double temp1=this->Location_X;
		double temp2=this->Location_Y;
		
		if(!(this->Location_X-1<0))
			this->Location_X--;
		else
			this->Location_X=0;
			
		if(!(this->Location_Y-1<0))
			this->Location_Y--;
		else
			this->Location_Y=0;
			
			
		return Circle(*this,temp1,temp2);
	}
	
	Circle Circle::operator --() //Prefix version
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
	
	const Circle operator +(const Circle& Circle_I, double Value)
	{
		Circle newCircle=Circle_I;
		
		newCircle.radius=Circle_I.radius+Value;
		newCircle.Location_X=newCircle.Location_X+Value;
		newCircle.Location_Y=newCircle.Location_Y+Value;
		newCircle.perimeterOfShape=2*3.14*Circle_I.radius;
		newCircle.areaOfShape=3.14*Circle_I.radius*Circle_I.radius;
		
		return newCircle;
	}
	
	const Circle operator -(const Circle& Circle_I, double Value)
	{
		Circle newCircle=Circle_I;
		//radius can not be negative...
		//** If the user gives the value bigger than radius, radius will be 0 (zero)... 
		if(!(Circle_I.radius-Value<0))
			newCircle.radius=Circle_I.radius-Value;
			
		else
			newCircle.radius=0;
		
		if(!(newCircle.Location_X-Value<0))
			newCircle.Location_X=newCircle.Location_X-Value;
		else
			newCircle.Location_X=0;
			
		if(!(newCircle.Location_Y-Value<0))
			newCircle.Location_Y=newCircle.Location_Y-Value;
		else
			newCircle.Location_Y=0;
	
		newCircle.perimeterOfShape=2*3.14*newCircle.radius;
		newCircle.areaOfShape=3.14*newCircle.radius*newCircle.radius;
		
		return newCircle;
	}
	
	ostream& operator <<(ostream& outputStream, const Circle& Circle_I)
	{
		if(Circle_I.radius>0)
		{
			outputStream<<"<circle cx=\""<<Circle_I.Location_X<<"\""<<" cy=\""<<Circle_I.Location_Y<<"\"";
			outputStream<<" r=\""<<Circle_I.radius<<"\"";
			outputStream<<" stroke=\"black\" stroke-width=\"0.5\"";	//this is for see the shapes clearly
			outputStream<<" fill=\""<<Circle_I.color<<"\"/>"<<endl;
		}
		else
			cout<<endl<<"You can not draw this shape!!"<<endl;
			
		return outputStream;
	}
}



		




