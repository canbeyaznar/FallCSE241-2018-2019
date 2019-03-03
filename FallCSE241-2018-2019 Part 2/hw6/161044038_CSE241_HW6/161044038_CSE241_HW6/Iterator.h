//Can Beyaznar 161044038
#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <iterator>

namespace Collection_Interface
{
	template<typename T>
	class Iterator
	{
		public:
			
			Iterator() noexcept {/*Default Constructor*/}
			Iterator(T* iteratorPtr) noexcept {Ptr=iteratorPtr; it=Ptr->begin();	}
			
			//Big Three
			Iterator(const Iterator& copyConst) noexcept {
				Ptr=copyConst.getPtr();
				it=Ptr->begin();
			}
			
			Iterator& operator =(const Iterator& copyConst) noexcept {
				Ptr=copyConst.getPtr();
				it=Ptr->begin();

				return *this;
			}
			
			~Iterator(){
				Ptr->clear();
			}
			
			
			bool hasNext() noexcept{
				
				int count = 0;
				for(auto i = it; i!=Ptr->end(); ++i )
					count++;
				
				return (count!=0);		
			}
			
			typename T::iterator next() noexcept {
				if(this->hasNext() == true)
					it++;
				return it;
			}
			
			typename T::iterator remove() noexcept {
			
				auto temp = it;
				Ptr->erase(temp);
				it++;
				return it;
	    	}
			
			int size() const noexcept {
				
				int count = 0;
				for(auto i = it; i!=Ptr->end(); i++)
					count++;
				return count;
			
			}
			T* getPtr() const{
				return Ptr;
			}
			
			typename T::iterator getIterator() const{
				return it;
			}
			
			void print(){
				std::cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<std::endl;
				int count=0;
				for(auto i = it; i != Ptr->end(); ++i)
				{
					std::cout<<count<<": "<<*i<<std::endl;
					count++;
				}
				std::cout<<"-o-o-o-o-o-o-o-o-o-o-o-o-o-o-"<<std::endl;
			}
		
		private:
			T* Ptr;
			typename T::iterator it;
	};
}

#endif

