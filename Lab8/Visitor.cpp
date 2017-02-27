#include "Visitor.h"
#include <iostream>
#include <sstream>

using namespace std;

//===============PrintVisitor Class============================================

//empty constructor
Visitor::Visitor() {};

//empty constructor
PrintVisitor::PrintVisitor() {};

//do nothing
void PrintVisitor::rootNode()
{
	return;
}

void PrintVisitor::sqrNode()
{
	output = output + " ^";
	return;
}

void PrintVisitor::multNode()
{
	output = output + " *";
	return;
}

void PrintVisitor::subNode()
{
	output = output + " -";
	return;
}

void PrintVisitor::addNode()
{
	output = output + " +";
	return;
}

void PrintVisitor::opNode(Op* op)
{
	double temp;
	temp = op->evaluate();
	ostringstream num;
	num << temp;
	
	output = output + " " + num.str();
	return;
}

void PrintVisitor::execute()
{
	cout << output << endl;
	return;
}