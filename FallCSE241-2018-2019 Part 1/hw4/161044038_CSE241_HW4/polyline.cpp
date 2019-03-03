//Can Beyaznar 161044038

#include "polyline.h"

namespace 
{
	Polyline::Polyline(const vector<Point2D> arrOfPoints)
	{
		sizeOfPoints=arrOfPoints.size();
		pointsOfShapes=new Point2D[sizeOfPoints];
		color="grey";
		
		for(int i=0; i<arrOfPoints.size(); i++)
			pointsOfShapes[i]=arrOfPoints[i];
			
	}
	
	Polyline::Polyline(const Rectangle Rectangle_I)
	{
		sizeOfPoints=4;
		pointsOfShapes=new Point2D[sizeOfPoints];
		color=Rectangle_I.getColor();
		
		pointsOfShapes[0].setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y());
		pointsOfShapes[1].setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y());
		pointsOfShapes[2].setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
		pointsOfShapes[3].setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
		
	}
	Polyline::Polyline(Circle Circle_I)
	{
		double PI=3.14159;
		int tX=1,tY=-1;
		
		sizeOfPoints=200;
		pointsOfShapes=new Point2D[sizeOfPoints];
		color=Circle_I.getColor();
		
		pointsOfShapes[0].setLocations(Circle_I.getLoc_X(),Circle_I.getLoc_Y()-Circle_I.getRadius());
		for(int i=1; i<sizeOfPoints; i++)
			pointsOfShapes[i].setLocations(Circle_I.getLoc_X()+(tX*Circle_I.getRadius()*sin(i*PI/100)),Circle_I.getLoc_Y()+(tY*Circle_I.getRadius()*cos(i*PI/100)) );
		
	}
	
	Polyline::Polyline(Triangle Triangle_I)
	{
		sizeOfPoints=3;
		pointsOfShapes=new Point2D[sizeOfPoints];
		color=Triangle_I.getColor();
		
		if(Triangle_I.getRotate()==0)
		{
			pointsOfShapes[0].setLocations(Triangle_I.getLoc_X(),Triangle_I.getLoc_Y());
			pointsOfShapes[1].setLocations(Triangle_I.getLoc_X()-Triangle_I.getEdge()/2,Triangle_I.getLoc_Y()+Triangle_I.getHeight());
			pointsOfShapes[2].setLocations(Triangle_I.getLoc_X()+Triangle_I.getEdge()/2,Triangle_I.getLoc_Y()+Triangle_I.getHeight());
		}
		else if(Triangle_I.getRotate()==1)
		{
			pointsOfShapes[0].setLocations(Triangle_I.getLoc_X()-Triangle_I.getEdge()/2,Triangle_I.getLoc_Y());
			pointsOfShapes[1].setLocations(Triangle_I.getLoc_X()+Triangle_I.getEdge()/2,Triangle_I.getLoc_Y());
			pointsOfShapes[2].setLocations(Triangle_I.getLoc_X(),Triangle_I.getLoc_Y()+Triangle_I.getHeight());
		}
		else
			cout<<"THERE IS A PROBLEM IN CODE!!"<<endl;
		
		
	}
	
	Polyline::Polyline(const Polyline& copyPolyline)
	{
		sizeOfPoints=copyPolyline.sizeOfPoints;
		pointsOfShapes=new Point2D[sizeOfPoints];
		color=copyPolyline.color;
		
		for(int i=0; i<sizeOfPoints; i++)
			pointsOfShapes[i]=copyPolyline.pointsOfShapes[i];
	}
	
	Polyline& Polyline:: operator =(const Polyline& copyPolyline)
	{
		if(this==&copyPolyline)
			return *this;
			
		delete []this->pointsOfShapes;
		this->sizeOfPoints=copyPolyline.sizeOfPoints;
		this->pointsOfShapes=new Point2D[this->sizeOfPoints];
		this->color=copyPolyline.color;
		
		for(int i=0; i<this->sizeOfPoints; i++)
			this->pointsOfShapes[i]=copyPolyline.pointsOfShapes[i];
			
		return *this;	
	}
	
	bool operator ==(const Polyline& firstPolyline, const Polyline& secondPolyline)
	{
		int count=0;
		
		if(firstPolyline.sizeOfPoints!=secondPolyline.sizeOfPoints)
			return 0;
			
		//if all the x and y locations are equal it is true...
		for(int i=0; i<firstPolyline.sizeOfPoints; i++)
		{
			if( (firstPolyline.pointsOfShapes[i].getLocX()==secondPolyline.pointsOfShapes[i].getLocX()) && (firstPolyline.pointsOfShapes[i].getLocY()==secondPolyline.pointsOfShapes[i].getLocY()))
				count++;
		}
		return (count==firstPolyline.sizeOfPoints);
	}
	
	bool operator !=(const Polyline& firstPolyline, const Polyline& secondPolyline)
	{
		return !(firstPolyline==secondPolyline);
	}
	
	const Polyline::Point2D& Polyline:: operator [](int index)
	{
		if(this->sizeOfPoints<=index || index<0)
		{
			cout<<"Illegal index in Polygon!!"<<endl;
			exit(0); //It is error!!
		}
		
		return this->pointsOfShapes[index];	
	}
	
	const Polyline operator +(const Polyline& firstPolyline, const Polyline& secondPolyline )
	{	
		int i;
		Polyline result;
		
		result.sizeOfPoints=firstPolyline.sizeOfPoints+secondPolyline.sizeOfPoints;
		result.pointsOfShapes=new Polyline::Point2D[result.sizeOfPoints];
		
		for(i=0; i<firstPolyline.sizeOfPoints; i++)
			result.pointsOfShapes[i]=firstPolyline.pointsOfShapes[i];
		for(i=firstPolyline.sizeOfPoints; i<result.sizeOfPoints; i++)
			result.pointsOfShapes[i]=secondPolyline.pointsOfShapes[i-firstPolyline.sizeOfPoints];
		
		return result;
	}
	
	ostream& operator <<(ostream& outs, const Polyline& tempPolyline)
	{
		outs<<"<polygon points=\"";
		for(int i=0; i<tempPolyline.sizeOfPoints; i++)
		{
			outs<<tempPolyline.pointsOfShapes[i].getLocX()<<",";
			outs<<tempPolyline.pointsOfShapes[i].getLocY()<<" ";
		}
		outs<<"\" stroke=\"black\" stroke-width=\"0.5\" ";
		outs<<"fill=\""<<tempPolyline.color<<"\"/>"<<endl;
			
		return outs;
	}
	
	Polyline::~Polyline()
	{
		delete []pointsOfShapes;
	}
}



