//Can Beyaznar 161044038

#ifndef rectangle_h
#define rectangle_h

#include <iostream>
#include <string>
#include "shape.h"

using namespace std;

namespace Shapes_namespace
{
	class Rectangle:public Shape
	{
		public:
			Rectangle() noexcept: width(0), height(0),Location_X(0),Location_Y(0), color("yellow"),perimeterOfShape(0), areaOfShape(0){/*default constructor*/}
			Rectangle(double width_I, double height_I) noexcept;
			Rectangle(Rectangle& tempRectangle, double locX, double locY) noexcept {*this=tempRectangle; Location_X=locX; Location_Y=locY;	}
			
			void draw(ostream& outputStream) noexcept;
			
			void setWidth(double width_I ) noexcept {width=width_I;	}
			void setHeight(double height_I) noexcept {height=height_I;	}
				
			double getWidth() const noexcept {return width; }
			double getHeight() const noexcept {return height; }
				
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
			char getType() const noexcept {return type;}
			//operator overload functions...
			
			Rectangle& operator ++(); //Prefix version
			Rectangle& operator ++(int); //Postfix version
			
			Rectangle& operator --(); //Prefix version
			Rectangle& operator --(int); //Postfix version
			
			
			friend bool operator ==(const Rectangle& firstRectangle,const Rectangle& secondRectangle ) noexcept {return (firstRectangle.areaOfShape==secondRectangle.areaOfShape );}
			friend bool operator !=(const Rectangle& firstRectangle,const Rectangle& secondRectangle ) noexcept {return !(firstRectangle.areaOfShape==secondRectangle.areaOfShape );}
			friend bool operator <=(const Rectangle& firstRectangle,const Rectangle& secondRectangle ) noexcept {return (firstRectangle.areaOfShape<=secondRectangle.areaOfShape );}
			friend bool operator >=(const Rectangle& firstRectangle,const Rectangle& secondRectangle ) noexcept {return (firstRectangle.areaOfShape>=secondRectangle.areaOfShape );}
			
			friend ostream& operator <<(ostream& outputStream, const Rectangle& Rectangle_I) noexcept;
			
		private:
			string color;
			char type='R';
			double perimeterOfShape;
			double areaOfShape;
			double width;
			double height;
			double Location_X;
			double Location_Y;
			
	};
}



#endif





