/**
 * 
 * @author Can Beyaznar
 *
 * @param <E> Integer or String
 */
public class myIterator<E> {
	
	private E[] myArr;
	private int location;
	
	/**
	 * 
	 * @throws Exception Default
	 */
	public myIterator() throws Exception {
		myArr=null;
		location=0;
	}
	
	/**
	 * 
	 * @param tempArr array parameter
	 * @throws Exception Default
	 */
	public myIterator(E[] tempArr) throws Exception {
		
		location=0;
		if(tempArr[0] instanceof Integer )
		{
			myArr = (E[]) new Integer[tempArr.length];
			for(int i=0; i<myArr.length; ++i)
				myArr[i] = (E) new Integer((int) tempArr[i]);
		}
			
		
		else if(tempArr[0] instanceof String )
		{
			myArr = (E[]) new String[tempArr.length];
			for(int i=0; i<myArr.length; ++i)
				myArr[i] = (E) new String((String) tempArr[i]);
		}
			
		else
			new Exception();
		
	}
	
	
	public boolean hasNext() throws Exception {
		
		if( location+1 > myArr.length )
			return false;
			
		return true;
	}
	
	public E next() throws Exception {
		
		if(this.hasNext())
			++location;	
		else 
			new Exception();
		
		return ( (E) myArr[location] );
	}
	
	public E remove() {
		
		int oldSize = myArr.length;
		if(myArr[0] instanceof Integer )
		{
			Integer tempElement = new Integer(-1);
			E[] tempArr  = (E[]) new Integer[oldSize-1];
			
			int count=0;
			for(int i=0; i<myArr.length; ++i)
			{
				if(i!=location)
				{
					tempArr[count] = (E) new Integer((int) myArr[i]);
					++count;
				}
				
				else
					tempElement = new Integer((int) myArr[i]);	
			}
			
			myArr = (E[]) new Integer[tempArr.length];
			for(int i=0; i<(oldSize-1); ++i)
				myArr[i] = (E) new Integer((int) tempArr[i]);
			
			return (E) tempElement;
		}
			
		
		else if(myArr[0] instanceof String )
		{
			
			String tempElement = new String("U");
			E[] tempArr  = (E[]) new String[oldSize-1];
			
			int count=0;
			for(int i=0; i<myArr.length; ++i)
			{
				if(i!=location)
				{
					tempArr[count] = (E) new String((String) myArr[i]);
					++count;
				}
				
				else
					tempElement = new String((String) myArr[i]);
				
					
			}
			
			myArr = (E[]) new String[tempArr.length];
			for(int i=0; i<(oldSize-1); ++i)
				myArr[i] = (E) new String((String) tempArr[i]);
			
			return (E) tempElement;
			
		}
		return null;
		
	}
	
	public int size() {
		return myArr.length;
	}
	
	public E[] getArr() {
		return myArr;
	}
	
	/**
	 * 
	 * @param index  int parameter to take element on index
	 * @return index 
	 */
	public E getElement(int index) {
		
		if(index>=myArr.length)
			return myArr[index];
		else
			return null;
	}
	
	public int getLocation() {
		return location;
	}
	
	public void print() {
		
		if(myArr==null)
		{
			System.out.println("EMPTY");
			return ;
		}
		
		if(myArr.length == 0)
			System.out.println("EMPTY");
		for(int i=0; i<myArr.length; ++i)
			System.out.println(i+". index: "+myArr[i]);
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		
	}	
	
}
