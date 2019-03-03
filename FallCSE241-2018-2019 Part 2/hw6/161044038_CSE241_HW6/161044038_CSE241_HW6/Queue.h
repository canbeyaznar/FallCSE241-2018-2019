//Can Beyaznar 161044038

#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <list>
#include "List.h"
#include "Collection.h"

using namespace std;

namespace Collection_Interface
{
	template<typename E,typename myContainer = list<E> >
	class myQueue: public myCollection<E, myContainer>
	{
		public:
			myQueue() {/*Default Constructor*/ }
			
			virtual E element() = 0;
			virtual void offer(E e) = 0;
			virtual E poll() = 0;
	};
	
}

#endif

