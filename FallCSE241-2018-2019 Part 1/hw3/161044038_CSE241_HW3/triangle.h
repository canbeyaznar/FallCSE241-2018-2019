//Can Beyaznar 161044038

#ifndef triangle_h
#define triangle_h

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Triangle
{
	public:
		Triangle(): edge(0),height(0),color("pink"){/* default contructor*/ }
		Triangle(double edge_I);
		Triangle(const Triangle &copyTriangle);
		
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
		
		double getPerimeter() const {return perimeterOfShape; }
		double getArea() const {return areaOfShape; }
		
		void setColor(string color_name) {color=color_name;	}
		string getColor() const {return color; }
		
		char getShapeType() const {return type;}
		
		//operator overload functions...
		Triangle operator ++(); //Prefix version
		Triangle operator ++(int); //Postfix version
		
		Triangle operator --(); //Prefix version
		Triangle operator --(int); //Postfix version
		
		friend const Triangle operator +(const Triangle& Triangle_I, double Value);
		friend const Triangle operator -(const Triangle& Triangle_I, double Value);
		
		friend bool operator ==(const Triangle& firstTriangle,const Triangle& secondTriangle ){return (firstTriangle.areaOfShape==secondTriangle.areaOfShape );}
		friend bool operator !=(const Triangle& firstTriangle,const Triangle& secondTriangle ){return !(firstTriangle.areaOfShape==secondTriangle.areaOfShape );}
		friend bool operator <=(const Triangle& firstTriangle,const Triangle& secondTriangle ){return (firstTriangle.areaOfShape<=secondTriangle.areaOfShape );}
		friend bool operator >=(const Triangle& firstTriangle,const Triangle& secondTriangle ){return (firstTriangle.areaOfShape>=secondTriangle.areaOfShape );}
		
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


#endif


