//Can Beyaznar 161044038

#ifndef circle_h
#define circle_h

#include <iostream>
#include <string>

using namespace std;

namespace Shapes_namespace
{
	class Circle
	{
		public:
			Circle(): radius(0),Location_X(0),Location_Y(0), color("grey"),perimeterOfShape(0), areaOfShape(0){/* default contructor */}
			Circle(double radius_I);
			//Circle(const Circle tempCircle,double locX,double locY): radius(tempCircle.getRadius()), Location_X(locX), Location_Y(locY), color(tempCircle.getColor()), perimeterOfShape(tempCircle.getPerimeter()), areaOfShape(tempCircle.getArea()){	}
			Circle(const Circle tempCircle,double locX,double locY){*this=tempCircle; Location_X=locX; Location_Y=(locY); }
			Circle(const Circle &copyCircle);		
			
			void setRadius(double Radius_I) {radius=Radius_I; }
			double getRadius() const {return radius; }
					
			void setLoc_X(double locX) {Location_X=locX; }
			void setLoc_Y(double locY) {Location_Y=locY; }
					
			double getLoc_X() const {return Location_X; }
			double getLoc_Y() const {return Location_Y; }
			
			void setPerimeter(double perimeter_I) {perimeterOfShape=perimeter_I;	}
			void setArea(double area_I) {areaOfShape=area_I;	}
			
			double getPerimeter() const {return perimeterOfShape; }
			double getArea() const {return areaOfShape; }
			
			void setColor(string color_name) {color=color_name;	}
			string getColor() const {return color; }
			
			char getShapeType() const {return type;}
			
			//operator overload functions...
			Circle operator ++(); //Prefix version
			Circle operator ++(int); //Postfix version
			
			Circle operator --(); //Prefix version
			Circle operator --(int); //Postfix version
			
			friend const Circle operator +(const Circle& Circle_I, double Value);
			friend const Circle operator -(const Circle& Circle_I, double Value);
			
			friend bool operator ==(const Circle& firstCircle,const Circle& secondCircle ){return (firstCircle.areaOfShape==secondCircle.areaOfShape );}
			friend bool operator !=(const Circle& firstCircle,const Circle& secondCircle ){return !(firstCircle.areaOfShape==secondCircle.areaOfShape );}
			friend bool operator <=(const Circle& firstCircle,const Circle& secondCircle ){return (firstCircle.areaOfShape<=secondCircle.areaOfShape );}
			friend bool operator >=(const Circle& firstCircle,const Circle& secondCircle ){return (firstCircle.areaOfShape>=secondCircle.areaOfShape );}
			
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



