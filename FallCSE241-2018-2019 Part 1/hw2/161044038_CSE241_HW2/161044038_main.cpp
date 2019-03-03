//Can Beyaznar 161044038

#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "composedshape.h"

using namespace std;

int test(ofstream &File)
{
	char Selection;
	double tempValue, tempValue2;
	cout<<"Please enter the main container shape (R, C, T)"<<endl;
	cin>>Selection;
	
	
	if(Selection=='R' || Selection=='r')
	{
		
		cout<<"Please enter the width"<<endl;
		cin>>tempValue;
		
		cout<<"Please enter the height"<<endl;
		cin>>tempValue2;
		
		Rectangle containerRectangle(tempValue,tempValue2);
		containerRectangle.setColor("red");
		
		cout<<"Please enter the small shape (R, C, T)"<<endl;
		cin>>Selection;
		
		if(Selection=='R' || Selection=='r')
		{
			cout<<"Please enter the width"<<endl;
			cin>>tempValue;
			
			cout<<"Please enter the height"<<endl;
			cin>>tempValue2;
			
			Rectangle smallRectangle(tempValue,tempValue2);
			smallRectangle.setColor("green");
			
			ComposedShape shapes(containerRectangle,smallRectangle);
			shapes.optimalFit();
			shapes.draw(File);
			
		}
		
		else if(Selection=='C' || Selection=='c' )
		{
			cout<<"Please enter the radius"<<endl;
			cin>>tempValue;
			
			Circle smallCircle(tempValue);
			smallCircle.setColor("green");
			
			ComposedShape shapes(containerRectangle,smallCircle);
			shapes.optimalFit();
			shapes.draw(File);
			
		}
			
		
		else if(Selection=='T' || Selection=='t' )
		{
			cout<<"Please enter the edge"<<endl;
			cin>>tempValue;
			
			Triangle smallTriangle(tempValue);
			smallTriangle.setColor("green");
			
			ComposedShape shapes(containerRectangle,smallTriangle);
			shapes.optimalFit();
			shapes.draw(File);
		}
			
		else
		{
			cout<<"UNKNOWN COMMAND!!"<<endl;
			return -1;
		}
		
	}
	
	else if(Selection=='C' || Selection=='c' )
	{
		cout<<"Please enter the radius"<<endl;
		cin>>tempValue;
		
		Circle containerCircle(tempValue);
		containerCircle.setColor("red");
		
		cout<<"Please enter the small shape (R, C, T)"<<endl;
		cin>>Selection;
		
		if(Selection=='R' || Selection=='r')
		{
			cout<<"Please enter the width"<<endl;
			cin>>tempValue;
			
			cout<<"Please enter the height"<<endl;
			cin>>tempValue2;
			
			Rectangle smallRectangle(tempValue,tempValue2);
			smallRectangle.setColor("green");
			
			ComposedShape shapes(containerCircle,smallRectangle);
			shapes.optimalFit();
			shapes.draw(File);
			
		}
		
		else if(Selection=='C' || Selection=='c' )
		{
			cout<<"Please enter the radius"<<endl;
			cin>>tempValue;
			
			Circle smallCircle(tempValue);
			smallCircle.setColor("green");
			
			ComposedShape shapes(containerCircle,smallCircle);
			shapes.optimalFit();
			shapes.draw(File);
		}
			
		
		else if(Selection=='T' || Selection=='t' )
		{
			cout<<"Please enter the edge"<<endl;
			cin>>tempValue;
			
			Triangle smallTriangle(tempValue);
			smallTriangle.setColor("green");
			
			ComposedShape shapes(containerCircle,smallTriangle);
			shapes.optimalFit();
			shapes.draw(File);
		}
			
		else
		{
			cout<<"UNKNOWN COMMAND!!"<<endl;
			return -1;
		}
		
	}
		
	
	else if(Selection=='T' || Selection=='t' )
	{
		cout<<"Please enter the edge"<<endl;
		cin>>tempValue;
		
		Triangle containerTriangle(tempValue);
		containerTriangle.setColor("red");
		
		cout<<"Please enter the small shape (R, C, T)"<<endl;
		cin>>Selection;
		
		if(Selection=='R' || Selection=='r')
		{
			cout<<"Please enter the width"<<endl;
			cin>>tempValue;
			
			cout<<"Please enter the height"<<endl;
			cin>>tempValue2;
			
			Rectangle smallRectangle(tempValue,tempValue2);
			smallRectangle.setColor("green");
			
			ComposedShape shapes(containerTriangle,smallRectangle);
			shapes.optimalFit();
			shapes.draw(File);
		}
		
		else if(Selection=='C' || Selection=='c' )
		{
			cout<<"Please enter the radius"<<endl;
			cin>>tempValue;
			
			Circle smallCircle(tempValue);
			smallCircle.setColor("green");
			
			ComposedShape shapes(containerTriangle,smallCircle);
			shapes.optimalFit();
			shapes.draw(File);
		}
			
		
		else if(Selection=='T' || Selection=='t' )
		{
			cout<<"Please enter the edge"<<endl;
			cin>>tempValue;
			
			Triangle smallTriangle(tempValue);
			smallTriangle.setColor("green");
			
			ComposedShape shapes(containerTriangle,smallTriangle);
			shapes.optimalFit();
			shapes.draw(File);
		}
			
		else
		{
			cout<<"UNKNOWN COMMAND!!"<<endl;
			return -1;
		}
		
	}
		
	else
	{
		cout<<"UNKNOWN COMMAND!!"<<endl;
		return -1;
	}
	
}

int main()
{
	Rectangle r1(527,391), r2(23,16);
	Circle c1(200), c2(20);
	Triangle t1(250), t2(20);

	//CONTAINER RECTANGLE EXAMPLES...
	//for rectangle in rectangle
	ofstream File1;
	File1.open("output1.svg");
	File1<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	//test(File);
	ComposedShape x1(r1,r2);
	x1.optimalFit();
	x1.draw(File1);

	File1<<endl<<"</svg>";
	File1.close();


	//for circle in rectangle
	ofstream File2;
	File2.open("output2.svg");
	File2<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x2(r1,c2);
	x2.optimalFit();
	x2.draw(File2);

	File2<<endl<<"</svg>";
	File2.close();


	//for triangle in rectangle
	ofstream File3;
	File3.open("output3.svg");
	File3<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x3(r1,t2);
	x3.optimalFit();
	x3.draw(File3);

	File3<<endl<<"</svg>";
	File3.close();


	//CONTAINER CIRCLE EXAMPLES
	
	//for rectangle in circle
	ofstream File4;
	File4.open("output4.svg");
	File4<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x4(c1,r2);
	x4.optimalFit();
	x4.draw(File4);
	
	File4<<endl<<"</svg>";
	File4.close();


	//for circle in circle
	ofstream File5;
	File5.open("output5.svg");
	File5<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x5(c1,c2);
	x5.optimalFit();
	x5.draw(File5);
	
	File5<<endl<<"</svg>";
	File5.close();


	//for triangle in circle
	ofstream File6;
	File6.open("output6.svg");
	File6<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x6(c1,t2);
	x6.optimalFit();
	x6.draw(File6);
	
	File6<<endl<<"</svg>";
	File6.close();

	//CONTAINER TRIANGLE EXAMPLES
	
	//for rectangle in triangle
	ofstream File7;
	File7.open("output7.svg");
	File7<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x7(t1,r2);
	x7.optimalFit();
	x7.draw(File7);
	
	File7<<endl<<"</svg>";
	File7.close();


	//for circle in triangle
	ofstream File8;
	File8.open("output8.svg");
	File8<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x8(t1,c2);
	x8.optimalFit();
	x8.draw(File8);
	
	File8<<endl<<"</svg>";
	File8.close();


	//for triangle in triangle
	ofstream File9;
	File9.open("output9.svg");
	File9<<" <svg version=\" 1.1 \" baseProfile=\" full \""<<endl<<"width=\"100%\" height=\"100%\" "<<endl<<" xmlns=\"http://www.w3.org/2000/svg\">"<<endl<<endl;
	
	ComposedShape x9(t1,t2);
	x9.optimalFit();
	x9.draw(File9);
	
	File9<<endl<<"</svg>";
	File9.close(); 

	return 0;
}

