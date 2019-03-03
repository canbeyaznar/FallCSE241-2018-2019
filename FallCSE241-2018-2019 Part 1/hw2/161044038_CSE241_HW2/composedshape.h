//Can Beyaznar 161044038

#ifndef composedshape_h
#define composedshape_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

int testRectinRect(Rectangle backgroundShape,Rectangle smallShape); //this function compares swapped height and width of small shape to find maximum count...

class ComposedShape
{
	public: 
		ComposedShape(){/*default constructor*/	}
		
		ComposedShape(Rectangle bigShape,Rectangle smallShape);
		ComposedShape(Rectangle bigShape,Circle smallShape);
		ComposedShape(Rectangle bigShape,Triangle smallShape);
		
		ComposedShape(Circle bigShape,Rectangle smallShape);
		ComposedShape(Circle bigShape,Circle smallShape);
		ComposedShape(Circle bigShape,Triangle smallShape);
		
		ComposedShape(Triangle bigShape,Rectangle smallShape);
		ComposedShape(Triangle bigShape,Circle smallShape);
		ComposedShape(Triangle bigShape,Triangle smallShape);
		
		void optimalFit();
		void draw(ofstream &File);
		
		void setContainer_sType(char value) {containerShape=value;	}
		void setInner_sType(char value) {innerShape=value; }
		void setSwapTheValues(int value) {swapTheValues=value;	}
		
		void setLocation_X(double x) {Location_X.push_back(x);	}
		void setLocation_Y(double y) {Location_Y.push_back(y);	}
		
		char getContainer_sType() const {return containerShape;}
		char getInner_sType() const {return innerShape;}
		
		vector<double> getLocation_X() const {return Location_X; }
		vector<double> getLocation_Y() const {return Location_Y; }
		
		
	private:
		char containerShape;
		char innerShape;
		int swapTheValues=-1; // it will use for swapping width and height.
		
		vector<double> Location_X;
		vector<double> Location_Y;
		
		Rectangle containerRectangle;
		Rectangle innerRectangle;
		
		Circle containerCircle;
		Circle innerCircle;
		
		Triangle containerTriangle;
		Triangle innerTriangle;

};


#endif

