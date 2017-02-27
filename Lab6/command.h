#ifndef __COMMAND_CLASS__
#define __COMMAND_CLASS__

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() { };
		double execute() {
			return root->evaluate();
		};
		Base* get_root() {
			return root;
		};
};

class OpCommand : public Command 
{
	//OpCommand Code Here
	public:
		//constructor
		OpCommand(double value)
		{
			root = new Op(value);
		}
};

class AddCommand : public Command
{
	//AddCommand Code Here
	public:	
		AddCommand(Command* cmd, double value)
		{
			root = new Add(cmd->get_root(), new Op(value));
		}
};

class SubCommand : public Command
{
	//SubCommand Code Here
	public:	
		SubCommand(Command* cmd, double value)
		{
			root = new Sub(cmd->get_root(), new Op(value));
		}
};

class MultCommand : public Command
{
	//MultCommand Code Here
	public:	
		MultCommand(Command* cmd, double value)
		{
			root = new Mult(cmd->get_root(), new Op(value));
		}
};

class SqrCommand : public Command
{
	//SqrCommand Code Here
	public:
		SqrCommand(Command* cmd)
		{	
			root = new Sqr(cmd->get_root());
		}
};

#endif //__COMMAND_CLASS__
