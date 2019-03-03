
import java.awt.Graphics;
import java.util.Comparator;
import javax.swing.JPanel;
/**
 * 
 * @author Can Beyaznar
 *
 */
public class Triangle extends JPanel implements Shape {
	
	private double Edge;
	private double Height;
	private double Loc_X;
	private double Loc_Y;
	private double area;
	private double perimeter;
	private int rotate;
	private String Color;
	
	/**
	 * Default Constructor
	 */
	public Triangle() {
		Edge=0;
		Height=0;
		Loc_X=0;
		Loc_Y=0;
		area=0;
		perimeter= 0;
		rotate=0;
	}
	/**
	 * 
	 * @param inputWidth Width
	 */
	public Triangle(double inputWidth) {
		Edge=inputWidth;
		Height=(1.732*Edge/2);
		Loc_X=Edge/2;
		Loc_Y=0;
		area = (Edge*Height)/2;
		perimeter =  3* Edge;
		rotate=0;
	}
	/**
	 * 
	 * @param inputWidth Width
	 * @param inputHeight Height
	 */
	public Triangle(double inputWidth, double inputHeight) {
		Edge=inputWidth;
		Height=inputHeight;
		Loc_X=0;
		Loc_Y=0;
		area = (Edge*Height)/2;
		perimeter =  3* Edge;
		rotate=0;
	}
	/**
	 * 
	 * @param inputWidth Width
	 * @param inputHeight Height
	 * @param inputLocX Location X
	 * @param inputLocY Location Y
	 */
	public Triangle(double inputWidth, double inputHeight, double inputLocX, double inputLocY) {
		Edge=inputWidth;
		Height=inputHeight;
		Loc_X=inputLocX;
		Loc_Y=inputLocY;
		area = (Edge*Height)/2;
		perimeter =  3* Edge;
		rotate=0;
	}
	/**
	 * 
	 * @param tempTriangle Triangle parameter
	 */
	public  Triangle(Triangle tempTriangle) {
		Edge=tempTriangle.Edge;
		Height=tempTriangle.Height;
		Loc_X=tempTriangle.Loc_X;
		Loc_Y=tempTriangle.Loc_Y;
		Color=tempTriangle.Color;
		area = (Edge*Height)/2;
		perimeter =  3* Edge;
		rotate=tempTriangle.getRotate();
	}
	
	public void setEdge(double inputWidth) {
		Edge=inputWidth;
	}
	
	public double getEdge() {
		return Edge;
	}
	
	public void setHeight(double inputHeight) {
		Height=inputHeight;
	}
	
	public int getHeight() {
		return (int)Height;
	}
	
	public double getLocX() {
		return Loc_X;
	}
	public double getLocY() {
		return Loc_Y;
	}
	
	public void setLoc_X(double locX) {
		Loc_X = locX;
	}
	
	public void setLoc_Y(double locY) {
		Loc_Y = locY;
	}
	public void setRotate(int num) {
		rotate=num;
	}
	
	public int getRotate() {
		return rotate;
	}
	
	@Override
	public double area() {
		return area;
	}
	@Override
	public double perimeter() {
		return perimeter;
	}
	
	/* increment and decrement will return Shape object */
	@Override
	public Shape increment() {
		
		++Loc_X;
		++Loc_Y;
		return this;
		
	}
	@Override
	public Shape decrement() {
		
		if( !( (Loc_X-1)<0 | (Loc_Y-1)<0 ) )
		{
			--Loc_X;
			--Loc_Y;
		}
		return this;
	}
	
	public String getColor() {
		return Color;
	}

	@Override
	public void draw(Graphics g) {
		
		paintComponent(g);
	}
	/**
	 * 
	 */
	@Override
	public void paintComponent(Graphics g) {
		
		super.paintComponent(g);
		
		Triangle tempTriangle = new Triangle(this);
		
		int[] xPoints = new int[3];
		int[] yPoints = new int[3];
		
		if(tempTriangle.getRotate()==0)
		{
			xPoints[0]=(int)(tempTriangle.getLocX());
			yPoints[0]=	(int)(tempTriangle.getLocY());
			
			xPoints[1]=(int)(tempTriangle.getLocX()-tempTriangle.getEdge()/2);
			yPoints[1]=(int)(tempTriangle.getLocY()+tempTriangle.getHeight());
			
			xPoints[2]=(int)(tempTriangle.getLocX()+tempTriangle.getEdge()/2);
			yPoints[2]=(int)(tempTriangle.getLocY()+tempTriangle.getHeight());
		}
		else if(tempTriangle.getRotate()==1)
		{
			xPoints[0]=(int)(tempTriangle.getLocX()-tempTriangle.getEdge()/2);
			yPoints[0]=	(int)(tempTriangle.getLocY());
			
			xPoints[1]=(int)(tempTriangle.getLocX()+tempTriangle.getEdge()/2);
			yPoints[1]=(int)(tempTriangle.getLocY());
			
			xPoints[2]=(int)(tempTriangle.getLocX());
			yPoints[2]=(int)(tempTriangle.getLocY()+tempTriangle.getHeight());
		}
		else
			System.out.println("THERE IS A PROBLEM IN CODE!!");
		
		g.drawPolygon(xPoints, yPoints, 3);
		
	}
	/**
	 * 
	 */
	@Override
	public int compare(Shape o1, Shape o2) {
		if(o1.area()==o2.area())
			return 1;
		return 0;
	}
}
