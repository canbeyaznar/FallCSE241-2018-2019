//Can Beyaznar 161044038

#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

namespace Shapes_namespace
{
	class Polygon
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
			Polygon(): pointsOfShapes(nullptr), sizeOfPoints(0), color("grey"){/*default constructor*/}
			Polygon(const vector <Point2D> arrOfPoints);
			Polygon(const Rectangle Rectangle_I);
			Polygon(const Circle Circle_I);
			Polygon(const Triangle Triangle_I);
			
			//Big three
			Polygon(const Polygon& copyPolygon);
			~Polygon();
			Polygon& operator =(const Polygon& copyPolygon);
			
			void setColor(string color_I) {color=color_I;	}
			string getColor() const {return color;}		
			
			int getSize() const {return sizeOfPoints; }
			
			//operator overload functions...
			friend bool operator ==(const Polygon& firstPolygon, const Polygon& secondPolygon);
			friend bool operator !=(const Polygon& firstPolygon, const Polygon& secondPolygon);
			
			const Point2D& operator [](int index);
			const Point2D& operator [](int index) const;
			
			friend const Polygon operator +(const Polygon& firstPolygon, const Polygon& secondPolygon );
			
			friend ostream& operator <<(ostream& outs, const Polygon& tempPolygon);
			
		private:
			Point2D *pointsOfShapes;
			int sizeOfPoints;
			string color;	
	};
}




#endif
