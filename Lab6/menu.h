#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include <vector>
#include <cstdlib>
#include "command.h"

using namespace std;

class Menu
{
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() 
		{
			//Base constructor to set up all necessary members
			history_index = -1;

		};
		void execute() 
		{
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			if (history_index == -1)
			{
				cout << '0' << endl;
			}
			else
			{
				cout << history.at(history_index)->execute() << endl; //the commands(pointers) are calling execute 
			}
		};
		bool initialized() 
		{
			//Return true if the history has been primed with a single op instruction
			//(checks if history has an initial command)
			//This is necessary because that is the base of a calculation
			if (history.size() != 0)
			{
				return true;
			}

			return false;
		};
		void add_command(Command* cmd) 
		{
			//Adds a command to history in the appropriate position (based on history_index)
			
			//if history is empty
			if (history.size() == 0)
			{
				history.push_back(cmd);
				++history_index;
			}
			else if (history_index == history.size() - 1)
			{
				history.push_back(cmd);
				++history_index;
			}
			else
			{
				history.at(history_index) = cmd;
				++history_index;
			}
		};
		Command* get_command() 
		{
			//Returns the command in history we are currently referring to (based on history_index)
			if (history.size() == 0) //empty
			{
				cout << "There are no commands" << endl;
				exit(0);
			}

			return history.at(history_index);
		};
		void undo() 
		{
			//Moves to the last command in history (if possible)
			--history_index;

		};
		void redo() 
		{
			//Moves to the next command in history (if possible)
			
			//checks for out of bounds
			if (history.size() == 0 || history_index == static_cast<int>(history.size() -1))
			{
				cout << "Cannot redo" << endl;
			}
			else
			{
				++history_index;
			}
		};
};

#endif //__MENU_CLASS__
