//Can Beyaznar 161044038

#ifndef composedshape_h
#define composedshape_h

#include <fstream>
#include <vector>

#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

using namespace std;

namespace Shapes_namespace
{
	int testRectinRect(Rectangle& backgroundShape,Rectangle& smallShape); //this function compares swapped height and width of small shape to find maximum count...

	class ComposedShape: public Shape
	{
		public: 
			ComposedShape(){/*default constructor*/	}
			
			ComposedShape(Rectangle bigShape,Rectangle smallShape) noexcept;
			ComposedShape(Rectangle bigShape,Circle smallShape) noexcept;
			ComposedShape(Rectangle bigShape,Triangle smallShape) noexcept;
			
			ComposedShape(Circle bigShape,Rectangle smallShape) noexcept;
			ComposedShape(Circle bigShape,Circle smallShape) noexcept;
			ComposedShape(Circle bigShape,Triangle smallShape) noexcept;
			
			ComposedShape(Triangle bigShape,Rectangle smallShape) noexcept;
			ComposedShape(Triangle bigShape,Circle smallShape) noexcept;
			ComposedShape(Triangle bigShape,Triangle smallShape) noexcept;
			
			ComposedShape(vector<Shape*> Shape_I)  noexcept;
			
			void optimalFit()  noexcept;
			double area() const  noexcept;
			double perimeter() const  noexcept;
			
			void setContainer_sType(char value)  noexcept {containerShape_type=value;	}
			void setInner_sType(char value)  noexcept {innerShape_type=value; }
			
			char getContainer_sType() const  noexcept {return containerShape_type; }
			char getInner_sType() const  noexcept {return innerShape_type;}
			
			vector<Shape*> getVectorShapes() const noexcept {return vectorOfShapes; }
			char getType() const noexcept {return 'c';}
			
			//operator overload function...
			ComposedShape& operator +=(const Rectangle& Rectangle_I)  noexcept;
			ComposedShape& operator +=(const Circle& Circle_I)  noexcept;
			ComposedShape& operator +=(const Triangle& Triangle_I)  noexcept;
			
			
			ComposedShape& operator ++();
			ComposedShape& operator ++(int) ;
			
			ComposedShape& operator --();
			ComposedShape& operator --(int);
			
			friend const bool operator ==(ComposedShape& firstShape, ComposedShape& secondShape)  noexcept { }
			friend const bool operator !=(ComposedShape& firstShape, ComposedShape& secondShape)  noexcept { }
			
			Shape* operator [](int index) noexcept {return this->vectorOfShapes[index];	} 
			
			void draw(ostream& outputStream) noexcept {outputStream<<*this;	}
			friend ostream& operator <<(ostream& outputStream,const ComposedShape& ComposedShape_I)  noexcept;
			
		private:
			char containerShape_type;
			char innerShape_type;
		
			vector<Shape*> vectorOfShapes;
			
			Rectangle containerRectangle;
			Rectangle innerRectangle;
			
			Circle containerCircle;
			Circle innerCircle;
			
			Triangle containerTriangle;
			Triangle innerTriangle;
	
	};
}
#endif




