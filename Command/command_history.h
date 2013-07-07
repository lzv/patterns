#ifndef COMMAND_HISTORY_H
#define COMMAND_HISTORY_H

#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;

class command;

class command_history
{
	private:
		vector <shared_ptr<command> > history;	// Выполненные команды.
		unsigned int cur_index;					/* Текущий индекс - номер команды, следующей за последней выполненной. 
													Обычно равен history.size(). */

	public:
		command_history ();
		void add (shared_ptr<command> com);
		void del (unsigned int index);
		bool undo ();
		bool redo ();
		
};

#endif // COMMAND_HISTORY_H
