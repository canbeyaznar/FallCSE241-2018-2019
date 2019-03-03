/**
 * 
 * @author Can Beyaznar
 *
 */
public class myMain {

	/**
	 * 
	 * @throws Exception Default
	 */
	public static void test() throws Exception {
		Integer myInt[]= new Integer[4];
		myInt[0]=new Integer(13);
		myInt[1]=new Integer(10);
		myInt[2]=new Integer(9);
		myInt[3]=new Integer(5);
		
		Integer myInt2[]= new Integer[4];
		myInt2[0]=new Integer(23);
		myInt2[1]=new Integer(13);
		myInt2[2]=new Integer(9);
		myInt2[3]=new Integer(21);
		
		String myStr[]= new String[4];
		myStr[0]=new String("A");
		myStr[1]=new String("D");
		myStr[2]=new String("H");
		myStr[3]=new String("C");
		
		myIterator<Integer> firstIt = new myIterator<Integer>(myInt);
		myIterator<String> secondIt = new myIterator<String>(myStr);
		
		
		myLinkedList linkedlist = new myLinkedList<Integer>(myInt);
		myHashSet hashset = new myHashSet<Integer>(myInt2);
		
		linkedlist.add(5);
		linkedlist.add(7);
		linkedlist.add(3);
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		System.out.println("|Linked List to Array List   |");
		hashset.addAll(linkedlist);
		hashset.print();
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		System.out.println("|Clear function example  |");
		
		String clearTestStr[]= new String[4];
		clearTestStr[0]=new String("A");
		clearTestStr[1]=new String("D");
		clearTestStr[2]=new String("H");
		clearTestStr[3]=new String("C");
		
		myHashSet clearTest = new myHashSet<String>(clearTestStr);
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		System.out.println("|Before Clear function |");
		clearTest.print();
		System.out.println("|After Clear function |");
		clearTest.clear();
		clearTest.print();
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-\n\n");
		System.out.println("|myHashSet remove and removeAll function |");
		myHashSet secondhashset = new myHashSet<String>(myStr);
		secondhashset.add("S");
		secondhashset.add("Z");
		secondhashset.print();
		
		System.out.println("|myHashSet remove function |");
		secondhashset.remove("S");
		secondhashset.print();
		
		System.out.println("|myHashSet removeAll function |");
		myHashSet thirdhashset = new myHashSet<String>(myStr);
		secondhashset.removeAll(thirdhashset);
		secondhashset.print();
		
		System.out.println("\n\n\n");
		System.out.println("\n\n-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		System.out.println("|containsAll function |");
		myArrayList<String> arraylist = new myArrayList<String>(myStr);
		
		if(arraylist.containsAll(thirdhashset))
			System.out.println("|containsAll function is TRUE|");
		else
			System.out.println("|containsAll function is FALSE|");
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-\n\n");
		
		
		
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		System.out.println("|RetainAll function |");
		Integer mySecondInt[]= new Integer[1];
		mySecondInt[0]=new Integer(13);
		
		System.out.println("|Retaintest parameter |");
		myLinkedList<Integer> retainTest = new myLinkedList<Integer>(mySecondInt);
		retainTest.add(3);
		retainTest.add(17);
		retainTest.add(9);
		retainTest.add(21);
		
		retainTest.print();
		
		System.out.println("|Retaintest2 parameter |");
		Integer myThirdInt[]= new Integer[1];
		myThirdInt[0]=new Integer(7);
		myLinkedList<Integer> retainTest2 = new myLinkedList<Integer>(myThirdInt);
		retainTest2.add(17);
		retainTest2.add(5);
		retainTest2.add(21);
		retainTest2.add(11);
		retainTest2.add(6);

		retainTest2.print();
		
		retainTest.retainAll(retainTest2);
		System.out.println("|RetainAll Result|");
		retainTest.print();

		System.out.println("|isEmpty Function|");
		if(retainTest.isEmpty())
			System.out.println("|it is Empty|\n");
		else
			System.out.println("|it is NOT Empty|\n");
		
		System.out.println("\n\n\n");
		System.out.println("\n\n-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		System.out.println("|Poll function |");
		
		myLinkedList<Integer> pollTest = new myLinkedList<Integer>(myThirdInt);
		pollTest.add(17);
		pollTest.add(5);
		pollTest.add(11);
		pollTest.add(5);
		
		System.out.println("|Before the Poll function |");
		pollTest.print();
		System.out.println("|After the Poll function |");
		Integer temp[] = new Integer[1];
		temp[0]=pollTest.poll();
		pollTest.print();
		System.out.println("|After the Poll function Returned Parameter :  "+temp[0]+"|");
		System.out.println("-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");
		
		System.out.println("\n\n\n");
		System.out.println("\n\n-o-o-o-o-o-o-o-o-o-o-o-o-o-o-");

		System.out.println("|Iterator Examples  |");
		
		Integer arr[] = new Integer[4];
		arr[0] = new Integer(3);
		arr[1] = new Integer(1);
		arr[2] = new Integer(7);
		arr[3] = new Integer(13);
		System.out.println("|Remove and hasNext functions of myIterator class  |");
		myIterator<Integer> myIt = new myIterator<Integer>(arr);
		System.out.println("|Before Removing|");
		myIt.print();
		while(myIt.hasNext() != false)
		{
			int removed = myIt.remove();
			System.out.println("|Removed "+removed+"|");
		}
		System.out.println("\n");
		System.out.println("|After Removing|");
		myIt.print();
		
		
		
	}
	
	public static void main(String[] args) throws Exception {
		
		try {
			test();
		}
		
		catch(Exception error)
		{
			System.out.println("Unexpected!!");
		}
		
	}
}
