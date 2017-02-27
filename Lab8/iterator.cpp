#include "iterator.h"
#include "composite.h"

OperatorIterator::OperatorIterator(Base* ptr): Iterator(ptr){}

void OperatorIterator::first() {
	current_ptr = self_ptr->get_left();
}

void OperatorIterator::next() {
	if (current_ptr == self_ptr->get_left()) {
		current_ptr = self_ptr->get_right();
	} else {
		current_ptr = NULL;
	}
}

bool OperatorIterator::is_done() {
	return (current_ptr == NULL);
}

Base* OperatorIterator::current() {
	return current_ptr;
}

NullIterator::NullIterator(Base*ptr): Iterator(ptr){}

void NullIterator::first() {
	return;
}

void NullIterator::next() {
	return;
}

bool NullIterator::is_done() {
	return true;
}

Base* NullIterator::current() {
	return NULL;
}

UnaryIterator::UnaryIterator(Base* ptr): Iterator(ptr){}

void UnaryIterator::first() {
	current_ptr = self_ptr->get_left();
}

void UnaryIterator::next() {
	current_ptr = NULL;
}

bool UnaryIterator::is_done() {
	return (current_ptr == NULL);
}

Base* UnaryIterator::current() {
	return current_ptr;
}

//Preorder Iterator

PreOrderIterator::PreOrderIterator(Base* ptr):Iterator(ptr){}

void PreOrderIterator::first() {
	if (self_ptr->get_left() == NULL) return;

	while (!iterators.empty()) {
		iterators.pop();
	}

	Iterator* it = self_ptr->create_iterator();
	it->first();

	iterators.push(it);
}

void PreOrderIterator::next() {
	if (iterators.empty()) return;

	Iterator* iTop = iterators.top()->current()->create_iterator();
	iTop->first();
	iterators.push(iTop);

	while (iterators.top()->is_done()) {
		iterators.pop();

		if (iterators.empty()) break;
		
		iterators.top()->next();
	}
}

bool PreOrderIterator::is_done() {
	return iterators.empty();
}

Base* PreOrderIterator::current() {
	return iterators.top()->current();
}
