//Can Beyaznar 161044038

#include <iostream>
#include <fstream>

#include "header.h"


using namespace std;


int main()
{
	char selection;
	Shapes backgroundShape_s, smallShape_s;
	
	ofstream File;
	File.open("output.svg");
	File<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	//File<<" <svg> "<<endl<<endl;
	
	cout<<"Please enter the main container shape (R, C, T)"<<endl;
	cin>>selection;
	if(findTypeofShape(selection,backgroundShape_s) == -1)
		return -1;
	
	EnterShapeInformation(backgroundShape_s);
	drawShapes(File ,backgroundShape_s);
	
	cout<<"Please enter the small shape (R, C, T)"<<endl;
	cin>>selection;
	if(findTypeofShape(selection, smallShape_s) == -1)
		return -1;
	
	EnterShapeInformation(smallShape_s);
	drawSmallshapes(File,backgroundShape_s,smallShape_s);
	
	
	File<<endl<<"</svg>";
	File.close();
	
	return 0;
}
