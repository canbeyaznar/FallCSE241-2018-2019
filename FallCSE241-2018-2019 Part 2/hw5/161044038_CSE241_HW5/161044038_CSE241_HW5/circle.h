//Can Beyaznar 161044038

#ifndef circle_h
#define circle_h

#include <iostream>
#include <string>
#include "shape.h"

using namespace std;

namespace Shapes_namespace
{
	class Circle: public Shape
	{
		public:
			Circle() noexcept:  radius(0),Location_X(0),Location_Y(0), color("grey"),perimeterOfShape(0), areaOfShape(0){/* default contructor */}
			Circle(double radius_I) noexcept; 
			Circle(Circle& tempCircle,double locX,double locY) noexcept: radius(tempCircle.getRadius()), Location_X(locX), Location_Y(locY), color(tempCircle.getColor()), perimeterOfShape(tempCircle.perimeter()), areaOfShape(tempCircle.area()){	}
			
			void draw(ostream& outputStream) noexcept;
			
			void setRadius(double Radius_I) noexcept {radius=Radius_I; }
			double getRadius() const noexcept {return radius; }
					
			void setLoc_X(double locX) noexcept {Location_X=locX; }
			void setLoc_Y(double locY) noexcept {Location_Y=locY; }
					
			double getLoc_X() const noexcept {return Location_X; }
			double getLoc_Y() const noexcept {return Location_Y; }
			
			void setPerimeter(double perimeter_I) noexcept {perimeterOfShape=perimeter_I;	}
			void setArea(double area_I) noexcept {areaOfShape=area_I;	}
			
			double perimeter() const noexcept {return perimeterOfShape; }
			double area() const noexcept {return areaOfShape; }
			
			void setColor(string color_name) noexcept {color=color_name;	}
			string getColor() const noexcept {return color; }
			
			char getShapeType() const noexcept {return type;}
			char getType() const noexcept {return type; }
			//operator overload functions...
			
			Circle& operator ++(); //Prefix version
			Circle& operator ++(int); //Postfix version
			
			Circle& operator --(); //Prefix version
			Circle& operator --(int); //Postfix version
			

			
			friend bool operator ==(const Circle& firstCircle,const Circle& secondCircle ) noexcept {return (firstCircle.areaOfShape==secondCircle.areaOfShape );}
			friend bool operator !=(const Circle& firstCircle,const Circle& secondCircle ) noexcept {return !(firstCircle.areaOfShape==secondCircle.areaOfShape );}
			friend bool operator <=(const Circle& firstCircle,const Circle& secondCircle ) noexcept {return (firstCircle.areaOfShape<=secondCircle.areaOfShape );}
			friend bool operator >=(const Circle& firstCircle,const Circle& secondCircle ) noexcept {return (firstCircle.areaOfShape>=secondCircle.areaOfShape );}
			
			friend ostream& operator <<(ostream& outputStream, const Circle& Circle_I);
			
		private:
			string color;
			char type='C';
			double perimeterOfShape;
			double areaOfShape;
			double radius;
			double Location_X;
			double Location_Y;
	};
}


#endif





