//Can Beyaznar 161044038

#ifndef composedshape_h
#define composedshape_h

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#include "polygon.h"

using namespace std;

namespace Shapes_namespace
{
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
			
			void optimalFit(Rectangle bigShape,Rectangle smallShape);
			void optimalFit(Rectangle bigShape,Circle smallShape);
			void optimalFit(Rectangle bigShape,Triangle smallShape);
			
			void optimalFit(Circle bigShape,Rectangle smallShape);
			void optimalFit(Circle bigShape,Circle smallShape);
			void optimalFit(Circle bigShape,Triangle smallShape);
			
			void optimalFit(Triangle bigShape,Rectangle smallShape);
			void optimalFit(Triangle bigShape,Circle smallShape);
			void optimalFit(Triangle bigShape,Triangle smallShape);
			
			
			void setContainer_sType(char value) {containerShape_type=value;	}
			void setInner_sType(char value) {innerShape_type=value; }
			
			
			char getContainer_sType() const {return containerShape_type;}
			char getInner_sType() const {return innerShape_type;}
			
			vector<Polygon> getAllShapesVector() const {return allShapes; }
			
			//operator overload function...
			ComposedShape operator +=(const Rectangle& Rectangle_I);
			ComposedShape operator +=(const Circle& Circle_I);
			ComposedShape operator +=(const Triangle& Triangle_I);
			
			const Polygon& operator [](int index);
			
			friend ostream& operator <<(ostream& outputStream, const ComposedShape& ComposedShape_I);
			
		private:
			char containerShape_type;
			char innerShape_type;
			
			vector<Polygon> allShapes;
			
			Rectangle containerRectangle;
			Rectangle innerRectangle;
			
			Circle containerCircle;
			Circle innerCircle;
			
			Triangle containerTriangle;
			Triangle innerTriangle;
	
	};

}




#endif



