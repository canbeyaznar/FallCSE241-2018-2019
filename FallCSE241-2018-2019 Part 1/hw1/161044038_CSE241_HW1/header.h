#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

#ifndef header_h
#define header_h

#define PI 3.14


using namespace std;


enum class TypeofShapes{
	RECTANGLE,
	CIRCLE,
	TRIANGLE
};

struct Shapes{
	TypeofShapes type;
	double width;
	double height;
	double radius;
	double AreaofShape;
};
int findTypeofShape(char , Shapes &);

int EnterShapeInformation(Shapes &);


void drawRectangle(ofstream & ,double , double , string );


void drawRectangle(ofstream &File,double ,double ,double , double , string );

void drawCircle(ofstream &File,double , double  ,double , string );


void drawTriangle(ofstream &,double , double , double ,int ,string );

void drawHexagon(ofstream &,double , double , double ,string );

int testRectinRect(Shapes ,Shapes ,int &, int &);

int drawSmallRectin_Rect(ofstream &, Shapes ,Shapes ,double &,string );

int drawSmallCirclein_Rect(ofstream &, Shapes ,Shapes ,double &,string );

int drawSmallTrianglein_Rect(ofstream &, Shapes ,Shapes ,double &,string );

int drawSmallRectin_Circle(ofstream &, Shapes ,Shapes ,double &,string );


int drawSmallCirclesin_Circle(ofstream &, Shapes ,Shapes ,double &,string );


int drawSmallTrianglein_Circle(ofstream &, Shapes ,Shapes ,double &,string );

int drawSmallRectin_Triangle(ofstream &, Shapes ,Shapes ,double &,string );

int drawSmallTrianglein_Triangle(ofstream &, Shapes ,Shapes ,double &,string );

int drawSmallCirclein_Triangle(ofstream &, Shapes ,Shapes ,double &,string );

int drawShapes(ofstream & ,Shapes &);


int drawSmallshapes(ofstream &, Shapes &,Shapes &);

#endif
