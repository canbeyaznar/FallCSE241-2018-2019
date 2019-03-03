//Can Beyaznar 161044038

#include "composedshape.h"
#include "polygondyn.h"
#include "polygonvect.h"

using namespace Shapes_namespace;

//Global operator overload of Shape object...
ostream& operator <<(ostream& outputStream,Shape& Shape_I) {Shape_I.draw(outputStream); return outputStream;  }

void printAll(ostream& outputStream, vector<Shape*> ShapesVector);
void printPoly(ostream& outputStream, vector<Shape*> ShapesVector);
vector<Shape*> convertAll(vector<Shape*> ShapesVector);
void sortShapes(vector<Shape*> &ShapesVector);



int main()
{
	Rectangle r1(500,250),r2(9,17);
	Circle c1(100), c2(10);
	Triangle t1(500),t2(17);
	
	//**ComposedShape Examples**
	//CONTAINER RECTANGLE EXAMPLES...
	
	//for rectangle in rectangle
	ofstream File1;
	File1.open("output1.svg");
	File1<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x1(r1,r2);
	x1.optimalFit();
	File1<<x1;

	File1<<endl<<"</svg>";
	File1.close();

	//for circle in rectangle
	ofstream File2;
	File2.open("output2.svg");
	File2<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x2(r1,c2);
	x2.optimalFit();
	File2<<x2;

	File2<<endl<<"</svg>";
	File2.close();


	//for triangle in rectangle
	ofstream File3;
	File3.open("output3.svg");
	File3<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x3(r1,t2);
	x3.optimalFit();
	File3<<x3;

	File3<<endl<<"</svg>";
	File3.close();


	//CONTAINER CIRCLE EXAMPLES
	
	//for rectangle in circle
	ofstream File4;
	File4.open("output4.svg");
	File4<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x4(c1,r2);
	x4.optimalFit();
	File4<<x4;
	
	File4<<endl<<"</svg>";
	File4.close();


	//for circle in circle
	ofstream File5;
	File5.open("output5.svg");
	File5<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x5(c1,c2);
	x5.optimalFit();
	File5<<x5;
	
	File5<<endl<<"</svg>";
	File5.close();


	//for triangle in circle
	ofstream File6;
	File6.open("output6.svg");
	File6<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x6(c1,t2);
	x6.optimalFit();
	File6<<x6;
	
	File6<<endl<<"</svg>";
	File6.close();

	//CONTAINER TRIANGLE EXAMPLES
	
	//for rectangle in triangle
	ofstream File7;
	File7.open("output7.svg");
	File7<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x7(t1,r2);
	x7.optimalFit();
	File7<<x7;
	
	File7<<endl<<"</svg>";
	File7.close();


	//for circle in triangle
	ofstream File8;
	File8.open("output8.svg");
	File8<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x8(t1,c2);
	x8.optimalFit();
	File8<<x8;
	
	File8<<endl<<"</svg>";
	File8.close();


	//for triangle in triangle
	ofstream File9;
	File9.open("output9.svg");
	File9<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x9(t1,t2);
	x9.optimalFit();
	File9<<x9;
	
	File9<<endl<<"</svg>";
	File9.close();
	
	
	PolygonDyn p1(t1);
	PolygonVect p2(c1);
	
	vector<Shape*> ShapeVec;
	ShapeVec.push_back(&r1);
	ShapeVec.push_back(&r2);
	ShapeVec.push_back(&c1);
	ShapeVec.push_back(&p1);
	ShapeVec.push_back(&r2);
	ShapeVec.push_back(&t1);
	ShapeVec.push_back(&p2);
	ShapeVec.push_back(&t2);
	
	ofstream File10;
	File10.open("output10.svg");
	File10<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;

	cout<<"printAll function for ShapeVec..."<<endl<<endl;
	printAll(File10,ShapeVec);
			
	File10<<endl<<"</svg>";
	File10.close();
	
	cout<<"-----Vector of Shape Pointer-----"<<endl;
	for(int i=0; i<ShapeVec.size(); i++)
		cout<<i<<":"<<ShapeVec[i]->area()<<endl;
	cout<<endl;
	
	
	/* SORTED */
	sortShapes(ShapeVec);
	cout<<"-----Sorted-----"<<endl;
	for(int i=0; i<ShapeVec.size(); i++)
		cout<<i<<":"<<ShapeVec[i]->area()<<endl;
	
	/* For printPoly Function */
	ofstream File11;
	File11.open("output11.svg");
	File11<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;

	cout<<endl<<"printPoly function for ShapeVec..."<<endl<<endl;
	printPoly(File11,ShapeVec);
			
	File11<<endl<<"</svg>";
	File11.close();
	
	cout<<"-----convertAll-----"<<endl<<endl;
	/*For convertAll Function*/
	vector<Shape*> ShapeVec_2;
	ShapeVec_2.push_back(&r1);
	ShapeVec_2.push_back(&c1);
	ShapeVec_2.push_back(&t1);
	ShapeVec_2.push_back(&p1);
	ShapeVec_2.push_back(&r2);
	ShapeVec_2.push_back(&c2);
	ShapeVec_2.push_back(&p2);
	ShapeVec_2.push_back(&t2);
	
	
	ofstream File12;
	File12.open("output12.svg");
	File12<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	
	vector<Shape* > Result;
	Result=convertAll(ShapeVec_2);
	printPoly(File12, Result);
		
			
	File12<<endl<<"</svg>";
	File12.close();
	
	/**ComposedShape Class Example**/
	ofstream File13;
	File13.open("output13.svg");
	File13<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	cout<<"----------------------------------"<<endl<<endl;
	ComposedShape r5(r1,r2);
	r5.optimalFit();
	Shape *s5, *s6;
	Polygon *p5;
	s5=&r5;
	p5=(Polygon*) s5;
	File13<<*p5;
			
	File13<<endl<<"</svg>";
	File13.close();
	
	return 0;
}

void printAll(ostream& outputStream, vector<Shape*> ShapesVector)
{
	for(int i=0; i<ShapesVector.size(); i++)
		outputStream<<*ShapesVector[i];
}

void printPoly(ostream& outputStream, vector<Shape*> ShapesVector)
{
	for(int i=0; i<ShapesVector.size(); i++)
	{
		try
		{
			if(ShapesVector[i]->getType() == 'P')
			{
				throw(ShapesVector[i]);
			}
		}
		catch(Shape* ShapePtr)
		{
			outputStream<<*ShapePtr;
			cout<<i<<": is polygon"<<endl;
		}
		
	}
}

vector<Shape*> convertAll(vector<Shape*> ShapesVector)
{
	vector<Shape*> Result;
	vector<Polygon*> ResultPolygon;
	for(int i=0; i<ShapesVector.size(); i++)
	{
		try
		{
			if(ShapesVector[i]->getType() == 'P')
			{
				Polygon* tempPolygon = dynamic_cast<Polygon*>(ShapesVector[i]); //it will only work for Polygon abstract class... 
				ResultPolygon.push_back(tempPolygon);
			}
			else if(ShapesVector[i]->getType() == 'R')
			{
				Rectangle* newRectangle = (Rectangle* )(ShapesVector[i]);
				Polygon* tempPolygon = new PolygonVect(*newRectangle);
				ShapesVector.push_back(tempPolygon);
			}
			else if(ShapesVector[i]->getType() == 'C')
			{
				Circle* newCircle = (Circle* )(ShapesVector[i]);
				Polygon* tempPolygon = new PolygonVect(*newCircle);
				ShapesVector.push_back(tempPolygon);
			}
			else if(ShapesVector[i]->getType() == 'T')
			{
				Triangle* newTriangle = (Triangle* )(ShapesVector[i]);
				Polygon* tempPolygon = new PolygonVect(*newTriangle);
				ShapesVector.push_back(tempPolygon);
			}
			
			else if(ShapesVector[i]->getType() == 'c')
			{
				/*
				char ContainerType, InnerType;
				ComposedShape* newComposedShape = (ComposedShape* )(ShapesVector[i]);
				ContainerType=newComposedShape->getContainer_sType();
				InnerType=newComposedShape->getInner_sType();
				
				if(ContainerType == 'R')
				{
					
				}
				else if(ContainerType == 'C')
				{
					
				}
				else if(ContainerType == 'T')
				{
					
				}
				else
				{
					cerr<<"Unknown Shape Type!!"<<endl; 
				}
				
				ComposedShape* newComposedShape = (ComposedShape* )(ShapesVector[i]);
				Polygon* tempPolygon = new PolygonDyn(*newComposedShape);
				ShapesVector.push_back(tempPolygon);
				*/
			}
			else
			{
				throw('S');
			}
		}
		catch(char Val)
		{
			cerr<<"Unknown type in Shape Vector !!" <<endl;
			cerr<<"Your type is : "<<Val<<endl;
			exit(0);
		}
	}
	for(int i=0; i<ResultPolygon.size(); i++)
		Result.push_back(((Shape*)ResultPolygon[i]));
		
	return Result;
}

void sortShapes(vector<Shape*> &ShapesVector)
{
	for(int i=0; i<ShapesVector.size(); i++)
	{
		for(int j=0; j<ShapesVector.size(); j++)
		{
			if(ShapesVector[i]->area()<=ShapesVector[j]->area())
			{
				Shape* tempShape=ShapesVector[i];
				ShapesVector[i]=ShapesVector[j];
				ShapesVector[j]=tempShape;
			}
		}
	}	
}



