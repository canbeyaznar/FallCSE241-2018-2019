//Can Beyaznar 161044038
#include <iostream>

#include "Iterator.h"
#include "HashSet.h"
#include "ArrayList.h"
#include "LinkedList.h"

using namespace std;
using namespace Collection_Interface;

int main()
{
	/**Linked List to Array List**/ 
	myArrayList<int> arrList;
	myLinkedList<int> linkedList;
	myList<int> *List;
	
	linkedList.add(13);
	linkedList.add(5);
	linkedList.add(23);
	linkedList.add(7);
	linkedList.add(8);
	linkedList.add(9);
	
	List=&linkedList;
	arrList.addAll(List);
	cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<endl;
	cout<<"|Linked List to Array List   |"<<endl;
	arrList.print();
	/** ----------------------- **/
	
	
	/**HashSet and Set**/
	myHashSet<char> HashSet;
	mySet<char> *Set;
	
	Set=&HashSet;
	Set->add('A');
	Set->add('E');
	Set->add('3');
	Set->add('G');
	Set->add('Z');
	
	cout<<endl<<endl<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<endl;
	cout<<"|       Set to HashSet       |"<<endl;
	Set->print();
	if(Set->contains('E'))
		cout<<endl<<" 'E' contains in Set Object"<<endl;
	if(!(Set->contains('C')))
		cout<<endl<<" 'C' does not contain in Set Object"<<endl;
	cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<endl;
	cout<<endl<<endl;
	
	/**ContainsAll Function**/
	myHashSet<char> HashSet2;
	mySet<char> *Set2;
	
	HashSet2.add('A');
	HashSet2.add('E');
	HashSet2.add('3');
	HashSet2.add('G');
	HashSet2.add('Z');
	Set2=&HashSet2;
	
	cout<<"--ContainsAll Function--"<<endl;
	if(HashSet2.containsAll(Set))
		cout<<"HashSet2 object contains all the elements of Set object"<<endl<<endl;
	
	cout<<"--RemoveAll function--"<<endl;
	
	Set->removeAll(&HashSet2);
	Set->print();
	cout<<"--------------------"<<endl;
	cout<<"-isEmpty Function-"<<endl<<endl;
	if(Set->isEmpty())
		cout<<"Set is Empty."<<endl<<endl;
	else
		cout<<"Set is not Empty!"<<endl<<endl;
	if(HashSet2.isEmpty())
		cout<<"HashSet2 is Empty."<<endl<<endl;
	else
		cout<<"HashSet2 is not Empty!"<<endl<<endl;
			
	cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<endl<<endl;
	
	/**LinkedList retainAll Function**/
	cout<<"-retainAll Function-"<<endl<<endl;
	myHashSet<double> HashSet3;
	HashSet3.add(3.7);
	HashSet3.add(7.2);
	HashSet3.add(9.1);
	HashSet3.add(2.4);
	
	myHashSet<double > HashSet4;
	HashSet4.add(3.7);
	HashSet4.add(7.1);
	HashSet4.add(-13.0);
	HashSet4.add(2.4);
	
	HashSet3.retainAll(&HashSet4);
	HashSet3.print();

	return 0;
}

