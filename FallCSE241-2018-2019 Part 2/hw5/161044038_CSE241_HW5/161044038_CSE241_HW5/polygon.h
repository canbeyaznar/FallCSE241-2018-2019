//Can Beyaznar 161044038

#ifndef POLYGON_H
#define POLYGON_H

#include "rectangle.h"
#include "circle.h"
#include "triangle.h"

namespace Shapes_namespace
{
	class Polygon: public Shape
	{
		public:
			Polygon()  noexcept: location_X(0), location_Y(0){/*default constructor*/}
			Polygon(double tempX, double tempY)  noexcept: location_X(tempX), location_Y(tempY){	}
					
			void setLocations(double locX,double locY) noexcept {location_X=locX; location_Y=locY;	}
			void setLocX(double Val) noexcept {location_X=Val;	}
			void setLocY(double Val) noexcept {location_Y=Val;	}
					
			double getLocX() const noexcept {return location_X; }
			double getLocY() const noexcept {return location_Y; }
		
		protected:
			double location_X;
			double location_Y;
	};
}
#endif


