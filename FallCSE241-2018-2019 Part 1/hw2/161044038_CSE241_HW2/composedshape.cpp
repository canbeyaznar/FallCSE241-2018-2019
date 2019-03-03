//Can Beyaznar 161044038

#include "composedshape.h"

using namespace std;

//if container shape is rectangle...	
ComposedShape::ComposedShape(Rectangle bigShape,Rectangle smallShape)
{
	containerShape='R';
	innerShape='R';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerRectangle=bigShape;
	innerRectangle=smallShape;	
}
ComposedShape::ComposedShape(Rectangle bigShape,Circle smallShape)
{
	containerShape='R';
	innerShape='C';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerRectangle=bigShape;
	innerCircle=smallShape;
}
ComposedShape::ComposedShape(Rectangle bigShape,Triangle smallShape)
{
	containerShape='R';
	innerShape='T';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerRectangle=bigShape;
	innerTriangle=smallShape;
}
//if container shape is circle...	

ComposedShape::ComposedShape(Circle bigShape,Rectangle smallShape)
{
	containerShape='C';
	innerShape='R';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerCircle=bigShape;
	innerRectangle=smallShape;
}
ComposedShape::ComposedShape(Circle bigShape,Circle smallShape)
{
	containerShape='C';
	innerShape='C';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerCircle=bigShape;
	innerCircle=smallShape;
}
ComposedShape::ComposedShape(Circle bigShape,Triangle smallShape)
{
	containerShape='C';
	innerShape='T';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerCircle=bigShape;
	innerTriangle=smallShape;
}

//if container shape is triangle...	
ComposedShape::ComposedShape(Triangle bigShape,Rectangle smallShape)
{
	containerShape='T';
	innerShape='R';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerTriangle=bigShape;
	innerRectangle=smallShape;
}
ComposedShape::ComposedShape(Triangle bigShape,Circle smallShape)
{
	containerShape='T';
	innerShape='C';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerTriangle=bigShape;
	innerCircle=smallShape;
}
ComposedShape::ComposedShape(Triangle bigShape,Triangle smallShape)
{
	
	containerShape='T';
	innerShape='T';
	bigShape.setColor("red");
	smallShape.setColor("green");
	containerTriangle=bigShape;
	innerTriangle=smallShape;
}

void ComposedShape::optimalFit()
{
	double result=0;
	int count=0;
	int control;
	int x,y;
	if(containerShape=='R')
	{
		cout<<"Main shape: Rectangle"<<endl;
		if(innerShape=='R')
		{
			cout<<"Small shape: Rectangle"<<endl;
			int control;
			int height=innerRectangle.getHeight();
			int width=innerRectangle.getWidth();
			control=testRectinRect(containerRectangle,innerRectangle);
			if(control==2) // if the second possibility is more than another it will swap width and height
			{
				height=innerRectangle.getWidth();
				width=innerRectangle.getHeight();
				swapTheValues=0;
			}
			int NumberofColumns=containerRectangle.getWidth()/width;
			int NumberofRows=containerRectangle.getHeight()/height;
			int remainingWidth=(int)containerRectangle.getWidth()%(int)width;
			int remainingHeight=(int)containerRectangle.getHeight()%(int)height;
			for(y=0; y<NumberofRows; y++)
			{
				for(x=0; x<NumberofColumns; x++)
				{
					setLocation_X(x*width);
					setLocation_Y(y*height);
					count++;
				}
			}
			if(height<=remainingWidth )
			{
				swapTheValues=Location_X.size(); //when draw function will work, swapTheValues helps to swap width and height easily
				for(y=0; y<(containerRectangle.getHeight()/width); y++)
				{
					if((width*(y))+width<= containerRectangle.getHeight())
					{
						for(x=0; x<(remainingWidth/height); x++)
						{
							if(((width*NumberofColumns)+(((x)*height))+height<=containerRectangle.getWidth()))
							{
								//drawRectangle(File,(innerRectangle.getWidth()*NumberofColumns)+(j*innerRectangle.getHeight()),(innerRectangle.getWidth()*i));
								setLocation_X((width*NumberofColumns)+(x*height));
								setLocation_Y((width*y));
								count++;
							}		
						}
					}
				}				
			}
			else if(width<=remainingHeight)
			{
					//cout<<width<<height
					swapTheValues=Location_X.size(); //when draw function will work, swapTheValues helps to swap width and height easily
					for(y=0; y<(containerRectangle.getWidth()/height); y++)
					{
						if((height*(y))+height<=containerRectangle.getWidth())
						{
							for(x=0; x<(remainingHeight/width); x++)
							{
								if(((height*NumberofRows)+(((x)*width)))+width<=containerRectangle.getHeight())
								{
									setLocation_X((innerRectangle.getHeight()*y));
									setLocation_Y((height*NumberofRows)+(x*width));
									count++;
								}
											
							}
						}
							
					}
			}
			result=containerRectangle.getHeight()*containerRectangle.getWidth()- count*innerRectangle.getHeight()*innerRectangle.getWidth();
			
		}
		else if(innerShape=='C')
		{
			cout<<"Small shape: Circle"<<endl;
			y=0;
			x=0;
			control=1;
			while(control==1)
			{
					if( (2*innerCircle.getRadius()+innerCircle.getRadius()*2*y) > containerRectangle.getWidth() )
					{
						y=0;
						x++;
					}
							
					else if((2*innerCircle.getRadius()+innerCircle.getRadius()*2*x > containerRectangle.getHeight()))
					{
						control=0;
					}
							
					else
					{
						setLocation_X(innerCircle.getRadius()+innerCircle.getRadius()*2*y);
						setLocation_Y(innerCircle.getRadius()+innerCircle.getRadius()*2*x);
						y++;
						count++;
					}		
				
						
			}
			result=containerRectangle.getHeight()*containerRectangle.getWidth()-3.14*count*innerCircle.getRadius()*innerCircle.getRadius();
			
		}
		else if(innerShape=='T')
		{
			cout<<"Small shape: Triangle"<<endl;
			int totalCount=0,countTriline=1,countLine=1; //**countTriline will take how many triangles put in one line, countLine will take how many lines used to put triangles...
			control=1;
			while(control==1)
			{	

				if(innerTriangle.getHeight()*(countLine)>containerRectangle.getHeight())
				{
					control=0;	
				}
				else
				{
					if((innerTriangle.getEdge()/2)*(double)(countTriline+1)>containerRectangle.getWidth() )
					{
						countLine++;
						totalCount=totalCount+countTriline-1;
						countTriline=1;
						
					}
					else
					{
						count++;
						setLocation_X(innerTriangle.getEdge()/2*countTriline);
						setLocation_Y(containerRectangle.getHeight()-(countLine*innerTriangle.getHeight()));
						countTriline++;
					}
				}
				result=containerRectangle.getHeight()*containerRectangle.getWidth()-count*innerTriangle.getHeight()*innerTriangle.getEdge()/2;
			}
		}
		
	}
	//containerShape=circle...
	else if(containerShape=='C')
	{
		cout<<"Main shape: Circle"<<endl;
		if(innerShape=='R')
		{
			cout<<"Small shape: Rectangle"<<endl;
			int lineControl=0;
			x=0;
			y=0;
			cout<<endl<<"Please wait..."<<endl;
			while(y<2*containerCircle.getRadius())
			{
				x=0;
				lineControl=0;
				while(x<2*containerCircle.getRadius())
				{
					//**These conditions are looking that are corners of rectangles in the circle, if they are, drawrectangle...
					if(sqrt( pow((containerCircle.getRadius()-x),2)+ pow((containerCircle.getRadius()-y),2) )<=containerCircle.getRadius())
					{
						if(sqrt( pow((containerCircle.getRadius()-(x+innerRectangle.getWidth())),2)+ pow((containerCircle.getRadius()-y),2) )<=containerCircle.getRadius())
						{
							if(sqrt( pow((containerCircle.getRadius()-(x)),2)+ pow((containerCircle.getRadius()-(y+innerRectangle.getHeight())),2) )<=containerCircle.getRadius())
							{
								if(sqrt( pow((containerCircle.getRadius()-(x+innerRectangle.getWidth())),2)+ pow((containerCircle.getRadius()-(y+innerRectangle.getHeight())),2) )<=containerCircle.getRadius())
								{
										setLocation_X(x);
										setLocation_Y(y);
										
										x+=innerRectangle.getWidth();
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
					y+=innerRectangle.getHeight();
					lineControl=0;
				}
				else
					y++;
			}
			result=3.14*containerCircle.getRadius()*containerCircle.getRadius()-count*innerRectangle.getWidth()*innerRectangle.getHeight();
	
		}
		else if(innerShape=='C')
		{
			cout<<"Small shape: Circle"<<endl;
			unsigned int k;
			int control=0;
		
			cout<<endl<<"Please wait..."<<endl;
			for(y=0; y<=2*containerCircle.getRadius(); y++) //for y locations...
			{
				control=0;
				for(x=0; x<=2*containerCircle.getRadius(); x++) //for x locations...
				{
					control=0;
					if( sqrt( pow( (containerCircle.getRadius()-x),2 ) + pow( (containerCircle.getRadius()-y),2 ) ) + innerCircle.getRadius() <= containerCircle.getRadius() ) //this location is suitable to put a circle
					{
						if(count==0)
						{
							setLocation_X(x);
							setLocation_Y(y);
							control=0;
							count++;
						}
							
						else
						{
							for(k=0; k<getLocation_X().size(); k++)
							{
								
								if( sqrt( pow( (getLocation_X()[k] - x),2 )+pow( (getLocation_Y()[k] - y),2 ) ) >=2*innerCircle.getRadius() ) //Finding distance between of the locations
								{
									control++;
								}
											
							}
							if(control>=count)
							{
								setLocation_X(x);
								setLocation_Y(y);
								control=0;
								count++;
							}
						}
					}
				}
			}
			result=3.14*containerCircle.getRadius()*containerCircle.getRadius()-3.14*count*innerCircle.getRadius()*innerCircle.getRadius();
			
		}
		else if(innerShape=='T')
		{
			cout<<"Small shape: Triangle"<<endl;
			int countLine=0;
			int countTriline=0;
			x=0,y=0;
			control=0;	
			cout<<endl<<"Please wait..."<<endl;
			while(y<2*containerCircle.getRadius())
			{
				
				x=0;
				countTriline=0;
				while(x<2*containerCircle.getRadius())
				{
					control=1;
					if((countTriline+countLine)%2==0)
					{
						if(sqrt(pow(x-containerCircle.getRadius(),2)+pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius() )
						{
							if(sqrt(pow((x-innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius() && sqrt(pow((x+innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius())
							{
								setLocation_X(x);
								setLocation_Y(y);
								x+=innerTriangle.getEdge()/2;
								countTriline++;
								control=1;
								count++;
							}
							else
								x++;
							
						}
						else
							x++;
					}
					else if((countTriline+countLine)%2==1)
					{
						if(sqrt(pow((x-innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius() && sqrt(pow((x+innerTriangle.getEdge()/2)-containerCircle.getRadius(),2)+pow(y-containerCircle.getRadius(),2))<=containerCircle.getRadius())
						{
							if(sqrt(pow(x-containerCircle.getRadius(),2)+pow((y+innerTriangle.getHeight())-containerCircle.getRadius(),2))<=containerCircle.getRadius() )
							{	
								setLocation_X(x);
								setLocation_Y(y);
								x+=innerTriangle.getEdge()/2;
								countTriline++;
								control=1;
								count++;
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
					y+=innerTriangle.getHeight();
					countLine++;
					control=0;
				}
				else
					y++;
			}
			result=3.14*containerCircle.getRadius()*containerCircle.getRadius()-(count*innerTriangle.getHeight()*innerTriangle.getEdge()/2);
		}
		
	}
	//containerShape=triangle...
	else if(containerShape=='T')
	{	
		cout<<"Container shape: Triangle"<<endl;
		if(innerShape=='R')
		{ 
			cout<<"Small shape: Rectangle"<<endl;
			int count1=0,count2=0;
			int countRectline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
			int i,j;
			double newHeight;
			int temp;
			
			double width,height;
			width=innerRectangle.getWidth();
			height=innerRectangle.getHeight();
			//it will compare 2 possibility and find which will put triangles most...
			
			countLine=(containerTriangle.getHeight()-(width/(2*sqrt(3))))/height;
			for(i=0; i<countLine; i++)
			{
				newHeight=(containerTriangle.getHeight()-i*height);
				countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
		
				for(j=0; j<countRectline; j++)
					count1++;
				
			}
			//swapped values...
			width=innerRectangle.getHeight();
			height=innerRectangle.getWidth();
			
			countLine=(containerTriangle.getHeight()-(innerRectangle.getWidth()/(2*sqrt(3))))/height;
			countLine=(containerTriangle.getHeight()-(width/(2*sqrt(3))))/height;
			for(i=0; i<countLine; i++)
			{
				newHeight=(containerTriangle.getHeight()-i*height);
				countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
		
				for(j=0; j<countRectline; j++)
					count2++;
				
			}
			if(count2>=count1)
			{
				setSwapTheValues(0);
				countLine=(containerTriangle.getHeight()-(innerRectangle.getWidth()/(2*sqrt(3))))/height;
				for(i=0; i<countLine; i++)
				{
					newHeight=(containerTriangle.getHeight()-i*height);
					countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
			
					for(j=0; j<countRectline; j++)
					{
						setLocation_X(((i+1)*height/sqrt(3))+width*j);
						setLocation_Y(containerTriangle.getHeight()-((i+1)*height));
						count++;
					}
					
				}
			}
			else if(count1>count2)
			{
				width=innerRectangle.getWidth();
				height=innerRectangle.getHeight();
				
				countLine=(containerTriangle.getHeight()-(width/(2*sqrt(3))))/height;
				for(i=0; i<countLine; i++)
				{
					newHeight=(containerTriangle.getHeight()-i*height);
					countRectline=((2*newHeight/sqrt(3))-(2*height/sqrt(3)))/width;
			
					for(j=0; j<countRectline; j++)
					{
						setLocation_X(((i+1)*height/sqrt(3))+width*j);
						setLocation_Y(containerTriangle.getHeight()-((i+1)*height));
						count++;
					}
					
				}
			}
			result=(containerTriangle.getHeight()*containerTriangle.getEdge()/2)-count*innerRectangle.getHeight()*innerRectangle.getWidth();
		}
		else if(innerShape=='C')
		{
			cout<<"Small shape: Circle"<<endl;
			int countCircleline,countLine; //**countCircleline will take how many Circles put in one line, countLine will take how many lines used to put Circles...
			
			countLine=((containerTriangle.getEdge()*sqrt(3)/2)-innerCircle.getRadius())/2*innerCircle.getRadius();
			
			for(y=0; y<countLine; y++)
			{

				countCircleline=((((containerTriangle.getEdge()-innerCircle.getRadius()*sqrt(3))/innerCircle.getRadius())+1)/2)-y;
				for(x=0; x<countCircleline; x++)
				{
					setLocation_X((innerCircle.getRadius()*sqrt(3))+(x*2*innerCircle.getRadius())+y*innerCircle.getRadius());
					setLocation_Y(containerTriangle.getHeight()-((innerCircle.getRadius())+(y*innerCircle.getRadius()*sqrt(3))));
					count++;
				}
			}
			
			result=(containerTriangle.getHeight()*containerTriangle.getEdge()/2)-3.14*count*innerCircle.getRadius()*innerCircle.getRadius();
		}
		else if(innerShape=='T')
		{			
			cout<<"Small shape: Triangle"<<endl;
			int totalLine=containerTriangle.getHeight()/innerTriangle.getHeight();		
			int totalTriinline;
			for(y=0; y<totalLine; y++)
			{
				totalTriinline=(containerTriangle.getEdge()/innerTriangle.getEdge())-(y);
				for(x=0; x<2*totalTriinline-1; x++)
				{
					setLocation_X((innerTriangle.getEdge()/2*(x+1))+y*innerTriangle.getEdge()/2);
					setLocation_Y(containerTriangle.getHeight()-((y+1)*innerTriangle.getHeight()));
					count++;
				}
			}
			result=(containerTriangle.getHeight()*containerTriangle.getEdge()/2)-count*(innerTriangle.getHeight()*innerTriangle.getEdge()/2);
		}
	}
	cout<<"I can fit at most "<<count<<" small shapes into main container. The empty area (red) in container is "<<result<<"."<<endl;
	cout<<endl<<"----------------------------------------------------------------------"<<endl<<endl;
}

void ComposedShape::draw(ofstream &File)
{
	int i,j,temp;
	int count=0;
	if(containerShape=='R')
	{
		containerRectangle.draw(File);
		
		if(innerShape=='R')
		{
			for(i=0; i<Location_X.size(); i++)
			{
				if(i==swapTheValues)
				{
					temp=innerRectangle.getWidth();
					innerRectangle.setWidth(innerRectangle.getHeight());
					innerRectangle.setHeight(temp);
				}
				
				innerRectangle.setLoc_X(Location_X[i]);
				innerRectangle.setLoc_Y(Location_Y[i]);
				innerRectangle.draw(File);	
			}
		}
		
		else if(innerShape=='C')
		{
			for(i=0; i<Location_X.size(); i++)
			{
				innerCircle.setLoc_X(Location_X[i]);
				innerCircle.setLoc_Y(Location_Y[i]);
				innerCircle.draw(File);
			}
		}
		
		else if(innerShape=='T')
		{	
			for(i=0; i<Location_X.size(); i++)
			{		
				innerTriangle.setRotate(i%2);
				innerTriangle.setLoc_X(Location_X[i]);
				innerTriangle.setLoc_Y(Location_Y[i]);
				innerTriangle.draw(File);
			}
			
		}
		
	}
	else if(containerShape=='C')
	{
		containerCircle.draw(File);
		if(innerShape=='R')
		{
			for(i=0; i<Location_X.size(); i++)
			{	
				innerRectangle.setLoc_X(Location_X[i]);
				innerRectangle.setLoc_Y(Location_Y[i]);
				innerRectangle.draw(File);		
			}
		}
		else if(innerShape=='C')
		{
			for(i=0; i<Location_X.size(); i++)
			{	
				innerCircle.setLoc_X(Location_X[i]);
				innerCircle.setLoc_Y(Location_Y[i]);
				innerCircle.draw(File);	
			}
		}
		else if(innerShape=='T')
		{
			int countLine=0;
			int countTriLine=0;
			double temp=Location_Y[0];
			for(i=0; i<Location_X.size(); i++)
			{	
				if(temp!=Location_Y[i])
				{
					countLine++;
					countTriLine=0;
					temp=Location_Y[i];
				}
				innerTriangle.setRotate((countTriLine+countLine)%2);
				innerTriangle.setLoc_X(Location_X[i]);
				innerTriangle.setLoc_Y(Location_Y[i]);
				innerTriangle.draw(File);
				countTriLine++;
			}
		}
		
	}
	else if(containerShape=='T')
	{
		containerTriangle.draw(File);
		if(innerShape=='R')
		{
			for(i=0; i<Location_X.size(); i++)
			{
				if(i==swapTheValues)
				{
					temp=innerRectangle.getWidth();
					innerRectangle.setWidth(innerRectangle.getHeight());
					innerRectangle.setHeight(temp);
				}
				
				innerRectangle.setLoc_X(Location_X[i]);
				innerRectangle.setLoc_Y(Location_Y[i]);
				innerRectangle.draw(File);
				
				
			}
		}
		else if(innerShape=='C')
		{
			for(i=0; i<Location_X.size(); i++)
			{	
				innerCircle.setLoc_X(Location_X[i]);
				innerCircle.setLoc_Y(Location_Y[i]);
				innerCircle.draw(File);
			}
		}
		else if(innerShape=='T')
		{
			int countTriLine=0;
			double temp=Location_Y[0];
			for(i=0; i<Location_X.size(); i++)
			{	
				if(temp!=Location_Y[i])
				{
					innerTriangle.setRotate(0);
					temp=Location_Y[i];
					countTriLine++;
				}		
				else
					innerTriangle.setRotate((countTriLine)%2);
					
				innerTriangle.setLoc_X(Location_X[i]);
				innerTriangle.setLoc_Y(Location_Y[i]);
				innerTriangle.draw(File);
				countTriLine++;
			}
		}
	}
	
	
}
int testRectinRect(Rectangle backgroundShape,Rectangle smallShape) //this function compares swapped height and width of small shape to find maximum count...
{
	int width, height;
	int count1=0, count2=0;
	
	height=smallShape.getHeight();
	width=smallShape.getWidth();
	
	int NumberofColumns=backgroundShape.getWidth()/width;
	int NumberofRows=backgroundShape.getHeight()/height;
	int remainingWidth=(int)backgroundShape.getWidth()%width;
	int remainingHeight=(int)backgroundShape.getHeight()%height;
	
	count1=NumberofColumns*NumberofRows;
	if(height<=remainingWidth)
	{
		count1=count1+(int)(remainingWidth/smallShape.getHeight())*(int)(backgroundShape.getHeight()/width);
	}
	else if(width<=remainingHeight)
	{
		count1=count1+(int)(remainingHeight/smallShape.getWidth())*(int)(backgroundShape.getWidth()/height);
	}
	//swapped height and width to find maximum count
	height=smallShape.getWidth();
	width=smallShape.getHeight();
	
	NumberofColumns=backgroundShape.getWidth()/width;
	NumberofRows=backgroundShape.getHeight()/height;
	remainingWidth=(int)backgroundShape.getWidth()%width;
	remainingHeight=(int)backgroundShape.getHeight()%height;
	
	count2=NumberofColumns*NumberofRows;
	if(height<=remainingWidth)
	{
		count2=count2+(int)(remainingWidth/smallShape.getHeight())*(int)(backgroundShape.getHeight()/width);

	}
	else if(width<=remainingHeight)
	{
		count2=count2+(int)(remainingHeight/smallShape.getWidth())*(int)(backgroundShape.getWidth()/height);
	}
	if(count1>=count2)
		return 1;
	else if(count1<count2)
		return 2;
	else 
		return -1;
}

