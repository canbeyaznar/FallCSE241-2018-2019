import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JFrame;
/**
 * 
 * @author Can Beyaznar
 *
 */
public class PolygonVect extends Polygon {

	private double area;
	private double perimeter;
	private ArrayList<Polygon> pointsOfShapes;
	private String Color;
	
	/**
	 * Default Constructor
	 */
	public PolygonVect() {
		area=0;
		perimeter=0;
		pointsOfShapes=null;
		Color=null;
	}
	
	/**
	 * 
	 * @param Rectangle_I Rectangle
	 */
	public PolygonVect(Rectangle Rectangle_I) {
		
		Color=Rectangle_I.getColor();
		area=Rectangle_I.area();
		perimeter=Rectangle_I.perimeter();
		pointsOfShapes = new ArrayList<Polygon>();
		
		PolygonVect tempPoint=new PolygonVect();
		tempPoint.setLocations(Rectangle_I.getLocX(),Rectangle_I.getLocY());
		pointsOfShapes.add(tempPoint);

		tempPoint=new PolygonVect();
		tempPoint.setLocations(Rectangle_I.getLocX()+Rectangle_I.getWidth(),Rectangle_I.getLocY());
		pointsOfShapes.add(tempPoint);

		tempPoint=new PolygonVect();
		tempPoint.setLocations(Rectangle_I.getLocX()+Rectangle_I.getWidth(),Rectangle_I.getLocY()+Rectangle_I.getHeight());
		pointsOfShapes.add(tempPoint);

		tempPoint=new PolygonVect();
		tempPoint.setLocations(Rectangle_I.getLocX(),Rectangle_I.getLocY()+Rectangle_I.getHeight());
		pointsOfShapes.add(tempPoint);
		
		
	}
	
	/**
	 * 
	 * @param Circle_I Circle
	 */
	public PolygonVect(Circle Circle_I) {
		
		double PI=Math.PI;
		int tX=1,tY=-1;
		pointsOfShapes = new ArrayList<Polygon>();
		
		Color=Circle_I.getColor();
		area=Circle_I.area();
		perimeter=Circle_I.perimeter();
		
		PolygonVect tempPoint=new PolygonVect();
		tempPoint.setLocations(Circle_I.getLocX(),Circle_I.getLocY()-Circle_I.getRadius());
		pointsOfShapes.add(tempPoint);
		
		for(int i=1; i<100; i++)
		{
			tempPoint=new PolygonVect();
			tempPoint.setLocations(Circle_I.getLocX()+(tX*Circle_I.getRadius()*Math.sin(i*PI/50)),Circle_I.getLocY()+(tY*Circle_I.getRadius()*Math.cos(i*PI/50)) );
			pointsOfShapes.add(tempPoint);
		}
		
	}
    
	/**
	 * 
	 * @param Triangle_I Triangle
	 */
	public PolygonVect(Triangle Triangle_I) {
		
		Color=Triangle_I.getColor();
		area=Triangle_I.area();
		perimeter=Triangle_I.perimeter();
		pointsOfShapes = new ArrayList<Polygon>();
		
		PolygonVect tempPoint=new PolygonVect();
		if(Triangle_I.getRotate()==0)
		{
			tempPoint.setLocations(Triangle_I.getLocX(),Triangle_I.getLocY());
			pointsOfShapes.add(tempPoint);
			
			tempPoint=new PolygonVect();
			tempPoint.setLocations(Triangle_I.getLocX()-Triangle_I.getEdge()/2,Triangle_I.getLocY()+Triangle_I.getHeight());
			pointsOfShapes.add(tempPoint);
			
			tempPoint=new PolygonVect();
			tempPoint.setLocations(Triangle_I.getLocX()+Triangle_I.getEdge()/2,Triangle_I.getLocY()+Triangle_I.getHeight());
			pointsOfShapes.add(tempPoint);
		}
		else if(Triangle_I.getRotate()==1)
		{
			tempPoint.setLocations(Triangle_I.getLocX()-Triangle_I.getEdge()/2,Triangle_I.getLocY());
			pointsOfShapes.add(tempPoint);
			
			tempPoint=new PolygonVect();
			tempPoint.setLocations(Triangle_I.getLocX()+Triangle_I.getEdge()/2,Triangle_I.getLocY());
			pointsOfShapes.add(tempPoint);
			
			tempPoint=new PolygonVect();
			tempPoint.setLocations(Triangle_I.getLocX(),Triangle_I.getLocY()+Triangle_I.getHeight());
			pointsOfShapes.add(tempPoint);
		}
		else
			System.out.println("THERE IS A PROBLEM IN CODE!!");
	}
	
	/**
	 * 
	 * @param PolygonVect_I PolygonVect
	 */
	public PolygonVect(PolygonVect PolygonVect_I )
	{
		area=PolygonVect_I.area;
		perimeter=PolygonVect_I.perimeter;
		pointsOfShapes=PolygonVect_I.pointsOfShapes;
		Color=PolygonVect_I.Color;
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
	 * @return pointsOfShapes.size()
	 */
	public int Size() {
		return pointsOfShapes.size();
	}
	
	/**
	 * 
	 * @return pointsOfShapes
	 */
	public ArrayList<Polygon> getPoints() {
		return pointsOfShapes;
	}
	
	@Override
	public int compare(Shape o1, Shape o2) {
		
		if(o1.area()==o2.area())
			return 1;
		return 0;
	}

	@Override
	public double area() {
		return area;
	}

	@Override
	public double perimeter() {
		return perimeter;
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
		PolygonVect temp = new PolygonVect(this);

		int size = temp.Size();

		int[] xPoints = new int[size];
		int[] yPoints = new int[size];
		
		ArrayList<Polygon> points= new ArrayList<Polygon>(temp.getPoints());
		for(int i=0; i<points.size(); ++i)
		{
			xPoints[i]=(int)(points.get(i).getLocX());
			yPoints[i]=(int)(points.get(i).getLocY());
			
		}
		g.drawPolygon(xPoints, yPoints, size);
		
	}

}
