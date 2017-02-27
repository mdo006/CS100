#include <iostream>
#include <vector>
#include "composite.h"
#include "iterator.h"
using namespace std;

int main() {

	Op* op3 = new Op(3);
	Op* op4 = new Op(4);
	Op* op2 = new Op(2);
	Op* op5 = new Op(5);
	Op* op10 = new Op(10);
	Add* add = new Add(op3, op4);
	Sqr* sqr = new Sqr(op2);
	Sub* sub = new Sub(add, sqr);
	Sub* sub2 = new Sub(sub, sqr);
	Add* add2 = new Add(sub2, op10);
	Add* add3 = new Add(add2, op5);

	Root* root = new Root(add3);

	cout << "--- PreOrder Iteration ---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root);
    
	for (pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) 
	{
		pre_itr->current()->print();
		cout << endl;
	}
};