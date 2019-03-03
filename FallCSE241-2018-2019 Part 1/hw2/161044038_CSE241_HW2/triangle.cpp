//Can Beyaznar 161044038

#include "triangle.h"

using namespace std;

Triangle::Triangle(): edge(0),height(0){/* default contructor */}
Triangle::Triangle(double edge_I): edge(edge_I), height(edge_I*sqrt(3)/2),Location_X(edge_I/2),Location_Y(0),rotate(0){ }
Triangle::Triangle(const Triangle &copyTriangle)
{
	color=copyTriangle.color;
	edge=copyTriangle.edge;
	rotate=copyTriangle.rotate;
	height=copyTriangle.height;
	Location_X=copyTriangle.Location_X;
	Location_Y=copyTriangle.Location_Y;
	type=copyTriangle.type;
}
	
void Triangle::setEdge(double edge_I) {edge=edge_I; }
void Triangle::setHeight(double height_I) {height=height_I;}
void Triangle::setRotate(int rotate_I) {rotate=rotate_I;}
	
double Triangle::getEdge() const{return edge; }
double Triangle::getHeight() const{return height; }
int Triangle::getRotate() const{return rotate; }
	
void Triangle::setLoc_X(double locX) {Location_X=locX; }
void Triangle::setLoc_Y(double locY) {Location_Y=locY; }
	
double Triangle::getLoc_X() const {return Location_X; }
double Triangle::getLoc_Y() const {return Location_Y; }	
	
void Triangle::draw(ofstream &File)
{
	if(getEdge()>0)
	{
		if(rotate==0)
		{
			File<<"<polygon points=\""<<Location_X<<","<<Location_Y<<" "<<Location_X+(edge/2)<<","<<Location_Y+(getEdge()*sqrt(3)/2)<<" "<<Location_X-(edge/2)<<","<<Location_Y+(edge*sqrt(3)/2)<<"\"";
			File<<" stroke=\"black\" stroke-width=\"0.5\""; //this is for see the shapes clearly
			File<<" fill=\""<<color<<"\"/>"<<endl<<endl;
		}
		else if(rotate==1)
		{
			File<<"<polygon points=\""<<Location_X-(edge/2)<<","<<Location_Y<<" "<<Location_X<<","<<Location_Y+(edge*sqrt(3)/2)<<" "<<Location_X+(edge/2)<<","<<Location_Y<<"\"";
			File<<" stroke=\"black\" stroke-width=\"0.5\"";
			File<<" fill=\""<<color<<"\"/>"<<endl<<endl;
		}
		else
			cout<<"THERE IS A PROBLEM IN CODE!!"<<endl;
	}
	
}
	
void Triangle::setColor(string color_name) {color=color_name;	}
string Triangle::getColor() const {return color; }

