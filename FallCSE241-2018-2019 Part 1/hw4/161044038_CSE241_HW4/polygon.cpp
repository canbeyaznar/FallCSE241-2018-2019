//Can Beyaznar 161044038

#include "polygon.h"

namespace Shapes_namespace
{
	Polygon::Polygon(const vector<Point2D> arrOfPoints)
	{
		sizeOfPoints=arrOfPoints.size();
		pointsOfShapes=new Point2D[sizeOfPoints];
		color="grey";
		
		for(int i=0; i<arrOfPoints.size(); i++)
			pointsOfShapes[i]=arrOfPoints[i];
			
	}
	
	Polygon::Polygon(const Rectangle Rectangle_I)
	{
		sizeOfPoints=4;
		pointsOfShapes=new Point2D[sizeOfPoints];
		color=Rectangle_I.getColor();
		
		pointsOfShapes[0].setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y());
		pointsOfShapes[1].setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y());
		pointsOfShapes[2].setLocations(Rectangle_I.getLoc_X()+Rectangle_I.getWidth(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
		pointsOfShapes[3].setLocations(Rectangle_I.getLoc_X(),Rectangle_I.getLoc_Y()+Rectangle_I.getHeight());
		
	}
	Polygon::Polygon(Circle Circle_I)
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
	
	Polygon::Polygon(Triangle Triangle_I)
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
	
	Polygon::Polygon(const Polygon& copyPolygon)
	{
		sizeOfPoints=copyPolygon.sizeOfPoints;
		pointsOfShapes=new Point2D[sizeOfPoints];
		color=copyPolygon.color;
		
		for(int i=0; i<sizeOfPoints; i++)
			pointsOfShapes[i]=copyPolygon.pointsOfShapes[i];
	}
	
	Polygon& Polygon:: operator =(const Polygon& copyPolygon)
	{
		if(this==&copyPolygon)
			return *this;
			
		delete []this->pointsOfShapes;
		this->sizeOfPoints=copyPolygon.sizeOfPoints;
		this->pointsOfShapes=new Point2D[this->sizeOfPoints];
		this->color=copyPolygon.color;
		
		for(int i=0; i<this->sizeOfPoints; i++)
			this->pointsOfShapes[i]=copyPolygon.pointsOfShapes[i];
			
		return *this;	
	}
	
	bool operator ==(const Polygon& firstPolygon, const Polygon& secondPolygon)
	{
		int count=0;
		
		if(firstPolygon.sizeOfPoints!=secondPolygon.sizeOfPoints)
			return 0;
			
		//if all the x and y locations are equal it is true...
		for(int i=0; i<firstPolygon.sizeOfPoints; i++)
		{
			if( (firstPolygon.pointsOfShapes[i].getLocX()==secondPolygon.pointsOfShapes[i].getLocX()) && (firstPolygon.pointsOfShapes[i].getLocY()==secondPolygon.pointsOfShapes[i].getLocY()))
				count++;
		}
		return (count==firstPolygon.sizeOfPoints);
	}
	
	bool operator !=(const Polygon& firstPolygon, const Polygon& secondPolygon)
	{
		return !(firstPolygon==secondPolygon);
	}
	
	const Polygon::Point2D& Polygon:: operator [](int index)
	{
		if(this->sizeOfPoints<=index || index<0)
		{
			cout<<"Illegal index in Polygon!!"<<endl;
			exit(0); //It is error!!
		}
		
		return this->pointsOfShapes[index];	
	}
	
	const Polygon operator +(const Polygon& firstPolygon, const Polygon& secondPolygon )
	{	
		int i;
		Polygon result;
		
		result.sizeOfPoints=firstPolygon.sizeOfPoints+secondPolygon.sizeOfPoints;
		result.pointsOfShapes=new Polygon::Point2D[result.sizeOfPoints];
		
		for(i=0; i<firstPolygon.sizeOfPoints; i++)
			result.pointsOfShapes[i]=firstPolygon.pointsOfShapes[i];
		for(i=firstPolygon.sizeOfPoints; i<result.sizeOfPoints; i++)
			result.pointsOfShapes[i]=secondPolygon.pointsOfShapes[i-firstPolygon.sizeOfPoints];
		
		return result;
	}
	
	ostream& operator <<(ostream& outs, const Polygon& tempPolygon)
	{
		outs<<"<polygon points=\"";
		for(int i=0; i<tempPolygon.sizeOfPoints; i++)
		{
			outs<<tempPolygon.pointsOfShapes[i].getLocX()<<",";
			outs<<tempPolygon.pointsOfShapes[i].getLocY()<<" ";
		}
		outs<<"\" stroke=\"black\" stroke-width=\"0.5\" ";
		outs<<"fill=\""<<tempPolygon.color<<"\"/>"<<endl;
			
		return outs;
	}
	
	Polygon::~Polygon()
	{
		delete []pointsOfShapes;
	}
}



