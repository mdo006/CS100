#include <iostream>

using namespace std;

class Sort
{
	public:
		/*constructors*/
		Sort();
	
		/*pure virtual functions*/
		virtual void sort(Container* container) = 0;
};

class Container
{
	protected:
		Sort* sort_function;

	public:
		/*constructors*/
		Container() : sort_function(function) {};
		Container(Sort* function) : sort_function(function) {};

		/*non-virtual functions*/
		
		//set the type of sorting algorithm
		void set_sort_function(Sort* sort_function);

		/*pure virtual functions*/
		
		//push the top pointer of the tree into container
		virtual void add_element(Base* element) = 0;
		//iterate through trees and output values
		virtual void print() = 0;
		//calls on the previously set sorting algorithm
		/*checks if sort_function is NOT null; throws
		  exception if otherwise*/
		virtual void sort() = 0;

		/*Essentially the only functions needed to sort*/

		//switch tree locations
		virtual void swap(int i, int j) = 0;
		//get top pointer of tree at index i
		virtual Base* at(int i) = 0;
		//return container size
		virtual int size() = 0;
};

int main()
{
	
	return 0;
}

