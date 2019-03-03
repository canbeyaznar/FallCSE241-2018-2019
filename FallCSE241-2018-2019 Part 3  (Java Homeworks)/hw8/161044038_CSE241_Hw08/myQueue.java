/**
 * 
 * @author Can Beyaznar
 *
 * @param <E> Integer or String
 */
public interface myQueue<E> extends myCollection<E> {
	
	public E element();
	public void offer(E e) throws Exception ;
	public E poll() throws Exception ;
}
