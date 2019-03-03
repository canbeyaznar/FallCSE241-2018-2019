//Can Beyaznar 161044038

#ifndef MYARRAYLIST_H
#define MYARRAYLIST_H

#include <iterator>
#include "List.h"


namespace Collection_Interface
{
	template<typename E, typename myContainer = list<E> >
	class myArrayList: public myList<E,myContainer>
	{
		public:
			myArrayList() noexcept {/*Default Constructor*/}
			
			myArrayList(std::list<E> Arr_I) noexcept {
					std::cout<<Arr_I.size()<<std::endl;
					Arr=Arr_I;
					sizeArr=Arr_I.size();
			}
			
			Iterator<myContainer> iterator() noexcept {
				
				Iterator<myContainer> temp(&Arr);
				temp.next();
				return temp;
				
			}
		    void add(E e) noexcept {
		    		
		    		Arr.insert(Arr.begin(),e);
		    		Arr.sort();
		
					sizeArr++;
				}
				
			void addAll(myCollection<E,myContainer>* c) noexcept {
				
				
				for(auto it=c->getBegin(); it!=c->getEnd(); ++it)
					this->add(*it);
				sizeArr=this->size();
			}
		    void clear() noexcept {
				Arr.clear();
				sizeArr=0;
			}
		    bool contains(E e) noexcept {
		    	
				for(auto i=Arr.begin(); i!=Arr.end(); ++i )
				{
					if(*i==e)
						return true;
				}
				return false;
			}
		    bool containsAll(myCollection<E,myContainer> *c) noexcept {
				
				if(Arr.size() == c->size())
				{
					auto j=c->getBegin();
					for(auto i=Arr.begin(); i!=Arr.end(); ++i )
					{
						if( *i != *j  )
							return false;	
						++j;
					}
					return true;
				}
				else
					return false;
				
			}
		    bool isEmpty() noexcept {
				return (Arr.empty());
			}
				
		    void remove(E e){
					
				for(auto i=Arr.begin(); i!=Arr.end(); ++i)
				{
					if(*i == e)
					{
						Arr.erase(i);
						--sizeArr;
						Arr.sort();
					}
						
				}
				Arr.sort();
			}
		    void removeAll(myCollection<E,myContainer> *c) noexcept {
					
				auto begin_it = Arr.begin();
				while(begin_it != Arr.end())
				{
					auto container_it = c->getBegin();
					while(container_it != c->getEnd())
					{
						if(*begin_it == *container_it)
						{
							this->remove(*begin_it);
							container_it = c->getEnd();
							Arr.sort();
						}	
						else	
							++container_it;			
					}		
					++begin_it;
				}
				Arr.sort();
			}
				
		    void retainAll(myCollection<E,myContainer> *c) noexcept {
		    	
		    	int control = 0;
				auto begin_it = Arr.begin();
				while(begin_it != Arr.end())
				{
					control=0;
					auto container_it = c->getBegin();
					while(container_it != c->getEnd())
					{
						if(*begin_it == *container_it)
							++control;
							
						++container_it;	
									
					}
					if(control == 0 )
					{
						this->remove(*begin_it);
						Arr.sort();
					}
				
					++begin_it;
				}
				Arr.sort();
			}
			    
		    int size() const noexcept  {
				return Arr.size();
			}
			
			typename list<E>::iterator getBegin(){
				return Arr.begin();
			}
			
			typename list<E>::iterator getEnd(){
				return Arr.end();
			}

		    void print() noexcept {
		    	
			    std::cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<std::endl;
				if(Arr.size() == 0)
				{
					cout<<"ArrayList is Empty!!"<<endl;
					return;
				}
		    			
		    	int count=0;
			    	
		    	for(auto i = Arr.begin(); i!=Arr.end(); ++i )
		    	{
		    		std::cout<<count<<": "<<*i<<std::endl;
		    		count++;
				}
				std::cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<std::endl;
			}
			    
	    private:
	    	std::list<E> Arr;
			int sizeArr;
	};
	
}

#endif
