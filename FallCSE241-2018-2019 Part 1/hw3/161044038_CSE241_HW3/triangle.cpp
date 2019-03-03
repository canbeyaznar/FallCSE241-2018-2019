//Can Beyaznar 161044038

#include "triangle.h"

using namespace std;

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
Triangle::Triangle(const Triangle &copyTriangle)
{
	color=copyTriangle.color;
	edge=copyTriangle.edge;
	rotate=copyTriangle.rotate;
	height=copyTriangle.height;
	perimeterOfShape=copyTriangle.perimeterOfShape;
	areaOfShape=copyTriangle.areaOfShape;
	Location_X=copyTriangle.Location_X;
	Location_Y=copyTriangle.Location_Y;
	type=copyTriangle.type;
}
//Operator overload functions

Triangle Triangle::operator ++(int IgnoreMe) //Postfix version
{
	++(*this);
	return *this;
	
}
Triangle Triangle::operator ++() //Prefix version
{
	this->Location_X++;
	this->Location_Y++;	
	return *this;
}

Triangle Triangle::operator --(int IgnoreMe) //Postfix version
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

Triangle Triangle::operator --() //Prefix version
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

const Triangle operator +(const Triangle& Triangle_I, double Value)
{
	Triangle newTriangle=Triangle_I;
	
	newTriangle.edge=Triangle_I.edge+Value;
	newTriangle.Location_X=newTriangle.Location_X+(Value/2);

	newTriangle.perimeterOfShape=3*Triangle_I.edge;
	newTriangle.areaOfShape=Triangle_I.edge*Triangle_I.edge*sqrt(3)/4;
	
	return newTriangle;
}

const Triangle operator -(const Triangle& Triangle_I, double Value)
{
	Triangle newTriangle=Triangle_I;
	//edge can not be negative...
	//** If the user gives the value bigger than edge, edge will be 0 (zero)... 
	if(!(Triangle_I.edge-Value<0))
		newTriangle.edge=Triangle_I.edge-Value;
		
	else
		newTriangle.edge=0;
		
	if(!(newTriangle.Location_X-Value<0))
		newTriangle.Location_X=newTriangle.Location_X-(Value/2);
	else
		newTriangle.Location_X=0;
	
	newTriangle.perimeterOfShape=3*newTriangle.edge;
	newTriangle.areaOfShape=newTriangle.edge*newTriangle.edge*sqrt(3)/4;
	
	return newTriangle;
}

ostream& operator <<(ostream& outputStream, const Triangle& Triangle_I)
{
	if(Triangle_I.getEdge()>0)
	{
		if(Triangle_I.getRotate()==0)
		{
			outputStream<<"<polygon points=\""<<Triangle_I.Location_X<<","<<Triangle_I.Location_Y<<" "<<Triangle_I.Location_X+(Triangle_I.edge/2)<<","<<Triangle_I.Location_Y+(Triangle_I.getEdge()*sqrt(3)/2)<<" "<<Triangle_I.Location_X-(Triangle_I.edge/2)<<","<<Triangle_I.Location_Y+(Triangle_I.edge*sqrt(3)/2)<<"\"";
			outputStream<<" stroke=\"black\" stroke-width=\"0.5\""; //this is for see the shapes clearly
			outputStream<<" fill=\""<<Triangle_I.color<<"\"/>"<<endl<<endl;
		}
		else if(Triangle_I.getRotate()==1)
		{
			outputStream<<"<polygon points=\""<<Triangle_I.Location_X-(Triangle_I.edge/2)<<","<<Triangle_I.Location_Y<<" "<<Triangle_I.Location_X<<","<<Triangle_I.Location_Y+(Triangle_I.edge*sqrt(3)/2)<<" "<<Triangle_I.Location_X+(Triangle_I.edge/2)<<","<<Triangle_I.Location_Y<<"\"";
			outputStream<<" stroke=\"black\" stroke-width=\"0.5\"";
			outputStream<<" fill=\""<<Triangle_I.color<<"\"/>"<<endl<<endl;
		}
		else
			outputStream<<"THERE IS A PROBLEM IN CODE!!"<<endl;
	}
	else
		cout<<endl<<"You can not draw this shape!!"<<endl;
	
	return outputStream;
}



