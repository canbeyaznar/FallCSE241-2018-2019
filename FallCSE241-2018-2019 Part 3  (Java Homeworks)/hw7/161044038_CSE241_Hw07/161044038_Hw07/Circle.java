
import java.awt.Graphics;
import javax.swing.JPanel;
/**
 * 
 * @author Can Beyaznar
 *
 */
public class Circle extends JPanel implements Shape {
	private double radius;
	private double Loc_X;
	private double Loc_Y;
	private double area;
	private double perimeter;
	private String Color;
	
	/**
	 * Default Constructor
	 */
	public Circle() {
		radius=0;
		Loc_X=0;
		Loc_Y=0;
		area=0;
		perimeter=0;
	}
	/**
	 * 
	 * @param inputRadius Radius 
	 */
	public Circle(double inputRadius) {
		radius=inputRadius;
		Loc_X=inputRadius;
		Loc_Y=inputRadius;
		area= Math.PI*radius*radius;
		perimeter = Math.PI*2*radius;
	}
	/**
	 * 
	 * @param inputRadius Radius
	 * @param inputLocX Location X
	 * @param inputLocY Location Y
	 */
	public Circle(double inputRadius, double inputLocX, double inputLocY) {
		radius=inputRadius;
		Loc_X=inputLocX;
		Loc_Y=inputLocY;
		area= Math.PI*radius*radius;
		perimeter = Math.PI*2*radius;
	}
	/**
	 * 
	 * @param tempCircle Circle parameter
	 */
	public  Circle(Circle tempCircle) {
		radius=tempCircle.radius;
		Loc_X=tempCircle.Loc_X;
		Loc_Y=tempCircle.Loc_Y;
		area=tempCircle.area;
		perimeter=tempCircle.area;
		Color=tempCircle.Color;
	}
	
	/**
	 * 
	 * @param inputRadius Radius
	 */
	public void setRadius(double inputRadius) {
		radius=inputRadius;
	}
	
	public double getRadius() {
		return radius;
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

	/**
	 * 
	 */
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
		g.drawOval((int)Loc_X-(int)radius, (int)Loc_Y-(int)radius, (int)radius*2, (int)radius*2);
		
	}

	@Override
	public int compare(Shape o1, Shape o2) {
		if(o1.area()==o2.area())
			return 1;
		return 0;
	}
}
