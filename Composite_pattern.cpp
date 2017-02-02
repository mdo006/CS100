#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>

using namespace std;

class Base
{
	public:
		//constructors
		Base() {};

		//pure virtual functions
		virtual double evaluate() = 0;
};

//composites (2 children)
class Mult : public Base
{
	private:
		Base* b1;
		Base* b2;

	public:
		//constructor
		Mult(Base* num1, Base* num2)
		{
			b1 = num1;
			b2 = num2;
		}

		double evaluate()
		{
			return (b1->evaluate() * b2->evaluate());
		}
};

class Div : public Base
{
	private:
		Base* b1;
		Base* b2;

	public:
		//constructor
		Div(Base* num1, Base* num2)
		{
			b1 = num1;
			b2 = num2;
		}

		double evaluate()
		{
			return (b1->evaluate() / b2->evaluate());
		}
};

class Add : public Base
{
	private:
		Base* b1;
		Base* b2;

	public:
		//constructor
		Add(Base* num1, Base* num2)
		{
			b1 = num1;
			b2 = num2;
		}

		double evaluate()
		{
			return (b1->evaluate() + b2->evaluate());
		}
};

class Sub : public Base
{
	private:
		Base* b1;
		Base* b2;

	public:
		//constructor
		Sub(Base* num1, Base* num2)
		{
			b1 = num1;
			b2 = num2;
		}

		double evaluate()
		{
			return (b1->evaluate() - b2->evaluate());
		}
};

//composite (1 child)
class Sqr : public Base
{
	private:
		Base* b1;

	public:
		//constructor
		Sqr(Base* num1)
		{
			b1 = num1;
		}

		double evaluate()
		{
			return (b1->evaluate() * b1->evaluate());
		}
};

//leaf
class Op : public Base
{
	private:
		double value;

	public:
		Op(double val)
		{
			value = val;
		}
		
		double evaluate()
		{
			return value;
		}
};

class Container;

class Sort
{
	public:
		Sort() {};

		virtual void sort(Container* container) = 0;
};

class Container
{
	protected:
		Sort* sort_function;

	public:
		/*constructors*/
		Container() : sort_function(NULL) {};
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

class BubbleSort : public Sort
{
	public:
		//constructors
		BubbleSort(){};

		virtual void sort(Container* container)
		{
			int i;
			int j;
			int flag = 1;
			int numLength = container->size();

			for (i = 1; (i <= numLength) && flag; ++i)
			{
				flag = 0;

				for (j = 0; j < (numLength - 1); ++j)
				{
					if (container->at(j + 1) -> evaluate() > container->at(j) -> evaluate())
					{
						container->swap(j, j + 1);
						flag = 1;
					}
				}
			}
		}
};

class SelectionSort : public Sort
{
	public:
		SelectionSort() {};

		void sort(Container* container)
		{
			int i;
			int j;
			int first;
			int numLength = container->size();

			for (i = numLength - 1; i > 0; --i)
			{
				first = 0;

				for (j = 1; j <= i; ++j)
				{
					if (container->at(j)->evaluate() < container->at(first)->evaluate())
					{
						first = j;
					}
				}

				container->swap(first, i);
			}
		}
};

class VectorContainer : public Container
{
	protected:
		vector <Base* > myVector;

	public:
		//Constructors
		VectorContainer(){};
		VectorContainer(Sort* function)
		{
			this->set_sort_function(function);
		}

		/*non-virtual functions*/
		
		//set type of sorting algorithm
		void set_sort_function(Sort* sort_function)
		{
			this->sort_function = sort_function;
		}

		/*pure virtual functions*/
		
		//push the top of the tree into the container
		virtual void add_element(Base* element)
		{
			myVector.push_back(element);
		}

		//iterate through trees and output values
		virtual void print()
		{
			for (unsigned i = 0; i < myVector.size(); ++i)
			{
				cout << myVector.at(i)->evaluate() << endl;
			}
		}

		/*calls on the previously set sorting algorithm. Checks if sort function is
		  not full, throws exception otherwise*/
		virtual void sort()
		{
			if (sort_function == NULL)
			{
				cout << "No sort function set" << endl;
			}
			else
			{
				sort_function->sort(this);
			}
		}

		/*functions for sorting*/
		
		//switch tree locations
		virtual void swap (int i, int j)
		{
			vector <Base* >::iterator it1 = myVector.begin();
			vector <Base* >::iterator it2 = myVector.begin();
			int k = 0;

			while(k < i)
			{
				++it1;
				++k;
			}

			k = 0;

			while(k < j)
			{
				++it2;
				++k;
			}
			
			std::swap (*it1, *it2);
		}
	
		//get top pointer of tree at index i
		virtual Base* at(int i)
		{
			vector <Base*>::iterator it = myVector.begin();
			int k;
			while(k < i)
			{
				++it;
				++k;
			}

			return *it;
		}

		//return container size
		virtual int size()
		{
			return myVector.size();
		}
};

class Decorator : public Base
{
	protected:
		Base* decorated_b;
	
	public:
		Decorator (Base* decorated_Base)
			: decorated_b(decorated_Base) {};
};

class Ceiling : public Decorator
{
	public:
		Ceiling (Base* Ceil)
			: Decorator(Ceil) {};
		
		double evaluate()
		{
			return ceil(decorated_b->evaluate());
		}

};

class Floor : public Decorator
{
	public:
		Floor (Base* Floor)
			: Decorator(Floor) {};

		double evaluate()
		{
			return floor(decorated_b->evaluate());
		}
};

class Absolute_Value : public Decorator
{
	public:
		Absolute_Value (Base* Abs)
			: Decorator(Abs) {};

		double evaluate()
		{
			return abs(decorated_b->evaluate());
		}
};

int main()
{
	Op* op7 = new Op(7);
	Op* op4 = new Op(4);
	Op* op3 = new Op(3);
	Op* op2 = new Op(2);

	Mult* A = new Mult(op7, op4);
	Add* B = new Add(op3, A);
	Sub* C = new Sub(B, op2);
	Sqr* D = new Sqr(C);
	
	VectorContainer* container = new VectorContainer();
	container->add_element(A);
	container->add_element(B);
	container->add_element(C);
	container->add_element(D);

	cout << "Container Before Sort: " << endl;
	container->print();

	cout << "Container After Sort: " << endl;
	container->set_sort_function(new SelectionSort());
	container->sort();
	container->print();

	//add test cases for Decorator
	Base* Ceil_test = new Ceiling(new Op(9.9));
	Base* Floor_test = new Floor(new Op(8.3));
	Base* Abs_test = new Absolute_Value(new Op(-3));

	//VectorContainer* container_2 = new VectorContainer();
	//container_2->add_element(Ceil_test);
	//container_2->add_element(Floor_test);
	//container_2->add_element(Abs_test);

	//cout << "Decorator: " << endl;
	//container_2->print();
	
	cout << "Decorator: " << endl;
	cout << "9.9" << endl;
	cout << Ceil_test->evaluate() << endl;
	cout << "8.3" << endl;
	cout << Floor_test->evaluate() << endl;
	cout << "-3" << endl;
	cout << Abs_test->evaluate() << endl;

	return 0;
}
