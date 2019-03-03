//Can Beyaznar 161044038

#include "header.h"

using namespace std;


int findTypeofShape(char Selection, Shapes &Shape_s)
{
	if(Selection=='R' || Selection=='r')
		Shape_s.type=TypeofShapes::RECTANGLE;
		
	else if(Selection=='C' || Selection=='c' )
		Shape_s.type=TypeofShapes::CIRCLE;
	
	else if(Selection=='T' || Selection=='t' )
		Shape_s.type=TypeofShapes::TRIANGLE;
	
	else
	{
		cout<<"UNKNOWN COMMAND!!"<<endl;
		return -1;
	}
	return 0;
}

int EnterShapeInformation(Shapes &Shape_s)
{
	if(Shape_s.type==TypeofShapes::RECTANGLE)
	{
		cout<<"Please enter the width"<<endl;
		cin>>Shape_s.width;
		
		cout<<"Please enter the height"<<endl;
		cin>>Shape_s.height;
		
		Shape_s.AreaofShape=Shape_s.height*Shape_s.width;
	}
		
	else if(Shape_s.type==TypeofShapes::CIRCLE)
	{
		cout<<"Please enter the radius"<<endl;
		cin>>Shape_s.radius;
		
		Shape_s.height=2*Shape_s.radius;
		Shape_s.width=2*Shape_s.radius;
		Shape_s.AreaofShape=3.14*pow(Shape_s.radius,2);
	}
	
	else if(Shape_s.type==TypeofShapes::TRIANGLE)
	{
		cout<<"Please enter the side length"<<endl;
		cin>>Shape_s.width;
		
		Shape_s.height=(Shape_s.width*sqrt(3)/2);
		Shape_s.AreaofShape=pow(Shape_s.width,2)*sqrt(3)/4;
		
	}
	
	else
		return -1;
	
	return 0;
}

//For the background shape
void drawRectangle(ofstream &File ,double Width, double Height, string color)
{
	File<<"<rect width=\""<<Width<<"\"";
	File<<" height=\""<<Height<<"\"";
	File<<" stroke=\"black\" stroke-width=\"0.5\""; //this is for see the shapes clearly
	File<<" fill=\""<<color<<"\"/>"<<endl<<endl;	
}

//for the small shapes
void drawRectangle(ofstream &File,double x,double y,double Width, double Height, string color)
{
	File<<"<rect x=\""<<x<<"\" "<<"y=\""<<y<<"\"";
	File<<" width=\""<<Width<<"\"";	
	File<<" height=\""<<Height<<"\"";
	File<<" stroke=\"black\" stroke-width=\"0.5\"";	//this is for see the shapes clearly
	File<<" fill=\""<<color<<"\"/>"<<endl<<endl;	
}

void drawCircle(ofstream &File,double cx, double cy ,double radius, string color)
{
	File<<"<circle cx=\""<<cx<<"\""<<" cy=\""<<cy<<"\"" <<" r=\""<<radius<<"\"";
	File<<" stroke=\"black\" stroke-width=\"0.5\"";	//this is for see the shapes clearly
	File<<" fill=\""<<color<<"\"/>"<<endl;
}

void drawTriangle(ofstream &File,double x, double y, double width,int rotate,string color)
{
	
	if(rotate==0)
	{
		File<<"<polygon points=\""<<x<<","<<y<<" "<<x+(width/2)<<","<<y+(width*sqrt(3)/2)<<" "<<x-(width/2)<<","<<y+(width*sqrt(3)/2)<<"\"";
		File<<" stroke=\"black\" stroke-width=\"0.5\""; //this is for see the shapes clearly
		File<<" fill=\""<<color<<"\"/>"<<endl<<endl;
	}
	else if(rotate==1)
	{
		File<<"<polygon points=\""<<x-(width/2)<<","<<y<<" "<<x<<","<<y+(width*sqrt(3)/2)<<" "<<x+(width/2)<<","<<y<<"\"";
		File<<" stroke=\"black\" stroke-width=\"0.5\"";
		File<<" fill=\""<<color<<"\"/>"<<endl<<endl;
	}
	else
		cout<<"THERE IS A PROBLEM IN CODE!!"<<endl;
	
}

/*void drawHexagon(ofstream &File,double x, double y, double width,string color)
{
	drawTriangle(File,x,y-(width*(sqrt(3)/2)),width,1,color );
	drawTriangle(File,x+width/2, y-(width*sqrt(3)/2),width,0,color );
	drawTriangle(File,x+width/2,y,width,1,color);
	drawTriangle(File,x,y,width,0,color );
	drawTriangle(File,x-width/2,y-(width*(sqrt(3)/2)),width,0,color);
	drawTriangle(File,x-width/2,y,width,1,color);
	
}*/

//This function will find which shape puts most with swapping width and height
int testRectinRect(Shapes backgroundShape,Shapes smallShape,int &count1, int &count2)
{
	int width, height;
	
	height=smallShape.height;
	width=smallShape.width;
	
	int NumberofColumns=backgroundShape.width/width;
	int NumberofRows=backgroundShape.height/height;
	int remainingWidth=(int)backgroundShape.width%width;
	int remainingHeight=(int)backgroundShape.height%height;
	
	count1=NumberofColumns*NumberofRows;
	if(height<=remainingWidth)
	{
		count1=count1+(int)(remainingWidth/smallShape.height)*(int)(backgroundShape.height/width);
	}
	else if(width<=remainingHeight)
	{
		count1=count1+(int)(remainingHeight/smallShape.width)*(int)(backgroundShape.width/height);
	}
	//swapped height and width to find maximum count
	height=smallShape.width;
	width=smallShape.height;
	
	NumberofColumns=backgroundShape.width/width;
	NumberofRows=backgroundShape.height/height;
	remainingWidth=(int)backgroundShape.width%width;
	remainingHeight=(int)backgroundShape.height%height;
	
	count2=NumberofColumns*NumberofRows;
	if(height<=remainingWidth)
	{
		count2=count2+(int)(remainingWidth/smallShape.height)*(int)(backgroundShape.height/width);

	}
	else if(width<=remainingHeight)
	{
		count2=count2+(int)(remainingHeight/smallShape.width)*(int)(backgroundShape.width/height);
	}
	if(count1>=count2)
		return 1;
	else if(count1<=count2)
		return 2;
	else 
		return -1;
}
int drawSmallRectin_Rect(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int count1=0, count2=0;
	int control=testRectinRect(backgroundShape,smallShape,count1,count2);
	double temp;
	if(control==2)
	{
		temp=smallShape.height;
		smallShape.height=smallShape.width;
		smallShape.width=temp;
	}
	
	
	int NumberofColumns=backgroundShape.width/smallShape.width;
	int NumberofRows=backgroundShape.height/smallShape.height;
	int remainingWidth=(int)backgroundShape.width%(int)smallShape.width;
	int remainingHeight=(int)backgroundShape.height%(int)smallShape.height;
	
	
	int i,j;
	
	for(i=0; i<NumberofRows; i++)
	{
		for(j=0; j<NumberofColumns; j++)
		{
			drawRectangle(File,(j*smallShape.width),(i*smallShape.height),smallShape.width,smallShape.height,color);
		}
	}
	if(smallShape.height<=remainingWidth )
	{
		for(i=0; i<(backgroundShape.height/smallShape.width); i++)
		{
			if((smallShape.width*(i))+smallShape.width<= backgroundShape.height)
			{
				for(j=0; j<(remainingWidth/smallShape.height); j++)
				{
					if(((smallShape.width*NumberofColumns)+(((j)*smallShape.height)))+smallShape.height<=backgroundShape.width)
					{
						drawRectangle(File,((smallShape.width*NumberofColumns)+(((j)*smallShape.height))),(smallShape.width*(i)),smallShape.height,smallShape.width,color);
					}		
				}
			}
		}					
	}
	else if(smallShape.width<=remainingHeight)
	{
			for(i=0; i<(backgroundShape.width/smallShape.height); i++)
			{
				if((smallShape.height*(i))+smallShape.height<=backgroundShape.width)
				{
					for(j=0; j<(remainingHeight/smallShape.width); j++)
					{
						if(((smallShape.height*NumberofRows)+(((j)*smallShape.width)))+smallShape.width<=backgroundShape.height)
						{
							drawRectangle(File,(smallShape.height*(i)),((smallShape.height*NumberofRows)+(((j)*smallShape.width))),smallShape.height,smallShape.width,color);
						}
									
					}
				}
					
			}
	}
	
	if(control==2)
	{
		temp=smallShape.height;
		smallShape.height=smallShape.width;
		smallShape.width=temp;
		
		Result=backgroundShape.AreaofShape-(smallShape.AreaofShape*count2);
		return count2;
	}	
	Result=backgroundShape.AreaofShape-(smallShape.AreaofShape*count1);
	return count1;
}

int drawSmallCirclein_Rect(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int y=0,x=0;
	int control=1;
	int count=0;
	while(control==1)
	{
			if( (2*smallShape.radius+smallShape.radius*2*x) > backgroundShape.width )
			{
				x=0;
				y++;
			}
					
			else if((2*smallShape.radius+smallShape.radius*2*y > backgroundShape.height))
			{
				control=0;
			}
					
			else
			{
				drawCircle(File,(smallShape.radius+smallShape.radius*2*x),(smallShape.radius+smallShape.radius*2*y),smallShape.radius,"green");
				x++;
				count++;
			}		
		
				
	}
	Result=(backgroundShape.AreaofShape)-(smallShape.AreaofShape*count);
	return count;
}

int drawSmallTrianglein_Rect(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int totalCount=0,countTriline=1,countLine=1; //**countTriline will take how many triangles put in one line, countLine will take how many lines used to put triangles...
	int control=0;
	while(control==0)
	{	
		if(smallShape.height*(countLine)>backgroundShape.height)
		{
			control=1;	
		}
		else
		{
			if((smallShape.width/2)*(double)(countTriline+1)>backgroundShape.width )
			{
				countLine++;
				totalCount=totalCount+countTriline-1;
				countTriline=1;
				
			}
			else
			{
				drawTriangle(File,(smallShape.width/2*countTriline),(backgroundShape.height-(countLine*smallShape.height)),smallShape.width,((countTriline-1+countLine-1)%2),color);
				countTriline++;
			}
		}
	}
	Result=backgroundShape.AreaofShape-(totalCount*smallShape.AreaofShape);
	return totalCount;
}

int drawSmallRectin_Circle(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int count=0;
	int lineControl=0;
	int x,y;
	x=0;
	y=0;
	cout<<endl<<"Please wait..."<<endl;
	while(y<2*backgroundShape.radius)
	{
		x=0;
		lineControl=0;
		while(x<2*backgroundShape.radius)
		{
			//**These conditions are looking that are corners of rectangles in the circle, if they are, drawrectangle...
			if(sqrt( pow((backgroundShape.radius-x),2)+ pow((backgroundShape.radius-y),2) )<=backgroundShape.radius)
			{
				if(sqrt( pow((backgroundShape.radius-(x+smallShape.width)),2)+ pow((backgroundShape.radius-y),2) )<=backgroundShape.radius)
				{
					if(sqrt( pow((backgroundShape.radius-(x)),2)+ pow((backgroundShape.radius-(y+smallShape.height)),2) )<=backgroundShape.radius)
					{
						if(sqrt( pow((backgroundShape.radius-(x+smallShape.width)),2)+ pow((backgroundShape.radius-(y+smallShape.height)),2) )<=backgroundShape.radius)
						{
						
								drawRectangle(File,x,y,smallShape.width,smallShape.height,color);
								x+=smallShape.width;
								lineControl=1;
								count++;
						}
						else
							x++;
					}
					else
							x++;
				}
				else
					x++;
					
			}
			else
				x++;	
		}
		if(lineControl==1)
		{
			y+=smallShape.height;
			lineControl=0;
		}
		else
			y++;
	}
	
	
	Result=backgroundShape.AreaofShape-(count*smallShape.AreaofShape);
	return count;
}



int drawSmallCirclesin_Circle(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	
	// **For the higher values this function works more slower than the other functions!!

	int i,j;
	unsigned int k;
	vector<double> location_X;
	vector<double> location_Y; // theese two vector will save all small circles' locations which put in the big circle
	int count=0;
	int control=0;

	cout<<endl<<"Please wait..."<<endl;
	for(i=0; i<=2*backgroundShape.radius; i++) //for y locations...
	{
		control=0;
		for(j=0; j<=2*backgroundShape.radius; j++) //for x locations...
		{
			control=0;
			if( sqrt( pow( (backgroundShape.radius-j),2 ) + pow( (backgroundShape.radius-i),2 ) ) + smallShape.radius <= backgroundShape.radius ) //this location is suitable to put a circle
			{
				if(count==0)
				{
					drawCircle(File,j, i, smallShape.radius ,color);
					location_X.push_back(j);
					location_Y.push_back(i);
					control=0;
					count++;
				}
					
				else
				{
					for(k=0; k<location_Y.size(); k++)
					{
						
						if( sqrt( pow( (location_X[k] - j),2 )+pow( (location_Y[k] - i),2 ) ) >=2*smallShape.radius ) //Finding distance between of the locations
						{
							control++;
						}
									
					}
					if(control>=count)
					{
						drawCircle(File,j, i, smallShape.radius ,color);
						location_X.push_back(j);
						location_Y.push_back(i);
						control=0;
						count++;
					}
				}
			}
		}
	}
	
	Result=backgroundShape.AreaofShape-smallShape.AreaofShape*count;
	return count;
	

	/* **There is a second way without vector, it works faster but it prints less than the other...
	
	int x=0,y=0;
	int count=0,countLine=1;
	int control=0,control2=0;
	
	
	while(backgroundShape.radius-(2*countLine*smallShape.radius)>=smallShape.radius)
	{
		while(y<2*backgroundShape.radius)
		{
			
			x=0;
			while(x<2*backgroundShape.radius)
			{
				if(sqrt( pow( (backgroundShape.radius-x),2 ) + pow( (backgroundShape.radius-y),2 ) ) + smallShape.radius <= backgroundShape.radius)
				{
					if(sqrt( pow( (backgroundShape.radius-x),2 ) + pow( (backgroundShape.radius-y),2 ) ) >= backgroundShape.radius-(2*countLine*smallShape.radius))
					{
						drawCircle(File,x, y, smallShape.radius ,color);
						x+=2*smallShape.radius;
						count++;
						control=1;
					}
					else
						x++;
				}
				else
					x++;
				
			}
			if(control==1)
			{
				y+=2*smallShape.radius;
				countLine++;
			}
				
			else
				y++;
		}
		countLine++;
	}*/
}

int drawSmallTrianglein_Circle(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int countLine=0;
	int countTriline=0;
	int Totalcount=0;
	double x=0,y=0;
	int control=0;
	
	cout<<endl<<"Please wait..."<<endl;
	while(y<2*backgroundShape.radius)
	{
		x=0;
		countTriline=0;
		while(x<2*backgroundShape.radius)
		{
			control=1;
			if((countTriline+countLine)%2==0)
			{
				if(sqrt(pow(x-backgroundShape.radius,2)+pow(y-backgroundShape.radius,2))<=backgroundShape.radius )
				{
					if(sqrt(pow((x-smallShape.width/2)-backgroundShape.radius,2)+pow((y+smallShape.height)-backgroundShape.radius,2))<=backgroundShape.radius && sqrt(pow((x+smallShape.width/2)-backgroundShape.radius,2)+pow((y+smallShape.height)-backgroundShape.radius,2))<=backgroundShape.radius)
					{
						drawTriangle(File,x,y,smallShape.width,((countTriline+countLine)%2),color);
						x+=smallShape.width/2;
						countTriline++;
						control=1;
						Totalcount++;
					}
					else
						x++;
					
				}
				else
					x++;
			}
			else if((countTriline+countLine)%2==1)
			{
				if(sqrt(pow((x-smallShape.width/2)-backgroundShape.radius,2)+pow(y-backgroundShape.radius,2))<=backgroundShape.radius && sqrt(pow((x+smallShape.width/2)-backgroundShape.radius,2)+pow(y-backgroundShape.radius,2))<=backgroundShape.radius)
				{
					if(sqrt(pow(x-backgroundShape.radius,2)+pow((y+smallShape.height)-backgroundShape.radius,2))<=backgroundShape.radius )
					{
						drawTriangle(File,x,y,smallShape.width,((countTriline+countLine)%2),color);
						x+=smallShape.width/2;
						countTriline++;
						control=1;
						Totalcount++;
					}
					else
						x++;
				}
				else
					x++;
				
			}
		}
		if(control==1)
		{
			y+=smallShape.height;
			countLine++;
			control=0;
		}
		else
			y++;
	}

	
	Result=backgroundShape.AreaofShape-(smallShape.AreaofShape*Totalcount);
	return Totalcount;
}

int drawSmallRectin_Triangle(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int totalCount=0, count1=0,count2=0;
	int countRectline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
	int i,j;
	int newHeight;
	int temp;
	
	//it will compare 2 possibility and find which will put triangles most...
	
	countLine=(backgroundShape.height-(smallShape.width/(2*sqrt(3))))/smallShape.height;
	for(i=0; i<countLine; i++)
	{
		newHeight=(backgroundShape.height-i*smallShape.height);
		countRectline=((2*newHeight/sqrt(3))-(2*smallShape.height/sqrt(3)))/smallShape.width;

		for(j=0; j<countRectline; j++)
			count1++;
		
	}
	//swapped values...
	temp=smallShape.width;
	smallShape.width=smallShape.height;
	smallShape.height=temp;
	
	countLine=(backgroundShape.height-(smallShape.width/(2*sqrt(3))))/smallShape.height;
	for(i=0; i<countLine; i++)
	{
		newHeight=(backgroundShape.height-i*smallShape.height);
		countRectline=((2*newHeight/sqrt(3))-(2*smallShape.height/sqrt(3)))/smallShape.width;

		for(j=0; j<countRectline; j++)
			count2++;
		
	}
	if(count2>=count1)
	{
		countLine=(backgroundShape.height-(smallShape.width/(2*sqrt(3))))/smallShape.height;
		for(i=0; i<countLine; i++)
		{
			newHeight=(backgroundShape.height-i*smallShape.height);
			countRectline=((2*newHeight/sqrt(3))-(2*smallShape.height/sqrt(3)))/smallShape.width;
	
			for(j=0; j<countRectline; j++)
			{
				drawRectangle(File,((i+1)*smallShape.height/sqrt(3))+smallShape.width*j,backgroundShape.height-((i+1)*smallShape.height),smallShape.width,smallShape.height,color );
				totalCount++;
			}
			
		}
	}
	else if(count1>count2)
	{
		temp=smallShape.width;
		smallShape.width=smallShape.height;
		smallShape.height=temp;
		
		countLine=(backgroundShape.height-(smallShape.width/(2*sqrt(3))))/smallShape.height;
		for(i=0; i<countLine; i++)
		{
			newHeight=(backgroundShape.height-i*smallShape.height);
			countRectline=((2*newHeight/sqrt(3))-(2*smallShape.height/sqrt(3)))/smallShape.width;
	
			for(j=0; j<countRectline; j++)
			{
				drawRectangle(File,((i+1)*smallShape.height/sqrt(3))+smallShape.width*j,backgroundShape.height-((i+1)*smallShape.height),smallShape.width,smallShape.height,color );
				totalCount++;
			}
			
		}
	}
	
	Result=backgroundShape.AreaofShape-(totalCount*smallShape.AreaofShape);
	return totalCount;
}

int drawSmallTrianglein_Triangle(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int count=0; //**countTriline will take how many triangles put in one line, countLine will take how many lines used to put triangles...
	int i,j;
	int totalLine=backgroundShape.height/smallShape.height;
	
	int totalTriinline;
	for(i=0; i<totalLine; i++)
	{
		totalTriinline=(backgroundShape.width/smallShape.width)-(i);
		for(j=0; j<2*totalTriinline-1; j++)
		{
			drawTriangle(File,(smallShape.width/2*(j+1))+i*smallShape.width/2,(backgroundShape.height-((i+1)*smallShape.height)),smallShape.width,((j)%2),color);
			count++;
		}
	}
	Result=backgroundShape.AreaofShape-(count*smallShape.AreaofShape);
	return count;
}

int drawSmallCirclein_Triangle(ofstream &File, Shapes backgroundShape,Shapes smallShape,double &Result,string color)
{
	int totalCount=0,countCircleline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
	int i,j;
	
	countLine=((backgroundShape.width*sqrt(3)/2)-smallShape.radius)/2*smallShape.radius;
	
	for(i=0; i<countLine; i++)
	{
		countCircleline=((((backgroundShape.width-smallShape.radius*sqrt(3))/smallShape.radius)+1)/2)-i;
		for(j=0; j<countCircleline; j++)
		{
			drawCircle(File,(smallShape.radius*sqrt(3))+(j*2*smallShape.radius)+i*smallShape.radius,(backgroundShape.height-((smallShape.radius)+(i*smallShape.radius*sqrt(3)))),smallShape.radius,color);
			totalCount++;
		}
	}
	
	Result=backgroundShape.AreaofShape-(totalCount*smallShape.AreaofShape);
	return totalCount;
}


int drawShapes(ofstream &File ,Shapes &backgroundShape)
{
	if(backgroundShape.type==TypeofShapes::RECTANGLE)
	{		
		drawRectangle(File,backgroundShape.width,backgroundShape.height,"red");		
	}
		
	else if(backgroundShape.type==TypeofShapes::CIRCLE)
	{
		drawRectangle(File,(2*backgroundShape.radius),(2*backgroundShape.radius),"grey"); //**firstly create a rectangle on background for circle
		drawCircle(File,backgroundShape.radius,backgroundShape.radius,backgroundShape.radius,"red");	
	}
	
	else if(backgroundShape.type==TypeofShapes::TRIANGLE)
	{
		drawTriangle(File,backgroundShape.width/2,0,backgroundShape.width,0,"red");
	}
		
	else
	{
		return -1;
	}
	
	return 0;	
}


int drawSmallshapes(ofstream &File, Shapes &backgroundShape,Shapes &smallShape)
{
	int Count=0;
	double Result;
	
	//There are 9 possibles
	if( backgroundShape.type==TypeofShapes::RECTANGLE ) //For rectangeles...
	{
		
		if(smallShape.type==TypeofShapes::RECTANGLE)
		{
			Count=drawSmallRectin_Rect(File,backgroundShape,smallShape,Result,"green");
		}
		
		else if(smallShape.type==TypeofShapes::CIRCLE)
		{	
			Count=drawSmallCirclein_Rect(File,backgroundShape,smallShape,Result,"green");
		}
		
		else if(smallShape.type==TypeofShapes::TRIANGLE)
		{
			Count=drawSmallTrianglein_Rect(File,backgroundShape,smallShape,Result,"green");
		}
		
		else
			return -1;
		
	}
	
	else if( backgroundShape.type==TypeofShapes::CIRCLE )
	{
		if(smallShape.type==TypeofShapes::CIRCLE)
		{	
			Count=drawSmallCirclesin_Circle(File,backgroundShape,smallShape,Result,"green");
			
		}
		else if(smallShape.type==TypeofShapes::RECTANGLE)	
		{
			Count=drawSmallRectin_Circle(File,backgroundShape,smallShape,Result,"green");
		}
		
		else if(smallShape.type==TypeofShapes::TRIANGLE)
		{
			Count=drawSmallTrianglein_Circle(File,backgroundShape,smallShape,Result,"green");
		}
		else
			return -1;
			
		
	}
	
	else if( backgroundShape.type==TypeofShapes::TRIANGLE )
	{
		if(smallShape.type==TypeofShapes::TRIANGLE)
		{
			Count=drawSmallTrianglein_Triangle(File,backgroundShape,smallShape,Result,"green");
		}
		
		else if(smallShape.type==TypeofShapes::CIRCLE)
		{
			Count=drawSmallCirclein_Triangle(File,backgroundShape,smallShape,Result,"green");
		}
		else if(smallShape.type==TypeofShapes::RECTANGLE)
		{
			Count=drawSmallRectin_Triangle(File,backgroundShape,smallShape,Result,"green");
		}
		else
			return -1;
	}
	
	else
		return -1;
	
	cout<<endl<<"I can fit at most "<<Count<<" small shapes into the main container. The empty area (red) incontainer is "<<Result<<"."<<endl<<endl;
	return 0;
}

