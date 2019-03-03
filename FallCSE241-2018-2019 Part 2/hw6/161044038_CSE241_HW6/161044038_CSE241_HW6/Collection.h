//Can Beyaznar 161044038

#ifndef MYCOLLECTION_H
#define MYCOLLECTION_H

#include <vector>
#include "Iterator.h"

using namespace std;

namespace Collection_Interface
{

template<typename E, typename myContainer = vector<E> >
class myCollection{

    public:
    	myCollection() {	}
    	
        virtual Iterator<myContainer> iterator() = 0;
        virtual void add(E e) = 0;
        virtual void addAll(myCollection<E,myContainer> *c) = 0;
        virtual void clear() = 0;
        virtual bool contains(E e) = 0;
        virtual bool containsAll(myCollection<E,myContainer> *c) = 0;
        virtual bool isEmpty() = 0;
        virtual void remove(E e) = 0;
        virtual void removeAll(myCollection<E,myContainer> *c) = 0;
        virtual void retainAll(myCollection<E,myContainer> *c) = 0;
        virtual typename myContainer::iterator getBegin() = 0;
        virtual typename myContainer::iterator getEnd() = 0;
        virtual int size() const = 0;
        virtual void print() = 0;
};

}

#endif
