#include "application.h"

#include <iostream>
using std::cout;
using std::endl;

application::application () 
	: content(string("")), com_history(command_history()), p_menu(nullptr), buttons(vector<button *>()) {}

application::~application ()
{
	if (p_menu) delete p_menu;
	unsigned int i, bc = buttons.size();
	for (i = 0; i < bc; ++i) delete buttons[i];
}

void application::set_menu (menu * p)
{
	if (p_menu) delete p_menu;
	p_menu = p;
}
menu * application::get_menu () {return p_menu;}

void application::add_button (button * but) {buttons.push_back(but);}
button * application::get_button (unsigned int index) {return index < buttons.size() ? buttons[index] : nullptr;}

void application::add_command_in_history (shared_ptr<command> com) {com_history.add(com);}
bool application::undo () {return com_history.undo();}
bool application::redo () {return com_history.redo();}

void application::insert_text (unsigned int position, string text)
{
	if (position <= content.length()) content.insert(position, text);
}

void application::remove_text (unsigned int first, unsigned int last)
{
	if (first < last and first < content.length()) content.erase(first, last - first);
}

string application::get_text (unsigned int first, unsigned int last)
{
	return (first < last and first < content.length()) ? string(content, first, last - first) : string("");
}

void application::Show ()
{
	cout << "\"" << content << "\"" << endl << endl;
}
