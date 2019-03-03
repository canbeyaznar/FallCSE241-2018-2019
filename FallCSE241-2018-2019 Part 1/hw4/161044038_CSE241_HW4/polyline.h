//Can Beyaznar 161044038

#ifndef POLYLINE_H
#define POLYLINE_H

#include <vector>

#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

using namespace Shapes_namespace;

namespace
{
	class Polyline
	{
		public:
			class Point2D
			{
				public:	
					Point2D(): location_X(0), location_Y(0){/*default constructor*/}
					Point2D(double tempX, double tempY): location_X(tempX), location_Y(tempY){	}
					
					void setLocations(double locX,double locY) {location_X=locX; location_Y=locY;	}
					void setLocX(double Val) {location_X=Val;	}
					void setLocY(double Val) {location_Y=Val;	}
					
					double getLocX() const {return location_X; }
					double getLocY() const {return location_Y; }
					
				private:
					double location_X;
					double location_Y;	
			};
			Polyline(): pointsOfShapes(nullptr), sizeOfPoints(0), color("grey"){/*default constructor*/}
			Polyline(const vector <Point2D> arrOfPoints);
			Polyline(const Rectangle Rectangle_I);
			Polyline(const Circle Circle_I);
			Polyline(const Triangle Triangle_I);
			
			//Big three
			Polyline(const Polyline& copyPolyline);
			~Polyline();
			Polyline& operator =(const Polyline& copyPolyline);
			
			void setColor(string color_I) {color=color_I;	}
			string getColor() const {return color;}
			
			//operator overload functions...
			friend bool operator ==(const Polyline& firstPolygon, const Polyline& secondPolygon);
			friend bool operator !=(const Polyline& firstPolygon, const Polyline& secondPolygon);
			
			const Point2D& operator [](int index);
			const Point2D& operator [](int index) const;
			
			friend const Polyline operator +(const Polyline& firstPolyline, const Polyline& secondPolyline );
			
			friend ostream& operator <<(ostream& outs, const Polyline& tempPolyline);
			
		private:
			Point2D *pointsOfShapes;
			int sizeOfPoints;
			string color;	
	};
}




#endif
