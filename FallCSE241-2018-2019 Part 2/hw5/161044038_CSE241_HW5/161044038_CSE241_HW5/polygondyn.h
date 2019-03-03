#ifndef SHAPES_NAMESPACE_POLYGONDYN_H
#define SHAPES_NAMESPACE_POLYGONDYN_H

#include "polygon.h"
#include <string>
using namespace std;

namespace Shapes_namespace {

	class PolygonDyn : public Polygon {
		
	  public:
	    PolygonDyn() noexcept {/*Default Constructor*/ };
	
	    PolygonDyn(Rectangle Rectangle_I) noexcept;
	    PolygonDyn(Circle Circle_I) noexcept;
	    PolygonDyn(Triangle Triangle_I) noexcept;
	
	    PolygonDyn(const PolygonDyn & copyPolygon) noexcept;
	    ~PolygonDyn();
	    PolygonDyn& operator =(const PolygonDyn & copyPolygon) noexcept;
	
	    char getType() const noexcept {return 'P';}
	    int getSize() const noexcept {return sizeOfPoints;}
	    string getColor() const noexcept {return color;}
	    
	    double area() const noexcept {return AreaOfShape; }
	    double perimeter() const noexcept {return AreaOfShape; }
	
	    PolygonDyn& operator ++() {/*EMPTY*/ } //Prefix version
	    PolygonDyn& operator ++(int ) {/*EMPTY*/ } //Postfix version
	
	    PolygonDyn& operator --() {/*EMPTY*/ }//Prefix version
	    PolygonDyn& operator --(int ) {/*EMPTY*/ }//Postfix version
	
	    void draw(ostream & outs) noexcept;
	
	
	  private:
	    int sizeOfPoints;
	    double AreaOfShape;
	    double PerimeterOfShape;
	    Polygon** pointsOfShapes;
	    string color;
	};

} 
#endif
