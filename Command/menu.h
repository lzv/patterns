#ifndef MENU_H
#define MENU_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;

class command;

class menu_item
{
	private:
		string name;
		shared_ptr<command> com;

	public:
		menu_item (string name, shared_ptr<command> com);
		void clicked ();
};

class menu
{
	private:
		vector<menu_item *> items;

	public:
		menu();
		~menu();
		void add (menu_item * item);
		menu_item * get (unsigned int index);
};

#endif // MENU_H
