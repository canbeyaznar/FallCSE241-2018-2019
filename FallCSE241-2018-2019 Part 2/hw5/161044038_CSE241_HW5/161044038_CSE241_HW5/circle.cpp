//Can Beyaznar 161044038

#include "circle.h"

namespace Shapes_namespace
{
	Circle::Circle(double radius_I) noexcept: radius(radius_I),Location_X(radius_I),Location_Y(radius_I), color("grey")
	{
		
		//radius can not be negative...
		if(radius_I<0 )
			radius=0;
		
		perimeterOfShape=2*3.14*radius;
		areaOfShape=3.14*radius*radius;
	}
	
			
	
	//Operator overload functions
	
	Circle& Circle::operator ++(int IgnoreMe) //Postfix version
	{
		double temp1=this->Location_X;
		double temp2=this->Location_Y;
		
		this->Location_X++;
		this->Location_Y++;	
		
		Circle temp(*this,temp1,temp2);
		Circle *newTemp=&temp;
		
		return *newTemp;
		
	}
	Circle& Circle::operator ++() //Prefix version
	{
		this->Location_X++;
		this->Location_Y++;	
		return *this;
	}
	
	Circle& Circle::operator --(int IgnoreMe) //Postfix version
	{	
		//The coordinates must not be negative numbers so we should do like that to avoid mistakes...
		double temp1=this->Location_X;
		double temp2=this->Location_Y;
		
		try
		{
			if(!(this->Location_X-1<0))
				this->Location_X--;
			else
			{
				throw(this->Location_X);
			}

			if(!(this->Location_Y-1<0))
				this->Location_Y--;
			else
			{
				throw(this->Location_Y);
			}
		}
		catch(double num)
		{
			cerr<<"Locations can not be negative!!"<<endl;
		}
			
		Circle temp(*this,temp1,temp2);
		Circle *newTemp=&temp;
		
		return *newTemp;
	}
	
	Circle& Circle::operator --() //Prefix version
	{	
		//The coordinates must not be negative numbers so we should do like that to avoid mistakes...	
		try
		{
			if(!(this->Location_X-1<0))
				this->Location_X--;
			else
			{
				throw(this->Location_X);
			}

			if(!(this->Location_Y-1<0))
				this->Location_Y--;
			else
			{
				throw(this->Location_Y);
			}
		}
		catch(double num)
		{
			cerr<<"Locations can not be negative!!"<<endl;
		}
		return *this;
	}
	
	
	void Circle::draw(ostream& outputStream) noexcept
	{
		outputStream<<*this;
	}
	
	ostream& operator <<(ostream& outputStream, const Circle& Circle_I)
	{
		try
		{
			if(Circle_I.getRadius()>0)
			{
				outputStream<<"<circle cx=\""<<Circle_I.getLoc_X()<<"\""<<" cy=\""<<Circle_I.getLoc_Y()<<"\"";
				outputStream<<" r=\""<<Circle_I.getRadius()<<"\"";
				outputStream<<" stroke=\"black\" stroke-width=\"0.5\"";	//this is for see the shapes clearly
				outputStream<<" fill=\""<<Circle_I.getColor()<<"\"/>"<<endl;
			}
			else
				throw(Circle_I.getColor());			
		}
		catch(double Radius)
		{
			cerr<<endl<<"You can not draw this shape!!"<<endl;
			cerr<<"Your radius is : "<<Radius<<endl;
			exit(0);
		}
		
		return outputStream;
	}
}



		






