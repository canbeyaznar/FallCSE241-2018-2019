//Can Beyaznar 161044038

#ifndef triangle_h
#define triangle_h

#include <iostream>
#include <string>
#include <cmath>
#include "shape.h"

using namespace std;

namespace Shapes_namespace
{
	class Triangle: public Shape
	{
		public:
			Triangle():edge(0),height(0),color("pink"){/* default contructor*/ }
			Triangle(double edge_I);
			Triangle(Triangle& tempTriangle,double locX, double locY): edge(tempTriangle.getEdge()),height(tempTriangle.getHeight()), Location_X(locX), Location_Y(locY),
																			color(tempTriangle.getColor()), perimeterOfShape(tempTriangle.perimeter()), areaOfShape(tempTriangle.area()), rotate(tempTriangle.getRotate()){ }
					
			void draw(ostream& outputStream) noexcept;													
			
			void setEdge(double edge_I) {edge=edge_I; }
			void setHeight(double height_I) {height=height_I;}
			void setRotate(int rotate_I) {rotate=rotate_I;}
				
			double getEdge() const{return edge; }
			double getHeight() const{return height; }
			int getRotate() const{return rotate; }
				
			void setLoc_X(double locX) {Location_X=locX; }
			void setLoc_Y(double locY) {Location_Y=locY; }
				
			double getLoc_X() const {return Location_X; }
			double getLoc_Y() const {return Location_Y; }		
			
			void setPerimeter(double perimeter_I) {perimeterOfShape=perimeter_I;	}
			void setArea(double area_I) {areaOfShape=area_I;	}
			
			double perimeter() const noexcept {return perimeterOfShape; }
			double area() const noexcept {return areaOfShape; }
			
			void setColor(string color_name) {color=color_name;	}
			string getColor() const {return color; }
			
			char getShapeType() const noexcept {return type;}
			char getType() const noexcept {return type;}
			//operator overload functions...
			
			Triangle& operator ++(); //Prefix version
			Triangle& operator ++(int); //Postfix version
			
			Triangle& operator --(); //Prefix version
			Triangle& operator --(int); //Postfix version
			
			
			friend bool operator ==(const Triangle& firstTriangle,const Triangle& secondTriangle ) noexcept {return (firstTriangle.areaOfShape==secondTriangle.areaOfShape );}
			friend bool operator !=(const Triangle& firstTriangle,const Triangle& secondTriangle ) noexcept {return !(firstTriangle.areaOfShape==secondTriangle.areaOfShape );}
			friend bool operator <=(const Triangle& firstTriangle,const Triangle& secondTriangle ) noexcept {return (firstTriangle.areaOfShape<=secondTriangle.areaOfShape );}
			friend bool operator >=(const Triangle& firstTriangle,const Triangle& secondTriangle ) noexcept {return (firstTriangle.areaOfShape>=secondTriangle.areaOfShape );}
			
			friend ostream& operator <<(ostream& outputStream, const Triangle& Triangle_I);
		
		private:
			string color;
			char type='T';
			int rotate;
			double perimeterOfShape;
			double areaOfShape;
			double height;
			double edge;
			double Location_X;
			double Location_Y;
	};
}


#endif





