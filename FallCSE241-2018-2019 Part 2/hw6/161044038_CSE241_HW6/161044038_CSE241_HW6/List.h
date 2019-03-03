//Can Beyaznar 161044038

#ifndef MYLIST_H
#define MYLIST_H

#include <list>
#include "Collection.h"

using namespace std;

namespace Collection_Interface
{
	
	template<typename E,typename myContainer = list<E> >
	class myList:public myCollection<E, myContainer>
	{
		public:
			myList() {/*Default Constructor*/}
	
	};
	
}

#endif
