import java.awt.Graphics;
//import java.awt.Point;
//import java.util.ArrayList;

import javax.swing.JFrame;
/**
 * 
 * @author Can Beyaznar
 *
 */
public class PolygonDyn extends Polygon {
	
	private Polygon[] pointsOfShapes;
	private int sizeOfPoints;
	private double area;
	private double perimeter;
	private String Color;
	
	/**
	 * Default Constructor
	 */
	public PolygonDyn() {
		sizeOfPoints=0;
		pointsOfShapes=null;
		area=0;
		perimeter=0;
	}
	
	/**
	 * 
	 * @param Shape_I
	 */
	PolygonDyn(Shape Shape_I){
		
		area=Shape_I.area();
		perimeter=Shape_I.perimeter();
		
		if(Shape_I instanceof Rectangle)
		{
			Rectangle Rectangle_I = new Rectangle((Rectangle) Shape_I);
			sizeOfPoints=4;
			pointsOfShapes=new Polygon[sizeOfPoints];
			
			Color=Rectangle_I.getColor();
			
			PolygonDyn tempPoint=new PolygonDyn();
			tempPoint.setLocations(Rectangle_I.getLocX(),Rectangle_I.getLocY());
			pointsOfShapes[0]=tempPoint;

			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Rectangle_I.getLocX()+Rectangle_I.getWidth(),Rectangle_I.getLocY());
			pointsOfShapes[1]=tempPoint;

			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Rectangle_I.getLocX()+Rectangle_I.getWidth(),Rectangle_I.getLocY()+Rectangle_I.getHeight());
			pointsOfShapes[2]=tempPoint;

			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Rectangle_I.getLocX(),Rectangle_I.getLocY()+Rectangle_I.getHeight());
			pointsOfShapes[3]=tempPoint;
		}
		
		else if(Shape_I instanceof Circle) {
			
			Circle Circle_I = new Circle((Circle) Shape_I);
			double PI=Math.PI;
			int tX=1,tY=-1;
			
			area=Circle_I.area();
			perimeter=Circle_I.perimeter();
			
			sizeOfPoints=100;
			pointsOfShapes=new Polygon[sizeOfPoints];
			Color=Circle_I.getColor();
			
			PolygonDyn tempPoint=new PolygonDyn();
			tempPoint.setLocations(Circle_I.getLocX(),Circle_I.getLocY()-Circle_I.getRadius());
			pointsOfShapes[0]=tempPoint;
			
			for(int i=1; i<sizeOfPoints; i++)
			{
				tempPoint=new PolygonDyn();
				tempPoint.setLocations(Circle_I.getLocX()+(tX*Circle_I.getRadius()*Math.sin(i*PI/50)),Circle_I.getLocY()+(tY*Circle_I.getRadius()*Math.cos(i*PI/50)) );
				pointsOfShapes[i]=tempPoint;
			}
			
		}
		
		else if(Shape_I instanceof Triangle) {
			
			Triangle Triangle_I = new Triangle((Triangle) Shape_I);
			
			area=Triangle_I.area();
			perimeter=Triangle_I.perimeter();
			
			sizeOfPoints=3;
			pointsOfShapes=new Polygon[sizeOfPoints];
			Color=Triangle_I.getColor();
			
			PolygonDyn tempPoint=new PolygonDyn();
			if(Triangle_I.getRotate()==0)
			{
				tempPoint.setLocations(Triangle_I.getLocX(),Triangle_I.getLocY());
				pointsOfShapes[0]=tempPoint;
				
				tempPoint=new PolygonDyn();
				tempPoint.setLocations(Triangle_I.getLocX()-Triangle_I.getEdge()/2,Triangle_I.getLocY()+Triangle_I.getHeight());
				pointsOfShapes[1]=tempPoint;
				
				tempPoint=new PolygonDyn();
				tempPoint.setLocations(Triangle_I.getLocX()+Triangle_I.getEdge()/2,Triangle_I.getLocY()+Triangle_I.getHeight());
				pointsOfShapes[2]=tempPoint;
			}
			else if(Triangle_I.getRotate()==1)
			{
				tempPoint.setLocations(Triangle_I.getLocX()-Triangle_I.getEdge()/2,Triangle_I.getLocY());
				pointsOfShapes[0]=tempPoint;
				
				tempPoint=new PolygonDyn();
				tempPoint.setLocations(Triangle_I.getLocX()+Triangle_I.getEdge()/2,Triangle_I.getLocY());
				pointsOfShapes[1]=tempPoint;
				
				tempPoint=new PolygonDyn();
				tempPoint.setLocations(Triangle_I.getLocX(),Triangle_I.getLocY()+Triangle_I.getHeight());
				pointsOfShapes[2]=tempPoint;
			}
			else
				System.out.println("THERE IS A PROBLEM IN CODE!!");
		}
		
		else
			System.out.println("THERE IS A PROBLEM IN CODE!!");
	}
	
	/**
	 * 
	 * @param Rectangle_I
	 */
	PolygonDyn(Rectangle Rectangle_I) {
		area=Rectangle_I.area();
		perimeter=Rectangle_I.perimeter();
		
		sizeOfPoints=4;
		pointsOfShapes=new Polygon[sizeOfPoints];
		Color=Rectangle_I.getColor();
		
		PolygonDyn tempPoint=new PolygonDyn();
		tempPoint.setLocations(Rectangle_I.getLocX(),Rectangle_I.getLocY());
		pointsOfShapes[0]=tempPoint;

		tempPoint=new PolygonDyn();
		tempPoint.setLocations(Rectangle_I.getLocX()+Rectangle_I.getWidth(),Rectangle_I.getLocY());
		pointsOfShapes[1]=tempPoint;

		tempPoint=new PolygonDyn();
		tempPoint.setLocations(Rectangle_I.getLocX()+Rectangle_I.getWidth(),Rectangle_I.getLocY()+Rectangle_I.getHeight());
		pointsOfShapes[2]=tempPoint;

		tempPoint=new PolygonDyn();
		tempPoint.setLocations(Rectangle_I.getLocX(),Rectangle_I.getLocY()+Rectangle_I.getHeight());
		pointsOfShapes[3]=tempPoint;
	}
	
	/**
	 * 
	 * @param Circle_I
	 */
    PolygonDyn(Circle Circle_I) {
    	
    	double PI=Math.PI;
		int tX=1,tY=-1;
		
		area=Circle_I.area();
		perimeter=Circle_I.perimeter();
		
		sizeOfPoints=100;
		pointsOfShapes=new Polygon[sizeOfPoints];
		Color=Circle_I.getColor();
		
		PolygonDyn tempPoint=new PolygonDyn();
		tempPoint.setLocations(Circle_I.getLocX(),Circle_I.getLocY()-Circle_I.getRadius());
		pointsOfShapes[0]=tempPoint;
		
		for(int i=1; i<sizeOfPoints; i++)
		{
			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Circle_I.getLocX()+(tX*Circle_I.getRadius()*Math.sin(i*PI/50)),Circle_I.getLocY()+(tY*Circle_I.getRadius()*Math.cos(i*PI/50)) );
			pointsOfShapes[i]=tempPoint;
		}
	}
    
    /**
     *
     * @param Triangle_I
     */
    PolygonDyn(Triangle Triangle_I) {
    	
    	area=Triangle_I.area();
		perimeter=Triangle_I.perimeter();
		
		sizeOfPoints=3;
		pointsOfShapes=new Polygon[sizeOfPoints];
		Color=Triangle_I.getColor();
		
		PolygonDyn tempPoint=new PolygonDyn();
		if(Triangle_I.getRotate()==0)
		{
			tempPoint.setLocations(Triangle_I.getLocX(),Triangle_I.getLocY());
			pointsOfShapes[0]=tempPoint;
			
			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Triangle_I.getLocX()-Triangle_I.getEdge()/2,Triangle_I.getLocY()+Triangle_I.getHeight());
			pointsOfShapes[1]=tempPoint;
			
			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Triangle_I.getLocX()+Triangle_I.getEdge()/2,Triangle_I.getLocY()+Triangle_I.getHeight());
			pointsOfShapes[2]=tempPoint;
		}
		else if(Triangle_I.getRotate()==1)
		{
			tempPoint.setLocations(Triangle_I.getLocX()-Triangle_I.getEdge()/2,Triangle_I.getLocY());
			pointsOfShapes[0]=tempPoint;
			
			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Triangle_I.getLocX()+Triangle_I.getEdge()/2,Triangle_I.getLocY());
			pointsOfShapes[1]=tempPoint;
			
			tempPoint=new PolygonDyn();
			tempPoint.setLocations(Triangle_I.getLocX(),Triangle_I.getLocY()+Triangle_I.getHeight());
			pointsOfShapes[2]=tempPoint;
		}
		else
			System.out.println("THERE IS A PROBLEM IN CODE!!");
	}
    /**
     * 
     * @param PolyDyn_I PolygonDyn
     */
    public PolygonDyn(PolygonDyn PolyDyn_I) {
    	
    	sizeOfPoints=PolyDyn_I.sizeOfPoints;
    	area=PolyDyn_I.area;
    	perimeter=PolyDyn_I.perimeter;
    	Color=PolyDyn_I.Color;
    	pointsOfShapes=new Polygon[sizeOfPoints];
    	pointsOfShapes=PolyDyn_I.pointsOfShapes;
    }
    /**
     * 
     * @return Color
     */
    public String getColor() {
    	return Color;
    }
	
    /**
     * 
     */
	public double area()
	{
		return area;
	}
	/**
	 * 
	 */
	public double perimeter()
	{
		return perimeter;
	}
	
	/**
	 * 
	 * @return sizeOfPoints
	 */
	public int Size() {
		return sizeOfPoints;
	}
	
	/**
	 * 
	 * @return pointsOfShapes
	 */
	public Polygon[] getPoints() {
		return pointsOfShapes;
	}
	
	@Override
	public Shape increment() {
		
		for(Polygon i : pointsOfShapes)
			i.increment();
		
		return this;
	}

	@Override
	public Shape decrement() {
		
		for(Polygon i : pointsOfShapes)
			i.decrement();
		
		return this;
	}
	@Override
	public void draw(Graphics g) {
		
		paintComponent(g);
	}
	@Override
	public void paintComponent(Graphics g) {
		
		super.paintComponent(g);
		
		int size=this.sizeOfPoints;
		
		int[] xPoints = new int[size];
		int[] yPoints = new int[size];
		
		int index=0;
		for(Polygon i : ( this.getPoints() ))
		{
			xPoints[index] = (int)(i.getLocX());
			yPoints[index] =(int)(i.getLocY());
			++index;
		}
		
		g.drawPolygon(xPoints, yPoints, size);	
		
	}
	@Override
	public int compare(Shape o1, Shape o2) {
		
		if(o1.area()==o2.area())
			return 1;
		return 0;
	}
	
}