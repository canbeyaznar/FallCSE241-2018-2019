
import java.util.Comparator;
import javax.swing.JPanel;
/**
 * 
 * @author Can Beyaznar
 *
 */
public abstract class Polygon extends JPanel implements Shape{
	
	protected double location_X;
	protected double location_Y;
	
	/**
	 * Default Constructor
	 */
	public Polygon() {
		location_X=0;
		location_Y=0;
	}
	/**
	 * 
	 * @param tempX Loc X 
	 * @param tempY Loc Y
	 */
	public Polygon(double tempX, double tempY) {
		location_X=tempX;
		location_Y=tempY;
	}
	/**
	 * 	
	 * @param locX location X
	 * @param locY location Y
	 */
	public void setLocations(double locX,double locY) {
		location_X=locX;
		location_Y=locY;
	}
	
	public void setLocX(double Val){
		location_X=Val;
	}
	
	public void setLocY(double Val) {
		location_Y=Val;
	}
			
	public double getLocX() {
		return location_X;
	}
	
	public double getLocY() {
		return location_Y;
	}
	
	@Override
	public Shape increment()
	{
		++location_X;
		++location_Y;
		return this;
	}
	
	@Override
	public Shape decrement()
	{
		if( !( (location_X-1)<0 | (location_Y-1)<0 ) )
		{
			--location_X;
			--location_Y;
		}
		return this;
	}

}
