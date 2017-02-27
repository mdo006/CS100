#ifndef ITERATOR_H
#define ITERATOR_H
#include <stack>

using namespace std;

class Base;
class Iterator {
	protected:
		Base* self_ptr;
		Base* current_ptr;

	public:
	Iterator (Base* ptr) {this->self_ptr = ptr;}

	//sets up iterator to start at beginning of traversal
	virtual void first() = 0;

	//go to next element
	virtual void next() = 0;

	//returns if you have finished iterating through all the elements
	virtual bool is_done() = 0;

	//return element iterator currently at
	virtual Base* current() = 0;
};

class OperatorIterator : public Iterator {
	public:
		OperatorIterator(Base* ptr);

		void first();
		void next();
		bool is_done();
		Base* current();
};

class UnaryIterator : public Iterator {
	public:
		UnaryIterator(Base* ptr);
		void first();
		void next();
		bool is_done();
		Base* current();
};

class NullIterator : public Iterator {
	public:
		NullIterator(Base* ptr);
		void first();
		void next();
		bool is_done();
		Base* current();
};

class PreOrderIterator : public Iterator {
	protected:
		stack<Iterator*> iterators;

	public:
		PreOrderIterator(Base* ptr);
		void first();
		void next();
		bool is_done();
		Base* current();
};

#endif