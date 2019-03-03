/**
 * 
 * @author Can Beyaznar
 *
 * @param <E> Integer or String
 */
public class myHashSet<E> implements mySet<E> {

	private E[] hashSetArr;
	private myIterator<E> iterator;	
	
	
	/**
	 * 
	 * @throws Exception Default
	 */
	public myHashSet() throws Exception {
		hashSetArr=null;
		iterator=null;
	}
	
	/**
	 * 
	 * @param inputArr input Array parameter
	 * @throws Exception Default
	 */
	public myHashSet(E[] inputArr) throws Exception {
		
		
		if(inputArr[0] instanceof Integer )
		{
			hashSetArr = (E[]) new Integer[1];
			hashSetArr[0] = (E) new Integer((int) inputArr[0]);
			
			for(int i=1; i<inputArr.length; ++i)
				this.add(inputArr[i]);
		}
			
		
		else if(inputArr[0] instanceof String )
		{
			hashSetArr = (E[]) new String[1];
			hashSetArr[0] = (E) new String((String) inputArr[0]);
			
			for(int i=1; i<inputArr.length; ++i)
				this.add(inputArr[i]);
		}
			
		else
			new Exception();
	}
	
	
	public myIterator<E> iterator() throws Exception
	{
		iterator = new myIterator<E>(hashSetArr);
		return iterator;
		
	}
	
	@Override
	public void add(E e) throws Exception {

		if(contains(e) == false)
		{
			int oldSize=hashSetArr.length;
			if(hashSetArr[0] instanceof Integer && e instanceof Integer )
			{
				
				Integer[] temp = new Integer[hashSetArr.length];
				for(int i=0; i<hashSetArr.length; ++i)
					temp[i] = new Integer((int) hashSetArr[i]);
				
				hashSetArr = (E[]) new Integer[oldSize+1];
				for(int i=0; i<oldSize; ++i)
					hashSetArr[i] = (E) new Integer((int) temp[i]);
				hashSetArr[oldSize] = (E) new Integer((int) e);
				
			}
			
			else if(hashSetArr[0] instanceof String && e instanceof String )
			{
				
				String[] temp = new String[hashSetArr.length];
				for(int i=0; i<hashSetArr.length; ++i)
					temp[i] = new String((String) hashSetArr[i]);
				
				hashSetArr = (E[]) new String[oldSize+1];
				for(int i=0; i<oldSize; ++i)
					hashSetArr[i] = (E) new String((String) temp[i]);
				hashSetArr[oldSize] = (E) new String((String) e);
				
			}
			
			else
				new Exception();
		}
		
	}

	@Override
	public void addAll(myCollection<E> c) throws Exception {
		
		for(int i=0; i<c.size(); ++i)
			this.add(c.getElement(i));
		
	}
	
	@Override
	public E getElement(int index) throws Exception
	{
		if(index>=hashSetArr.length )
			new Exception();
		
		return hashSetArr[index];
	}
	
	@Override
	public void clear() {
		hashSetArr=null;
	}

	@Override
	public boolean contains(E e) {

		for(int i=0; i<hashSetArr.length; ++i )
			if( e.equals(hashSetArr[i]))
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
	public boolean isEmpty() {

		if(this.size()==0 ||  hashSetArr==null)
			return true;	
		
		return false;
	}

	@Override
	public void remove(E e) throws Exception {

		if(this.contains(e))
		{
			if(hashSetArr[0] instanceof Integer)
			{
				
				int oldSize = hashSetArr.length;
				Integer[] temp = new Integer[hashSetArr.length-1];
				
				int count = 0;
				int j=0;
				for(int i=0; i<this.size(); i++)
				{
					
					if( hashSetArr[i].equals(e) )
						count++;
					
					else 
					{
						temp[j] = (Integer) hashSetArr[count]; 
						count++;
						j++;
					}
					
				}
				
				hashSetArr = (E[]) new Integer[oldSize-1];
				for(int i=0; i<oldSize-1; i++)
					hashSetArr[i] = (E) temp[i];
			}
			
			else if(hashSetArr[0] instanceof String)
			{
				
				int oldSize = hashSetArr.length;
				String[] temp = new String[hashSetArr.length-1];
				
				int count = 0;
				int j=0;
				for(int i=0; i<this.size(); i++)
				{
					
					if( hashSetArr[i].equals(e) )
						count++;
					
					else 
					{
						temp[j] = (String) hashSetArr[count]; 
						count++;
						j++;
					}
					
				}
				
				hashSetArr = (E[]) new String[oldSize-1];
				for(int i=0; i<oldSize-1; i++)
					hashSetArr[i] = (E) temp[i];
			}
			
			
		}
		
		
	}

	@Override
	/**
	 * 
	 */
	public void removeAll(myCollection<E> c) throws Exception {
		
		for(int i=0; i<hashSetArr.length; i++)
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
		
		if(hashSetArr==null)
			return 0;
		
		return hashSetArr.length;
	}

	@Override
	public void print() {
		
		if(hashSetArr==null)
		{
			System.out.println("EMPTY");
			return ;
		}
		if(hashSetArr.length == 0)
			System.out.println("EMPTY");
		for(int i=0; i<hashSetArr.length; ++i)
			System.out.println(i+". index: "+hashSetArr[i]);
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		
	}

}
