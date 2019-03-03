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
		Triangle();
		Triangle(double edge_I);
		Triangle(const Triangle &copyTriangle);
		
		void setEdge(double edge_I);
		void setHeight(double height_I);
		void setRotate(int rotate_I);
		
		double getEdge() const;
		double getHeight() const;
		int getRotate() const;
		
		void setLoc_X(double locX);
		void setLoc_Y(double locY);
		
		double getLoc_X() const;
		double getLoc_Y() const;	
		
		void draw(ofstream &File);
		
		void setColor(string color_name);
		string getColor() const;
	
	private:
		string color;
		char type='T';
		int rotate;
		double height;
		double edge;
		double Location_X;
		double Location_Y;
};


#endif

