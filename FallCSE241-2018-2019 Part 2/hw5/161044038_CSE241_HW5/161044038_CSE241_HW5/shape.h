#ifndef SHAPES_NAMESPACE_SHAPE_H
#define SHAPES_NAMESPACE_SHAPE_H

#include <iostream>
#include <fstream>

using namespace std;

namespace Shapes_namespace {

class Shape {
  public:
    inline Shape() noexcept {/* Default Constructor */};

    virtual double area() const noexcept = 0;
    virtual double perimeter() const noexcept = 0;

    virtual char getType() const noexcept {return 'S';} //getType will help to find the class type of objects. For example
    								//Rectangle = R, Circle = C, Triangle = T, ComposedShape = c, PolygonDyn and PolygonVect = P 
    virtual void draw(ostream & outputStream) noexcept = 0;

    virtual Shape & operator ++() = 0; //Prefix version
    virtual Shape & operator ++(int ) = 0; //Postfix version

    virtual Shape & operator --() = 0;//Prefix version
    virtual Shape & operator --(int ) = 0;//Postfix version
	
    friend inline const bool operator ==(Shape & firstShape, Shape & secondShape) noexcept {return (firstShape.area()==secondShape.area()); };
    friend inline const bool operator !=(Shape & firstShape, Shape & secondShape) noexcept {return (firstShape.area()==secondShape.area()); };

};

}
#endif
