

public interface myCollection<E> {
	
	public myIterator<E> iterator() throws Exception;
	public void add(E e) throws Exception;
	public void addAll(myCollection<E> c) throws Exception;
	
	public void clear();
	
	public boolean contains(E e);
	public boolean containsAll(myCollection<E> c) throws Exception;
	public E getElement(int index) throws Exception;
	
	public boolean isEmpty();
	public void remove(E e) throws Exception ;
	public void removeAll(myCollection<E> c) throws Exception;
	public void retainAll(myCollection<E> c) throws Exception;
	
//  myContainer::iterator getBegin();
//	myContainer::iterator getEnd();
	public int size();
	public void print();

}
