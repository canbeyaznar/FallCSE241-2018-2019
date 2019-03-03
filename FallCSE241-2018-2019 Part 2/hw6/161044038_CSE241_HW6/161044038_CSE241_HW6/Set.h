//Can Beyaznar 161044038

#ifndef MYSET_H
#define MYSET_H

#include <set>
#include "Collection.h"

using namespace std;

namespace Collection_Interface
{

	template<typename E,typename myContainer = set<E> >
	class mySet: public myCollection<E,myContainer>
	{
		public:
			mySet() {/*Default Constructor*/}
		
	};
	
}



#endif

