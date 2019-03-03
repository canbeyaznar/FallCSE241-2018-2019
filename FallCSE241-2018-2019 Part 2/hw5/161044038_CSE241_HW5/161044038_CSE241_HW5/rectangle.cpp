//Can Beyaznar 161044038

#include "rectangle.h"

namespace Shapes_namespace
{
	Rectangle::Rectangle(double width_I, double height_I) noexcept:width(width_I), height(height_I),Location_X(0),Location_Y(0), color("yellow")
	{
		//width or height can not be negative...
		if(width_I<0 || height_I<0)
		{
			width=0;
			height=0;
		}
			
		perimeterOfShape=2*(width+height);
		areaOfShape=width*height;
	}
	

	
	//Operator overload functions
	
	Rectangle& Rectangle::operator ++(int IgnoreMe) //Postfix version
	{
		double temp1=this->Location_X;
		double temp2=this->Location_Y;
		
		this->Location_X++;
		this->Location_Y++;	
		
		Rectangle temp(*this,temp1,temp2);
		Rectangle *newTemp=&temp;
		
		return *newTemp;
		
	}
	Rectangle& Rectangle::operator ++() //Prefix version
	{
		this->Location_X++;
		this->Location_Y++;	
		return *this;
	}
	
	
	Rectangle& Rectangle::operator --(int IgnoreMe) //Postfix version
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
			
			Rectangle temp(*this,temp1,temp2);
			Rectangle *newTemp=&temp;
			
			return *newTemp;
		}
		catch(double num)
		{
			cerr<<"Locations can not be negative!!"<<endl;
		}
	}
	
	Rectangle& Rectangle::operator --() //Prefix version
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
	
	void Rectangle::draw(ostream& outputStream) noexcept
	{
		outputStream<<*this;
	}
	
	ostream& operator <<(ostream& outputStream, const Rectangle& Rectangle_I) noexcept
	{
		try
		{
			if(Rectangle_I.getWidth()>0 || Rectangle_I.getHeight()>0)
			{
				outputStream<<"<rect x=\""<<Rectangle_I.getLoc_X()<<"\" "<<"y=\""<<Rectangle_I.getLoc_Y()<<"\"";
				outputStream<<" width=\""<<Rectangle_I.getWidth()<<"\"";	
				outputStream<<" height=\""<<Rectangle_I.getHeight()<<"\"";
				outputStream<<" stroke=\"black\" stroke-width=\"0.5\"";
				outputStream<<" fill=\""<<Rectangle_I.getColor()<<"\"/>"<<endl<<endl;
			}
			else
				throw(0);	
		}
		catch(int num)
		{
			cerr<<endl<<"You can not draw this shape!!"<<endl;
			cerr<<"Your width and height is : "<<Rectangle_I.getWidth()<<" "<<Rectangle_I.getHeight()<<endl;
			exit(0);
		}
		
		return outputStream;
	}
	
}





