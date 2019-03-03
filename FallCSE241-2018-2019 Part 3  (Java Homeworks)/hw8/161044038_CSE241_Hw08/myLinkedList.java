import java.util.Arrays;

/**
 * 
 * @author Can Beyaznar
 *
 * @param <E> Integer or String
 */
public class myLinkedList<E> implements myList<E>, myQueue<E> {

	private E[] LinkedListArr;
	private myIterator<E> iterator;

	@Override
	/**
	 * 
	 */
	public myIterator<E> iterator() throws Exception {

		myIterator<E> iterator = new myIterator<E>(LinkedListArr);
		return iterator;

	}
	
	/**
	 * 
	 * @throws Exception Default
	 */
	public myLinkedList() throws Exception
	{
		LinkedListArr=null;
		iterator = new myIterator<E>(LinkedListArr);

	}
	
	/**
	 * 
	 * @param inputArr input Array parameter
	 * @throws Exception Default
	 */
	public myLinkedList(E[] inputArr) throws Exception
	{


		if(inputArr[0] instanceof Integer )
		{
			LinkedListArr = (E[]) new Integer[1];
			LinkedListArr[0] = (E) new Integer((int) inputArr[0]);
			
			for(int i=1; i<inputArr.length; ++i)
				this.add(inputArr[i]);
			Arrays.sort(LinkedListArr);
		}
			
		
		else if(inputArr[0] instanceof String )
		{
			LinkedListArr = (E[]) new String[1];
			LinkedListArr[0] = (E) new String((String) inputArr[0]);
			
			for(int i=1; i<inputArr.length; ++i)
				this.add(inputArr[i]);
			Arrays.sort(LinkedListArr);
		}
			
		else
			new Exception();

	}


	@Override
	public void add(E e) throws Exception {

		int oldSize=LinkedListArr.length;
		if(LinkedListArr[0] instanceof Integer && e instanceof Integer )
		{
			
			Integer[] temp = new Integer[LinkedListArr.length];
			for(int i=0; i<LinkedListArr.length; ++i)
				temp[i] = new Integer((int) LinkedListArr[i]);
			
			LinkedListArr = (E[]) new Integer[oldSize+1];
			for(int i=0; i<oldSize; ++i)
				LinkedListArr[i] = (E) new Integer((int) temp[i]);
			LinkedListArr[oldSize] = (E) new Integer((int) e);
			
			Arrays.sort(LinkedListArr);
		}
		
		else if(LinkedListArr[0] instanceof String && e instanceof String )
		{
				
			String[] temp = new String[LinkedListArr.length];
			for(int i=0; i<LinkedListArr.length; ++i)
				temp[i] = new String((String) LinkedListArr[i]);
				
			LinkedListArr = (E[]) new String[oldSize+1];
			for(int i=0; i<oldSize; ++i)
				LinkedListArr[i] = (E) new String((String) temp[i]);
			LinkedListArr[oldSize] = (E) new String((String) e);
			
			Arrays.sort(LinkedListArr);
		}
			
		else
			new Exception();
	}

	@Override
	public void addAll(myCollection<E> c) throws Exception {
		for(int i=0; i<c.size(); ++i)
			this.add(c.getElement(i));

	}

	@Override
	public void clear() {
		LinkedListArr=null;

	}

	@Override
	public boolean contains(E e) {
		
		for(int i=0; i<LinkedListArr.length; ++i )
			if( e.equals(LinkedListArr[i]))
				return true;
		return false;
	}

	@Override
	public boolean containsAll(myCollection<E> c) throws Exception {
		if(this.size() == c.size())
		{
			int count = 0;
			for(int i=0; i<c.size(); ++i)
			{
				if(this.contains(c.getElement(i)))
					++count;
			}
			
			if(count==this.size())
				return true;	
		}
		return false;
	}

	@Override
	public E getElement(int index) throws Exception {
		if(index>=LinkedListArr.length )
			new Exception();
		
		return LinkedListArr[index];
	}

	@Override
	public boolean isEmpty() {
		if(this.size()==0 ||  LinkedListArr==null)
			return true;	
		
		return false;
	}

	@Override
	public void remove(E e) throws Exception {
		if(this.contains(e))
		{
			if(LinkedListArr[0] instanceof Integer)
			{
				
				int oldSize = LinkedListArr.length;
				Integer[] temp = new Integer[LinkedListArr.length-1];
				
				int count = 0;
				int j=0;
				for(int i=0; i<this.size(); i++)
				{
					
					if( LinkedListArr[i].equals(e) )
						count++;
					
					else 
					{
						temp[j] = (Integer) LinkedListArr[count]; 
						count++;
						j++;
					}
					
				}
				
				LinkedListArr = (E[]) new Integer[oldSize-1];
				for(int i=0; i<oldSize-1; i++)
					LinkedListArr[i] = (E) temp[i];
			}
			
			else if(LinkedListArr[0] instanceof String)
			{
				
				int oldSize = LinkedListArr.length;
				String[] temp = new String[LinkedListArr.length-1];
				
				int count = 0;
				int j=0;
				for(int i=0; i<this.size(); i++)
				{
					
					if( LinkedListArr[i].equals(e) )
						count++;
					
					else 
					{
						temp[j] = (String) LinkedListArr[count]; 
						count++;
						j++;
					}
					
				}
				
				LinkedListArr = (E[]) new String[oldSize-1];
				for(int i=0; i<oldSize-1; i++)
					LinkedListArr[i] = (E) temp[i];
			}
			
			
		}
		

	}

	@Override
	public void removeAll(myCollection<E> c) throws Exception {
		for(int i=0; i<LinkedListArr.length; i++)
			this.remove(c.getElement(i));

	}

	@Override
	public void retainAll(myCollection<E> c) throws Exception {
		int index=0;
		while(index<this.size())
		{
			int count=0;
			for(int j=0; j<c.size(); j++)
			{
				if(!(this.getElement(index).equals(c.getElement(j))))
					count++;
					
			}
			if(count == c.size())
				this.remove(this.getElement(index));
				
			else
				index++;
			
		}
		

	}

	@Override
	public int size() {
		if(LinkedListArr==null)
			return 0;
		
		return LinkedListArr.length;
	}

	@Override
	public void print() {
		
		if(LinkedListArr==null)
		{
			System.out.println("EMPTY");
			return ;
		}
		
		if(LinkedListArr.length == 0)
			System.out.println("EMPTY");
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		for(int i=0; i<LinkedListArr.length; ++i)
			System.out.println(i+". index: "+LinkedListArr[i]);

		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-");

	}

	@Override
	public E element() {
		
		if(LinkedListArr != null)
			return LinkedListArr[0];
		
		return null;
	}

	@Override
	public void offer(E e) throws Exception {
		this.add(e);

	}

	@Override
	public E poll() throws Exception {

		
		
		if(LinkedListArr[0] instanceof Integer )
		{
			E temp =  (E) new Integer((Integer)LinkedListArr[0]);
			E[] tempArr = (E[]) new Integer[this.size()-1];
			
			for(int i=0; i<tempArr.length; i++)
			{
				tempArr[i] = (E) new Integer((Integer) LinkedListArr[i+1]);
			}
				
			
			LinkedListArr = (E[]) new Integer[tempArr.length];
			for(int i=0; i<tempArr.length; i++)
				LinkedListArr[i] = (E) new Integer((Integer) tempArr[i]);
			return temp;
		}
		
		else if(LinkedListArr[0] instanceof String )
		{
			E temp =  (E) new String((String)LinkedListArr[0]);
			E[] tempArr = (E[]) new String[this.size()-1];
			
			for(int i=0; i<tempArr.length; i++)
			{
				tempArr[i] = (E) new String((String) LinkedListArr[i+1]);
			}
				
			
			LinkedListArr = (E[]) new String[tempArr.length];
			for(int i=0; i<tempArr.length; i++)
				LinkedListArr[i] = (E) new String((String) tempArr[i]);
			return temp;
		}
		
		return null;
		
		
	}

}
