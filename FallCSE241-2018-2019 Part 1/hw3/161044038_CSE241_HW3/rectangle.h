//Can Beyaznar 161044038

#ifndef rectangle_h
#define rectangle_h

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Rectangle
{
	public:
		Rectangle(): width(0), height(0),Location_X(0),Location_Y(0), color("black"),perimeterOfShape(0), areaOfShape(0){/*default constructor*/}
		Rectangle(double width_I, double height_I);
		Rectangle(const Rectangle &copyRectangle);
		
		void setWidth(double width_I ) {width=width_I;	}
		void setHeight(double height_I) {height=height_I;	}
			
		double getWidth() const {return width; }
		double getHeight() const {return height; }
			
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
		Rectangle operator ++(); //Prefix version
		Rectangle operator ++(int); //Postfix version
		
		Rectangle operator --(); //Prefix version
		Rectangle operator --(int); //Postfix version
		
		friend const Rectangle operator +(const Rectangle& Rectangle_I, double Value);
		friend const Rectangle operator -(const Rectangle& Rectangle_I, double Value);
		
		friend bool operator ==(const Rectangle& firstRectangle,const Rectangle& secondRectangle ){return (firstRectangle.areaOfShape==secondRectangle.areaOfShape );}
		friend bool operator !=(const Rectangle& firstRectangle,const Rectangle& secondRectangle ){return !(firstRectangle.areaOfShape==secondRectangle.areaOfShape );}
		friend bool operator <=(const Rectangle& firstRectangle,const Rectangle& secondRectangle ){return (firstRectangle.areaOfShape<=secondRectangle.areaOfShape );}
		friend bool operator >=(const Rectangle& firstRectangle,const Rectangle& secondRectangle ){return (firstRectangle.areaOfShape>=secondRectangle.areaOfShape );}
		
		friend ostream& operator <<(ostream& outputStream, const Rectangle& Rectangle_I);
		
		/*static double getNewPerimeter();
		static double getNewArea();*/
		
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

#endif


