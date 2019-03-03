#ifndef SHAPES_NAMESPACE_POLYGONVECT_H
#define SHAPES_NAMESPACE_POLYGONVECT_H


#include "polygon.h"
#include <vector>
#include <string>

using namespace std;

namespace Shapes_namespace {

class PolygonVect : public Polygon {
  public:
    PolygonVect() {/*Default Constructor*/ };

    PolygonVect(Rectangle Rectangle_I) noexcept;
    PolygonVect(Circle Circle_I) noexcept;
    PolygonVect(Triangle Triangle_I) noexcept;

    PolygonVect(const PolygonVect & copyPolygon) noexcept;
    ~PolygonVect();
    PolygonVect& operator =(const PolygonVect & copyPolygon) noexcept;

    char getType() const noexcept {return 'P';}
    int getSize() const noexcept {return pointsOfShapes.size();}
    string getColor() const noexcept {return color;}
    
    double area() const noexcept {return AreaOfShape; }
    double perimeter() const noexcept {return AreaOfShape; }

    PolygonVect & operator ++() {/*EMPTY*/ } //Prefix version
    PolygonVect & operator ++(int ){/*EMPTY*/ } //Postfix version

    PolygonVect & operator --() {/*EMPTY*/ }//Prefix version
    PolygonVect & operator --(int ){/*EMPTY*/ }//Postfix version

    void draw(ostream & outs) noexcept;


  private:
    double AreaOfShape;
    double PerimeterOfShape;
    vector<Polygon*> pointsOfShapes;
    string color;

};

} // namespace Shapes_namespace
#endif
