
import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * 
 * @author Can Beyaznar
 *
 */

public class Rectangle extends JPanel implements Shape {
	
	private int Width;
	private int Height;
	private double Loc_X;
	private double Loc_Y;
	private double area;
	private double perimeter;
	private String Color;
	
	/**
	 * Default Constructor
	 */
	public Rectangle() {
		Width=0;
		Height=0;
		Loc_X=0;
		Loc_Y=0;
		area=0;
		perimeter=0;
	}
	
	/**
	 * 
	 * @param inputWidth Width Parameter
	 * @param inputHeight Height Parameter
	 */
	public Rectangle(int inputWidth, int inputHeight) {
		Width=inputWidth;
		Height=inputHeight;
		Loc_X=0;
		Loc_Y=0;
		area=Width*Height;
		perimeter= 2*( Width+Height );
	}
	
	/**
	 * 
	 * @param inputWidth Width Parameter
	 * @param inputHeight Height Parameter
	 * @param inputLocX Location X parameter
	 * @param inputLocY Location Y parameter
	 */
	public Rectangle(int inputWidth, int inputHeight, double inputLocX, double inputLocY) {
		Width=inputWidth;
		Height=inputHeight;
		Loc_X=inputLocX;
		Loc_Y=inputLocY;
		area=Width*Height;
		perimeter= 2*( Width+Height );
	}
	
	/**
	 * Copy Constructor
	 * @param tempRectangle Rectangle Parameter for Copy
	 */
	public  Rectangle(Rectangle tempRectangle) {
		Width=tempRectangle.Width;
		Height=tempRectangle.Height;
		Loc_X=tempRectangle.Loc_X;
		Loc_Y=tempRectangle.Loc_Y;
		Color=tempRectangle.Color;
		area=Width*Height;
		perimeter= 2*( Width+Height );
	}
	
	/**
	 * setWidth function
	 * @param inputWidth Width Parameter
	 */
	public void setWidth(int inputWidth) {
		Width=inputWidth;
	}
	
	/**
	 * getWidth function
	 */
	public int getWidth() {
		return Width;
	}
	
	/**
	 * setHeight function
	 * @param inputHeight Height Parameter
	 */
	public void setHeight(int inputHeight) {
		Height=inputHeight;
	}
	
	/**
	 * getHeight() return Height
	 */
	public int getHeight() {
		return Height;
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
	/**
	 * 
	 */
	public double area() {
		return area;
	}
	
	/**
	 * 
	 */
	public double perimeter() {
		return perimeter;
	}
	
	/* increment and decrement will return Shape object */
	/**
	 * increment
	 */
	public Shape increment() {
		
		++Loc_X;
		++Loc_Y;
		return this;
		
	}
	/**
	 * decrement
	 */
	public Shape decrement() {
		
		if( !( (Loc_X-1)<0 | (Loc_Y-1)<0 ) )
		{
			--Loc_X;
			--Loc_Y;
		}
		return this;
	}
	/**
	 * getColor
	 * @return Color
	 */
	public String getColor() {
		return Color;
	}
	/**
	 * 
	 */
	public void draw(Graphics g) {
		
		paintComponent(g);
	}
	
	/**
	 * paintComponent
	 */
	public void paintComponent(Graphics g) {
		
		super.paintComponent(g);
		g.drawRect((int)getLocX(),(int)getLocY(),(int)getWidth(),(int)getHeight());
		
	}
	/**
	 * compare
	 */
	@Override
	public int compare(Shape o1, Shape o2) {
		if(o1.area()==o2.area())
			return 1;
		return 0;
	}
	
	
}
