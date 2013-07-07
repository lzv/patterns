#include "command_history.h"
#include "command.h"

command_history::command_history() : history(vector<shared_ptr<command> >()), cur_index(0) {}

void command_history::add (shared_ptr<command> com) 
{
	// Если в момент добавления мы отошли назад по истории, удаляем отмененные команды.
	if (cur_index < history.size()) history.erase(history.begin() + cur_index, history.end());
	history.push_back(com);
	++cur_index;
}

void command_history::del (unsigned int index)
{
	if (index < history.size())
	{
		// cur_index не уменьшается, если удаляется отмененная команда.
		if (index < cur_index) --cur_index;
		history.erase(history.begin() + index);
	}
}

bool command_history::undo ()
{
	bool result = cur_index > 0;
	if (result) history[--cur_index]->UnExecute();
	return result;
}

bool command_history::redo ()
{
	bool result = cur_index < history.size();
	if (result) history[cur_index++]->ReExecute();
	return result;
}
