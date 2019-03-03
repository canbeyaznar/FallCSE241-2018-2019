import java.awt.Graphics;
import java.util.Comparator;

import javax.swing.JFrame;

/**
 * 
 * @author Can Beyaznar
 *
 */

public interface Shape extends Comparator<Shape>{

	public double area();
	public double perimeter();
	
	public Shape increment();
	public Shape decrement();
	
	public void draw(Graphics g);
	public int compare(Shape o1, Shape o2);
}
