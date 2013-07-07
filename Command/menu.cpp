#include "menu.h"
#include "command.h"

menu_item::menu_item (string name, shared_ptr<command> com) : name(name), com(com) {}
void menu_item::clicked () {com->Execute();}

menu::menu () : items(vector<menu_item *>()) {}

menu::~menu ()
{
	unsigned int i, count = items.size();
	for (i = 0; i < count; ++i) delete items[i];
}

void menu::add (menu_item * item)
{
	items.push_back(item);
}

menu_item * menu::get (unsigned int index)
{
	return index < items.size() ? items[index] : nullptr;
}
