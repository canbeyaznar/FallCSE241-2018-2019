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

using namespace std;

int testRectinRect(Rectangle backgroundShape,Rectangle smallShape); //this function compares swapped height and width of small shape to find maximum count...

class ComposedShape
{
	public: 
		class ShapeElem
		{
			public:
				enum class TypeofShapes{RECTANGLE, CIRCLE, TRIANGLE};
				
				void setShape(Rectangle tempRectangle) {type=TypeofShapes::RECTANGLE; Rectangle_I=tempRectangle; perimeterOfShape=tempRectangle.getPerimeter();  areaOfShape=tempRectangle.getArea();	}
				void setShape(Circle tempCircle) {type=TypeofShapes::CIRCLE; Circle_I=tempCircle; perimeterOfShape=tempCircle.getPerimeter();  areaOfShape=tempCircle.getArea();	}
				void setShape(Triangle tempTriangle) {type=TypeofShapes::TRIANGLE;  Triangle_I=tempTriangle; perimeterOfShape=tempTriangle.getPerimeter();  areaOfShape=tempTriangle.getArea();	}
				
				void setRectangle(Rectangle tempRectangle) {type=TypeofShapes::RECTANGLE; Rectangle_I=tempRectangle; perimeterOfShape=tempRectangle.getPerimeter();  areaOfShape=tempRectangle.getArea();	}
				void setCircle(Circle tempCircle) {type=TypeofShapes::CIRCLE; Circle_I=tempCircle; perimeterOfShape=tempCircle.getPerimeter();  areaOfShape=tempCircle.getArea();	}
				void setTriangle(Triangle tempTriangle) {type=TypeofShapes::TRIANGLE;  Triangle_I=tempTriangle; perimeterOfShape=tempTriangle.getPerimeter();  areaOfShape=tempTriangle.getArea();	}
				
				Rectangle getRectangle() const {return Rectangle_I;	}
				Circle getCircle() const {return Circle_I;	}
				Triangle getTriangle() const {return Triangle_I;	}
				
				double getPerimeter() const{return perimeterOfShape;}
				double getArea() const{return areaOfShape;}
				
				void setTypeInner(char Selection);
				TypeofShapes getTypeInner() const {return type; }
				
				//operator overload functions
				friend ostream& operator <<(ostream& outputStream, const ComposedShape::ShapeElem& ShapeElem_I);
				
				
			private:
				double perimeterOfShape;
				double areaOfShape;
				TypeofShapes type;
				Rectangle Rectangle_I;
				Circle Circle_I;
				Triangle Triangle_I;
		};
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
		
		void setContainer_sType(char value) {containerShape_type=value;	}
		void setInner_sType(char value) {innerShape_type=value; }
		void setSwapTheValues(int value) {swapTheValues=value;	}
		
		
		char getContainer_sType() const {return containerShape_type;}
		char getInner_sType() const {return innerShape_type;}
		
		vector<ShapeElem> getShapeElem() const {return innerShapes;}
		
		//operator overload function...
		ComposedShape operator +=(const Rectangle& Rectangle_I);
		ComposedShape operator +=(const Circle& Circle_I);
		ComposedShape operator +=(const Triangle& Triangle_I);
		
		ShapeElem operator [](int index){return this->innerShapes[index];	} 
		friend ostream& operator <<(ostream& outputStream, const ComposedShape& ComposedShape_I);
		
	private:
		char containerShape_type;
		char innerShape_type;
		int swapTheValues=-1; // it will use for swapping width and height.
		
		vector<ShapeElem> innerShapes;
		
		Rectangle containerRectangle;
		Rectangle innerRectangle;
		
		Circle containerCircle;
		Circle innerCircle;
		
		Triangle containerTriangle;
		Triangle innerTriangle;

};


#endif


