//Can Beyaznar 161044038

#include "triangle.h"

namespace Shapes_namespace
{
	Triangle::Triangle(double edge_I): edge(edge_I), height(edge_I*sqrt(3)/2),Location_X(edge_I/2),Location_Y(0),color("pink"),rotate(0)
	{
		//edge can not be negative...
		if(edge_I<0 )
		{
			edge=0;
			Location_X=0;
		}
		perimeterOfShape=3*edge;
		areaOfShape=edge*edge*sqrt(3)/4;
	}
	//Operator overload functions
	
	Triangle& Triangle::operator ++(int IgnoreMe) //Postfix version
	{
		double temp1=this->Location_X;
		double temp2=this->Location_Y;
		
		this->Location_X++;
		this->Location_Y++;	
		
		Triangle temp(*this,temp1,temp2);
		Triangle *newTemp=&temp;
		
		return *newTemp;
		
	}
	Triangle& Triangle::operator ++() //Prefix version
	{
		this->Location_X++;
		this->Location_Y++;	
		return *this;
	}
	
	Triangle& Triangle::operator --(int IgnoreMe) //Postfix version
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
			
		Triangle temp(*this,temp1,temp2);
		Triangle *newTemp=&temp;
		
		return *newTemp;
	}
	
	Triangle& Triangle::operator --() //Prefix version
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

	void Triangle::draw(ostream& outputStream) noexcept
	{
		outputStream<<*this;
	}
	
	ostream& operator <<(ostream& outputStream, const Triangle& Triangle_I)
	{
		try
		{
			if(Triangle_I.getEdge()>0)
			{
				if(Triangle_I.getRotate()==0)
				{
					outputStream<<"<polygon points=\""<<Triangle_I.getLoc_X()<<","<<Triangle_I.getLoc_Y()<<" "<<Triangle_I.getLoc_X()+(Triangle_I.getEdge()/2)<<","<<Triangle_I.getLoc_Y()+(Triangle_I.getEdge()*sqrt(3)/2)<<" "<<Triangle_I.getLoc_X()-(Triangle_I.getEdge()/2)<<","<<Triangle_I.getLoc_Y()+(Triangle_I.getEdge()*sqrt(3)/2)<<"\"";
					outputStream<<" stroke=\"black\" stroke-width=\"0.5\""; //this is for see the shapes clearly
					outputStream<<" fill=\""<<Triangle_I.getColor()<<"\"/>"<<endl<<endl;
				}
				else if(Triangle_I.getRotate()==1)
				{
					outputStream<<"<polygon points=\""<<Triangle_I.getLoc_X()-(Triangle_I.getEdge()/2)<<","<<Triangle_I.getLoc_Y()<<" "<<Triangle_I.getLoc_X()<<","<<Triangle_I.getLoc_Y()+(Triangle_I.getEdge()*sqrt(3)/2)<<" "<<Triangle_I.getLoc_X()+(Triangle_I.getEdge()/2)<<","<<Triangle_I.getLoc_Y()<<"\"";
					outputStream<<" stroke=\"black\" stroke-width=\"0.5\"";
					outputStream<<" fill=\""<<Triangle_I.getColor()<<"\"/>"<<endl<<endl;
				}
				else
					outputStream<<"THERE IS A PROBLEM IN CODE!!"<<endl;
			}
			else
				throw(Triangle_I.getEdge());
				
		}
		catch(double Edge)
		{
			cerr<<endl<<"You can not draw this shape!!"<<endl;
			cerr<<"Your edge is : "<<Edge<<endl;
			exit(0);
		}
		
		
		return outputStream;
	}
}
